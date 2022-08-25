#include "stm32f10x.h"
void delay(unsigned long t){while(t--);}
void cauhinhLED()
{   GPIO_InitTypeDef GPIO_InitStructure;  
    RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOD,ENABLE ); 
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;  
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz ;
    GPIO_Init(GPIOD,&GPIO_InitStructure);  
	
}
void cauhinhGPIOchoEXTI()
{   GPIO_InitTypeDef GPIO_InitStructure;  
    RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);  
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE); 
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8; 
    GPIO_InitStructure .GPIO_Mode = GPIO_Mode_IPU ; 
    GPIO_Init(GPIOA,&GPIO_InitStructure);   
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource8);  
}
void cauhinhEXTI()
{   EXTI_InitTypeDef EXTI_InitStructure; 
    EXTI_InitStructure.EXTI_Line = EXTI_Line8;  
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt; 
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling ; 
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;  
    EXTI_Init(&EXTI_InitStructure);   
}
void cauhinhNVICchoEXTI()
{   NVIC_InitTypeDef NVIC_InitStructure;   
 #ifdef VECT_TAB_RAM
    NVIC_SetVectorTable(NVIC_VectTab_RAM, 0x0);
  
 #else
    NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);
  
 #endif
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0 );  
    NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;  
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  
    NVIC_Init(&NVIC_InitStructure);
}

void EXTI9_5_IRQHandler()
{
   if(EXTI_GetITStatus(EXTI_IMR_MR8) != RESET)  
 {   EXTI_ClearITPendingBit(EXTI_IMR_MR8); 
     PWR_EnterSTANDBYMode();
 }
}
int main(void)
{  SystemInit ();
   cauhinhLED();
   cauhinhGPIOchoEXTI() ;
   cauhinhEXTI();
   cauhinhNVICchoEXTI();
   PWR_WakeUpPinCmd(ENABLE ); 
 while(1)
 {
   GPIO_SetBits(GPIOD,GPIO_Pin_2); delay(500000);
   GPIO_ResetBits(GPIOD,GPIO_Pin_2); delay(500000);
 }
}
