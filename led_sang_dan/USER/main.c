#include "stm32f10x.h"

uint16_t sangdan[8] = {0xFE, 0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x00};
uint16_t toidan[8] =  {0xFE, 0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x00};
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
	  int i;
	 for(i = 0; i<8;i++){
    GPIO_Write(GPIOA, sangdan[i]); 
		 delay(10);
	 }
	 for(i = 7; i >= 0;i--){
    GPIO_Write(GPIOA, toidan[i]); 
		 delay(10);
	 }
	 for(i = 7; i>=0;i--){
    GPIO_Write(GPIOA, sangdan[i]); 
		 delay(10);
	 }
	 for(i = 0; i <8;i++){
    GPIO_Write(GPIOA, toidan[i]); 
		 delay(10);
	 }
 }
}
