/* -*- Mode: C; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*- */
/* NetworkManager Wireless Applet -- Display wireless access points and allow user control
 *
 * Dan Williams <dcbw@redhat.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * (C) Copyright 2007 - 2011 Red Hat, Inc.
 */

#ifndef UTILS_H
#define UTILS_H

#include <glib.h>
#include <nm-connection.h>
#include <nm-device.h>
#include <net/ethernet.h>
#include <nm-access-point.h>
#include <gnome-keyring.h>

const char *utils_get_device_description (NMDevice *device);

guint32 utils_freq_to_channel (guint32 freq);
guint32 utils_channel_to_freq (guint32 channel, char *band);
guint32 utils_find_next_channel (guint32 channel, int direction, char *band);

gboolean utils_ether_addr_valid (const struct ether_addr *test_addr);

gboolean utils_connection_valid_for_device (NMConnection *connection,
                                            NMDevice *device,
                                            gpointer specific_object);

GSList *utils_filter_connections_for_device (NMDevice *device, GSList *connections);

char *utils_hash_ap (const GByteArray *ssid,
                     NM80211Mode mode,
                     guint32 flags,
                     guint32 wpa_flags,
                     guint32 rsn_flags);

char *utils_escape_notify_message (const char *src);

#define KEYRING_UUID_TAG "connection-uuid"
#define KEYRING_SN_TAG "setting-name"
#define KEYRING_SK_TAG "setting-key"

GnomeKeyringAttributeList *utils_create_keyring_add_attr_list (NMConnection *connection,
                                                               const char *connection_uuid,
                                                               const char *connection_id,
                                                               const char *setting_name,
                                                               const char *setting_key,
                                                               char **out_display_name);

#endif /* UTILS_H */

