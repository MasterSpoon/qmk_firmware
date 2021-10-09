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
#define PRODUCT ergospoondox

/* key matrix size */
#define MATRIX_ROWS 12
#define MATRIX_COLS 7

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
#define MATRIX_ROW_PINS { C14, F0, F1, A0, A1, A3 }
#define MATRIX_COL_PINS { C15, C13, A2, B0, A7, A6, A5 }

// #define UNUSED_PINS

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
#define SPLIT_HAND_PIN B9
#define SPLIT_MODS_ENABLE
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_WPM_ENABLE
// #define SPLIT_USB_DETECT
// #define SPLIT_USB_TIMEOUT 2000

#define SERIAL_USART_FULL_DUPLEX  // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN B10   // USART TX pin
#define SERIAL_USART_RX_PIN B11   // USART RX pin
//#define USART1_REMAP             // Remap USART TX and RX pins on STM32F103 MCUs, see table below.
//#define SERIAL_USART_PIN_SWAP    // Swap TX and RX pins if keyboard is master halve.
// Check if this feature is necessary with your keyboard design and available on the mcu.
#define SELECT_SOFT_SERIAL_SPEED 0	// or 0, 2, 3, 4, 5
                                    //  0: 460800 baud
                                    //  1: 230400 baud (default)
                                    //  2: 115200 baud
                                    //  3: 57600 baud
                                    //  4: 38400 baud
                                    //  5: 19200 baud
#define SERIAL_USART_DRIVER SD3     // USART driver of TX and RX pin. default: USART1
#define SERIAL_USART_TX_PAL_MODE 4  // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 7
#define SERIAL_USART_RX_PAL_MODE 4  // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 7
#define SERIAL_USART_TIMEOUT 100    // USART driver timeout. default 100

/* AVR ONLY - For using I2C instead of Serial (defaults to serial) */
// #define USE_I2C

/* WS2812 SPI driver config */
#define DRIVER_LED_TOTAL 96
#define RGBLED_NUM 96
#define WS2812_SPI SPID2            // default: SPID1
#define RGB_DI_PIN B15              // MOSI pin
#define WS2812_SPI_MOSI_PAL_MODE 0  // MOSI pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 5
#define WS2812_SPI_SCK_PIN B13      // Required for F072, may be for others -- SCK pin, see the respective datasheet for the appropriate values for your MCU. default: unspecified
#define WS2812_SPI_SCK_PAL_MODE 0   // SCK pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 5
#define RGB_MATRIX_SPLIT { 48, 48 }	// (Optional) For split keyboards, the number of LEDs connected on each half. X = left, Y = Right.

/* Oled config */
#define OLED_DISPLAY_ADDRESS 0x3C
#define I2C_DRIVER I2CD1
#define I2C1_SCL_BANK GPIOB
#define I2C1_SCL 6
#define I2C1_SCL_PAL_MODE 1
#define I2C1_SDA_BANK GPIOB
#define I2C1_SDA 7
#define I2C1_SDA_PAL_MODE 1

/* I2c Timings at 48mhz - Fast mode 400KHz */
// #define I2C1_TIMINGR_PRESC 2U
// #define I2C1_TIMINGR_SCLDEL 1U
// #define I2C1_TIMINGR_SDADEL 0U
// #define I2C1_TIMINGR_SCLH 9U
// #define I2C1_TIMINGR_SCLL 26U

/* I2c Timings at 48mhz - Fast mode plus 1MHz */
#define I2C1_TIMINGR_PRESC 2U
#define I2C1_TIMINGR_SCLDEL 0U
#define I2C1_TIMINGR_SDADEL 0U
#define I2C1_TIMINGR_SCLH 2U
#define I2C1_TIMINGR_SCLL 9U

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
