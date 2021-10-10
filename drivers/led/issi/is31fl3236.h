/* Copyright 2017 Jason Williams
 * Copyright 2018 Jack Humbert
 * Copyright 2018 Yiancar
 * Copyright 2020 MelGeek
 * Copyright 2021 MasterSpoon
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// This is a 7-bit address, that gets left-shifted and bit 0
// set to 0 for write, 1 for read (as per I2C protocol)
// The address will vary depending on your wiring:
// 00 <-> GND
// 01 <-> SCL
// 10 <-> SDA
// 11 <-> VCC
// ADDR represents A1:A0 of the 7-bit address.
// The result is: 0b01111(ADDR)
#ifndef DRIVER_ADDR_1
#    define DRIVER_ADDR_1 0b0111100
#endif

// Unused here but defined as passed through in Matrix Types
#    define ISSI_SSR_1 0x00
#    define ISSI_SSR_2 0x00
#    define ISSI_SSR_3 0x00
#    define ISSI_SSR_4 0x00

// Register Functions
#define ISSI_REG_CONTROL 0x00 // Shutdown Register
#define ISSI_PWM_REG_1ST 0x01
#define ISSI_REG_UPDATE 0x25
#define ISSI_UPDATE 0x00
#define ISSI_SCL_REG_1ST 0x26 // LED Control Register
#define ISSI_REG_GCR 0x4A
#define ISSI_REG_FREQ 0x4B
#define ISSI_REG_RESET 0x4F

// Set defaults for Register Functions
#ifndef ISSI_CONTROL
#    define ISSI_CONTROL 0x01
#endif
#ifndef ISSI_GCR
#    define ISSI_GCR 0x00
#endif
#ifndef ISSI_FREQ
#    define ISSI_FREQ 0x00
#endif

// Set defaults for LED Control Registers
#ifndef ISSI_SCAL_RED
#    define ISSI_SCAL_RED 0x01
#endif
#ifndef ISSI_SCAL_BLUE
#    define ISSI_SCAL_BLUE 0x01
#endif
#ifndef ISSI_SCAL_GREEN
#    define ISSI_SCAL_GREEN 0x01
#endif
#define ISSI_SCAL_RED_OFF 0x00
#define ISSI_SCAL_GREEN_OFF 0x00
#define ISSI_SCAL_BLUE_OFF 0x00

#ifndef ISSI_SCAL_LED
#    define ISSI_SCAL_LED 0x01
#endif
#define ISSI_SCAL_LED_OFF 0x00

// Set buffer sizes
#define ISSI_MAX_LEDS 36
#define ISSI_SCALING_SIZE 36
#define ISSI_PWM_TRF_SIZE 18
#define ISSI_SCALING_TRF_SIZE 18

// Map OUT locations to order in PWM / Scaling buffers
// This matches the ORDER in the Datasheet Register not the POSITION
// It will always count from 0x00 to (ISSI_MAX_LEDS - 1)
#define	OUT1	0x00
#define	OUT2	0x01
#define	OUT3	0x02
#define	OUT4	0x03
#define	OUT5	0x04
#define	OUT6	0x05
#define	OUT7	0x06
#define	OUT8	0x07
#define	OUT9	0x08
#define	OUT10	0x09
#define	OUT11	0x0A
#define	OUT12	0x0B
#define	OUT13	0x0C
#define	OUT14	0x0D
#define	OUT15	0x0E
#define	OUT16	0x0F
#define	OUT17	0x10
#define	OUT18	0x11
#define	OUT19	0x12
#define	OUT20	0x13
#define	OUT21	0x14
#define	OUT22	0x15
#define	OUT23	0x16
#define	OUT24	0x17
#define	OUT25	0x18
#define	OUT26	0x19
#define	OUT27	0x1A
#define	OUT28	0x1B
#define	OUT29	0x1C
#define	OUT30	0x1D
#define	OUT31	0x1E
#define	OUT32	0x1F
#define	OUT33	0x20
#define	OUT34	0x21
#define	OUT35	0x22
#define	OUT36	0x23