// Copyright 2023 Dani (@captnketchup)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#define FORCE_NKRO
#define NUMBER_OF_ENCODERS 1
#define ENCODERS_PAD_A { GP21 }
#define ENCODERS_PAD_B { GP22 }
#define ENCODER_RESOLUTION 1
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
