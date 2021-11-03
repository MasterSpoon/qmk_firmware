/* Copyright 2021 MasterSpoon
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

#include_next <mcuconf.h>

// Disable USBPD on pins B4 & B6, Setting bit UCPD1_DBDIS =1
#undef STM32_PWR_CR3
#define STM32_PWR_CR3						(PWR_CR3_EIWF | PWR_CR3_UCPD_DBDIS)

// Enable I2C1 for IS31FL3743A 
#ifdef RGB_MATRIX_ENABLE
#undef STM32_I2C_USE_I2C1
#define STM32_I2C_USE_I2C1                  TRUE
#endif
