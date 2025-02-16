// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#define _BASE 0
#define _LOWER 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Esc│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│PSc│DIS│ROT│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┴───┼───┤
     * │ 0 │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ Ö │ Ü │ Ó │ Backsp│Del│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Z │ U │ I │ O │ P │ Ő │ Ú │  Ű  │ScL│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ É │ Á │  Enter │Hom│
     * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │Shif│ Í │ Y │ X │ C │ V │ B │ N │ M │ , │ . │ - │ Shift│ ↑ │End│
     * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │Ctrl│GUI │Alt │                        │Alt│GUI│Ctl│ ← │ ↓ │ → │
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
     */
    [_BASE] = LAYOUT_75_ansi(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,    KC_F11,   KC_F12,   KC_SCRL,             KC_MPLY,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,      KC_MINS,  KC_EQL,   KC_BSPC,             KC_INS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,      KC_LBRC,  KC_RBRC,  KC_BSLS,             KC_DEL,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN,   KC_QUOT,  KC_ENT,                        KC_HOME, 
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,    KC_SLSH,  KC_RSFT,              KC_UP,   KC_END, 
        KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,                          KC_RALT,   MO(1),    KC_RCTL,  KC_LEFT,   KC_DOWN, KC_RGHT
    ),

    [_LOWER] = LAYOUT_75_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_F20,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_F21,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   KC_F22,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_VOLU, KC_F23,
        _______, _______, _______,                            _______,                            _______, _______, KC_F24,  KC_MPRV, KC_VOLD, KC_MNXT
    )        
    };

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (IS_LAYER_ON(_BASE)){
        if (clockwise) {
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
        }
    }
    else if (IS_LAYER_ON(_LOWER)){ 
        if (clockwise) {
            register_code(KC_LCTL);
            tap_code(KC_TAB);
            unregister_code(KC_LCTL);
        } else {
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            tap_code(KC_TAB);
            unregister_code(KC_LCTL);
            unregister_code(KC_LSFT);
        }
    }
    return true;
}
