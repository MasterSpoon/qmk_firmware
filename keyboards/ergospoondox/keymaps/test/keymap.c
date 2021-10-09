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
		KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, 							KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, TG(_NUMBERS), 
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, 							KC_RBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, 
		MO(_NUMBERS), KC_A, KC_S, KC_D, KC_F, KC_G, KC_P4, 					KC_SCLN, KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_ENT, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_PDOT, 						KC_UP, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, MO(_FKEYS), 
		KC_LCTL, KC_LGUI, KC_P2, KC_SPC, KC_LALT, 											TT(_LEDS), KC_DOWN, KC_LEFT, KC_RGHT, KC_RCTL, 
										KC_PSCR, KC_HOME,						KC_INS, KC_PAUS,
												KC_END,							KC_PGUP,
									KC_ENT, KC_BSPC, KC_DEL,					KC_PGDN, KC_BSPC, KC_SPC
    ),
	[_FKEYS] = LAYOUT(
		KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, 							KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, TD(TD_NUMSCR), 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 											KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
													KC_TRNS, KC_TRNS,			KC_TRNS, KC_TRNS,
															KC_TRNS,			KC_TRNS,
											KC_TRNS, KC_TRNS, KC_TRNS,			KC_TRNS, KC_TRNS, KC_TRNS
    ),
	[_NUMBERS] = LAYOUT(
		KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, 							KC_7, KC_PAST, KC_LSPO, KC_RSPC, KC_MINS, KC_EQL, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS, 					KC_TRNS, KC_TRNS, KC_P7, KC_P8, KC_P9, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS, 					KC_TRNS, KC_TRNS, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_1, KC_2, KC_3, KC_COMM, KC_TRNS, 					KC_TRNS, KC_TRNS, KC_P1, KC_P2, KC_P3, KC_PSLS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_0, KC_0, KC_DOT, 													KC_P0, KC_P0, KC_PDOT, KC_COMM, KC_TRNS, 
													KC_TRNS, KC_TRNS,			KC_TRNS, KC_TRNS,
															KC_TRNS,			KC_TRNS,
											KC_TRNS, KC_TRNS, KC_TRNS,			KC_TRNS, KC_TRNS, KC_TRNS
    ),
	[_LEDS] = LAYOUT(
		RGB_TOG, RGB_RMOD, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, 		RGB_VAD, RGB_VAI, KC_F9, KC_F10, RGB_SPD, RGB_SPI, KC_TRNS, 
		KC_TRNS, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, KC_TRNS, KC_TRNS, 			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 											KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
													KC_TRNS, KC_TRNS,			KC_TRNS, KC_TRNS,
															KC_TRNS,			KC_TRNS,
											KC_TRNS, KC_TRNS, KC_TRNS,			KC_TRNS, KC_TRNS, KC_TRNS
    )
};

// Define that left is always master
#define LEFT_IS_ALWAYS_MASTER
#ifdef LEFT_IS_ALWAYS_MASTER
#include "usb_util.h"
__attribute__((weak)) bool is_keyboard_master(void) {
    static enum { UNKNOWN, MASTER, SLAVE } usbstate = UNKNOWN;

    // only check once, as this is called often
    if (usbstate == UNKNOWN) {
        usbstate = is_keyboard_left() ? MASTER : SLAVE;

        // Avoid NO_USB_STARTUP_CHECK - Disable USB as the previous checks seem to enable it somehow
        if (usbstate == SLAVE) {
            usb_disable();
        }
    }

    return (usbstate == MASTER);
}
#endif

/* RGB Matrix */
#ifdef RGB_MATRIX_ENABLE

