// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _SYM,
    _NAV
};

#define SYM_SPC LT(_SYM, KC_SPC)
#define NAV_ESC LT(_NAV, KC_ESC)
#define ___ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
         KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,  KC_BSPC,
         NAV_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
         KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
         KC_LCTL, KC_LGUI, KC_LALT,          SYM_SPC,                   KC_SPC,           KC_RALT, KC_RGUI, KC_RCTL
    ),

    [_SYM] = LAYOUT(
         KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    ___,     QK_BOOT,
           ___,   ___,     ___,     ___,     KC_MINS, KC_EQL,  ___,     ___,     ___,     ___,     ___,     KC_BSLS,
           ___,   ___,     ___,     ___,     KC_LBRC, KC_RBRC, ___,     ___,     ___,     ___,     KC_PGUP, ___,
           ___,   ___,     ___,              ___,                       ___,              KC_HOME, KC_PGDN, KC_END
    ),

    [_NAV] = LAYOUT(
           ___,   ___,     ___,     ___,     ___,     ___,     ___,     ___,     ___,     ___,     ___,     ___,     ___,
           ___,   ___,     ___,     ___,     ___,     ___,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, ___,     ___,
           ___,   ___,     ___,     ___,     ___,     ___,     ___,     ___,     ___,     ___,     ___,     ___,
           ___,   ___,     ___,              ___,                       ___,              ___,     ___,     ___
    )
};


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}
