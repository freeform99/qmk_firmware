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

#include QMK_KEYBOARD_H

#include "version.h"

enum layers {
    BASE, // default layer
    SYMB, // symbols
    MDIA, // media keys
};

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_TRANSPARENT  , KC_1                      , KC_2                  , KC_3,    KC_4, KC_5, KC_GRAVE, KC_QUOTE, KC_6, KC_7, KC_8, KC_9, KC_0, LCTL(KC_T),
    RALT(KC_S)      , KC_B                      , KC_U                  , KC_DOT, KC_COMMA, RALT(KC_Y), LSFT(KC_6), KC_TRANSPARENT, KC_P, KC_C, KC_L, KC_M, KC_F, KC_X,
    KC_TRANSPARENT  , MT(MOD_LGUI, KC_H)        , MT(MOD_LALT, KC_I)    , MT(MOD_LCTL, KC_E), MT(MOD_LSFT, KC_A), KC_O, KC_QUES, KC_EXLM, KC_D, MT(MOD_RSFT, KC_T), MT(MOD_LCTL, KC_R), MT(MOD_LALT, KC_N), MT(MOD_LGUI, KC_S), KC_HASH,
    KC_SLASH        , KC_K                      , MT(MOD_RALT, KC_Y)    , RALT(KC_P), RALT(KC_Q), KC_Q, KC_J, KC_G, KC_W, MT(MOD_RALT, KC_V), KC_Z, KC_TRANSPARENT,
    KC_TRANSPARENT  , KC_TRANSPARENT            , KC_TRANSPARENT        , KC_TRANSPARENT, LT(3, KC_ESCAPE), CAPS_WORD, KC_QUOTE, LT(6, KC_DELETE), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    LT(1, KC_BSPC)  , LT(2, KC_TAB)             , KC_MEH, KC_TRANSPARENT, LT(5, KC_ENTER), LT(4, KC_SPACE)
  ),
  [1] = LAYOUT_moonlander(
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_TRANSPARENT, RESET,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          LSFT(KC_INSERT),LCTL(KC_INSERT),LSFT(KC_DELETE),KC_UNDO,     KC_TRANSPARENT,
      KC_TRANSPARENT, KC_LGUI,        OSM(MOD_LALT),  OSM(MOD_LCTL),  OSM(MOD_LSFT),  KC_NO,          KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_CAPS_LOCK,    KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT,
      KC_TRANSPARENT, KC_NO,          KC_RALT,        KC_NO,          KC_NO,          KC_NO,                                          KC_INSERT,      KC_HOME,        KC_PAGE_DOWN,      KC_PAGE_UP,        KC_END,         KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_DELETE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT,                 KC_TRANSPARENT, KC_ENTER,       KC_BACKSPACE
    ),
    [2] = LAYOUT_moonlander(
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_TRANSPARENT, RESET,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          LSFT(KC_INSERT),LCTL(KC_INSERT),LSFT(KC_DELETE),KC_UNDO,     KC_TRANSPARENT,
      KC_TRANSPARENT, KC_LGUI,        KC_LALT,        KC_LEFT_CTRL,   KC_LSFT,      KC_NO,          KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_NO,          KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_TRANSPARENT,
      KC_TRANSPARENT, KC_NO,          KC_RALT,        KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_MS_BTN3,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_MS_BTN2,     KC_MS_BTN1
    ),
    [3] = LAYOUT_moonlander(
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_TRANSPARENT, RESET,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, RGB_TOG,        RGB_MOD,        RGB_HUI,        RGB_SAI,        RGB_VAI,        KC_TRANSPARENT,
      KC_TRANSPARENT, KC_LGUI,        KC_LALT,        KC_LEFT_CTRL,   KC_LSFT,      KC_NO,          KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_NO,          KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT,
      KC_TRANSPARENT, KC_NO,          KC_RALT,        KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_NO,          KC_NO,          KC_TRANSPARENT,                 KC_TRANSPARENT, KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE
    ),
    [4] = LAYOUT_moonlander(
      KC_TRANSPARENT, LCTL(KC_1),     LCTL(KC_2),     LCTL(KC_3),     LCTL(KC_4),     KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_TRANSPARENT, KC_LEFT_BRACKET,    KC_7,           KC_8,           KC_9,           KC_RIGHT_BRACKET,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          RESET,          KC_TRANSPARENT,
      KC_TRANSPARENT, KC_SEMICOLON,      KC_4,           KC_5,           KC_6,           KC_EQUAL,       KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_NO,          KC_LSFT,      KC_LEFT_CTRL,       KC_LALT,        KC_LGUI,        KC_TRANSPARENT,
      KC_TRANSPARENT, KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_BACKSLASH,                                      KC_NO,          KC_NO,          KC_NO,          KC_RALT,        KC_NO,          KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_DOT,         KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_0,           KC_MINUS,       KC_TRANSPARENT,                 KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT
    ),
    [5] = LAYOUT_moonlander(
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_TRANSPARENT, KC_LCBR,        KC_AMPR,        KC_ASTR,        KC_RPRN,        KC_RCBR,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          RESET,          KC_TRANSPARENT,
      KC_TRANSPARENT, KC_COLN,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_PLUS,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_NO,          KC_LSFT,      KC_LEFT_CTRL,       KC_LALT,        KC_LGUI,        KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_PIPE,                                        KC_NO,          KC_NO,          KC_NO,          KC_RALT,        KC_NO,          KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_QUES,        KC_LPRN,        KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_RPRN,        KC_MINUS,    KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_NO
    ),
    [6] = LAYOUT_moonlander(
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_TRANSPARENT, KC_F12,         KC_F7,          KC_F8,          KC_F9,          KC_PRINT_SCREEN,     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          RESET,          KC_TRANSPARENT,
      KC_TRANSPARENT, KC_F11,         KC_F4,          KC_F5,          KC_F6,          KC_SCROLL_LOCK,  KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_NO,          KC_LSFT,      KC_LEFT_CTRL,       KC_LALT,        KC_LGUI,        KC_TRANSPARENT,
      KC_TRANSPARENT, KC_F10,         KC_F1,          KC_F2,          KC_F3,          KC_PAUSE,                                       KC_NO,          KC_NO,          KC_NO,          KC_RALT,        KC_NO,          KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_APPLICATION, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_SPACE,       KC_TAB,         KC_TRANSPARENT,                 KC_TRANSPARENT, KC_NO,          KC_NO
    ),
  //     [BASE] = LAYOUT_moonlander(
  //         KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT,           KC_RGHT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  //         KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    TG(SYMB),         TG(SYMB), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //         KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HYPR,           KC_MEH,  KC_H,    KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), LGUI_T(KC_QUOT),
  //         KC_LSFT, LCTL_T(KC_Z),KC_X,KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), KC_RSFT,
  //     LT(SYMB,KC_GRV),WEBUSB_PAIR,A(KC_LSFT),KC_LEFT, KC_RGHT,  LALT_T(KC_APP),    RCTL_T(KC_ESC),   KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(SYMB),
  //                                             KC_SPC,  KC_BSPC, KC_LGUI,           KC_LALT,  KC_TAB,  KC_ENT
  //     ),

