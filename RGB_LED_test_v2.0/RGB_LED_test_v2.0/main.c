/*
 * RGP_LED_test.c
 *
 * Created: 28.02.2020 14:58:39
 * Author : GaD_Bogdan
 */ 

#include "main.h"
//===================================================================================================================
uint8_t Red_array[LED_number];
uint8_t Green_array[LED_number];
uint8_t Blue_array[LED_number];
uint8_t count = 0, count_state = 1;
//===================================================================================================================
int main(void)
{
	SetBit(DDRC, 0);

	Single_color_fill(LED_number, black, Red_array, Green_array, Blue_array);

	setArraysGRB(LED_number, Red_array, Green_array, Blue_array);		
    while (1)
    {
		uint8_t i, j;

		for (j = 0; j < 8; j++)
		{
			uint32_t color;
			switch (j)
			{
			case 0:
				color = red;
				break;	
			case 1:
				color = aqua;
				break;
			case 2:
				color = yellow;
				break;
			case 3:
				color = green;
				break;
			case 4:
				color = blue;
				break;
			case 5:
				color = orange;
				break;
			case 6:
				color = violet;
				break;
			case 7:
				color = black;
				break;
			}
			for (i = 0; i < LED_number; i++)
			{
				Red_array[i] = 0xFF; Blue_array[i] = 0xFF; Green_array[i] = 0xFF;
				if (i != 0)
				{
					Single_color_fill(i, color, Red_array, Green_array, Blue_array);
				}
				setArraysGRB(LED_number, Red_array, Green_array, Blue_array);
				_delay_ms(30);
			}
		}
		for (i = 0; i < LED_number; i++)
		{
			Red_array[i] = 0xFF; Blue_array[i] = 0xFF; Green_array[i] = 0xFF;
			if (i != 0)
			{
				Single_color_fill(i-1, red, Red_array, Green_array, Blue_array);
			}
			setArraysGRB(LED_number, Red_array, Green_array, Blue_array);
			_delay_ms(30);
		}
		for (i = 0; i < LED_number; i++)
		{
			Red_array[i] = 0xFF; Blue_array[i] = 0xFF; Green_array[i] = 0xFF;
			if (i != 0)
			{
				Single_color_fill(i-1, blue, Red_array, Green_array, Blue_array);
			}
			setArraysGRB(LED_number, Red_array, Green_array, Blue_array);
			_delay_ms(10);
		}
    }
}
//===================================================================================================================
