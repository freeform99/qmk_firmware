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
#include "features/select_word.h"
#include "features/sentence_case.h"

// https://combos.gboards.ca/docs/install/
#include "g/keymap_combo.h"
#include "version.h"

// enum layers {
//     BASE, // default layer
//     SYMB, // symbols
//     MDIA, // media keys
// };
//
enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
    SELWORD,
};

uint8_t mod_state;
uint8_t oneshot_mod_state;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_TRANSPARENT  , KC_1                      , KC_2                  , KC_3,    KC_4, KC_5, KC_GRAVE, KC_QUOTE, KC_6, KC_7, KC_8, KC_9, KC_0, LCTL(KC_T),
    RALT(KC_S)      , KC_B                      , KC_U                  , KC_DOT, KC_COMMA, RALT(KC_Y), LSFT(KC_6), KC_TRANSPARENT, KC_P, KC_C, KC_L, KC_M, KC_F, KC_X,
    KC_TRANSPARENT  , MT(MOD_LGUI, KC_H)        , MT(MOD_LALT, KC_I)    , MT(MOD_LCTL, KC_E), MT(MOD_LSFT, KC_A), KC_O, KC_QUES, KC_EXLM, KC_D, MT(MOD_RSFT, KC_T), MT(MOD_LCTL, KC_R), MT(MOD_LALT, KC_N), MT(MOD_LGUI, KC_S), KC_HASH,
    KC_SLASH        , KC_K                      , MT(MOD_RALT, KC_Y)    , RALT(KC_P), RALT(KC_Q), KC_Q, KC_J, KC_G, KC_W, MT(MOD_RALT, KC_V), KC_Z, KC_TRANSPARENT,
    KC_TRANSPARENT  , KC_TRANSPARENT            , KC_TRANSPARENT        , KC_TRANSPARENT, LT(3, KC_ESCAPE), CAPS_WORD, KC_QUOTE, LT(6, KC_DELETE), KC_TRANSPARENT, SELWORD, KC_TRANSPARENT, KC_TRANSPARENT,
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
      KC_TRANSPARENT, RESET,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_NO, RGB_TOG,        RGB_MOD,        RGB_HUI,        RGB_SAI,        RGB_VAI,        KC_TRANSPARENT,
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
};


bool process_record_user(uint16_t keycode, keyrecord_t * record) {
//  https://getreuer.info/posts/keyboards/select-word/index.html
  if (!process_select_word(keycode, record, SELWORD)) { return false; }
// https://getreuer.info/posts/keyboards/sentence-case/index.html#add-it-to-your-keymap
  if (!process_sentence_case(keycode, record)) { return false; }

// original content of this function
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

const key_override_t dot_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_QUES);  // Shift . is ?
const key_override_t comm_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_EXLM); // Shift , is !

const key_override_t** key_overrides = (const key_override_t*[]){
    &dot_key_override,
    &comm_key_override,
    NULL
};

// enum combo_events {
//   BSPC_LSFT_CLEAR,
//   COMBO_LENGTHS,
// };
// uint16_t COMBO_LEN = COMBO_LENGTHS; // remove the COMBO_COUNT define and use this instead!
//
//
// const uint16_t PROGMEM clear_line_combo[] = {LT(1, KC_BSPC), MT(MOD_LSFT, KC_A), COMBO_END};
//
//
// combo_t key_combos[] = {
//   [BSPC_LSFT_CLEAR] = COMBO_ACTION(clear_line_combo),
// };
//
// void process_combo_event(uint16_t combo_index, bool pressed) {
//   switch(combo_index) {
//     case BSPC_LSFT_CLEAR:
//       if (pressed) {
//         tap_code16(KC_END);
//         tap_code16(S(KC_HOME));
//         tap_code16(KC_BSPC);
//       }
//       break;
//   }
// }