//   [SYMB] = LAYOUT_moonlander(
//     VRSN, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______, _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
//     _______, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, _______, _______, KC_UP, KC_7, KC_8, KC_9, KC_ASTR, KC_F12,
//     _______, KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_GRV, _______, _______, KC_DOWN, KC_4, KC_5, KC_6, KC_PLUS, _______,
//     _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_AMPR, KC_1, KC_2, KC_3, KC_BSLS, _______,
//     EE_CLR, _______, _______, _______, _______, RGB_VAI, RGB_TOG, _______, KC_DOT, KC_0, KC_EQL, _______,
//     RGB_HUD, RGB_VAD, RGB_HUI, TOGGLE_LAYER_COLOR, _______, _______
//   ),
//
//   [MDIA] = LAYOUT_moonlander(
//     LED_LEVEL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,
//     _______, _______, _______, KC_MS_U, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY,
//     _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT, _______, _______,
//     _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
//     _______, _______, _______, _______, _______, _______
//   ),
};

bool process_record_user(uint16_t keycode, keyrecord_t * record) {
  if (record -> event.pressed) {
    switch (keycode) {
    case VRSN:
      SEND_STRING(QMK_KEYBOARD "/"
        QMK_KEYMAP " @ "
        QMK_VERSION);
      return false;
    }
  }
  return true;
}
