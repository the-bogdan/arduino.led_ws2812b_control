#include "PWM.h"

void init_PWM_timer0(void)
{
	TCCR0A = 0;
	TCCR0A = (OC0A_is_connected_to_PWM<<COM0A1)|(0<<COM0A0);  // Настройка PWM на ножке OC0A
	TCCR0A |= (OC0B_is_connected_to_PWM<<COM0B1)|(0<<COM0B0); // Настройка PWM на ножке OC0B
	TCCR0A |= (1<<WGM01)|(1<<WGM00);   // Выбор режима ШИМ
	TCCR0B = 0;
	TCCR0B = (0<<FOC0A)|(0<<FOC0B)|(0<<WGM02); // Непонятные биты и выбор режима
	TCCR0B |= (1<<CS02)|(0<<CS01)|(0<<CS00); // Выбор предделителя
	TCNT0 = 0;
	OCR0A = 0;
	OCR0B = 0;
}