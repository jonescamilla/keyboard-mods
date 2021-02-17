#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"

// _MO_1
  // LAUNCH
  #define KC_TERMINAL_LAUNCH LSFT(LCTL(LALT(LGUI(KC_T))))
  #define KC_BROWSER_LAUNCH LSFT(LCTL(LALT(LGUI(KC_S))))
  // AMETHYST
  #define KC_AMETHYST_RELAUNCH LSFT(LCTL(LALT(LGUI(KC_B))))
  #define KC_AMETHYST_FOCUS_TO_MAIN LSFT(LALT(KC_ENT))

// COMMAND MACROS
  #define KC_GUI_BSPC LGUI(KC_BSPC)
  #define KC_GUI_H LGUI(KC_H)
  #define KC_GUI_SLSH LGUI(KC_SLSH)
  #define KC_GUI_DOT LGUI(KC_DOT)
  #define KC_CTRL_TAB LCTL(KC_TAB)

// cases/keycodes for process_record_user
enum custom_keycodes {
  LINKEDIN = AP2_SAFE_RANGE,
  GITHUB,
  CONSOLE_LOG,
	NVIM_TERM,
	NVIM_FUZZY_FINDER,
	NVIM_FERN
};

// function that handles sending strings based on case pressed by keeb
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	// personal links
  case LINKEDIN:
    if (record->event.pressed) {
      SEND_STRING("https://www.linkedin.com/in/jon-escamilla/");
    } else {}
    break;
  case GITHUB: 
    if (record->event.pressed) {
      SEND_STRING("https://github.com/jonescamilla");
    } else {}
    break;
	// dev assistancefern
  case CONSOLE_LOG: 
    if (record->event.pressed) {
      SEND_STRING("console.log(");
    } else {}
    break;
	// nvim settings
	case NVIM_TERM:
		if (record->event.pressed) {
			SEND_STRING("\\t");
		} else {}
		break;
	case NVIM_FUZZY_FINDER:
		if (record->event.pressed) {
			SEND_STRING("\\p");
		} else {}
		break;
	case NVIM_FERN:
		if (record->event.pressed) {
			SEND_STRING("\\f");
		} else {}
		break;
  }
  return true;
};

// keyboard layers defined
enum anne_pro_layers {
  _BASE_LAYER,
  _MO_1,
  _MO_2,
};

// keymaps
const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {	// prettier-ignore

 /* Layer _BASE_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * | esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bksp    |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  |  w  |  f  |  p  |  b  |  j  |  l  |  u  |  y  |  ;  |  [  |  ]  |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | FN1     |  a  |  r  |  s  |  t  |  g  |  k  |  n  |  e  |  i  |  o  |  '  |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  x  |  c  |  d  |  v  |  z  |  m  |  h  |  ,  |  .  |  /  |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  Alt   |  Cmd  |               space            |  FN2  | Left  | Down  | Right |
  * \-----------------------------------------------------------------------------------------/
  */

  [_BASE_LAYER] = KEYMAP( /* Base */
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
    MO(_MO_1), KC_A, KC_R, KC_S, KC_T, KC_G, KC_K, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_ENT,
    KC_LSFT, KC_X, KC_C, KC_D, KC_V, KC_Z, KC_M, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, MO(_MO_2), KC_LEFT, KC_DOWN, KC_RGHT
  ),

 /* Layer _MO_1
  * ,-----------------------------------------------------------------------------------------.
  * |  ~  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |   Bksp    |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |     |     |     |     |     |     | Up  |     |     |     |     |        |
  * |-----------------------------------------------------------------------------------------+
  * | Trns    |Shift|Ctrl |     |     |     |     |Left |Down |Right|Play |  ~  |   Enter     |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |     |     |     |     |     |     |     |     |     |     |       Up       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  Alt  |  Cmd  |               Alt               |  FN2  | Left  | Down  | Right |
  * \-----------------------------------------------------------------------------------------/
  */

  [_MO_1] = KEYMAP(
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, 
    KC_CTRL_TAB, CONSOLE_LOG, NVIM_FERN, KC_TRNS, NVIM_FUZZY_FINDER, KC_AMETHYST_RELAUNCH, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_LSFT, KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPLY, KC_GRV, KC_AMETHYST_FOCUS_TO_MAIN,
    KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_GUI_DOT, KC_GUI_SLSH, KC_UP,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_LALT, MO(_MO_2), KC_LEFT, KC_DOWN, KC_RGHT
  ),

 /* Layer _MO_2
  * ,-----------------------------------------------------------------------------------------.
  * |     |     |     |     |     |     |     |     |     |     |     |Vol- |Vol+ |           |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
  * |-----------------------------------------------------------------------------------------+
  * | Trns    |Shift|     |     |     |     |     |     |     |Prev |Play |Next |             |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |     |     |     |     |     |     |     |     |     |     |       Up       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  Alt  |  Cmd  |               space             | Trns  | Left  | Down  | Right |
  * \-----------------------------------------------------------------------------------------/
  */

  [_MO_2] = KEYMAP( /* Base */
    KC_NO, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, KC_AP2_BT_UNPAIR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLD, KC_VOLU, KC_GUI_BSPC,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LINKEDIN, GITHUB, KC_GUI_H,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MRWD, KC_MPLY, KC_MFFD, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_GUI_DOT, KC_GUI_SLSH, KC_UP,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT
  ), // prettier-ignore-end
};

const uint16_t keymaps_size = sizeof(keymaps);

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

layer_state_t layer_state_set_user(layer_state_t layer) {
  return layer;
}
