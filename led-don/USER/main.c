#include "stm32f10x.h"

void delay(unsigned int time){
	unsigned int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<0x2AFF;j++);
	}
}

void led_don(){
	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	/* cau hinh gpio*/
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Pin = GPIO_Pin_1;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpio);
}

int main(){
	led_don();
	while(1){
		GPIO_ResetBits(GPIOB, GPIO_Pin_1);
		delay(5);
		GPIO_SetBits(GPIOB, GPIO_Pin_1);
		delay(5);
		
	}
}

	
	
