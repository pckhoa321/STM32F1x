#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
void GPIOC_Configure(){
	GPIO_InitTypeDef gpio;
	//cap clock 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &gpio);
}
void delay(int time){
	for(int i = 0; i< time; i++){
		for(int j = 0; j< 0x2AFF; j++);
	}
}
int  Led7Seg[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
int main(){
	GPIOC_Configure();
	while(1){
		for(int i = 0; i < 10; i++){
			GPIO_Write(GPIOC, Led7Seg[i]);
			delay(50);
		}
	}
}
