#include "HT66F0185.h"

#define LED _pa3    
#define KEY1 _pc4                                                    

typedef unsigned int u16;
typedef unsigned int u8;

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
	
	//set Tm0
	_tm0c0 = 0x30; // set f = 1/64
	_tm0c1 = 0xc1;//timer mode and ccra match
	_tm0al = 625 & 0xFF;//must write to Low 8-bit
	_tm0ah = 625>>8;
	_mf0e = 1; // multi-fun isr enable
	_t0ae = 1; // tm0 isr enable
	_emi = 1;// EMI 
	_t0on = 1; //open tm0
	
	while(1){
		/*if(KEY1 == 0){
			delay_ms(50);
			if(KEY1 == 0){
				LED = ~LED;	
			}
		}		
		*/
	};
}
//remember this function,it is defined in header file
DEFINE_ISR(t0isr,0x0c){
	static u8 num = 0;
	if(_t0af){
		_t0af = 0;
		num++;
		if(num>200){
			LED = ~LED;
			num = 0;
			}	
	}
}
