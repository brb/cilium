/* SPDX-License-Identifier: GPL-2.0 */
/* Copyright (C) 2016-2020 Authors of Cilium */

/*
 *
 *
 *                     **** WARNING ****
 * This is just a dummy header with dummy values to allow for test
 * compilation without the full code generation engine backend.
 *
 *
 *
 */
#include "lib/utils.h"

DEFINE_MAC(NODE_MAC, 0xde, 0xad, 0xbe, 0xef, 0xc0, 0xde);
#define NODE_MAC fetch_mac(NODE_MAC)

DEFINE_IPV6(ROUTER_IP, 0xbe, 0xef, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x1, 0x0, 0x1, 0x0, 0x0);
#define ENCAP_IFINDEX 1
#define HOST_IFINDEX 1
#define CILIUM_IFINDEX 1
#define NATIVE_DEV_IFINDEX 1
#define NATIVE_DEV_MAC_BY_IFINDEX(_) { .addr = { 0xce, 0x72, 0xa7, 0x03, 0x88, 0x56 } }
DEFINE_IPV6(HOST_IP, 0xbe, 0xef, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0xa, 0x0, 0x2, 0xf, 0xff, 0xff);
#define HOST_ID 1
#define WORLD_ID 2
#define UNMANAGED_ID 3
#define HEALTH_ID 4
#define INIT_ID 5
#define REMOTE_NODE_ID 6
#define HOST_IFINDEX_MAC { .addr = { 0xce, 0x72, 0xa7, 0x03, 0x88, 0x56 } }
#define NAT46_PREFIX { .addr = { 0xbe, 0xef, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0 } }
#define NODEPORT_PORT_MIN 30000
#define NODEPORT_PORT_MAX 32767
#define NODEPORT_PORT_MIN_NAT (NODEPORT_PORT_MAX + 1)
#define NODEPORT_PORT_MAX_NAT 43835

#define CT_CONNECTION_LIFETIME_TCP	21600
#define CT_CONNECTION_LIFETIME_NONTCP	60
#define CT_SERVICE_LIFETIME_TCP		21600
#define CT_SERVICE_LIFETIME_NONTCP	60
#define CT_SYN_TIMEOUT			60
#define CT_CLOSE_TIMEOUT		10
#define CT_REPORT_INTERVAL		5
#define CT_REPORT_FLAGS			0xff

#ifdef ENABLE_IPV4
#define IPV4_MASK 0xffff
#define IPV4_GATEWAY 0xfffff50a
#define IPV4_LOOPBACK 0x1ffff50a
#ifdef ENABLE_NODEPORT
#define SNAT_MAPPING_IPV4 cilium_snat_v4_external
#define SNAT_MAPPING_IPV4_SIZE 524288
#endif /* ENABLE_NODEPORT */
#endif /* ENABLE_IPV4 */

#ifdef ENABLE_IPV6
#ifdef ENABLE_NODEPORT
#define SNAT_MAPPING_IPV6 cilium_snat_v6_external
#define SNAT_MAPPING_IPV6_SIZE 524288
#endif /* ENABLE_NODEPORT */
#endif /* ENABLE_IPV6 */

#define ENCAP_GENEVE 1
#define ENDPOINTS_MAP test_cilium_lxc
#define EVENTS_MAP test_cilium_events
#define SIGNAL_MAP test_cilium_signals
#define METRICS_MAP test_cilium_metrics
#define POLICY_CALL_MAP test_cilium_policy
#define SOCK_OPS_MAP test_sock_ops_map
#define IPCACHE_MAP test_cilium_ipcache
#define ENCRYPT_MAP test_cilium_encrypt_state
#define TUNNEL_MAP test_cilium_tunnel_map
#define EP_POLICY_MAP test_cilium_ep_to_policy
#define LB6_REVERSE_NAT_MAP test_cilium_lb6_reverse_nat
#define LB6_SERVICES_MAP_V2 test_cilium_lb6_services
#define LB6_BACKEND_MAP test_cilium_lb6_backends
#define LB6_REVERSE_NAT_SK_MAP cilium_lb6_reverse_sk
#define LB4_REVERSE_NAT_MAP test_cilium_lb4_reverse_nat
#define LB4_SERVICES_MAP_V2 test_cilium_lb4_services
#define LB4_BACKEND_MAP test_cilium_lb4_backends
#define LB4_REVERSE_NAT_SK_MAP cilium_lb4_reverse_sk
#define ENABLE_ARP_RESPONDER
#define TUNNEL_ENDPOINT_MAP_SIZE 65536
#define ENDPOINTS_MAP_SIZE 65536
#define METRICS_MAP_SIZE 65536
#define CILIUM_NET_MAC  { .addr = { 0xce, 0x72, 0xa7, 0x03, 0x88, 0x57 } }
#define LB_REDIRECT 1
#define LB_DST_MAC { .addr = { 0xce, 0x72, 0xa7, 0x03, 0x88, 0x58 } }
#define CILIUM_LB_MAP_MAX_ENTRIES	65536
#define POLICY_MAP_SIZE 16384
#define IPCACHE_MAP_SIZE 512000
#define POLICY_PROG_MAP_SIZE ENDPOINTS_MAP_SIZE
#ifndef SKIP_DEBUG
#define LB_DEBUG
#endif
#define MONITOR_AGGREGATION 5
#define MTU 1500
#define ENABLE_IPSEC
#define EPHEMERAL_MIN 32768
#ifdef ENABLE_NODEPORT
#define CT_MAP_TCP6 test_cilium_ct_tcp6_65535
#define CT_MAP_ANY6 test_cilium_ct_any6_65535
#define CT_MAP_TCP4 test_cilium_ct_tcp4_65535
#define CT_MAP_ANY4 test_cilium_ct_any4_65535
#define CT_MAP_SIZE_TCP 4096
#define CT_MAP_SIZE_ANY 4096
#define CONNTRACK
#define CONNTRACK_ACCOUNTING
#endif /* ENABLE_NODEPORT */

#ifdef ENABLE_NODEPORT
#ifdef ENABLE_IPV4
#define NODEPORT_NEIGH4 test_cilium_neigh4
#endif
#ifdef ENABLE_IPV6
#define NODEPORT_NEIGH6 test_cilium_neigh6
#endif
#endif