/* LED Matrix Layout
*	.-------.-------.-------.-------.-------.-------.-------.47			95	.-------.-------.-------.-------.-------.-------.-------.87
*39	|	6	|	5	|	4	|	3	|	2	|	1	|	0	|				|	48	|	49	|	50	|	51	|	52	|	53	|	54	|
*	|-------+-------+-------+-------+-------+-------+-------|				|-------+-------+-------+-------+-------+-------+-------|
*	|	7	|	8	|	9	|	10	|	11	|	12	|	13	|				|	61	|	60	|	59	|	58	|	57	|	56	|	55	|
*	|-------+-------+-------+-------+-------+-------+-------|46			94	|-------+-------+-------+-------+-------+-------+-------|
*40	|	20	|	19	|	18	|	17	|	16	|	15	|	14	|				|	62	|	63	|	64	|	65	|	66	|	67	|	68	|88
*	|-------+-------+-------+-------+-------+-------+-------|				|-------+-------+-------+-------+-------+-------+-------|
*	|	21	|	22	|	23	|	24	|	25	|	26	|	27	|45			93	|	75	|	74	|	73	|	72	|	71	|	70	|	69	|
*	|-------+-------+-------+-------+-------+-------`-------`				`-------`-------+-------+-------+-------+-------+-------|
*41	|	32	|	31	|	30	|	29	|	28	|												|	76	|	77	|	78	|	79	|	80	|89
*	`-------`-------`-------`-------`-------`												`-------`-------`-------`-------`-------`
*						42				43	.-------.-------.				.-------.-------.	91				90
*									 		|	38	|	37	|				|	85	|	86	|
*									.-------+-------+-------|				|-------+-------|-------.
*									|		|		|	36	|				|	84	|		|		|
*									|	33	|	34	|-------|				|-------|	82	|	81	|
*									|		|		|	35	|				|	83	|		|		|
*									`-------`-------`-------`				`-------`-------`-------`
*													44								92
*/

// Setup for changing bulk keys
// Indices do NOT have to be listed in ascending order for this to work.
int CAPS_A[] = {8, 9, 10, 11, 12, 15, 16, 17, 18, 19, 22, 23, 24, 25, 26, 56, 57, 58, 59, 60, 63, 64, 65, 66, 73, 74};
int FKEYS_A[] = {0, 1, 2, 3, 4, 5, 6, 48, 49, 50, 51, 52, 53, 54};
int NUM_A[] = {9, 10, 11, 16, 17, 18, 23, 24, 25, 28, 29, 30, 57, 58, 59, 64, 65, 66, 71, 72, 73, 76, 77, 78};
int NUM_B[] = {26, 49, 50, 51, 52, 53, 67, 70, 79};
int LEDS_A[] = {0, 1, 2, 3, 4, 5, 6, 48, 49, 50, 51, 52, 53, 54};

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
	rgb_matrix_set_group(CAPS_A, 26, 70, 125, 123);
	}
	
	// Layer Changes
    switch(get_highest_layer(layer_state|default_layer_state)) {
            case _FKEYS:
				rgb_matrix_set_group(FKEYS_A, 14, 128, 255, 0);
                break;
            case _NUMBERS:
				rgb_matrix_set_group(NUM_A, 24, 0, 128, 128);
				rgb_matrix_set_group(NUM_B, 9, 255, 0, 255);
                break;
            case _LEDS:
				rgb_matrix_set_group(LEDS_A, 14, 0, 255, 255);
                break;				
            default:
                break;
			}
}
#endif

