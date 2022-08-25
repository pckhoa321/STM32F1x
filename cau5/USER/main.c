#include "stm32f10x.h"                  // Device header
#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC

int i,j,k;
void Delay_ms(uint16_t _time);
void led_Init(void);
void button_Init(void);
void nhan_button(void);
void nhap_nhay(void);
void trai_sang_phai(void);

int macdinh=1;
int hientai;
int dem=-1;
int sang_dan_trai_phai[8]={0xFFFE, 0XFFF0,0XFFF8,0XFFF0,0XFFE0,0XFFC0,0XFF80,0XFF00};

int main(){
		led_Init();
		button_Init();
		while(1){
				nhan_button();
	
	}
}

void Delay_ms(uint16_t _time){
		uint16_t i,j;
		for(i = 0; i < _time; i++){
			for(j = 0; j < 0x2AFF; j++);
	}
}

void led_Init(void){
	
		GPIO_InitTypeDef led_init;
		
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

		
		led_init.GPIO_Mode = GPIO_Mode_Out_PP;
		led_init.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|
												GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
		led_init.GPIO_Speed = GPIO_Speed_50MHz;
		
		GPIO_Init(GPIOB,&led_init);
		GPIO_Write(GPIOB, 0xFFFF);
//		GPIOB->ODR = 0Xffff;
}
// CAU hinh button
void button_Init(void){
		GPIO_InitTypeDef button_init;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		button_init.GPIO_Mode = GPIO_Mode_IPU;
		button_init.GPIO_Pin = GPIO_Pin_1;
		button_init.GPIO_Speed = GPIO_Speed_50MHz;
		
		GPIO_Init(GPIOA,&button_init);
}

void trai_sang_phai(void){
		int i;
		for(i=0;i<8;i++){
		GPIO_Write(GPIOB,sang_dan_trai_phai[i]);
			Delay_ms(10);
		}
		GPIO_Write(GPIOB, 0xFFFF);
		//GPIOB-> ODR=0xffff;
		Delay_ms(10);
}

void nhap_nhay(void){
	GPIO_ResetBits(GPIOB,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|
												GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);
		//GPIO_Write(GPIOB, 0x0000);
	//GPIOB-> ODR=0x0000;
		Delay_ms(10);
	GPIO_SetBits(GPIOB, GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|
												GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);
	//	GPIO_Write(GPIOB, 0xFFFF);
	//GPIOB-> ODR=0xffff;
		Delay_ms(10);
}
void nhan_button(void){
	
		hientai= GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1);
		if(hientai != macdinh)
		{ 
				if(hientai==0){
						dem+=1;
				}
		macdinh	= hientai;
		}
		if((dem%2)==0){
				trai_sang_phai();
		}
		if((dem%2)==1){nhap_nhay();
		}

}
