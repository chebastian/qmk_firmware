/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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
#define SWE_AA UC(0xF8)  // Å
#define SWE_AE UC(0xE4)  // Ä
#define SWE_OE UC(0xF6)  // Ö
#define TAPPING_TOGGLE 1

#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,  // default layer
    GAME, // layer with no modifiers
    SWEL, // Swedish
    SYMB,  // symbols
    NUML,  // numberl layer
    CODE, //layer of code related keys
    VIML, // vim like motion layer
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_HOME,           KC_END, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    DF(GAME),         DF(SWEL), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HYPR,           KC_MEH,  KC_H,    KC_J,    KC_K,    KC_L,    LT(CODE, KC_SCLN), LGUI_T(KC_QUOT),
        SC_LSPO, LCTL_T(KC_Z),KC_X,KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), KC_RSFT,
        LT(SYMB,KC_GRV),KC_LALT,A(KC_LSFT),S(KC_TAB), KC_TAB,  TT(VIML), RCTL_T(KC_ESC),   KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(SYMB),
                                            LT(NUML,KC_SPC),  KC_BSPC, KC_LGUI,           KC_LALT,  KC_TAB,  KC_ENT
    ),
    [SWEL] = LAYOUT_moonlander(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_HOME,           KC_END, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    DF(BASE),         KC_NO, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    UC(SWE_AA),
        KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HYPR,           KC_MEH,  KC_H,    KC_J,    KC_K,    KC_L,    UC(SWE_OE), UC(SWE_AE),
        SC_LSPO, LCTL_T(KC_Z),KC_X,KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), KC_RSFT,
        LT(SYMB,KC_GRV),KC_LALT,A(KC_LSFT),S(KC_TAB), KC_TAB,  TT(VIML), RCTL_T(KC_ESC),   KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(SYMB),
                                            LT(NUML,KC_SPC),  KC_BSPC, KC_LGUI,           KC_LALT,  KC_TAB,  KC_ENT
    ),
    [GAME] = LAYOUT_moonlander(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT,           KC_RGHT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,         DF(BASE), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HYPR,           KC_MEH,  KC_H,    KC_J,    KC_K,    KC_L,    LT(CODE, KC_SCLN), LGUI_T(KC_QUOT),
        KC_LSFT, KC_Z,KC_X,KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), KC_RSFT,
        KC_LCTL,KC_LALT,A(KC_LSFT),S(KC_TAB), KC_TAB,  TG(VIML), RCTL_T(KC_ESC),   KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(SYMB),
                                            KC_SPC,  KC_BSPC, KC_LGUI,           KC_LALT,  KC_TAB,  KC_ENT
    ),

    [SYMB] = LAYOUT_moonlander(
        VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,           _______, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
        _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  _______,           _______, KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
        _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                             KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
        EE_CLR,  _______, _______, _______, _______,          RGB_VAI,           RGB_TOG,          _______, KC_DOT,  KC_0,    KC_EQL,  _______,
                                            RGB_HUD, RGB_VAD, RGB_HUI, TOGGLE_LAYER_COLOR,_______, _______
    ),

    [CODE] = LAYOUT_moonlander(
        _______,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, _______, KC_LCBR, KC_RCBR, KC_PLUS, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_LPRN, KC_RPRN, KC_EQL, KC_GT,           _______, KC_BSPC, KC_F10, KC_F11, KC_F12, _______, _______,
        _______, _______, _______, KC_LT, KC_GT, _______,                             _______, KC_F5, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,         _______,            _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [VIML] = LAYOUT_moonlander(
        _______,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, LCTL(KC_RIGHT), _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______,
        _______, _______, _______, _______, _______, LCTL(KC_LEFT),                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,         _______,            TG(BASE),          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
    [NUML] = LAYOUT_moonlander(
        _______,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,           _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,         _______,            _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
    // [CODE] = LAYOUT_moonlander(
    //     _______,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______,         _______,            _______,          _______, _______, _______, _______, _______,
    //                                         _______, _______, _______,           _______, _______, _______
    // ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}
