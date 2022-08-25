#include "stm32f10x.h"

void gpio(){
	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	gpio.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &gpio);
}

void delay(unsigned int time){
	unsigned int i, j;
	for(i = 0 ; i < time;i++){
		for(j=0;j < 0x2aff ;j++){}
	}
}

int main(){
	gpio();
	while(1)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3); 
		delay(5);
		GPIO_ResetBits(GPIOA, GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3);
		delay(5);
	}
}
		
	

	
	
	