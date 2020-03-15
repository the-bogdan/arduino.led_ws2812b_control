#ifndef PWM_H_
#define PWM_H_

#include "main.h"

#define OC0A_is_connected_to_PWM 1  // �������� OC0A (��� ������� ���������� ������������ OCR0A)
#define OC0B_is_connected_to_PWM 0  // �������� OC0B (��� ������� ���������� ������������ OCR0B)

void init_PWM_timer0(void);


#endif /* PWM_H_ */