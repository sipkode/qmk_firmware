/*
      ___                   ___      ___         ___        _____        ___
     /  /\      ___        /  /\    /__/|       /  /\      /  /::\      /  /\
    /  /:/_    /  /\      /  /::\  |  |:|      /  /::\    /  /:/\:\    /  /:/_
   /  /:/ /\  /  /:/     /  /:/\:\ |  |:|     /  /:/\:\  /  /:/  \:\  /  /:/ /\
  /  /:/ /::\/__/::\    /  /:/~/:/_|  |:|    /  /:/  \:\/__/:/ \__\:|/  /:/ /:/_
 /__/:/ /:/\:\__\/\:\__/__/:/ /:/__/\_|:|___/__/:/ \__\:\  \:\ /  /:/__/:/ /:/ /\
 \  \:\/:/~/:/  \  \:\/\  \:\/:/\  \:\/:::::|  \:\ /  /:/\  \:\  /:/\  \:\/:/ /:/
  \  \::/ /:/    \__\::/\  \::/  \  \::/~~~~ \  \:\  /:/  \  \:\/:/  \  \::/ /:/
   \__\/ /:/     /__/:/  \  \:\   \  \:\      \  \:\/:/    \  \::/    \  \:\/:/
     /__/:/      \__\/    \  \:\   \  \:\      \  \::/      \__\/      \  \::/
     \__\/                 \__\/    \__\/       \__\/                   \__\/
*/

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define ALT_TIME_TIMEOUT 1000 // milliseconds

static bool g_is_alt_tab_active = false;
static uint16_t g_alt_tab_timer = 0;

// Friendly Layer Names
enum gherkin_layers
{
    _QWERTY = 0,
    _NUMBERS,
    _FUNCTIONS,
    _SYMBOLS,
    _NUMPAD,
    _NAV,
    _MEDIA,
    _ADJUST,

    _COUNT
};

// Custom keycodes
enum gherkin_keycodes
{
    QWERTY = SAFE_RANGE,
    NUMBERS,
    FUNCTIONS,
    SYMBOLS,
    SONGS,
    PLOVER,
    BACKLIT,
    EXT_PLV,
    ALT_TAB
};

// Tap Dance Declarations
enum
{
    TD_Z_LCTL = 0,
    TD_X_LGUI = 1,
    TD_C_LALT = 2,
    TD_F_TAB = 3,
    TD_Q_ESC = 4,
    TD_N_COMM = 5,
    TD_M_DOT = 6
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
        case KC_RIGHT:  // Intentional fall-through
        case KC_LEFT:   // Intentional fall-through
        case KC_DOWN:   // Intentional fall-through
        case KC_UP:
            if (record->event.pressed && g_is_alt_tab_active)
            {
                g_alt_tab_timer = timer_read();
            }
            break;
        case ALT_TAB:// This will do most of the grunt work with the keycodes.case ALT_TAB : if (record->event.pressed)
        {
            if (record->event.pressed)
            {
                if (!g_is_alt_tab_active)
                {
                    g_is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                g_alt_tab_timer = timer_read();
                register_code(KC_TAB);
            }
            else
            {
                unregister_code(KC_TAB);
            }
        }
        break;
    }
    return true;
}

void matrix_scan_user(void)
{
    if (g_is_alt_tab_active)
    { // The very important timer.if (is_alt_tab_active)
        if (timer_elapsed(g_alt_tab_timer) > ALT_TIME_TIMEOUT)
        {
            unregister_code(KC_LALT);
            g_is_alt_tab_active = false;
        }
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_ortho_3x10(
    TD(TD_Q_ESC), KC_W,               KC_E,         KC_R,             KC_T,               KC_Y,                 KC_U,                 KC_I,          KC_O,               KC_P,
    LCTL_T(KC_A), KC_S,               KC_D,         TD(TD_F_TAB),     LT(_MEDIA,KC_G),    KC_H,                 KC_J,                 KC_K,          LT(_SYMBOLS,KC_L),  LT(_ADJUST,KC_SCLN),
    LSFT_T(KC_Z), TD(TD_X_LGUI),      LALT_T(KC_C), LT(_SYMBOLS,KC_V),LT(_NAV, KC_BSPC),  LT(_NUMBERS, KC_SPC), LT(_FUNCTIONS,KC_B),  TD(TD_N_COMM), TD(TD_M_DOT),       RSFT_T(KC_ENT)
  ),

  [_NUMBERS] = LAYOUT_ortho_3x10(
    KC_1,     KC_2,    KC_3,     KC_4,     KC_5,             KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
    _______,  _______, _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,
    KC_CAPS,  _______, _______,  _______,  LT(_NAV,KC_DEL),  _______,  _______,  _______,  _______,  _______
  ),
    
  [_FUNCTIONS] = LAYOUT_ortho_3x10(
    KC_F1,    KC_F2,   KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
    KC_F11,   KC_F12,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),

  [_SYMBOLS] = LAYOUT_ortho_3x10(
    KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,          KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,
    KC_GRV,   _______,  XXXXXXX,  XXXXXXX,  _______,          KC_BSLS,  KC_MINS,  KC_EQL ,  KC_QUOT,  LT(_ADJUST,KC_SCLN),
    KC_LSFT,  _______,  _______,  XXXXXXX,  LT(_NAV,KC_DEL),  KC_LBRC,  KC_RBRC,  KC_COMM,  KC_DOT,   RSFT_T(KC_SLSH)
  ),

  [_NUMPAD] = LAYOUT_ortho_3x10(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PSLS,  KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_PMNS,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  KC_PAST,  KC_KP_4,  KC_KP_5,  KC_KP_6,  LT(_ADJUST,KC_PPLS),
    _______,  _______,  _______,  XXXXXXX,  KC_PDOT,  KC_KP_0,  KC_KP_1,  KC_KP_2,  KC_KP_3,  KC_PENT
  ),

  [_NAV] = LAYOUT_ortho_3x10(
    ALT_TAB,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PGUP,  KC_UP,    KC_HOME,  XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,
    _______,  _______,  _______,  XXXXXXX,  _______,  XXXXXXX,  KC_PGDN,  XXXXXXX,  KC_END,   XXXXXXX
  ),

  [_MEDIA] = LAYOUT_ortho_3x10(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_VOLU,  XXXXXXX,  XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,  KC_MPRV,  KC_VOLD,  KC_MNXT,  _______,
    _______,  _______,  _______,  XXXXXXX,  _______,  KC_MPLY,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  [_ADJUST] = LAYOUT_ortho_3x10(
    TO(_QWERTY),  TO(_NUMBERS), TO(_SYMBOLS), TO(_NUMPAD),  TO(_NAV), TO(_MEDIA), _______,  _______,  _______,  _______,
    MUV_DE,       MUV_IN,       MU_ON,        MU_OFF,       _______,  _______,    _______,  _______,  _______,  _______,
    BACKLIT,      _______,      _______,      _______,      RESET,    _______,    _______,  _______,  _______,  _______
  )
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  // Tap once for LParam, twice for RParam
  [TD_Z_LCTL] = ACTION_TAP_DANCE_DOUBLE(KC_Z, KC_LCTL),
  [TD_X_LGUI] = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_LGUI),
  [TD_C_LALT] = ACTION_TAP_DANCE_DOUBLE(KC_C, KC_LALT),
  [TD_F_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_F, KC_TAB),
  [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
  [TD_N_COMM] = ACTION_TAP_DANCE_DOUBLE(KC_N, KC_COMM),
  [TD_M_DOT] = ACTION_TAP_DANCE_DOUBLE(KC_M, KC_DOT)
};
