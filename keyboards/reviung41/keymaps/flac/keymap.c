/* Copyright 2020 gtips
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

int dvorak_active;

enum layer_names {
    _QWERTY,
    _DVORAK,
    _LOWER1,
    _LOWER2,
    _RAISE1,
    _RAISE2,
    _ADJUST,
    _GAMING
};

#define QWERTY DF(_QWERTY)
#define DVORAK DF(_DVORAK)
#define GAMING TG(_GAMING)

#define CTAB LCTL_T(KC_TAB)

#define dCOPY  C(KC_C)
#define dPASTE C(KC_V)
#define dUNDO  C(KC_Z)

#define qCOPY  C(KC_I)
#define qPASTE C(KC_DOT)
#define qUNDO  C(KC_SLASH)

// #define mCOPY  smartCopy
// #define mPASTE smartPaste
// #define mUNDO  smartUndo

#define RAISE1 MO(_RAISE1)
#define RAISE2 MO(_RAISE2)

#define LOWER1 MO(_LOWER1)
#define LOWER2 MO(_LOWER2)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_reviung41(
    KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
      CTAB,   KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  RSFT_T(KC_ENT),
                                            KC_LALT,   LOWER1,    KC_SPC,   RAISE1,    KC_RGUI
  ),
  
  [_DVORAK] = LAYOUT_reviung41(
    KC_ESC,   KC_QUOT,  KC_COMM,  KC_DOT,     KC_P,      KC_Y,               KC_F,     KC_G,     KC_C,     KC_R,     KC_L,     KC_BSPC,
       CTAB,     KC_A,     KC_O,    KC_E,     KC_U,      KC_I,               KC_D,     KC_H,     KC_T,     KC_N,     KC_S,     KC_MINS,
    KC_LSFT,  KC_SCLN,     KC_Q,    KC_J,     KC_K,      KC_X,               KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,     RSFT_T(KC_ENT),
                                            KC_LALT,   LOWER2,    KC_SPC,   RAISE2,    KC_RGUI
  ),
  
  [_LOWER1] = LAYOUT_reviung41(
    KC_ESC,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,    KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,
    _______,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,   KC_PIPE,            KC_GRV,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_TILD,
    _______,    qUNDO,    qCOPY,   qPASTE,  KC_CAPS,   KC_DQUO,            KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN,  KC_PSCR,  RSFT_T(KC_SPC),
                                            _______,   _______,  KC_ENT,   _______,  _______
  ),
  
  [_LOWER2] = LAYOUT_reviung41(
    KC_ESC,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,    KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,
    _______,  KC_LCBR,  KC_RCBR,  KC_UNDS,  KC_PLUS,   KC_PIPE,            KC_GRV,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_TILD,
    _______,    dUNDO,    dCOPY,   dPASTE,  KC_CAPS,   KC_DQUO,            KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN,  KC_PSCR,  RSFT_T(KC_SPC),
                                            _______,   _______,  KC_ENT,   _______,  _______
  ),
   
  [_RAISE1] = LAYOUT_reviung41(
    KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,      KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
    KC_VOLU,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,   KC_BSLS,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,
    KC_VOLD,  KC_ESC,   KC_RGUI,  KC_RALT,  KC_CAPS,   KC_QUOT,            KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
                                            _______,   _______,  KC_BSPC,  _______,  _______
  ),
   
  [_RAISE2] = LAYOUT_reviung41(
    KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,      KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
    KC_VOLU,  KC_LBRC,  KC_RBRC,   KC_MINS,  KC_EQL,   KC_BSLS,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,
    KC_VOLD,  KC_ESC,   KC_RGUI,  KC_RALT,  KC_CAPS,   KC_QUOT,            KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
                                            _______,   _______,  KC_BSPC,  _______,  _______
  ),
  
  [_ADJUST] = LAYOUT_reviung41(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            RESET,    XXXXXXX,  XXXXXXX,  QWERTY,   DVORAK,  GAMING,
                                            _______,   _______,  XXXXXXX,  _______,  _______
  ),  
  
  [_GAMING] = LAYOUT_reviung41(
    KC_ESC,  KC_1,     KC_2,     KC_3,     KC_4,      KC_5,            KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
    KC_TAB,  KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    KC_LSFT, KC_A,     KC_S,     KC_D,     KC_F,      KC_G,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  GAMING,
                                            KC_LALT,  KC_SPC, KC_LCTL,  _______,  _______
),  
};



layer_state_t layer_state_set_user(layer_state_t state) {
  switch (biton32(default_layer_state)){
    case _DVORAK:
      return update_tri_layer_state(state, _LOWER2, _RAISE2, _ADJUST);
    case _QWERTY:
      return  update_tri_layer_state(state, _LOWER1, _RAISE1, _ADJUST);
    default:
      return  update_tri_layer_state(state, _LOWER1, _RAISE1, _ADJUST);
  }
}