/* Oled screens */
#ifdef OLED_DRIVER_ENABLE
/* 	Note for rendering images on Oled screens. 
*	Screens are setup in horizontal rows, 8 pixels high, they render left to right.
*	Unless told otherwise they will keep going to the right until running out of space on that row and will then wrap down to the next row.
*	If you run over the end of the bottom row it will loop back to the start of the top row.
*	Using oled_set_cursor(X,Y) we can set position of where to start rendering.
*	X is the position from the left spaced in character spacing (default is 6px wide per character), starting at 0 for the start of the row.
*	Y is the position from the top row, starting at 0 for the top row.
*	128x32 size Oleds have 4 rows, 128px wide and 8px high, identified from row 0 being the top row and row 3 at the bottom.
*	They are 21.3 characters wide, with 0 being the left most and 20 being the start of the last character.
*	If you try render a 32px x 32px picture it will draw the first 32px wide, then the next 32px wide section next to it, not under it.
*	To correct for this the image needs to be broken up into segments, each segment being what is to be rendered on that line.
*	Breaking the image into segments is easy as each vertical row of 8px in the column is a byte. Represented in the image file as a hexidecimal value.
*	This translates to a binary digit rendered vertically in our Oled column http://cactus.io/resources/toolbox/decimal-binary-octal-hexadecimal-conversion
*	Data for each row of our Oled is then X amount of hexidecimal value's where X is how many pixels wide the image is we are trying to render.
*	Putting these chunks sequentially inside a const char allows us to pull them out easily. 
*	Setup is <char_name>[<total number of chunks>][<how many pixels wide each chunk is>]
*	If rendering single image only then total number of chunks is simply how many lines, if animation is lines x images
*	Note, while logo_example[4][32] is 4 lines of image each 32px wide, when we call them back the counter starts at 0 and goes to 3, not 1 to 4
*	Once we have our image broken up we need to render it line by line, for our 32x32px example we want to
*	Set cursor to the desired X position on Y = 0 row, render the [0] chunk
*	Set cursor to the desired X position on Y = 1 row, render the [1] chunk
*	Set cursor to the desired X position on Y = 2 row, render the [2] chunk
*	Set cursor to the desired X position on Y = 3 row, render the [3] chunk
*	To avoid doing this manually, especially if rendering multiple images we can setup a loop we can feed the images into.
*
*	// Loop to create line by line rendering for Horizontal display
*	// Input is oled_render_image(how many rows tall, how many pixels wide, what to render, X pos, Y pos, Frame offset)
*	void oled_render_image(int lines, int px, const char render_line[][px], int X_pos, int Y_pos, int frame) {
*	for (uint8_t i = 0; i < lines; i++){ 
*            oled_set_cursor(X_pos, Y_pos + i);
*			oled_write_raw_P(render_line[i + frame], px);
*		}
*	}
*
*	oled_render_image(4, 32, my_logo, 15, 0, 0, 0, 0);
* 	This would draw the my_logo image, 32x32px in size, on the far right of the screen.
*	Note : 128x32 screens only have 4 rows high, if you were try render at 15,1 as the first row of the image
*	would be on the second row of the screen and the last row would wrap around and be on the first row.
*   Note : The Frame offset is used to select different images in the array. Eg. Sit1 is 0,1,2 in the array and Sit2 is 3,4,5.
*	If we want to render Sit2 we offset the counter by 3 to get 3,4,5.
*/

/* Oled screen orientation correction */
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_left()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if left hand
    }
    return rotation;
}

/* KEYBOARD PET START */

/* settings */
#define MIN_WALK_SPEED 10
#define MIN_RUN_SPEED 50

/* advanced settings */
#define LUNA_FRAME_DURATION 230 // how long each frame lasts in ms
#define LUNA_SIZE 32 // number of bytes in array. This is how many pixels wide your image is. max is 1024 but would apply if line wrapping and not segmeting image and on 128x64 size screen, 512 is max on 128x32.

/* Setup Variables */
uint8_t current_frame = 0;
bool isSneaking = false;
bool isJumping = false;
bool showedJump = true;
int jump_height = 0;

