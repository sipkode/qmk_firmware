#include "dz60.h"

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define RGB_STA RGB_M_P //rgb static
#define RGB_BRE RGB_M_B //rgb breathe
#define RGB_RAI RGB_M_R //rgb rainbow
#define RGB_SWI RGB_M_SW //rgb swirl
#define RGB_SNA RGB_M_SN //rgb snake
#define RGB_KNI RGB_M_K //rgb knight
#define RGB_GRA RGB_M_G //rgb gradient


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   /* Keymap: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * |CAPS/MO|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |TT |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |Alt |Gui |MO  |Ctrl |
   * `-----------------------------------------------------------'
   */
    LAYOUT(
        KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , XXXXXXX, KC_BSPC,
        KC_TAB ,          KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
        LT(MO(1), KC_CAPS),KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,         KC_ENT ,
        KC_LSFT, XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,          TT(2),
        KC_LCTL,          KC_LGUI, KC_LALT, KC_SPC ,          KC_SPC ,          KC_SPC , KC_RALT, KC_RGUI, XXXXXXX, MO(1)  ,          KC_RCTL),

   /* Keymap : Second Layer (WASD and Media)
   * ,-----------------------------------------------------------.
   * |ESC| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|   DEL |
   * |-----------------------------------------------------------|
   * |     |   | Up|   |   |   |   |   |Prn|Slk|Pau|   |   |     |
   * |-----------------------------------------------------------|
   * |      |Lft|Dwn|Rgt|   |   |   |   |Ins|Hom|PgU|   |        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |Del|End|PgD|          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */

    LAYOUT(
        KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , XXXXXXX, KC_DEL ,
        _______,          XXXXXXX,  KC_UP,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUSE,XXXXXXX, XXXXXXX, XXXXXXX,
        _______,          KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS , KC_HOME, KC_PGUP, XXXXXXX,          _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_DEL,  KC_END, KC_PGDN, _______,          _______,
        _______,          _______, _______, XXXXXXX,          XXXXXXX,          XXXXXXX, _______, _______, XXXXXXX, _______,          _______),

   /* Keymap : Third Layer (RGB / Reset)
   * ,-----------------------------------------------------------.
   * | ` |   |   |   |   |   |   |   |   |   |   |   |   |       |
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |   |   |   |   |        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */

    LAYOUT(
        KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , XXXXXXX, KC_SLEP,
        _______,          RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, RESET  ,
        _______,          RGB_STA, RGB_BRE, RGB_RAI, RGB_SWI, RGB_SNA, RGB_KNI, RGB_GRA, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______,
        _______, XXXXXXX, BL_DEC , BL_TOGG, BL_INC , BL_STEP, BL_BRTG, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY, _______,          _______,
        _______,          _______, _______, _______,          XXXXXXX,          XXXXXXX, _______, _______, XXXXXXX, _______,          _______),

};
