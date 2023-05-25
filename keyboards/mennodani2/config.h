// Copyright 2023 KexPilot (@KexPilot)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define OLED_TIMEOUT            1000

#define OLED_DISPLAY_CUSTOM
#define OLED_DISPLAY_WIDTH      32
#define OLED_DISPLAY_HEIGHT     64
#define OLED_MATRIX_SIZE        (OLED_DISPLAY_HEIGHT / 8 * OLED_DISPLAY_WIDTH)
#define OLED_BLOCK_TYPE         uint16_t
#define OLED_BLOCK_COUNT        (sizeof(OLED_BLOCK_TYPE) * 8)
#define OLED_BLOCK_SIZE         (OLED_MATRIX_SIZE / OLED_BLOCK_COUNT)
#define OLED_COM_PINS           COM_PINS_ALT
/* These need to be defined, but only relevant if 90° rotation is used
https://docs.qmk.fm/#/feature_oled_driver?id=_128x64-amp-custom-sized-oled-displays */
#define OLED_SOURCE_MAP         { 0, 8, 16, 24 }
#define OLED_TARGET_MAP         { 24, 16, 8, 0 }

#define I2C1_CLOCK_SPEED        100000u

#define I2C_DRIVER              I2CD1
#define I2C1_SCL_PIN            GP27
#define I2C1_SDA_PIN            GP26
//#define I2C1_SCL_PAL_MODE       1
//#define I2C1_SDA_PAL_MODE       1

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
