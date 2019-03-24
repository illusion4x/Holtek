#include "HT66F0185.h"

#define LED _pa3    
#define KEY1 _pc4                                                    

typedef unsigned int u16;

void delay_ms(u16 ms){
	while(ms--){
		GCC_DELAY(2000);
		GCC_CLRWDT();
	}	
}

void main()
{
	_wdtc = 0xa8;//关闭看门狗
	_pac3 = 0;
	_cos = 1;//设定pa3输出（同时屏蔽复用）
	_pcc4 = 1;//设定按键输入,上拉
	_pcpu4 = 1;
	
	LED = 1;
	
	while(1){
		if(KEY1 == 0){
			delay_ms(50);
			if(KEY1 == 0){
				LED = ~LED;	
			}
		}		
		
	}
}
//remember this function,it is defined in header file
DEFINE_ISR(t0isr,0x0c){
		
}