// Loop to create line by line rendering for Horizontal display
// Input is oled_render_image(how many rows tall, how many pixels wide, what to render, X pos, Y pos, Frame offset)
	void oled_render_image(int lines, int px, const char render_line[][px], int X_pos, int Y_pos, int frame) {
	for (uint8_t i = 0; i < lines; i++){ 
            oled_set_cursor(X_pos, Y_pos + i);
			oled_write_raw_P(render_line[i + frame], px);
		}
	}

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y, int LOGO_X, int LOGO_Y) {

	/* setup some variables & timers */
	static uint8_t prev_wpm = 0;
	static uint32_t tap_timer = 0; // WPM and mod triggered
	if (get_current_wpm() > prev_wpm || get_mods()) { tap_timer = timer_read32(); }
	prev_wpm = get_current_wpm();

	// Elapsed time between key presses
	uint32_t keystroke = timer_elapsed32(tap_timer);
	static uint16_t anim_timer = 0;
    
// 'QMK logo', 32x32px
    static const char PROGMEM qmk_logo[4][32] = {
		{0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0xc0, 0xe0, 0xf0, 0xfe, 0xf0, 0x70, 0xf0, 0xfe, 0xf0, 0xf0, 
		0xf0, 0x7e, 0xf0, 0xf0, 0xf0, 0xfe, 0xf0, 0x70, 0xf0, 0xfe, 0xf0, 0xe0, 0xc0, 0x80, 0x80, 0x80}, 
		{0x00, 0x00, 0x00, 0x88, 0x88, 0x88, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 
		0x00, 0x00, 0x00, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x88, 0x88, 0x88}, 
		{0x00, 0x00, 0x00, 0x88, 0x88, 0x88, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xf0, 0xf1, 
		0x80, 0x00, 0x80, 0xf1, 0xf0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x88, 0x88, 0x88}, 
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x3f, 0x07, 0x07, 0x07, 0x3f, 0x07, 0x07, 
		0x07, 0x3f, 0x07, 0x07, 0x07, 0x3f, 0x07, 0x07, 0x07, 0x3f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00}
    };
	
    /* Sit - 32x24px */
    static const char PROGMEM sit[6][LUNA_SIZE] = {
        /* 'sit1' */
        {   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c,
		0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28,
		0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},		
        /* 'sit2' */
        {   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c,
		0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{   0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28,
        0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
    };

    /* Walk - 32x24px */
    static const char PROGMEM walk[6][LUNA_SIZE] = {
        /* 'walk1' */
        {   0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80,
		0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00},
        {   0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
		0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00},
        {   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03,
		0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},		
		/* 'walk2' */
        {   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
		0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
		0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e,
		0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
    };

    /* Run - 32x24px */
    static const char PROGMEM run[6][LUNA_SIZE] = {
        /* 'run1' */
        {    0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
		0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01,
		0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00},		
         /* 'run2' */
        {    0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
		0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37,
		0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
    };

    /* Bark - 32x24px */
    static const char PROGMEM bark[6][LUNA_SIZE] = {
        /* 'bark1' */
        {    0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40,
		0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00},
        {    0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02,
		0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},		
        /* 'bark2' */
        {    0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40,
		0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00},		
        {    0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10},		
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02,
		0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
    };

    /* Sneak - 32x24px */
    static const char PROGMEM sneak[6][LUNA_SIZE] = {
        /* 'sneak1' */
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04,
		0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06,
		0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00},		
        /* 'sneak2' */
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00},		
        {    0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04,
		0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00},		
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04,
		0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00}
    };

    /* animation */
    void animate_luna(void) {

	// Render QMK Logo, has been placed inside Luna code due to OLED Flicker
	oled_render_image(4, 32, qmk_logo, LOGO_X, LOGO_Y, 0);

		/* jump */
        if (isJumping || !showedJump) {

            // Is jumping, clear the bottom line and tell animation to render 1 line up
            oled_set_cursor(LUNA_X,LUNA_Y +3);
            oled_write("     ", false);
			jump_height = 1;
            showedJump = true;
        } else {

            // Not jumping, clears the top row and tells animation to render bottom 3 rows
            oled_set_cursor(LUNA_X,LUNA_Y);
            oled_write("     ", false);
			jump_height = 0;
        }

        /* switch frame */
        // current_frame = (current_frame + <number of lines per image>) % <lines x how many frames>;
		current_frame = (current_frame + 3) % 6;

        /* current status */
        if(host_keyboard_led_state().caps_lock) {
            oled_render_image(3, LUNA_SIZE, bark, LUNA_X, LUNA_Y + 1, current_frame);
			
        } else if(isSneaking) {
			oled_render_image(3, LUNA_SIZE, sneak, LUNA_X, LUNA_Y + 1 - jump_height, current_frame);
         			
        } else if(prev_wpm <= MIN_WALK_SPEED) {
			oled_render_image(3, LUNA_SIZE, sit, LUNA_X, LUNA_Y + 1, current_frame);
			
        } else if(prev_wpm <= MIN_RUN_SPEED) {
			oled_render_image(3, LUNA_SIZE, walk, LUNA_X, LUNA_Y + 1 - jump_height, current_frame);
						
        } else {
			oled_render_image(3, LUNA_SIZE, run, LUNA_X, LUNA_Y + 1 - jump_height, current_frame);
					
        }
    }

	if (keystroke > OLED_TIMEOUT) { oled_off(); }
	else if (timer_elapsed(anim_timer) > (LUNA_FRAME_DURATION - (prev_wpm/2))) {
		anim_timer = timer_read();
		animate_luna();
	}
}

