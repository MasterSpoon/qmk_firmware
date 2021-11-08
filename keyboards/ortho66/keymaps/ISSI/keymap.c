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
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap

enum layer_names {
	    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _FKEYS,
	_NUMBERS,
    _LEDS,
};

// Tap Dance declarations
enum {
	TD_NUMSCR,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
	// Tap once for Num Lock, twice for Scroll Lock 
	[TD_NUMSCR] = ACTION_TAP_DANCE_DOUBLE(KC_NLCK, KC_SLCK),
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY */
    [_QWERTY] = LAYOUT(
		KC_ESC, 	KC_1, 	KC_2, 	KC_3, 	KC_4, 	KC_5, 	KC_6, 	KC_7, 	KC_8,	KC_9, 	KC_0, 	KC_MINS, 	KC_EQL, 	TG(_NUMBERS), 
		KC_TAB, 	KC_Q, 	KC_W, 	KC_E, 	KC_R, 	KC_T, 	KC_LBRC, KC_RBRC, KC_Y, KC_U, 	KC_I, 	KC_O, 		KC_P, 		KC_BSLS, 
		MO(_NUMBERS), KC_A, KC_S, 	KC_D, 	KC_F, 	KC_G, KC_PGUP, KC_SCLN, KC_H, 	KC_J, 	KC_K, 	KC_L, 		KC_QUOT, 	KC_ENT, 
		KC_LSFT, 	KC_Z, 	KC_X, 	KC_C, 	KC_V, 	KC_B, 	KC_PGDN, KC_DEL, KC_N, 	KC_M, 	KC_COMM, KC_DOT, 	KC_SLSH, 	MO(_FKEYS), 
		KC_LCTL, KC_LGUI, KC_LALT, 		KC_ENT, 		KC_BSPC, 		KC_SPC, 			KC_DOWN,	KC_LEFT,	KC_UP,	KC_RGHT 
    ),
	[_FKEYS] = LAYOUT(
		KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, TD(TD_NUMSCR), 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(_LEDS), 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_END, KC_INS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS								
    ),
	[_NUMBERS] = LAYOUT(
		KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_PAST, KC_LSPO, KC_RSPC, KC_MINS, KC_EQL, KC_TRNS,  
		KC_TRNS, KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P7, KC_P8, KC_P9, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_1, KC_2, KC_3, KC_COMM, KC_TRNS, KC_TRNS, KC_TRNS, KC_P1, KC_P2, KC_P3, KC_PSLS, KC_TRNS, 
		KC_TRNS, KC_P0, KC_PDOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_PDOT, KC_COMM, KC_TRNS		
    ),
	[_LEDS] = LAYOUT(
		RGB_TOG, RGB_RMOD, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, KC_F9, KC_F10, RGB_SPD, RGB_SPI, KC_TRNS, 
		KC_TRNS, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PAUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS	
    )
};

/* RGB Matrix */
#ifdef RGB_MATRIX_ENABLE

/* LED Matrix Layout
*	.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.
*	|	0	|	1	|	2	|	3	|	4	|	5	|	6	|	7	|	8	|	9	|	10	|	11	|	12	|	13	|
*	|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
*	|	14	|	15	|	16	|	17	|	18	|	19	|	20	|	21	|	22	|	23	|	24	|	25	|	26	|	27	|
* .---------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+---------.
* |		28	|	29	|	30	|	31	|	32	|	33	|	34	|	35	|	36	|	37	|	38	|	39	|	40	|	41	  |
* |---------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+---------|
* |		42	|	43	|	44	|	45	|	46	|	47	|	48	|	49	|	50	|	51	|	52	|	53	|	54	|	55	  |
* `---------`-------`-------`-------+-------`-------+-------`-------+-------`-------+-------+-------+-------+---------`
*		|	56	|	 57	  |   58	|		59		|		60		|		61		|	62	|	63	|	64	|	65	|
*		`-------`---------`---------`---------------`---------------`---------------`-------`-------`-------`-------`
*/

// Setup for changing bulk keys
// Indices do NOT have to be listed in ascending order for this to work.
int CAPS_A[] = {15, 16, 17, 18, 19, 22, 23, 24, 25, 26, 29, 30, 31, 32, 33, 36, 37, 38, 39, 43, 44, 45, 46, 47, 50, 51};
int FKEYS_A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 34, 48, 49};
int NUM_A[] = {16, 17, 18, 23, 24, 25, 30, 31, 32, 37, 38, 39, 44, 45, 46, 51, 52, 53, 57, 58, 62, 63};
int NUM_B[] = {8, 9, 10, 11, 12, 40, 47, 54, 64};
int LEDS_A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 34, 48};

