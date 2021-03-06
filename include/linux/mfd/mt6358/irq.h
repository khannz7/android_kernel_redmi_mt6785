/*
 * Copyright (C) 2018 MediaTek Inc.

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 */

#ifndef __MFD_MT6358_IRQ_H__
#define __MFD_MT6358_IRQ_H__


struct sp_top_t {
	int hwirq_base;
	unsigned int num_int_regs;
	unsigned int en_reg;
	unsigned int mask_reg;
	unsigned int sta_reg;
	unsigned int raw_sta_reg;
	unsigned int top_offset;
};

struct pmic_irq_t {
	const char *name;
	int hwirq;
	struct sp_top_t *sp_top;
};

#define SP_TOP_GEN(sp)	\
	{	\
		.hwirq_base = -1,	\
		.num_int_regs = 1,	\
		.en_reg = MT6358_##sp##_TOP_INT_CON0,		\
		.mask_reg = MT6358_##sp##_TOP_INT_MASK_CON0,	\
		.sta_reg = MT6358_##sp##_TOP_INT_STATUS0,		\
		.raw_sta_reg = MT6358_##sp##_TOP_INT_RAW_STATUS0,	\
		.top_offset = PMIC_INT_STATUS_##sp##_TOP_SHIFT,		\
	}

#endif /* __MFD_MT6358_IRQ_H__ */
