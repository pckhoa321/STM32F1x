#include "stm32f10x.h"

uint16_t sang[13] = {0xFFFE,0xFFFD,0xFFFB,0xFFF7,0xFFEF,0xFFDF,0xFFBF,0xFF7F,0xFEFF,0xFDFF,0xFBFF,0xF7FF,0xEFFF};
uint16_t tat[13] = {0xFFFE,0xFFFD,0xFFFB,0xFFF7,0xFFEF,0xFFDF,0xFFBF,0xFF7F,0xFEFF,0xFDFF,0xFBFF,0xF7FF,0xEFFF};
uint16_t sangNguoc[13] = {0xEFFF,0xF7FF,0xFBFF,0xFDFF,0xFEFF,0xFF7F,0xFFBF,0xFFDF,0xFFEF,0xFFF7,0xFFFB,0xFFFD,0xFFFE};

void gpioLed()
{
	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOC, ENABLE);
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6
									|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&gpio);
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6
									|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpio);
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&gpio);
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Pin = GPIO_Pin_2;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD,&gpio);
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
		GPIO_ResetBits(GPIOD, GPIO_Pin_2);
		delay(1);
		GPIO_SetBits(GPIOD, GPIO_Pin_2);
		delay(1);
		for(i = 0; i < 13; i++)
		{
			GPIO_Write(GPIOA, sang[i]);
			GPIO_Write(GPIOB, sang[i]);
			delay(1);
		}
		GPIO_ResetBits(GPIOC, GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4);
		delay(1);
	  GPIO_SetBits(GPIOC,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4);
		delay(1);
		GPIO_ResetBits(GPIOD, GPIO_Pin_2);
		delay(1);
		
	  GPIO_SetBits(GPIOD, GPIO_Pin_2);
		delay(1);
		for(j = 12; j > 0; j--)
		{
			GPIO_Write(GPIOA, tat[j]);
			GPIO_Write(GPIOB, tat[j]);
			delay(1);
		}
		GPIO_ResetBits(GPIOC, GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4);
		delay(1);
		GPIO_SetBits(GPIOC,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4);
		delay(1);
		for(i = 0; i <13 ;i++){
			GPIO_Write(GPIOA, sang[i]);
			delay(1);
		}
		for(i=0;i<13;i++){
			GPIO_Write(GPIOB, sangNguoc[i]);
			delay(1);
		}
	}
}