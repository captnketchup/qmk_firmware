// Copyright 2023 KexPilot (@KexPilot)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define OLED_TIMEOUT            10000

#define OLED_DISPLAY_CUSTOM
#define OLED_DISPLAY_WIDTH      64
#define OLED_DISPLAY_HEIGHT     32
#define OLED_COLUMN_OFFSET      32
#define OLED_MATRIX_SIZE        (OLED_DISPLAY_HEIGHT / 8 * OLED_DISPLAY_WIDTH)
#define OLED_BLOCK_TYPE         uint16_t
#define OLED_BLOCK_COUNT        (sizeof(OLED_BLOCK_TYPE) * 8)
/* If this is not defined and too much is updated, the screen wont be able to keep up. By default it is defined to
1, but it seems that RP2040 can keep up with allowing full update */
#define OLED_UPDATE_PROCESS_LIMIT OLED_BLOCK_COUNT
#define OLED_BLOCK_SIZE         (OLED_MATRIX_SIZE / OLED_BLOCK_COUNT)
#define OLED_COM_PINS           COM_PINS_ALT
/* These need to be defined, but only relevant if 90° rotation is used
https://docs.qmk.fm/#/feature_oled_driver?id=_128x64-amp-custom-sized-oled-displays */
#define OLED_SOURCE_MAP         { }
#define OLED_TARGET_MAP         { }

#define I2C_DRIVER              I2CD1
#define I2C1_SCL_PIN            GP27
#define I2C1_SDA_PIN            GP26

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
