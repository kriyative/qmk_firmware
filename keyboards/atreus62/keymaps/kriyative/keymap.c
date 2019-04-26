#include QMK_KEYBOARD_H

#define _______ KC_TRNS
#define FN MO(_FN)
#define TODO KC_NO

enum atreus62_layers {
  _DEFAULT,
  _FN,
  _RESET
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Default layer
   * ,-----------------------------------------.                ,-----------------------------------------.
   * |  `   |   1  |   2  |   3  |   4  |   5  |                |   6  |   7  |   8  |   9  |   0  |  -   |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |                |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * | Caps |   A  |   S  |   D  |   F  |   G  |,------.,------.|   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
   * |Shift |   Z  |   X  |   C  |   V  |   B  || BSPC || SPC  ||   N  |   M  |   ,  |   .  |   /  |Shift |
   * |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
   * | ESC  |      |Super |  Ctrl |  Fn |  Alt |`------'`------'| Ctrl |  Fn  | Alt  |Super |   =  |Enter |
   * `-----------------------------------------'                `-----------------------------------------'
   */
  [_DEFAULT] = LAYOUT( /* qwerty */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_ESC,  KC_TRNS, KC_LGUI, KC_LCTRL,FN,      KC_LALT, KC_BSPC, KC_SPC,   KC_RCTRL,FN,      KC_RALT, KC_RGUI, KC_EQL,  KC_ENT
  ),

  /* Function layer
   * ,-----------------------------------------.                ,-----------------------------------------.
   * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |  PS  | Vol+ | |<   | ||>  |  >|  |  []  |                | MoLt | MoRt |  Up  |   [  |  ]   | Home |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * | PAU  | Vol- |      |      |      |MoWhUp|,------.,------.| MoUp | Left | Down |Right |      |  End |
   * |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
   * |      | Mute | MoB1 | MoB2 | MoB3 |MoWhDn|| BSPC ||  SPC || MoDn | F20  | F21  | F22  | F23  | PgUp |
   * |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
   * |RESET |      |      |      |      |      |`------'`------'|      |      |      |      |      | PgDn |
   * `-----------------------------------------'                `-----------------------------------------'
   */
  [_FN] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_PSCR, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP,                   KC_MS_L, KC_MS_R, KC_UP  , KC_LBRC, KC_RBRC, KC_HOME,
    KC_PAUS, KC_VOLD, _______, _______, _______, KC_WH_U,                   KC_MS_U, KC_LEFT, KC_DOWN, KC_RIGHT,_______, KC_END ,
    _______, KC_MUTE, KC_BTN1, KC_BTN2, KC_BTN3, KC_WH_D,                   KC_MS_D,  KC_F20,  KC_F21,   KC_F22, KC_F23, KC_PGUP,
 TO(_RESET), _______, KC_LGUI, KC_LCTRL,_______, KC_LALT,KC_BSPC, KC_SPC,   KC_RCTRL,_______, KC_RALT, KC_RGUI, _______, KC_PGDN
  ),

  /*
   * This layer makes it possible to reset the firmware; don't get rid of it and make sure there is a way to activate it.
   * ,-----------------------------------------.                ,-----------------------------------------.
   * |      |      |      |      |      |      |                |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |      |      |      |      |      |      |                |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |      |      |      |      |      |      |,------.,------.|      |      |      |      |      |      |
   * |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
   * |      |      |      |      |      |      ||      ||      ||      |      |      |      |      |      |
   * |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
   * |RETURN|      |      |      |      |      |`------'`------'|      |      |      |      |      |RESET |
   * `-----------------------------------------'                `-----------------------------------------'
   */
  [_RESET] = LAYOUT(
    KC_NO,        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO,        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO,        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO,        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    TO(_DEFAULT), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET
  )

  /*
  [_TRNS] = LAYOUT(
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  */
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch (id) {
  case 0:
    if (record->event.pressed) {
      register_code(KC_RSFT);
    }
    else {
      unregister_code(KC_RSFT);
    }
    break;
  }
  return MACRO_NONE;
};
