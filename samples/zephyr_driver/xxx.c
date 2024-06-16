/*
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/device.h>
#include <zephyr/kernel.h>
#include <zephyr/devicetree.h>
#include <zephyr/types.h>
#include <zephyr/sys/device_mmio.h>
#include <zephyr/logging/log_instance.h>
#include <zephyr/logging/log.h>

#include "xxx.h"

#define DT_DRV_COMPAT xxx
#define XXX_LOG_NAME  xxx

LOG_MODULE_REGISTER(XXX_LOG_NAME, CONFIG_XXX_LOG_LEVEL);

static int xxx_init(const struct device *dev)
{
	struct xxx_data *dev_data = dev->data;
	int ret;

	LOG_INST_INF(dev_data->log, "Init xxx driver");

	DEVICE_MMIO_MAP(dev, K_MEM_CACHE_NONE);

	return ret;
}

#define XXX(idx)                                                                                   \
	LOG_INSTANCE_REGISTER(XXX_LOG_NAME, idx, CONFIG_XXX_LOG_LEVEL);                            \
	static struct xxx_data xxx_data_##idx = {LOG_INSTANCE_PTR_INIT(log, XXX_LOG_NAME, idx)};   \
	static struct xxx_config xxx_cfg_##idx = {                                                 \
		DEVICE_MMIO_ROM_INIT(DT_DRV_INST(idx)),                                            \
	};                                                                                         \
	DEVICE_DT_INST_DEFINE(idx, xxx_init, NULL, &xxx_data_##idx, &xxx_cfg_##idx, POST_KERNEL,   \
			      CONFIG_KERNEL_INIT_PRIORITY_DEFAULT, NULL);

DT_INST_FOREACH_STATUS_OKAY(XXX);
