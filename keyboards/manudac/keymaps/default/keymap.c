/* Copyright 2019 %YOUR_NAME%
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

enum custom_layers {
	_ABHW,
	_AB_ARNUM,
	_ABHW_SHIFT,
	_ABHW_PUNC,
};

#define MO_SHFT LM(_ABHW_SHIFT, MOD_LSFT)
#define MO_AN MO(_AB_ARNUM)
#define MO_PUNC MO(_ABHW_PUNC)
#define SLAN LT(_AB_ARNUM, KC_SLSH)

#undef S
#define S(kc) LSFT(KC_##kc)

#define CTAB LGUI(KC_TAB)
#define CGRV LGUI(KC_GRV)

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

									   //
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ABHW] = LAYOUT( \
KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,                       KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, \
KC_LEAD,KC_W,   KC_F,   KC_U,   KC_Y,   KC_Z,                        KC_X,   KC_H,   KC_P,   KC_B,   KC_Q,   KC_LEAD,\
KC_ESC, KC_L,   KC_O,   KC_E,   KC_A,   KC_I,                        KC_N,   KC_R,   KC_T,   KC_D,   KC_S,   KC_TAB, \
KC_ENT, KC_COMM,KC_G,   KC_M,   KC_J,   KC_SCLN,                     KC_V,   KC_K,   KC_C,   KC_DOT, SLAN,   KC_ENT, \
                KC_0,   KC_1,       KC_LCTL, MO_SHFT,            MO_PUNC,KC_SPC,     KC_NO, KC_NO, \
                                        CTAB,  MO_AN,       KC_LGUI,KC_RALT,\
                                        CGRV,  KC_BSPC,     KC_RALT,KC_LEAD \
  ),
  [_AB_ARNUM] = LAYOUT( \
RESET,  _______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______,RESET,  \
_______,KC_HOME,KC_BSPC,KC_DEL, KC_END, _______,                     KC_MINS,KC_7,   KC_8,   KC_9,   _______,_______,\
_______,KC_LEFT,KC_UP,  KC_DOWN,KC_RGHT,_______,                     KC_DOT, KC_4,   KC_5,   KC_6,   _______,_______,\
_______,_______,KC_PGUP,KC_PGDN,_______,_______,                     KC_0,   KC_1,   KC_2,   KC_3,   _______,_______,\
                _______,_______,    _______,_______,             _______,_______,_______,_______,\
                                        KC_VOLU,_______,    _______,_______,\
                                        KC_VOLD,KC_MUTE,    _______,_______ \
  ),
  [_ABHW_SHIFT] = LAYOUT( \
_______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______,_______,\
_______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______,_______,\
_______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______,_______,\
_______,KC_1,   _______,_______,_______,_______,                     _______,_______,_______,KC_SLSH,_______,_______,\
                _______,_______,    _______,_______,             _______,_______,_______,_______,\
                                        _______,_______,     _______,_______,\
                                        _______,_______,     _______,_______ \
  ),
  [_ABHW_PUNC] = LAYOUT( \
_______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______,_______,\
_______,S(QUOT),S(MINS),KC_LBRC,KC_RBRC,S(6),                        S(1),   S(COMM),S(DOT), KC_EQL, S(7),   _______,\
_______,KC_SLSH,KC_MINS,S(LBRC),S(RBRC),S(8),                        S(SLSH),S(9),   S(0),   KC_QUOT,S(SCLN),_______,\
_______,S(3),   S(4),   S(BSLS),S(GRV), KC_GRV,                      S(EQL), S(5),   KC_BSLS,S(2),   _______,_______,\
                _______,_______,    _______,_______,             _______,_______,_______,_______,\
                                        _______,_______,     _______,_______,\
                                        _______,_______,     _______,_______ \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

LEADER_EXTERNS();

void matrix_scan_user(void) {
	LEADER_DICTIONARY() {
		leading = false;
		leader_end();

		SEQ_ONE_KEY(KC_V) {
			SEND_STRING(SS_LCTRL(SS_LGUI(SS_LALT("v"))));
		}
	}
}

void led_set_user(uint8_t usb_led) {

}