// Loop for setting groups of LED's each cycle
// Input is rgb_matrix_set_group(array of LED numbers, how many LED's in array, red, green, blue);
// working out arrange size can be done manually by counting or by pasing "(&array_name)[1] - array_name"
// QMK has some predefined colours which can be entered instead of the red, green, blue values
// Example
// int these_leds[] = {0, 1, 2, 3, 4, 5};
// rgb_matrix_set_group(these_leds, (&these_leds)[1] - these_leds, 255, 0, 0);
// or rgb_matrix_set_group(these_leds, (&these_leds)[1] - these_leds, RGB_RED);
// or rgb_matrix_set_group(these_leds, 6, RGB_RED);
// https://arjunsreedharan.org/post/69303442896/how-to-find-the-size-of-an-array-in-c-without

void rgb_matrix_set_group(int *index, int array_size, uint8_t red, uint8_t green, uint8_t blue) {
  for (uint8_t i = 0; i < array_size; i++){ 
  rgb_matrix_set_color(index[i], red, green, blue);
  }
}

// RGB Colour shift setup
void rgb_matrix_indicators_kb(void) {
	
	// letter keys change on CAPS Lock
    if (host_keyboard_led_state().caps_lock) {
	rgb_matrix_set_group(CAPS_A, (&CAPS_A)[1] - CAPS_A, 255, 255, 255);
	}
	
	// Layer Changes
    switch(get_highest_layer(layer_state|default_layer_state)) {
            case _FKEYS:
				rgb_matrix_set_group(FKEYS_A, (&FKEYS_A)[1] - FKEYS_A, 128, 255, 0);
                break;
            case _NUMBERS:
				rgb_matrix_set_group(NUM_A, (&NUM_A)[1] - NUM_A, 0, 128, 128);
				rgb_matrix_set_group(NUM_B, (&NUM_B)[1] - NUM_B, 255, 0, 255);
                break;
            case _LEDS:
				rgb_matrix_set_group(LEDS_A, (&LEDS_A)[1] - LEDS_A, 0, 255, 255);
                break;				
            default:
                break;
			}
}
#endif


uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
mod_state = get_mods(); 
	switch (keycode) {
        
	/* Shift + Backspace for Delete */
    case KC_BSPC:
        {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        static bool delkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                // Update the boolean variable to reflect the status of KC_DEL
                delkey_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
    }

	/* layer shift to numbers layer otherwise KC_CLCK if left Alt held */
    case MO(_NUMBERS):
        // Detect the activation of only Left Alt
        if ((get_mods() & MOD_BIT(KC_LALT)) == MOD_BIT(KC_LALT)) {
            if (record->event.pressed) {
                // No need to deregister KC_LALT because doesn't change Caps behaviour.
                // The Alt modifier will apply on this KC_CAPS.
                register_code(KC_CAPS);
            } else {
                unregister_code(KC_CAPS);
            }
            // Do not let QMK process the keycode further
            return false;
        }
        // Else, let QMK process the MO(_NUMBERS) keycode as usual
        return true;
		
	/* layer shift to numbers layer otherwise KC_CALC if left shift held */
    case TG(_NUMBERS):
        // Detect the activation of only Left Shift
        if ((get_mods() & MOD_BIT(KC_LSFT)) == MOD_BIT(KC_LSFT)) {
            if (record->event.pressed) {
                // No need to deregister KC_LSFT because doesn't change KC_CALC behaviour.
                // The Shift modifier will apply on this KC_CALC.
                register_code(KC_CALC);
            } else {
                unregister_code(KC_CALC);
            }
            // Do not let QMK process the keycode further
            return false;
        }
        // Else, let QMK process the MO(_NUMBERS) keycode as usual
        return true;

#ifdef ISSI_DEBUG
    case KC_SPC:
		if (record->event.pressed) {
		IS31FL_open_check(DRIVER_ADDR_1, 0);
        }
		return false;

	case KC_ENT:
		if (record->event.pressed) {
		IS31FL_short_check(DRIVER_ADDR_1, 0);
		}
        return false;
#endif
    }
    return true;
}
