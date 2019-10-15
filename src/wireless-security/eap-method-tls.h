// SPDX-License-Identifier: GPL-2.0+
/* NetworkManager Applet -- allow user control over networking
 *
 * Dan Williams <dcbw@redhat.com>
 *
 * (C) Copyright 2007 - 2010 Red Hat, Inc.
 */

#ifndef EAP_METHOD_TLS_H
#define EAP_METHOD_TLS_H

#include "wireless-security.h"

typedef struct _EAPMethodTLS EAPMethodTLS;

EAPMethodTLS *eap_method_tls_new (WirelessSecurity *ws_parent,
                                  NMConnection *connection,
                                  gboolean phase2,
                                  gboolean secrets_only);

#endif /* EAP_METHOD_TLS_H */

