#ifndef GPIO_INIT_CUSTOM_H
#define GPIO_INIT_CUSTOM_H

#include "stm32f10x.h"

typedef enum{
    gpioa = 1,
    gpiob = 2,
    gpioc = 3,
    gpiod = 4,
    gpioe = 5,
    gpiof = 6,
    gpiog = 7
} gpio_def;

void custom_gpio_init(gpio_def GPIOx,GPIOSpeed_TypeDef Speed,GPIOMode_TypeDef Mode,uint16_t Pin);
#endif //  GPIO_INIT_CUSTOM_H
