#ifndef __KEYPAD_H__
#define __KEYPAD_H__

#include "stm32f4xx_hal.h"
#define C1_PIN GPIO_PIN_9
#define C2_PIN GPIO_PIN_10
#define C3_PIN GPIO_PIN_11
#define C4_PIN GPIO_PIN_12
#define C_PORT GPIOA

#define R1_PIN GPIO_PIN_4
#define R2_PIN GPIO_PIN_5
#define R3_PIN GPIO_PIN_6
#define R4_PIN GPIO_PIN_7
#define R_PORT GPIOD
void Keypad_Init(void);
char Keypad_GetKey(void);

/* Bạn có thể đổi mapping keypad tại đây */
extern const char Keypad_Map[4][4];

/* Hàm gán chân Keypad (khai báo ở main.c) */
extern GPIO_TypeDef* ROW_PORT[4];
extern uint16_t ROW_PIN[4];

extern GPIO_TypeDef* COL_PORT[4];
extern uint16_t COL_PIN[4];

#endif
