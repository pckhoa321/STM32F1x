#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
void GPIOA_Configure(){
	//Cap clock cho portA
	RCC->APB2ENR |=0X4;
	//khai bao chan,che do, toc do cho CRL
	GPIOA ->CRL|= 0x0;
	GPIOA ->CRL|= 0x33333333;
	//khai bao chan,che do, toc do cho CRH
	GPIOA ->CRH|= 0x0;
	GPIOA ->CRH|= 0x33333333;
}

void GPIOB_Configure(){
	//Cap clock cho portB
	RCC->APB2ENR |=0x8;
	//khai bao chan,che do, toc do cho CRL
	GPIOB ->CRL|= 0x0;
	GPIOB ->CRL|= 0x33333333;
		//khai bao chan,che do, toc do cho CRH
	GPIOB ->CRH|= 0x0;
	GPIOB ->CRH|= 0x33333333;
}

void delay(int time){
	for(int i=0;i<time;i++)
		for(int j=0;j<0x2AFF;j++);
}
//mang chay sang dan 2 phia
int mang[]= {0xFFFC,0xFFF8,0xFFF0,0xFFE0,0xFFC0,0XFF80,0XFF00,0XFE00,0XFC00,0XF800,0XF000,0XE000,0XC000,0X8000,0X0};
int mang2[]={0x7FFF,0x3FFF,0x1FFF,0X0FFF,0x07FF,0x03FF,0X01FF,0X00FF,0X007F,0X003F,0X001F,0X000F,0X0007,0X0003,0X001};
//mang sang vong tron
int mang3[]={0xFFFE,0xFFFC,0xFFF8,0xFFF0,0xFFE0,0XFFC0,0XFF80,0XFF00,0XFE00,0XFC00,0XF800,0XF000,0XE000,0XC000,0X8000,0X0};
//mang sang chia lam 4(sang xuoi)
int mang4[]={0xFEFE,0xFDFD,0xFBFB,0xF7F7,0xEFEF,0XDFDF,0XBFBF,0X7F7F};
// sang nhap nhay 4 goc(sang nguoc)
int mang5[]={0x7F7F,0XBFBF,0XDFDF,0XEFEF,0XF7F7,0XFBFB,0XFDFD,0XFEFE};
void sangnguoc(){
		for(int j=0;j<8;j++){
			GPIOA->ODR &=mang5[j];
			GPIOB->ODR &=mang5[j];
			delay(5);
		}
}

void sangvongtron(){
	//sang tu PA0-PA15
	for(int i=0;i<16;i++){
			GPIOA->ODR &= mang3[i];
			delay(3);
		}
		//tiep den chay sang dan trai tim vong tron o portB
		for(int i=0;i<16;i++){
			GPIOB->ODR &= mang3[i];
			delay(3);
		}
}

void sang2phia(){
	//led dau tien o giua sang
	GPIOA->ODR &=0XFFFE;
			delay(2);
			//chay trai tim toa sang dan sang 2 ben
		for(int i=0;i<14;i++){
			GPIOA->ODR &= mang[i];
			GPIOB->ODR &= mang2[i];
			delay(2);
		}
		//led duoi cung sang len
		GPIOB->ODR &=0X0000;
			delay(2);
		for(int i=3;i>0;i--){
			GPIOA ->ODR |=0xFFFF;
			GPIOB ->ODR |=0xFFFF;
			delay(5);
			GPIOA ->ODR &=~0xFFFF;
			GPIOB ->ODR &=~0xFFFF;
			delay(5);
		}
}
int main(){
		GPIOA_Configure();
		GPIOB_Configure();
		while(1){
			//tat tat cac cac led
			GPIOA->ODR |=0XFFFF;
			GPIOB->ODR |=0XFFFF;
			sangnguoc();
			//tat tat cac cac led
			GPIOA->ODR |=0XFFFF;
			GPIOB->ODR |=0XFFFF;
			sangvongtron();
			//tat tat cac cac led
			GPIOA->ODR |=0XFFFF;
			GPIOB->ODR |=0XFFFF;
			sang2phia();	
	}
}