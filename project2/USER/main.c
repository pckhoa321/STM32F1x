#include<stm32f10x.h>
void delay(unsigned long t){while(t--);}
void cauhinhGPIO()
{
 GPIO_InitTypeDef GPIO;
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA
 |RCC_APB2Periph_GPIOD|RCC_APB2Periph_AFIO,ENABLE );
 RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
 // Cho phép c?p ngu?n cho b? di?u khi?n nang lu?ng
 GPIO.GPIO_Pin = GPIO_Pin_8;
 GPIO.GPIO_Mode = GPIO_Mode_IPU ;
 GPIO_Init (GPIOA,&GPIO);
 GPIO.GPIO_Pin= GPIO_Pin_9;
 GPIO.GPIO_Mode = GPIO_Mode_Out_PP ;
 GPIO.GPIO_Speed = GPIO_Speed_50MHz ;
 GPIO_Init (GPIOD,&GPIO);
 GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,
 GPIO_PinSource8 );
}
void cauhinhEXTI()
{
 EXTI_InitTypeDef NN;
 NN.EXTI_Line= EXTI_Line8 ;
 NN.EXTI_Mode= EXTI_Mode_Event; // Ch? d? s? ki?n
 NN.EXTI_Trigger = EXTI_Trigger_Falling ;
 NN.EXTI_LineCmd = ENABLE;
	EXTI_Init(&NN);
}
int main()
{
 SystemInit();
 cauhinhGPIO();
 cauhinhEXTI();
 while(1)
 {
 // Ðua CPU vào ch? d? Stop b?ng WFE
 PWR_EnterSTOPMode(PWR_Regulator_LowPower
 ,PWR_STOPEntry_WFE);
 //Khi CPU thoát kh?i Stop thì c?u hình l?i xung clock
 SystemInit();
 GPIO_SetBits(GPIOD,GPIO_Pin_9);delay(5000000);
 GPIO_ResetBits(GPIOD,GPIO_Pin_9); delay(5000000);
 }
}