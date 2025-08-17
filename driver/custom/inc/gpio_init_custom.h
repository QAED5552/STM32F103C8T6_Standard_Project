#ifndef GPIO_INIT_CUSTOM_H
#define GPIO_INIT_CUSTOM_H

#include "stm32f10x.h"

void custom_gpio_init(uint16_t GPIOx,GPIOSpeed_TypeDef Speed,GPIOMode_TypeDef Mode,uint16_t Pin);
#endif //  GPIO_INIT_CUSTOM_H
