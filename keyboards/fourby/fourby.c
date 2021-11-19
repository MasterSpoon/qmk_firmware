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

#include "fourby.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {	23, 21, 0, 2 },
  {	19, 20, 5, 4 },
  {	17, 16, 6, 7 },
  {	12, 13, 14, 15 }
  }, {
  // LED Index to Physical Position
	{ 120 , 5 }, { 128 , 0 }, { 136 , 5 }, { 144, 16 }, { 136 , 21 }, { 120 , 21 },
	{ 120 , 37 }, { 136 , 37 }, { 144, 48 }, { 128, 64 }, { 96 , 64 }, { 80 , 48 },
	{ 88 , 53 }, { 104 , 53 }, { 120 , 53 }, { 136 ,53 }, { 104 , 37 }, { 88 , 37 },
	{ 80, 16 }, { 88 , 21 }, { 104 , 21 }, { 104 , 5 }, { 96 , 0 }, { 88 , 5 }
}, {
  // LED Index to Flag
	4, 2, 4, 2, 4, 4, 4, 4, 2, 2, 2, 2, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 2, 4
} };
#endif
