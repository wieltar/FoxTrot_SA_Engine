#pragma once
// ----------------------------
// -- USB STANDARD SCANCODES --
// ----------------------------
// https://www.usb.org/sites/default/files/documents/hut1_12v2.pdf 
// PAG. 53
// SOURCED FROM SDL KEYCODES FILE
namespace Glitch
{
	enum KeyCode
	{
		KEY_UNKNOWN = 0,
		KEY_A = 4,
		KEY_B = 5,
		KEY_C = 6,
		KEY_D = 7,
		KEY_E = 8,
		KEY_F = 9,
		KEY_G = 10,
		KEY_H = 11,
		KEY_I = 12,
		KEY_J = 13,
		KEY_K = 14,
		KEY_L = 15,
		KEY_M = 16,
		KEY_N = 17,
		KEY_O = 18,
		KEY_P = 19,
		KEY_Q = 20,
		KEY_R = 21,
		KEY_S = 22,
		KEY_T = 23,
		KEY_U = 24,
		KEY_V = 25,
		KEY_W = 26,
		KEY_X = 27,
		KEY_Y = 28,
		KEY_Z = 29,

		KEY_1 = 30,
		KEY_2 = 31,
		KEY_3 = 32,
		KEY_4 = 33,
		KEY_5 = 34,
		KEY_6 = 35,
		KEY_7 = 36,
		KEY_8 = 37,
		KEY_9 = 38,
		KEY_0 = 39,

		KEY_RETURN = 40,
		KEY_ESCAPE = 41,
		KEY_BACKSPACE = 42,
		KEY_TAB = 43,
		KEY_SPACE = 44,

		KEY_MINUS = 45,
		KEY_EQUALS = 46,
		KEY_LEFTBRACKET = 47,
		KEY_RIGHTBRACKET = 48,
		KEY_BACKSLASH = 49,	/**< Located at the lower left of the return
		*   key on ISO keyboards and at the right end
		*   of the QWERTY row on ANSI keyboards.
		*   Produces REVERSE SOLIDUS (backslash) and
		*   VERTICAL LINE in a US layout, REVERSE
		*   SOLIDUS and VERTICAL LINE in a UK Mac
		*   layout, NUMBER SIGN and TILDE in a UK
		*   Windows layout, DOLLAR SIGN and POUND SIGN
		*   in a Swiss German layout, NUMBER SIGN and
		*   APOSTROPHE in a German layout, GRAVE
		*   ACCENT and POUND SIGN in a French Mac
		*   layout, and ASTERISK and MICRO SIGN in a
		*   French Windows layout.
		*/
		KEY_SEMICOLON = 51,
		KEY_APOSTROPHE = 52,
		KEY_GRAVE = 53, /**< Located in the top left corner (on both ANSI
		*   and ISO keyboards). Produces GRAVE ACCENT and
		*   TILDE in a US Windows layout and in US and UK
		*   Mac layouts on ANSI keyboards, GRAVE ACCENT
		*   and NOT SIGN in a UK Windows layout, SECTION
		*   SIGN and PLUS-MINUS SIGN in US and UK Mac
		*   layouts on ISO keyboards, SECTION SIGN and
		*   DEGREE SIGN in a Swiss German layout (Mac:
		*   only on ISO keyboards), CIRCUMFLEX ACCENT and
		*   DEGREE SIGN in a German layout (Mac: only on
		*   ISO keyboards), SUPERSCRIPT TWO and TILDE in a
		*   French Windows layout, COMMERCIAL AT and
		*   NUMBER SIGN in a French Mac layout on ISO
		*   keyboards, and LESS-THAN SIGN and GREATER-THAN
		*   SIGN in a Swiss German, German, or French Mac
		*   layout on ANSI keyboards.
		*/
		KEY_COMMA = 54,
		KEY_PERIOD = 55,
		KEY_SLASH = 56,

		KEY_CAPSLOCK = 57,

		KEY_F1 = 58,
		KEY_F2 = 59,
		KEY_F3 = 60,
		KEY_F4 = 61,
		KEY_F5 = 62,
		KEY_F6 = 63,
		KEY_F7 = 64,
		KEY_F8 = 65,
		KEY_F9 = 66,
		KEY_F10 = 67,
		KEY_F11 = 68,
		KEY_F12 = 69,

		KEY_PRINTSCREEN = 70,
		KEY_SCROLLLOCK = 71,
		KEY_PAUSE = 72,
		KEY_INSERT = 73,
		KEY_HOME = 74,
		KEY_PAGEUP = 75,
		KEY_DELETE = 76,
		KEY_END = 77,
		KEY_PAGEDOWN = 78,
		KEY_RIGHT = 79,
		KEY_LEFT = 80,
		KEY_DOWN = 81,
		KEY_UP = 82,

		KEY_THOUSANDSSEPARATOR = 178,
		KEY_DECIMALSEPARATOR = 179,
		KEY_CURRENCYUNIT = 180,
		KEY_CURRENCYSUBUNIT = 181,
		KEY_KP_LEFTPAREN = 182,
		KEY_KP_RIGHTPAREN = 183,
		KEY_KP_LEFTBRACE = 184,
		KEY_KP_RIGHTBRACE = 185,
		KEY_KP_TAB = 186,
		KEY_KP_BACKSPACE = 187,

		KEY_LCTRL = 224,
		KEY_LSHIFT = 225,
		KEY_LALT = 226, /**< alt, option */
		KEY_LGUI = 227, /**< windows, command (apple), meta */
		KEY_RCTRL = 228,
		KEY_RSHIFT = 229,
		KEY_RALT = 230, /**< alt gr, option */
		KEY_RGUI = 231, /**< windows, command (apple), meta */
	};
}