// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum Layers {
    BASE = 0, FUNC, MOUS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Esc│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│PSc│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┴───┬───┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│Hom│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │     │PgU│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐ Ent├───┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ # │    │PgD│
     * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┼───┤
     * │Shft│ \ │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│ ↑ │End│
     * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │Ctrl│GUI │Alt │                        │Alt│GUI│Ctl│ ← │ ↓ │ → │
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
     */
    [BASE] = LAYOUT_75_iso(
        KC_ESC,            KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,
        KC_GRV,            KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_PGUP,
        KC_TAB,            KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_PGDN,
        LT(MOUS, KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,  KC_DEL,
        KC_LSFT,           KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_HOME,
        KC_LCTL,           KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, MO(FUNC),KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [FUNC] = LAYOUT_75_iso(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_VOLD,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_END,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
    ),
    [MOUS] = LAYOUT_75_iso( /* B-) */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,    _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,    _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_BTN1, KC_MS_UP,   KC_MS_BTN2,
        _______, _______, _______,                            _______,                   _______, _______, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT
    ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [FUNC] = { ENCODER_CCW_CW(LCTL(KC_MS_WH_DOWN), LCTL(KC_MS_WH_UP)) },
    [MOUS] = { ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP) },
};
#endif

#ifdef OLED_ENABLE
/**
 * @brief Test code for OLED debugging
 */
bool oled_task_user(void) {
    /*
    oled_clear();

    led_t led_state = host_keyboard_led_state();
    //oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    //oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    */

    static int s = 0;
    s = 1 - s;

    for(int x = 0; x < 64; x++) {
        for(int y = 0; y < 32; y++) {
            oled_write_pixel(x, y, (x + y + s) & 0x1);
        }
    }

    return false;
}
#endif
