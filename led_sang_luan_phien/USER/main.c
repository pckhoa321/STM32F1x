#include "stm32f10x.h"

void cauhinhLED()
{   GPIO_InitTypeDef gpio;  
    RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA,ENABLE ); 
    gpio.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7; 
    gpio.GPIO_Mode = GPIO_Mode_Out_PP ;  
    gpio.GPIO_Speed = GPIO_Speed_50MHz ;
    GPIO_Init(GPIOA,&gpio);  
	
}

void delay(unsigned int time)
{
	unsigned int i,j;
	for(i = 0;i <time;i++){
		for(j=0;j <0x2AFF;j++){}
		}
}
int main(void)
{ 
   cauhinhLED();
    while(1)
 {
   GPIO_Write(GPIOA, 0xAA); delay(50);
   GPIO_Write(GPIOA, 0x55); delay(50);
 }
}
