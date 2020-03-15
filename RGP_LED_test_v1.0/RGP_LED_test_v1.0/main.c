/*
 * RGP_LED_test.c
 *
 * Created: 28.02.2020 14:58:39
 * Author : GaD_Bogdan
 */ 

#include "main.h"
//===================================================================================================================
#define ClearBitLED PORTC &= (~(1<<0))
#define SetBitLED PORTC |= (1<<0)
#define LED_number 227

#define red 0xFF0000
#define orange 0x0F4000
#define yellow 0x0F0F00
#define green 0x00FF00
#define blue 0x0000FF
#define indigo 0x4B000F
#define violet 0x48000F
//===================================================================================================================
unsigned long int array[LED_number];
unsigned char color1 = 0;
unsigned char color = 0;
//===================================================================================================================
void Set0(void) // Выставляем в линию ноль ~0.4 мкс
{
	SetBitLED;
	asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
	ClearBitLED; //После этого временной интервал немного увеличен, в связи с выполнением циклов,
	             //но диоды сигнал ловят исправно
}
//===================================================================================================================
void Set1(void) // Выставляем в линию единицу ~0.85 мкс
{
	SetBitLED;
	asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
	asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
	ClearBitLED; //После этого временной интервал немного увеличен, в связи с выполнением циклов,
	//но диоды сигнал ловят исправно
}
//===================================================================================================================
void setArray(void) // Выставление всего массива в линию
{
	unsigned long int a;
	unsigned int j,i;
	
	for (j=0; j<LED_number; j++)
	{
		a = 0x1000000;
		for (i=0; i<24; i++)
		{
			a=a>>1;
			if ((array[j]&a) == 0x00000000)
			{
				Set0();
			} 
			else
			{
				Set1();
			}
		}
	}
}
//===================================================================================================================

int main(void)
{
	SetBit(DDRC, 0);
    while (1) 
    {
		if (color1 == 0)
		{
			color1 = 6;
		}
		else 
		{
			color1--;
		}
		
		color = color1;
		
		unsigned char i;
		for(i = 0; i < LED_number; i++)
		{
			switch (color)
			{
				case 0:
					array[i] = red;
					color++;
					break;
				case 1:
					array[i] = orange;
					color++;
					break;
				case 2:
					array[i] = yellow;
					color++;
					break;
				case 3:
					array[i] = green;
					color++;
					break;
				case 4:
					array[i] = blue;
					color++;
					break;
				case 5:
					array[i] = indigo;
					color++;
					break;
				case 6:
					array[i] = violet;
					color = 0;
					break;
			}
			 
		}
		setArray();
		_delay_ms(50);
    }
}
