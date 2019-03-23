/*
 * Copyright(c) 2006 to 2018 ADLINK Technology Limited and others
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v. 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0, or the Eclipse Distribution License
 * v. 1.0 which is available at
 * http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * SPDX-License-Identifier: EPL-2.0 OR BSD-3-Clause
 */
#ifndef _DDS_TKMAP_H_
#define _DDS_TKMAP_H_

#include "dds__types.h"
#include "dds/ddsrt/atomics.h"

#if defined (__cplusplus)
extern "C" {
#endif

struct ddsi_tkmap;
struct ddsi_serdata;
struct dds_topic;

struct ddsi_tkmap_instance
{
  struct ddsi_serdata * m_sample;
  uint64_t m_iid;
  ddsrt_atomic_uint32_t m_refc;
};

DDS_EXPORT struct ddsi_tkmap * ddsi_tkmap_new (void);
DDS_EXPORT void ddsi_tkmap_free (struct ddsi_tkmap *tkmap);
DDS_EXPORT void ddsi_tkmap_instance_ref (struct ddsi_tkmap_instance *tk);
DDS_EXPORT uint64_t ddsi_tkmap_lookup (struct ddsi_tkmap *tkmap, const struct ddsi_serdata *serdata);
DDS_EXPORT struct ddsi_tkmap_instance * ddsi_tkmap_find(struct ddsi_serdata *sd, const bool rd, const bool create);
DDS_EXPORT struct ddsi_tkmap_instance * ddsi_tkmap_find_by_id (struct ddsi_tkmap *map, uint64_t iid);
DDS_EXPORT struct ddsi_tkmap_instance * ddsi_tkmap_lookup_instance_ref (struct ddsi_serdata * sd);
DDS_EXPORT void ddsi_tkmap_instance_unref (struct ddsi_tkmap_instance *tk);

#if defined (__cplusplus)
}
#endif
#endif