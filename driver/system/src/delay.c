#include "delay.h"

#if TIMER_DELAY_MODE == 0

/**
 * @brief 保证接口一致留的占位函数，调用无效果
 * @return 无
 */
void delay_init(void){}

/**
 * @brief 1us延时(粗略)，仅供内部调用
 * @return 无
 */
static void delay_1us(void)
{
    for(uint32_t i = 0; i < 72; i++)
    {
        __NOP();
    }
}

/**
 * @brief us延时(粗略)，供外部调用
 * @param time 延时的时间，单位us
 * @return 无
 */
void delay_us(uint32_t time)//us延时
{
    for(uint32_t i = 0; i < time; i++)
    {
        delay_1us();
    }
}

/**
 * @brief ms延时(粗略)，供外部调用
 * @param time 延时的时间，单位ms
 * @return 无
 */
void delay_ms(uint32_t time)
{
    for(uint32_t i = 0; i < time; i++)
    {
        delay_us(1000);
    }
}

#elif TIMER_DELAY_MODE == 1

/**
 * @brief 定时器初始化函数，供外部调用
 * @return 无
 */
void delay_init(void)
{
    //使能定时器时钟
    TIM_TimeBaseInitTypeDef TIM_InitStruct;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

    TIM_InitStruct.TIM_Prescaler = 72-1;
    TIM_InitStruct.TIM_Period = 0;
    TIM_InitStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM3, &TIM_InitStruct);

    TIM_Cmd(TIM3, DISABLE);
}

/**
 * @brief 1us延时，仅供内部调用
 * @return 无
 */
static void delay_1us(void)
{
    TIM_ClearFlag(TIM3, TIM_FLAG_Update);
    TIM_Cmd(TIM3, ENABLE);
    while (TIM_GetFlagStatus(TIM3, TIM_FLAG_Update) != SET);
    TIM_Cmd(TIM3, DISABLE);
}

/**
 * @brief us延时，供外部调用
 * @param time 延时的时间，单位us
 * @return 无
 */
void delay_us(uint32_t time)
{
    for(uint32_t i = 0; i < time; i++)
    {
        delay_1us();
    }
}

/**
 * @brief ms延时，供外部调用
 * @param time 延时的时间，单位ms
 * @return 无
 */
void delay_ms(uint32_t time)
{
    if(time > 65)
    {
        for(uint32_t i = 0; i < time; i++)
        {
            delay_us(1000);
        }
    }
    else
    {
        uint32_t period = time * 1000 - 1;

        TIM_SetAutoreload(TIM3, period);
        TIM_SetCounter(TIM3, 0);

        TIM_ClearFlag(TIM3, TIM_FLAG_Update);
        TIM_Cmd(TIM3, ENABLE);

        while (TIM_GetFlagStatus(TIM3, TIM_FLAG_Update) != SET);

        TIM_Cmd(TIM3, DISABLE);
    }
}

#else

#endif
