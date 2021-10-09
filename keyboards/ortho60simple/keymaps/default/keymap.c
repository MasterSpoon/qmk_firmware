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
		KC_LSFT, 	KC_Z, 	KC_X, 	KC_C, 	KC_V, 	KC_B, 	KC_PDOT, KC_DEL, KC_N, 	KC_M, 	KC_COMM, KC_DOT, 	KC_SLSH, 	MO(_FKEYS), 
		KC_LCTL, KC_LGUI, KC_LALT, 		KC_ENT, 		KC_BSPC, 		KC_SPC, 			KC_UP, 	KC_DOWN, 	KC_LEFT, 	KC_RGHT 
    ),
	[_FKEYS] = LAYOUT(
		KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, TD(TD_NUMSCR), 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(_LEDS), 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS								
    ),
	[_NUMBERS] = LAYOUT(
		KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_PAST, KC_LSPO, KC_RSPC, KC_MINS, KC_EQL, KC_TRNS,  
		KC_TRNS, KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P7, KC_P8, KC_P9, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_1, KC_2, KC_3, KC_COMM, KC_TRNS, KC_TRNS, KC_TRNS, KC_P1, KC_P2, KC_P3, KC_PSLS, KC_TRNS, 
		KC_TRNS, KC_P0, KC_PDOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_PDOT, KC_COMM, KC_TRNS		
    ),
};

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

    }
    return true;
}
