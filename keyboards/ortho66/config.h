/*
Copyright 2021 MasterSpoon

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x0000
#define DEVICE_VER 0x0001
#define MANUFACTURER MasterSpoon
#define PRODUCT Ortho66

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 14

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: pins used for columns, left to right
 * ROWS: pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS { A4, A10, F1, A3, A2 }
#define MATRIX_COL_PINS { A9, A8, B0, A7, A5, A6, A0, A1, B3, F0, B7, B6, B5, B4  }

// #define UNUSED_PINS

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION ROW2COL

#ifdef RGB_MATRIX_ENABLE
/* I2C Config */
#define I2C_DRIVER I2CD1
#define I2C1_SCL_PIN A13
#define I2C1_SCL_PAL_MODE 4
#define I2C1_SDA_PIN A14
#define I2C1_SDA_PAL_MODE 4

/* I2c Timings at 170MHz - Fast mode 400KHz */
// #define I2C1_TIMINGR_PRESC 1U
// #define I2C1_TIMINGR_SCLDEL 8U
// #define I2C1_TIMINGR_SDADEL 0U
// #define I2C1_TIMINGR_SCLH 45U
// #define I2C1_TIMINGR_SCLL 155U

/* I2c Timings at 170MHz - Fast mode plus 1MHz */
#define I2C1_TIMINGR_PRESC 0U
#define I2C1_TIMINGR_SCLDEL 8U
#define I2C1_TIMINGR_SDADEL 0U
#define I2C1_TIMINGR_SCLH 33U
#define I2C1_TIMINGR_SCLL 114U

/* LED controller settings */
#define DRIVER_COUNT 1
#define DRIVER_LED_TOTAL 66
// #define ISSI_MANUAL_SCALING 15
#define ISSI_SCAL_RED 190
// #define ISSI_SCAL_GREEN 255
// #define ISSI_SCAL_BLUE 255
#endif

// #define DEBUG_MATRIX_SCAN_RATE

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
// #define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
// #define LOCKING_RESYNC_ENABLE

/* If defined, GRAVE_ESC will always act as ESC when CTRL is held.
 * This is useful for the Windows task manager shortcut (ctrl+shift+esc).
 */
//#define GRAVE_ESC_CTRL_OVERRIDE

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during a
 * power-up.
 *
 */
//#define FORCE_NKRO

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

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

/* Bootmagic Lite key configuration */
//#define BOOTMAGIC_LITE_ROW 0
//#define BOOTMAGIC_LITE_COLUMN 0
