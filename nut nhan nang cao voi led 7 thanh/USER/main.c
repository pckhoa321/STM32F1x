#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
uint16_t Led7Seg[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void delay(unsigned int time){
	unsigned int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<0x2AFF;j++);
	}
}

void led_don(){
	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);
	
	/* cau hinh nut nhan*/
	gpio.GPIO_Mode = GPIO_Mode_IPU;
	gpio.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_3;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &gpio);
	
	/* cau hinh gpio*/
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_0;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &gpio);
}

int main(){
	int i=0;
	led_don();
	GPIO_Write(GPIOC, Led7Seg[0]);
	while(1){
			if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)==0){
				delay(2);
				if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)==0){
					if(i<9) i+=1;
					while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)==0);
					if(i == 9) GPIO_Write(GPIOC, Led7Seg[9]);
					else GPIO_Write(GPIOC, Led7Seg[i]);
				}
			}
			if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2)==0){
				delay(2);
				if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2)==0){
					if(i>=1) i-=1;
					while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2)==0);
					if(i == 0) GPIO_Write(GPIOC, Led7Seg[0]);
					else GPIO_Write(GPIOC, Led7Seg[i]);
				}
			}
	}
}

	
	
