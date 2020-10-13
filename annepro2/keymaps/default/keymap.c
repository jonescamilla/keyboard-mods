#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"

enum anne_pro_layers {
  _BASE_LAYER,
  _FN1_LAYER,
  _FN2_LAYER,
};

 /* Layer _BASE_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * | esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
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

 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE_LAYER] = KEYMAP( /* Base */
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
    MO(_FN1_LAYER), KC_A, KC_R, KC_S, KC_T, KC_G, KC_K, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_ENT,
    KC_LSFT, KC_X, KC_C, KC_D, KC_V, KC_Z, KC_M, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, MO(_FN2_LAYER), KC_LEFT, KC_DOWN, KC_RGHT
),

 /* Layer _FN1_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  ~  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |     |     |     |     |     |     | Up  |     |     |     |     |        |
  * |-----------------------------------------------------------------------------------------+
  * | Trns    |Shift|     |     |     |     |     |Left |Down |Right|Play |  ~  |   Enter     |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |     |     |     |     |     |     |     |     |     |     |       Up       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  Alt  |  Cmd  |               Alt               |  FN2  | Left  | Down  | Right |
  * \-----------------------------------------------------------------------------------------/
  */

 [_FN1_LAYER] = KEYMAP( /* Base */
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPLY, KC_GRV, KC_TRNS,
    KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UP,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_LALT, MO(_FN2_LAYER), KC_LEFT, KC_DOWN, KC_RGHT
),

 /* Layer _FN2_LAYER
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

 [_FN2_LAYER] = KEYMAP( /* Base */
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLD, KC_VOLU, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MRWD, KC_MPLY, KC_MFFD, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UP,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT
 ),
};

const uint16_t keymaps_size = sizeof(keymaps);

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

layer_state_t layer_state_set_user(layer_state_t layer) {
  return layer;
}
