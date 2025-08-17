#include "gpio_init_custom.h"

/********************************************************
 * @brief  自定义GPIO初始化函数
 * @param  GPIOx: GPIO端口号(A~G = 0~7)
 * @param  GPIO_Speed: GPIO速度(GPIOSpeed_10MHz/GPIOSpeed_20MHz/GPIOSpeed_50MHz)
 * @param  GPIO_Mode: GPIO模式(GPIO_MODE_AIN/IN_FLOATING/IPD/IPU/OUT_OD/OUT_PP/AF_OD/AF_PP)
 * @param  GPIO_Pin: GPIO引脚号{GPIO_Pin_0~15}
 * @retval None
 ********************************************************/

void custom_gpio_init(uint16_t GPIOx,GPIOSpeed_TypeDef GPIO_Speed,GPIOMode_TypeDef GPIO_Mode,uint16_t GPIO_Pin)
{   
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode;
    switch(GPIOx)
    {
        case 1:
        {
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
            GPIO_Init(GPIOA,&GPIO_InitStructure);
            break;
        }
        case 2:
        {
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
            GPIO_Init(GPIOB,&GPIO_InitStructure);
            break;
        }
        case 3:
        {
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
            GPIO_Init(GPIOC,&GPIO_InitStructure);
            break;
        }
        case 4:
        {
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);
            GPIO_Init(GPIOD,&GPIO_InitStructure);
            break;
        }
        case 5:
        {
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
            GPIO_Init(GPIOE,&GPIO_InitStructure);
            break;
        }
        case 6:
        {
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF,ENABLE);
            GPIO_Init(GPIOF,&GPIO_InitStructure);
            break;
        }
        case 7:
        {
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG,ENABLE);
            GPIO_Init(GPIOG,&GPIO_InitStructure);
            break;
        }
        default:break;
    }
}
