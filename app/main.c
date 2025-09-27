#include "stm32f10x.h"

//延时模式切换在#include delay.h之前，否则会有警告.
//目前延时模式有三种，但都是阻塞式延时，如需使用非阻塞延时需自行在delay.h中添加.
//1.普通模式延时(默认模式) #define TIMER_DELAY_MODE 0
//2.定时器模式延时 #define TIMER_DELAY_MODE 1
//3.SYSTICK模式延时 #define TIMER_DELAY_MODE 2
#include "delay.h"

int main(void)
{
	while(1)
	{

	}
}