// enum combo_events {
//     /* Backspace steno-lite combos */
//     // These let me type common words and n-grams
//     // more quickly, in one single stroke.
//     BSPCEV_EVERY,
//     BSPCU_YOU,
//     BSPCA_AND,
//     BSPCW_WITH,
//     BSPCF_FOR,
//     BSPCH_HERE,
//     BSPCT_THE,
//     BSPCM_MENT,
//     BSPCG_ING,
//     BSPCO_OUGH,
//     BSPCOL_OULD,
//     BSPCI_ION,
//     BSPCIS_IONS,
//     BSPCTA_THAT,
//     BSPCQ_QUE,
//     // I use the word "key" much more frequently than the common folk
//     // and if you're reading this, you probably do too
//     BSPCK_KEY,
//     BSPCTS_THIS,
//     BSPCDN_DONT,
//     BSPCIT_IN_THE,
//
//     /* Other steno-lite combos */
//     // Additional steno-lite combos for common words and n-grams
//     // that do not involve the backspace thumb key because these
//     // combinations of keys do not generate too many conflicts
//     // in normal typing.
//     HV_HAVE,
//     QK_QMK,
//     KB_KEYBOARD,
//     WA_WHAT,
//
//     /* Non-alphanumeric combos */
//     // Combos for which the output isn't one or more alphanumeric characters
//     UYCLN_INDEX,
// //     OS_SFT_CAPS,
//     REPEATX_BSLS,
//     BSPCE_ESC,
//     DOTSLASH_UPDIR,
//     ZEROEIGHT_COMMA,
//     EIGHTNINE_DOT,
// //     PT_MOUSE,
//
//     // This must be the last item in the enum.
//     // This is used to automatically update the combo count.
//     COMBO_LENGTH
// };
// uint16_t COMBO_LEN = COMBO_LENGTH;
//
// const uint16_t PROGMEM BSPC_E_V_COMBO[]   = {KC_BSPC,  KC_E,  KC_V,    COMBO_END};
// const uint16_t PROGMEM BSPC_U_COMBO[]     = {KC_BSPC,  KC_U,    COMBO_END};
// const uint16_t PROGMEM BSPC_A_COMBO[]     = {KC_BSPC,  KC_A,  COMBO_END};
// const uint16_t PROGMEM BSPC_N_COMBO[]     = {KC_BSPC,  KC_H,  COMBO_END};
// const uint16_t PROGMEM BSPC_W_COMBO[]     = {KC_BSPC,  KC_W,    COMBO_END};
// const uint16_t PROGMEM BSPC_F_COMBO[]     = {KC_BSPC,  KC_F,    COMBO_END};
// const uint16_t PROGMEM BSPC_H_COMBO[]     = {KC_BSPC,  KC_H,    COMBO_END};
// const uint16_t PROGMEM BSPC_T_COMBO[]     = {KC_BSPC,  KC_T,  COMBO_END};
// const uint16_t PROGMEM BSPC_M_COMBO[]     = {KC_BSPC,  KC_M,    COMBO_END};
// const uint16_t PROGMEM BSPC_G_COMBO[]     = {KC_BSPC,  KC_G,    COMBO_END};
// const uint16_t PROGMEM BSPC_O_COMBO[]     = {KC_BSPC,  KC_O,  COMBO_END};
// const uint16_t PROGMEM BSPC_O_L_COMBO[]   = {KC_BSPC,  KC_O,  KC_L,    COMBO_END};
// const uint16_t PROGMEM BSPC_I_COMBO[]     = {KC_BSPC,  KC_I,  COMBO_END};
// const uint16_t PROGMEM BSPC_I_S_COMBO[]   = {KC_BSPC,  KC_I,  KC_S,  COMBO_END};
// const uint16_t PROGMEM BSPC_Q_COMBO[]     = {KC_BSPC,  KC_Q,    COMBO_END};
// const uint16_t PROGMEM BSPC_K_COMBO[]     = {KC_BSPC,  KC_K,    COMBO_END};
// const uint16_t PROGMEM BSPC_T_S_COMBO[]   = {KC_BSPC,  KC_T,  KC_S,  COMBO_END};
// const uint16_t PROGMEM K_B_COMBO[]        = {KC_K,     KC_B,    COMBO_END};
// const uint16_t PROGMEM BSPC_T_A_COMBO[]   = {KC_BSPC,  KC_T,  KC_A,  COMBO_END};
// const uint16_t PROGMEM BSPC_D_N_COMBO[]   = {KC_BSPC,  KC_D,    KC_H,  COMBO_END};
// const uint16_t PROGMEM BSPC_I_T_COMBO[]   = {KC_BSPC,  KC_I,  KC_T,  COMBO_END};
// const uint16_t PROGMEM H_V_COMBO[]        = {KC_H,     KC_V,    COMBO_END};
// const uint16_t PROGMEM Q_K_COMBO[]        = {KC_Q,     KC_K,    COMBO_END};
// const uint16_t PROGMEM W_A_COMBO[]        = {KC_W,     KC_A,  COMBO_END};
// const uint16_t PROGMEM U_Y_SCLN_COMBO[]   = {KC_U,     KC_Y,    KC_SCLN, COMBO_END};
// const uint16_t PROGMEM OS_SFT_COMBO[]     = {KC_LSFT,  KC_RSFT, COMBO_END};
// // const uint16_t PROGMEM REPEAT_X_COMBO[]   = {REPEAT,   KC_X,    COMBO_END};
// const uint16_t PROGMEM BSPC_E_COMBO[]     = {KC_BSPC,  KC_E,  COMBO_END};
// // const uint16_t PROGMEM DOT_SLASH_COMBO[]  = {TD_DOT,   KC_SLSH, COMBO_END};
// const uint16_t PROGMEM ZERO_EIGHT_COMBO[] = {KC_0,     KC_8,    COMBO_END};
// const uint16_t PROGMEM EIGHT_NINE_COMBO[] = {KC_8,     KC_9,    COMBO_END};
// const uint16_t PROGMEM P_T_COMBO[]        = {KC_P,     KC_T,  COMBO_END};
//
// combo_t key_combos[] = {
//     [BSPCEV_EVERY]    = COMBO_ACTION(BSPC_E_V_COMBO),
//     [BSPCU_YOU]       = COMBO_ACTION(BSPC_U_COMBO),
//     [BSPCA_AND]       = COMBO_ACTION(BSPC_A_COMBO),
//     [BSPCW_WITH]      = COMBO_ACTION(BSPC_W_COMBO),
//     [BSPCF_FOR]       = COMBO_ACTION(BSPC_F_COMBO),
//     [BSPCH_HERE]      = COMBO_ACTION(BSPC_H_COMBO),
//     [BSPCT_THE]       = COMBO_ACTION(BSPC_T_COMBO),
//     [BSPCM_MENT]      = COMBO_ACTION(BSPC_M_COMBO),
//     [BSPCG_ING]       = COMBO_ACTION(BSPC_G_COMBO),
//     [BSPCO_OUGH]      = COMBO_ACTION(BSPC_O_COMBO),
//     [BSPCOL_OULD]     = COMBO_ACTION(BSPC_O_L_COMBO),
//     [BSPCI_ION]       = COMBO_ACTION(BSPC_I_COMBO),
//     [BSPCIS_IONS]     = COMBO_ACTION(BSPC_I_S_COMBO),
//     [BSPCTA_THAT]     = COMBO_ACTION(BSPC_T_A_COMBO),
//     [BSPCQ_QUE]       = COMBO_ACTION(BSPC_Q_COMBO),
//     [BSPCK_KEY]       = COMBO_ACTION(BSPC_K_COMBO),
//     [BSPCTS_THIS]     = COMBO_ACTION(BSPC_T_S_COMBO),
//     [BSPCDN_DONT]     = COMBO_ACTION(BSPC_D_N_COMBO),
//     [BSPCIT_IN_THE]   = COMBO_ACTION(BSPC_I_T_COMBO),
//     [HV_HAVE]         = COMBO_ACTION(H_V_COMBO),
//     [QK_QMK]          = COMBO_ACTION(Q_K_COMBO),
//     [KB_KEYBOARD]     = COMBO_ACTION(K_B_COMBO),
//     [WA_WHAT]         = COMBO_ACTION(W_A_COMBO),
// //     [OS_SFT_CAPS]     = COMBO(OS_SFT_COMBO, CAPS_WORD_LOCK),
// //     [REPEATX_BSLS]    = COMBO(REPEAT_X_COMBO, KC_BACKSLASH),
//     [BSPCE_ESC]       = COMBO(BSPC_E_COMBO, KC_ESC),
// //     [DOTSLASH_UPDIR]  = COMBO_ACTION(DOT_SLASH_COMBO),
//     [ZEROEIGHT_COMMA] = COMBO(ZERO_EIGHT_COMBO, KC_COMMA),
//     [EIGHTNINE_DOT]   = COMBO(EIGHT_NINE_COMBO, KC_DOT),
//     [UYCLN_INDEX]     = COMBO_ACTION(U_Y_SCLN_COMBO),
// //     [PT_MOUSE]        = COMBO(P_T_COMBO, MOUSE),
// };
//
// void process_combo_event(uint16_t combo_index, bool pressed) {
//     // Process mod-taps before the combo is fired,
//     // this helps making modifier-aware combos,
//     // like UYCLN_INDEX more fluid
//     // when I use them with home row mods.
//     action_tapping_process((keyrecord_t){});
//     mod_state = get_mods();
//     oneshot_mod_state = get_oneshot_mods();
// #ifdef CONSOLE_ENABLE
//     combo_t *combo = &key_combos[combo_index];
//     uint8_t idx = 0;
//     uint16_t combo_keycode;
//     while ((combo_keycode = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
//         uprintf("0x%04X\t%u\t%u\t0x%X\t%u\t0x%02X\t0x%02X\t0\n",
//             combo_keycode,
//             KEYLOC_COMBO,
//             KEYLOC_COMBO,
//             layer_state|default_layer_state,
//             pressed,
//             get_mods(),
//             get_oneshot_mods()
//             /* tap_count==0 */
//         );
//         idx++;
//     }
// #endif
//     switch(combo_index) {
//
//         case UYCLN_INDEX:
//             if (pressed) {
//                 if (mod_state & MOD_MASK_SHIFT) {
//                     del_mods(MOD_MASK_SHIFT);
//                     SEND_STRING("[1]");
//                     set_mods(mod_state);
//                 }
//                 else if (mod_state & MOD_MASK_CTRL) {
//                     del_mods(MOD_MASK_CTRL);
//                     SEND_STRING("[0]");
//                     set_mods(mod_state);
//                 }
//                 else {
//                     SEND_STRING("[i]");
//                 }
//         }
//         break;
//
//         case HV_HAVE:
//             if (pressed) {
//                 SEND_STRING("have");
//             }
//         break;
//
//         case QK_QMK:
//             if (pressed) {
//                 if (mod_state & MOD_MASK_SHIFT || oneshot_mod_state & MOD_MASK_SHIFT) {
//                     del_mods(MOD_MASK_SHIFT);
//                     del_oneshot_mods(MOD_MASK_SHIFT);
//                     SEND_STRING("QMK");
//                     set_mods(mod_state);
//                 }
//                 else {
//                     SEND_STRING("qmk");
//                 }
//         }
//         break;
//
//         case BSPCEV_EVERY:
//             if (pressed) {
//                 SEND_STRING("every");
//             }
//         break;
//
//         case BSPCU_YOU:
//             if (pressed) {
//                 SEND_STRING("you");
//             }
//         break;
//
//         case BSPCA_AND:
//             if (pressed) {
//                 SEND_STRING("and");
//             }
//         break;
//
//         case BSPCW_WITH:
//             if (pressed) {
//                 SEND_STRING("with");
//             }
//         break;
//
//         case BSPCF_FOR:
//             if (pressed) {
//                 SEND_STRING("for");
//             }
//         break;
//
//         case BSPCH_HERE:
//             if (pressed) {
//                 SEND_STRING("here");
//             }
//         break;
//
//         case BSPCT_THE:
//             if (pressed) {
//                 SEND_STRING("the");
//             }
//         break;
//
//         case BSPCM_MENT:
//             if (pressed) {
//                 SEND_STRING("ment");
//             }
//         break;
//
//         case BSPCG_ING:
//             if (pressed) {
//                 SEND_STRING("ing");
//             }
//         break;
//
//         case BSPCO_OUGH:
//             if (pressed) {
//                 SEND_STRING("ough");
//             }
//         break;
//
//         case BSPCOL_OULD:
//             if (pressed) {
//                 SEND_STRING("ould");
//             }
//             break;
//
//         case BSPCI_ION:
//             if (pressed) {
//                 SEND_STRING("ion");
//             }
//         break;
//
//         case BSPCIS_IONS:
//             if (pressed) {
//                 SEND_STRING("ions");
//             }
//         break;
//
//         case BSPCTA_THAT:
//             if (pressed) {
//                 SEND_STRING("that");
//             }
//         break;
//
//         case BSPCQ_QUE:
//             if (pressed) {
//                 SEND_STRING("que");
//             }
//         break;
//
//         case BSPCK_KEY:
//             if (pressed) {
//                 SEND_STRING("key");
//             }
//         break;
//
//         case KB_KEYBOARD:
//             if (pressed) {
//                 SEND_STRING("keyboard");
//             }
//         break;
//
//         case WA_WHAT:
//             if (pressed) {
//                 SEND_STRING("what");
//             }
//         break;
//
//         case BSPCTS_THIS:
//             if (pressed) {
//                 SEND_STRING("this");
//             }
//         break;
//
//         case BSPCDN_DONT:
//             if (pressed) {
//                 SEND_STRING("don't");
//             }
//         break;
//
//         case BSPCIT_IN_THE:
//             if (pressed) {
//                 SEND_STRING("in the");
//             }
//         break;
//
//         case DOTSLASH_UPDIR:
//             if (pressed) {
//                 SEND_STRING("../");
//             }
//         break;
//     }
// };

