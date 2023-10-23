/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2022 Laurent Granié

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define _COLEMAKDHM 0
#define _SYMBOLS 2
#define _NAVIGATION 4
#define _ADDONS 8

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAKDHM] = LAYOUT_split_3x6_3(
  //,-------------------------------------------------------------------------------.                    ,---------------------------------------------------------------------.
            KC_ESC,         KC_Q,         KC_W,         KC_F,         KC_P,    KC_B,                      KC_J,         KC_L,         KC_U,         KC_Y,      KC_SCLN, KC_BSPC,
  //|--------------+-------------+-------------+-------------+-------------+--------|                    |----+-------------+-------------+-------------+-------------+--------|
             KC_TAB, LGUI_T(KC_A), LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T),    KC_G,                     KC_M, RCTL_T(KC_N), RSFT_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O),  KC_ENT,
  //|--------------+-------------+-------------+-------------+-------------+--------|                    |----+-------------+-------------+-------------+-------------+--------|
           XXXXXXX,         KC_Z,         KC_X,         KC_C,         KC_D,    KC_V,                      KC_K,         KC_H,      KC_COMM,       KC_DOT,      KC_SLSH, XXXXXXX,
  //|--------------+-------------+-------------+-------------+-------------+--------+--------|  |--------+----+-------------+-------------+-------------+-------------+--------|
                                                     _______,  _______,  LT(_SYMBOLS, KC_SPC),    LT(_NAVIGATION, KC_SPC), _______, _______
                                                  //`-------+---------+----------------------'   `-----------------------+--------+--------'
  ),

  [_SYMBOLS] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------.                     ,-----------------------------------------------------------------------------.
     KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,            KC_7,            KC_8,            KC_9,    KC_0, _______,
  //|------+--------+--------+--------+--------+--------|                    |--------+----------------+----------------+----------------+--------+--------|
    XXXXXXX, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,                      KC_LBRC, RCTL_T(KC_RBRC), RSFT_T(KC_BSLS), RGUI_T(KC_QUOT), KC_RGUI, XXXXXXX,
  //|------+--------+--------+--------+--------+--------|                    |--------+----------------+----------------+----------------+--------+--------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,          KC_EQL,         _______,         _______, _______, XXXXXXX,
  //|------+--------+--------+--------+--------+--------+-------|  |-----------+------+----------------+----------------+----------------+--------+--------|
                                       _______, _______, _______,   MO(_ADDONS), _______, _______
                                    //`-------+--------+--------'  `-----------+--------+--------'
  ),

  [_NAVIGATION] = LAYOUT_split_3x6_3(
  //,----------------------------------------------------------------------------------.                    ,-----------------------------------------------------------------------------------.
     XXXXXXX,          KC_F1,          KC_F2,           KC_F3,           KC_F4,   KC_F5,                        KC_F6,           KC_F7,         KC_F8,           KC_F9,          KC_F10,  KC_DEL,
  //|-------+---------------+---------------+----------------+----------------+--------|                    |--------+----------------+--------------+----------------+----------------+--------|
     XXXXXXX, LGUI_T(KC_F11), LALT_T(KC_F12), LSFT_T(KC_BTN1), LCTL_T(KC_BTN2), KC_BTN3,                      KC_LEFT, RCTL_T(KC_DOWN), RSFT_T(KC_UP), RALT_T(KC_RGHT), RGUI_T(KC_WH_U), XXXXXXX,
  //|-------+---------------+---------------+----------------+----------------+--------|                    |--------+----------------+--------------+----------------+----------------+--------|
     XXXXXXX,        XXXXXXX,        XXXXXXX,         XXXXXXX,         XXXXXXX, XXXXXXX,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_WH_D, XXXXXXX,
  //|-------+---------------+---------------+----------------+----------------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                   _______, _______, MO(_ADDONS),   _______,  _______,  _______
                                                                 //`------+--------+------------'   `------+---------+---------'
  ),

  [_ADDONS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------.                    ,-----------------------------------------------------.
            QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, XXXXXXX,
  //|--------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______, _______, _______,   _______,  _______,  _______
                                              //`------+--------+--------'   `------+---------+---------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (biton32(layer_state)) {
        case _COLEMAKDHM:
          oled_write_ln_P(PSTR("Colemakdh"), false);
          break;
        case _SYMBOLS:
          oled_write_ln_P(PSTR("Symbols"), false);
          break;
        case _NAVIGATION:
          oled_write_ln_P(PSTR("Navigation"), false);
          break;
        case _ADDONS:
          oled_write_ln_P(PSTR("Addons"), false);
          break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
