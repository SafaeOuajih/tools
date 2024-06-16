/*
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef XXX_H__
#define XXX_H__

#include <zephyr/kernel.h>
#include <zephyr/sys/device_mmio.h>

struct xxx_config {
	DEVICE_MMIO_ROM;
};

struct xxx_data {
	DEVICE_MMIO_RAM;
	LOG_INSTANCE_PTR_DECLARE(log);
};

#endif /* XXX_H__ */
