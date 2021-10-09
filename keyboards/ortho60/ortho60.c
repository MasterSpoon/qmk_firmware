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

#include "ortho60.h"

// LED position on controller
const is31_led __flash g_is31_leds[DRIVER_LED_TOTAL] = {
//		Red,		Green,		Blue
    {0, CS8_SW11,	CS9_SW11,	CS7_SW11},	// D1
    {0, CS8_SW2,	CS9_SW2,	CS7_SW2},	// D2
    {0, CS8_SW1,	CS9_SW1,	CS7_SW1},	// D3	
    {0, CS5_SW2,	CS4_SW2,	CS6_SW2},	// D4	
    {0, CS5_SW1,	CS4_SW1,	CS6_SW1},	// D5	
    {0, CS2_SW2,	CS3_SW2,	CS1_SW1},	// D6	
    {0, CS2_SW1,	CS3_SW1,	CS1_SW1},	// D7
    {0, CS11_SW2,	CS12_SW2,	CS10_SW2},	// D8	
    {0, CS11_SW1,	CS12_SW1,	CS10_SW1},	// D9	
    {0, CS17_SW1,	CS16_SW1,	CS18_SW1},	// D10	
    {0, CS17_SW2,	CS16_SW2,	CS18_SW2},	// D11
    {0, CS14_SW1,	CS15_SW1,	CS13_SW1},	// D12
    {0, CS14_SW2,	CS15_SW2,	CS13_SW2},	// D13
    {0, CS14_SW10,	CS15_SW10,	CS13_SW10},	// D14

    {0, CS8_SW3,	CS9_SW3,	CS7_SW3},	// D15
    {0, CS8_SW4,	CS9_SW4,	CS7_SW4},	// D16
    {0, CS8_SW6,	CS9_SW6,	CS7_SW6},	// D17	
    {0, CS5_SW4,	CS4_SW4,	CS6_SW4},	// D18	
    {0, CS5_SW6,	CS4_SW6,	CS6_SW6},	// D19	
    {0, CS2_SW4,	CS3_SW4,	CS1_SW4},	// D20	
    {0, CS2_SW6,	CS3_SW6,	CS1_SW6},	// D21
    {0, CS11_SW4,	CS12_SW4,	CS10_SW4},	// D22	
    {0, CS11_SW6,	CS12_SW6,	CS10_SW6},	// D23	
    {0, CS17_SW10,	CS16_SW10,	CS18_SW10},	// D24	
    {0, CS17_SW5,	CS16_SW5,	CS18_SW5},	// D25
    {0, CS17_SW3,	CS16_SW3,	CS18_SW3},	// D26
    {0, CS14_SW5,	CS15_SW5,	CS13_SW5},	// D27
    {0, CS14_SW3,	CS15_SW3,	CS13_SW3},	// D28

    {0, CS8_SW10,	CS9_SW10,	CS7_SW10},	// D29
    {0, CS8_SW8,	CS9_SW8,	CS7_SW8},	// D30
    {0, CS5_SW10,	CS4_SW10,	CS6_SW10},	// D31
    {0, CS5_SW8,	CS4_SW8,	CS6_SW8},	// D32
    {0, CS5_SW11,	CS4_SW11,	CS6_SW11},	// D33
    {0, CS2_SW8,	CS3_SW8,	CS1_SW8},	// D34
    {0, CS2_SW10,	CS3_SW10,	CS1_SW10},	// D35
    {0, CS11_SW11,	CS12_SW11,	CS10_SW11},	// D36
    {0, CS11_SW8,	CS12_SW8,	CS10_SW8},	// D37
    {0, CS11_SW10,	CS12_SW10,	CS10_SW10},	// D38
    {0, CS17_SW6,	CS16_SW6,	CS18_SW6},	// D39
    {0, CS17_SW4,	CS16_SW4,	CS18_SW4},	// D40
    {0, CS14_SW6,	CS15_SW6,	CS13_SW6},	// D41
    {0, CS14_SW4,	CS15_SW4,	CS13_SW4},	// D42

    {0, CS8_SW9,	CS9_SW9,	CS7_SW9},	// D43
    {0, CS8_SW5,	CS9_SW5,	CS7_SW5},	// D44
    {0, CS5_SW3,	CS4_SW3,	CS6_SW3},	// D45
    {0, CS5_SW5,	CS4_SW5,	CS6_SW5},	// D46	
    {0, CS2_SW11,	CS3_SW11,	CS1_SW11},	// D47
    {0, CS2_SW5,	CS3_SW5,	CS1_SW5},	// D48
    {0, CS2_SW3,	CS3_SW3,	CS1_SW3},	// D49
    {0, CS11_SW9,	CS12_SW9,	CS10_SW9},	// D50
    {0, CS11_SW5,	CS12_SW5,	CS10_SW5},	// D51
    {0, CS11_SW3,	CS12_SW3,	CS10_SW3},	// D52
    {0, CS17_SW8,	CS16_SW8,	CS18_SW8},	// D53
    {0, CS17_SW11,	CS16_SW11,	CS18_SW11},	// D54
    {0, CS14_SW8,	CS15_SW8,	CS13_SW8},	// D55
    {0, CS14_SW11,	CS15_SW11,	CS13_SW11},	// D56
	
    {0, CS8_SW7,	CS9_SW7,	CS7_SW7},	// D57
    {0, CS5_SW9,	CS4_SW9,	CS6_SW9},	// D58	
    {0, CS5_SW7,	CS4_SW7,	CS6_SW7},	// D59
    {0, CS2_SW7,	CS3_SW7,	CS1_SW7},	// D60	
    {0, CS2_SW9,	CS3_SW9,	CS1_SW9},	// D61	
    {0, CS11_SW7,	CS12_SW7,	CS10_SW7},	// D62	
    {0, CS17_SW7,	CS16_SW7,	CS18_SW7},	// D63
    {0, CS17_SW9,	CS16_SW9,	CS18_SW9},	// D64
    {0, CS14_SW7,	CS15_SW7,	CS13_SW7},	// D65
    {0, CS14_SW9,	CS15_SW9,	CS13_SW9}	// D66	
};

