/*
 * EEPROM.c
 *
 * Created: 2/24/2020 12:35:10 AM
 *  Author: GaD_Bogdan
 */ 

#include "EEPROM.h"
//==================================================================================================
void EEPROM_init(void) // выбираем одновременное стирание и запись в память в виде унарной опирации. Не обязательно
{
	EECR = (0<<EEPM1)|(0<<EEPM0);  // Только для записи
}
//==================================================================================================
void EEPROM_write_byte(unsigned int uiAddress, unsigned char ucData) // Пишем однобайтовую величину
{
	while (EECR & (1<<EEPE))  // Ждем освобождения флага окончания последней операцией с памятью
	{}
	EEAR = uiAddress; // Устанавливаем адресс
	EEDR = ucData; // Пишем данные в регистр
	SetBit(EECR, EEMPE); // Разрешаем запись
	SetBit(EECR, EEPE); // Пишем байт в память
}
//==================================================================================================
unsigned char EEPROM_read_byte(unsigned int uiAddress) // Читаем однобайтовую величину
{
	while (EECR & (1<<EEPE))  // Ждем освобождения флага окончания последней операцией с памятью
	{}
	EEAR = uiAddress; // Устанавливаем адресс
	SetBit(EECR, EERE); // Включаем чтение памяти
	return EEDR; // Возвращаем результат
}
//==================================================================================================
void EEPROM_write_word(unsigned int uiAddress, unsigned char *p_ucData)
{
	EEPROM_write_byte(uiAddress++, *p_ucData++); // записываем первый байт, постинкрементим указатель и адрес
	EEPROM_write_byte(uiAddress, *p_ucData); // записываем следующий байт в следующий адресс
}
//==================================================================================================
void EEPROM_read_word(unsigned int uiAddress, unsigned char *p_ucData)
{
	*p_ucData++ = EEPROM_read_byte(uiAddress++); // читаем первый байт, постинкрементим указатель и адрес
	*p_ucData = EEPROM_read_byte(uiAddress);  // читаем следующий байт из следующего адреса
}
//==================================================================================================
void EEPROM_write_dword(unsigned int uiAddress, unsigned char *p_ucData)
{
	EEPROM_write_byte(uiAddress++, *p_ucData++); // записываем первый байт, постинкрементим указатель и адрес
	EEPROM_write_byte(uiAddress++, *p_ucData++);
	EEPROM_write_byte(uiAddress++, *p_ucData++);
	EEPROM_write_byte(uiAddress, *p_ucData); // записываем следующий байт в следующий адресс
}
//==================================================================================================
void EEPROM_read_dword(unsigned int uiAddress, unsigned char *p_ucData)
{
	*p_ucData++ = EEPROM_read_byte(uiAddress++);  // читаем первый байт, постинкрементим указатель и адрес
	*p_ucData++ = EEPROM_read_byte(uiAddress++);
	*p_ucData++ = EEPROM_read_byte(uiAddress++);
	*p_ucData = EEPROM_read_byte(uiAddress); // читаем следующий байт из следующего адреса
}
//==================================================================================================
void EEPROM_write_string(unsigned int uiAddress, char *string)
{
	while (*string) // проходимся по элементам строки, пока не наткнемся на 0
	{
		EEPROM_write_byte(uiAddress++, *string++); // пишем элементы, постинкрементируя указатель и адресс
	}
}
//==================================================================================================
// !!! После использования желательно очистить память функциеq free!!! //
char * EEPROM_read_string(unsigned int uiAddress, unsigned char size)
{
	unsigned char i;
	char *string;  // заводим указатель на тип char
	string = (char *) malloc(size+1);  // просим программу выделить нам память для нашей строки
	for (i = 0; i < size; i++) // читаем все это в цикле
	{
		string[i] = EEPROM_read_byte(uiAddress++); // пишем в выделенную нам память
	}
	string[size] = 0; // в конце добавляем 0, обозначающий конец строки
	return string;
}
//==================================================================================================
// !!! После использования желательно очистить память функциеq free!!! //
char * EEPROM_read_string_for_int_size(unsigned int uiAddress, unsigned int size)
{
	unsigned int i;
	char *string; // заводим указатель на тип char
	string=(char *) malloc(size+1); // просим программу выделить нам память для нашей строки
	for (i = 0; i < size; i++) // читаем все это в цикле
		{
			string[i] = EEPROM_read_byte(uiAddress++); // пишем в выделенную нам память
		}
	string[size] = 0; // в конце добавляем 0, обозначающий конец строки
	return string;
}
//==================================================================================================
