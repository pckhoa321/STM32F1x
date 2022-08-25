#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"


void delay(unsigned int time){
	unsigned int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<0x2AFF;j++);
	}
}

void led_don(){
	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);
	
	/* cau hinh nut nhan*/
	gpio.GPIO_Mode = GPIO_Mode_IPU;
	gpio.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_3;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &gpio);
	
	/* cau hinh gpio*/
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_0;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpio);
}

int main(){
	led_don();
	GPIO_SetBits(GPIOB, GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_0);
	while(1){
			
			if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)==0){
				while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)==0);
				GPIO_Write(GPIOB,0x00);
			}
			if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2) == 0){
				while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)==0);
				GPIO_Write(GPIOB,0xFF);
			}
	}
}

	
	