led_config_t g_led_config = { {
// Key Matrix to LED Index
        {0,1,2,3,4,5,6,7,8,9,10,11,12,13},
		{14,15,16,17,18,19,20,21,22,23,24,25,26,27},
		{28,29,30,31,32,33,34,35,36,37,38,39,40,41},
		{42,43,44,45,46,47,48,49,50,51,52,53,54,55},
		{56,57,58,59,60,61,62,63,64,65}
  }, {
// LED Index to Physical Position	
{8, 0}, {24, 0}, {40, 0}, {56, 0}, {72, 0}, {88, 0}, {104, 0}, {120, 0}, {136, 0}, {152, 0}, {168, 0}, {184, 0}, {200, 0}, {216, 0},
{8,16}, {24,16}, {40,16}, {56,16}, {72,16}, {88,16}, {104,16}, {120,16}, {136,16}, {152,16}, {168,16}, {184,16}, {200,16}, {216,16},
{6,32}, {24,32}, {40,32}, {56,32}, {72,32}, {88,32}, {104,32}, {120,32}, {136,32}, {152,32}, {168,32}, {184,32}, {200,32}, {218,32},
{6,48}, {24,48}, {40,48}, {56,48}, {72,48}, {88,48}, {104,48}, {120,48}, {136,48}, {152,48}, {168,48}, {184,48}, {200,48}, {218,48},
{14,64}, {34,64}, {54,64}, {80,64}, {112,64}, {144,64}, {168,64}, {184,64}, {200,64}, {216,64}
}, {
  // LED Index to Flag
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,  
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4
}
};
