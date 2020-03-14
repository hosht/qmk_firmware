#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  ADJUST = SAFE_RANGE,
  LOWER,
  RAISE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
     KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV, \
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC, \
    KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, \
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC, KC_RBRC,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, \
                      KC_LALT, KC_LGUI,   LOWER,  KC_SPC,  KC_ENT,  KC_ENT,  KC_SPC,   RAISE, KC_RGUI, KC_RALT\
  ),

  [_LOWER] = LAYOUT( \
     KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11, \
    _______, _______,   KC_UP, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
    KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                   _______, _______, _______, _______, _______, _______, \
    KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RSFT, \
                      KC_LALT, KC_LGUI, _______, _______, _______, _______, _______, _______, KC_RGUI, KC_RALT\
  ),

  [_RAISE] = LAYOUT( \
     KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11, \
    _______, _______, _______, _______, _______, _______,                   _______, KC_LBRC, KC_RBRC, KC_MINS,  KC_EQL, KC_BSLS, \
    KC_LCTL, _______, _______, _______, _______, _______,                   KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______, \
    KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RSFT, \
                      KC_LALT, KC_LGUI, _______, _______, _______, _______, _______, _______, KC_RGUI, KC_RALT\
  ),

  [_ADJUST] =  LAYOUT( \
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, KC_BRMD, KC_BRMU, _______, \
    _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,                   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______\
  )
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
