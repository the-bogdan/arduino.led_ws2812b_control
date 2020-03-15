#ifndef PWM_H_
#define PWM_H_

#include "main.h"

#define OC0A_is_connected_to_PWM 1  // ¬ключаем OC0A (дл€ задани€ скважности использовать OCR0A)
#define OC0B_is_connected_to_PWM 0  // ¬ключаем OC0B (дл€ задани€ скважности использовать OCR0B)

void init_PWM_timer0(void);


#endif /* PWM_H_ */