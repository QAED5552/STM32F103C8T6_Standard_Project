#ifndef DELAY_H
#define DELAY_H

#include "stm32f10x.h"

#define systemcoreclock 72000000

// 通过定义TIMER_DELAY_MODE来选择延时方式
// 0: 阻塞式延时
// 1: 定时器式延时(Timer)
// 2: 定时器式延时(SysTick)
#ifndef TIMER_DELAY_MODE
#define TIMER_DELAY_MODE 0
#endif

void delay_init(void);
void delay_ms(uint32_t time);
void delay_us(uint32_t time);
#endif // DELAY_H
