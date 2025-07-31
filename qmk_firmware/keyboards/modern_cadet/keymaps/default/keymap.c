// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define SAK LALT(KC_PSCR)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌─────┐  ┌─────┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
     * │ SAK │  │ Esc │ │F1 │F2 │F3 │F4 │ │F5 │F6 │F7 │F8 │ │F9 │F10│F11│F12│ │Pau│SLk│NLk│ ┌───┬───┬───┬───┐
     * └─────┘  └─────┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘ │ D │ E │ F │ / │
     * ┌─────┐  ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┬───┬───┐ ├───┼───┼───┼───┤
     * │Break│  │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │   │   │ │Ins│Hom│PgU│ │ A │ B │ C │ : │
     * ├─────┤  ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
     * │Focus│  │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │ │Del│End│PgD│ │ 7 │ 8 │ 9 │ - │
     * ├─────┤  ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
     * │ Cap │  │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │ │Prv│All│Nxt│ │ 4 │ 5 │ 6 │ + │
     * ├─────┤  ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
     * │Menu │  │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │      │   │ │   │ ↑ │   │ │ 1 │ 2 │ 3 │   │
     * ├─────┤  ├────┬───┼───┼───┼───┴───┴───┴───┴───┴───┴┬──┴┬──┴┬────┬┴───┤ ├───┼───┼───┤ ├───┼───┼───┤Ent│
     * │ Cmd │  │Ctrl│Alt│Sup│Hyp│                        │AGr│L2 │Cmps│Ctrl│ │ ← │ ↓ │ → │ │ 0 │00 │ . │   │
     * └─────┘  └────┴───┴───┴───┴────────────────────────┴───┴───┴────┴────┘ └───┴───┴───┘ └───┴───┴───┴───┘
     */
    [0] = LAYOUT_all(
     SAK,       KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,        KC_F5,   KC_F6,   KC_F7,   KC_F8,        KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_PAUS, KC_SCRL, KC_NUM,
                                                                                                                                                                                      KC_F16,  KC_F17,  KC_F18,  KC_PSLS,
     KC_STOP,   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_INT1,   KC_INS,  KC_HOME, KC_PGUP,   KC_F13,  KC_F14,  KC_F15,  KC_PAST,
     KC_HELP,   KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,       KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN,   KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
     KC_COPY,   KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,                KC_ENT,   KC_PRIR, KC_SLCT, KC_AGIN,   KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
     KC_APP,    KC_LSFT,      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,              KC_LSFT, KC_NUBS,   KC_F19,  KC_UP,   KC_F20,    KC_P1,   KC_P2,   KC_P3,   KC_PENT,
     KC_LCMD,   KC_LCTL, KC_LALT, KC_RSFT, KC_RCMD,                   KC_SPC,                                      KC_RALT, KC_LNG8, KC_LNG9, KC_RCTL,   KC_LEFT, KC_DOWN, KC_RGHT,   KC_P0,   KC_F13,  KC_PDOT
    ),
};

