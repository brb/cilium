// Copyright 2016-2019 Authors of Cilium
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// +build !privileged_tests

package common

import (
	"testing"

	"github.com/cilium/cilium/pkg/checker"

	"gopkg.in/check.v1"
	"io/ioutil"
	"os"
	"path/filepath"
)

// Hook up gocheck into the "go test" runner.
func Test(t *testing.T) {
	check.TestingT(t)
}

type CommonSuite struct{}

var _ = check.Suite(&CommonSuite{})

func (s *CommonSuite) TestC2GoArray(c *check.C) {
	c.Assert(C2GoArray("0x0, 0x1, 0x2, 0x3"), checker.DeepEquals, []byte{0, 0x01, 0x02, 0x03})
	c.Assert(C2GoArray("0x0, 0xff, 0xff, 0xff"), checker.DeepEquals, []byte{0, 0xFF, 0xFF, 0xFF})
	c.Assert(C2GoArray("0xa, 0xbc, 0xde, 0xf1"), checker.DeepEquals, []byte{0xa, 0xbc, 0xde, 0xf1})
	c.Assert(C2GoArray("0x0"), checker.DeepEquals, []byte{0})
	c.Assert(C2GoArray(""), checker.DeepEquals, []byte{})
}

func (s *CommonSuite) TestGoArray2C(c *C) {
	tests := []formatTestCase{
		{
			input:  []byte{0, 0x01, 0x02, 0x03},
			output: "0x0, 0x1, 0x2, 0x3",
		},
		{
			input:  []byte{0, 0xFF, 0xFF, 0xFF},
			output: "0x0, 0xff, 0xff, 0xff",
		},
		{
			input:  []byte{0xa, 0xbc, 0xde, 0xf1},
			output: "0xa, 0xbc, 0xde, 0xf1",
		},
		{
			input:  []byte{0},
			output: "0x0",
		},
		{
			input:  []byte{},
			output: "",
		},
	}

	for _, test := range tests {
		c.Assert(GoArray2C(test.input), Equals, test.output)
	}
}

func (s *CommonSuite) TestMoveNewFilesTo(c *check.C) {
	oldDir := c.MkDir()
	newDir := c.MkDir()
	f1, err := ioutil.TempFile(oldDir, "")
	c.Assert(err, check.IsNil)
	f2, err := ioutil.TempFile(oldDir, "")
	c.Assert(err, check.IsNil)
	f3, err := ioutil.TempFile(newDir, "")
	c.Assert(err, check.IsNil)

	// Copy the same f4 file in both directories to make sure the same files
	// are not moved from the old directory into the new directory.
	err = ioutil.WriteFile(filepath.Join(oldDir, "foo"), []byte(""), os.FileMode(0644))
	c.Assert(err, check.IsNil)
	err = ioutil.WriteFile(filepath.Join(newDir, "foo"), []byte(""), os.FileMode(0644))
	c.Assert(err, check.IsNil)

	compareDir := func(dir string, wantedFiles []string) {
		files, err := ioutil.ReadDir(dir)
		c.Assert(err, check.IsNil)
		filesNames := make([]string, 0, len(wantedFiles))
		for _, file := range files {
			filesNames = append(filesNames, file.Name())
		}
		c.Assert(wantedFiles, checker.DeepEquals, filesNames)
	}

	type args struct {
		oldDir string
		newDir string
	}
	tests := []struct {
		name       string
		args       args
		wantErr    bool
		wantOldDir []string
		wantNewDir []string
	}{
		{
			name: "copying from one directory to the other",
			args: args{
				oldDir: oldDir,
				newDir: newDir,
			},
			wantErr: false,
			wantOldDir: []string{
				"foo",
			},
			wantNewDir: []string{
				f1.Name(),
				f2.Name(),
				f3.Name(),
				"foo",
			},
		},
	}
	for _, tt := range tests {
		if err := MoveNewFilesTo(tt.args.oldDir, tt.args.newDir); (err != nil) != tt.wantErr {
			c.Assert(err != nil, check.Equals, tt.wantErr)
			compareDir(tt.args.oldDir, tt.wantOldDir)
			compareDir(tt.args.newDir, tt.wantNewDir)
		}
	}
}
