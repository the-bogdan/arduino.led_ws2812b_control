/*
 * WS2812b.h
 *
 * Created: 07.03.2020 1:21:43
 *  Author: GaD_Bogdan
 */ 


#ifndef WS2812B_H_
#define WS2812B_H_

#include "main.h"
//===================================================================================================================
#define LED_number 90
//===================================================================================================================
#define black 0x000000
#define red 0x3F0000
#define green 0x003F00
#define blue 0x00003F
#define orange 0xFFA500
#define yellow 0x7F7F00
#define  aqua 0x007F7F
#define violet 0x774177
//===================================================================================================================
void setArraysGRB (uint8_t num_of_leds, uint8_t *Red_array, uint8_t *Green_array, uint8_t *Blue_array);
//===================================================================================================================
void Linear_interpolation  (uint8_t number_of_leds, uint32_t Start_color, uint32_t Finish_color,
											uint8_t *R_array, uint8_t *G_array, uint8_t *B_array);
//===================================================================================================================
void Single_color_fill(uint8_t number_of_leds, uint32_t Color, uint8_t *R_array, uint8_t *G_array, uint8_t *B_array);
//===================================================================================================================

#endif /* WS2812B_H_ */