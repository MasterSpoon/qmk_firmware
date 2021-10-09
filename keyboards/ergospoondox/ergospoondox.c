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

#include "ergospoondox.h"

led_config_t g_led_config = { {
  // Key Matrix to LED Index
	// Left
  {    6,  5,  4,  3,  2,  1,  0 			},
  {    7,  8,  9, 10, 11, 12, 13 			},
  {   20, 19, 18, 17, 16, 15, 14 			},
  {   21, 22, 23, 24, 25, 26, 27 			},
  {   32, 31, 30, 29, 28, NO_LED, NO_LED 	},
  {   NO_LED, 35, 34, 33, 36, 38, 37	 	},
  
	// Right
  {   54, 53, 52, 51, 50, 49, 48 			},
  {   55, 56, 57, 58, 59, 60, 61 			},
  {   68, 67, 66, 65, 64, 63, 62 			},
  {   69, 70, 71, 72, 73, 74, 75 			},
  {   80, 79, 78, 77, 76, NO_LED, NO_LED 	},
  {   NO_LED, 83, 82, 81, 84, 86, 85		},  
  }, {
  // LED Index to Physical Position
{	64	,	2	}, {	54	,	2	}, {	45	,	1	}, {	35	,	0	}, {	26	,	1	}, {	16	,	4	}, {	7	,	4	}, 
{	4	,	13	}, {	16	,	13	}, {	26	,	11	}, {	35	,	10	}, {	45	,	11	}, {	54	,	12	}, {	64	,	12	},
{	64	,	21	}, {	54	,	21	}, {	45	,	20	}, {	35	,	19	}, {	26	,	20	}, {	16	,	23	}, {	5	,	23	},
{	5	,	32	}, {	16	,	32	}, {	26	,	30	}, {	35	,	29	}, {	45	,	30	}, {	54	,	31	}, {	64	,	31	},
{	46	,	40	}, {	35	,	38	}, {	26	,	39	}, {	16	,	42	}, {	5	,	42	},
					{	56	,	48	}, {	64	,	52	}, {	74	,	60	}, {	79	,	52	}, {	83	,	44	}, {	75	,	39	}, 
{	0	,	1	}, {	0	,	18	}, {	0	,	41	}, {	25	,	48	}, {	46	,	52	}, {	65	,	63	}, {	71	,	35	}, {	68	,	20	},{	68	,	1	},
{	160	,	2	}, {	170	,	2	}, {	179	,	1	}, {	189	,	0	}, {	198	,	1	}, {	208	,	4	}, {	217	,	4	},
{	220	,	13	}, {	208	,	13	}, {	198	,	11	}, {	189	,	10	}, {	179	,	11	}, {	170	,	12	}, {	160	,	12	},
{	160	,	21	}, {	170	,	21	}, {	179	,	20	}, {	189	,	19	}, {	198	,	20	}, {	208	,	23	}, {	219	,	23	},
{	219	,	32	}, {	208	,	32	}, {	198	,	30	}, {	189	,	29	}, {	179	,	30	}, {	170	,	31	}, {	160	,	31	},
										{	178	,	40	}, {	189	,	38	}, {	198	,	39	}, {	208	,	42	}, {	219	,	42	},
{	168	,	48	},{	160	,	52	}, {	150	,	60	}, {	146	,	52	}, {	141	,	44	}, {	149	,	39	},
{	224	,	1	}, {	224	,	18	}, {	224	,	41	}, {	200	,	48	}, {	178	,	52	}, {	159	,	63	}, {	153	,	35	}, {	156	,	20	}, {	156	,	1	}
}, {
  // LED Index to Flag
  4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4,
  1, 4, 4, 4, 4, 4, 4,
  1, 4, 4, 4, 1,
				4, 4,
				4,
				4, 4, 4,
  2, 2, 2, 2, 2, 2, 2, 2, 2,
  4, 4, 4, 4, 4, 4, 1,
  4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 1,
  4, 4,
  4,
  4, 4, 4,
  2, 2, 2, 2, 2, 2, 2, 2, 2
} };