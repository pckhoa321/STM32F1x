#include "stm32f10x.h"

uint16_t sang[8] = {0xE7, 0xDB, 0xBD, 0x7E, 0xBD, 0xDB, 0xE7, 0xFF};
uint16_t tat[8] = {0xE7, 0xDB, 0xBD, 0x7E, 0xBD, 0xDB, 0xE7, 0xFF};

void gpioLed()
{
	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB, ENABLE);
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&gpio);
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpio);
}

void delay(unsigned int time)
{
	unsigned int i, j;
	for(i = 0; i < time ;i++)
	{
		for(j = 0; j <0x2AFF; j++){}
	}
}

int main()
{
	gpioLed();
	while(1)
	{
		unsigned int i,j;
		for(i = 0; i < 8; i++)
		{
			GPIO_Write(GPIOA, sang[i]);
			GPIO_Write(GPIOB, sang[i]);
			delay(5);
		}
		
		/*GPIO_SetBits(GPIOA, GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);
		GPIO_SetBits(GPIOB, GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);
		delay(5);
		GPIO_ResetBits(GPIOA, GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);
		GPIO_ResetBits(GPIOB, GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);
		delay(5);*/
		for(j = 7; j > 0; j--)
		{
			GPIO_Write(GPIOA, tat[j]);
			GPIO_Write(GPIOB, tat[j]);
			delay(5);
		}
		/*GPIO_SetBits(GPIOA, GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);
		GPIO_SetBits(GPIOB, GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);
		delay(5);
		GPIO_ResetBits(GPIOA, GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);
		GPIO_ResetBits(GPIOB, GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);
		delay(5);*/
	}
}


	