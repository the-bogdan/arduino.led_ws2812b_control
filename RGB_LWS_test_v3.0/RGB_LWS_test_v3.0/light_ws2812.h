/*
 * light weight WS2812 lib include
 *
 * Version 2.3  - Nev 29th 2015
 * Author: GaD_Bogdan. За основу взята библиотека от Tim (cpldcpu@gmail.com)
 *
 * License: GNU GPL v2+
 +
 */ 

#ifndef LIGHT_WS2812_H_
#define LIGHT_WS2812_H_

//===================================================================================================================
#include "main.h"
//===================================================================================================================
#define ws2812_resettime	50		/* Define Reset time in µs. This is the time the library spends
								       waiting after writing the data. WS2812 and clones need 50 µs*/
#define ws2812_port			B		// Data out port
#define ws2812_pin			2		// Data out pin
//===================================================================================================================
/*
 *  Structure of the LED array
 *
 * cRGB:     RGB  for WS2812S/B/C/D, SK6812, SK6812Mini, SK6812WWA, APA104, APA106
 */
struct cRGB  {uint8_t g; uint8_t r; uint8_t b;};
//===================================================================================================================

/* User Interface
 * 
 * Input:
 *         ledarray:           An array of GRB data describing the LED colors
 *         number_of_leds:     The number of LEDs to write
 *
 * The functions will perform the following actions:
 *         - Set the data-out pin as output
 *         - Send out the LED data 
 *         - Wait 50µs to reset the LEDs
 */
void ws2812_sendarray (uint8_t *ledarray, uint16_t num_of_leds);

//===================================================================================================================
/*
 * Internal defines
 */
#if !defined(CONCAT)
#define CONCAT(a, b)            a ## b
#endif

#if !defined(CONCAT_EXP)
#define CONCAT_EXP(a, b)   CONCAT(a, b)
#endif

#define ws2812_PORTREG  CONCAT_EXP(PORT, ws2812_port)
#define ws2812_DDRREG   CONCAT_EXP(DDR, ws2812_port)

#endif /* LIGHT_WS2812_H_ */