/* KEYBOARD PET END */

void oled_task_user(void) {
	    if (is_keyboard_master()) {
/* What to do on the primary OLED */

    /* KEYBOARD PET START */
    render_luna(0,0,15,0); // (luna X pos, luna Y pos, QMK X pos, QMK Y pos) note that is 4 lines tall Y settings must be 0 on 128x32 display
    /* KEYBOARD PET END */

	// Host Keyboard Layer Status
	oled_set_cursor(7,1); // sets position where "Layer" will be displayed
    oled_write_P(PSTR("Layer:"), false);
	oled_set_cursor(7,2); // sets position where layer name will be displayed	

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default "), false);
            break;
        case _FKEYS:
            oled_write_P(PSTR("F Keys  "), false);
            break;
        case _NUMBERS:
            oled_write_P(PSTR("Number's"), false);
            break;
        case _LEDS:
            oled_write_P(PSTR("LED's   "), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefind"), false);
    }
}
	else {
/* What to do on the secondary OLED */

	/* wpm counter */
    oled_set_cursor(0,0); // sets position where "wpm" will be displayed
    oled_write("Words per minute", false);

    uint8_t n = get_current_wpm();
    char wpm_str[4];
    oled_set_cursor(17,0); // sets position where WPM counter will be displayed
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + n % 10;
    wpm_str[1] = '0' + ( n /= 10) % 10;
    wpm_str[0] = '0' + n / 10;
    oled_write(wpm_str, false);

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
	    /* caps lock */
	oled_set_cursor(0,2); // sets position where CAPS will be displayed
    oled_write(" CAPS ", led_state.caps_lock);
	oled_set_cursor(0,3); // sets position where LOCK will be displayed
    oled_write(" LOCK ", led_state.caps_lock);
		/* num lock */
	oled_set_cursor(7,2); // sets position where NUM will be displayed
    oled_write(" NUM  ", led_state.num_lock);
	oled_set_cursor(7,3); // sets position where LOCK will be displayed
    oled_write(" LOCK ", led_state.num_lock);
	    /* scroll lock */
	oled_set_cursor(14,2); // sets position where SCR will be displayed
    oled_write(" SCR  ", led_state.scroll_lock);
	oled_set_cursor(14,3); // sets position where LOCK will be displayed
    oled_write(" LOCK ", led_state.scroll_lock);
    }
}
#endif

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
mod_state = get_mods();    
	switch (keycode) {
        /* KEYBOARD PET STATUS START */

        case KC_LCTL:
        case KC_RCTL:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;

        /* KEYBOARD PET STATUS END */
 
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