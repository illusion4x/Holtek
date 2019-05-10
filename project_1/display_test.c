#include 'config.h'
#include 'display.h'
#include 'TM1730.h'

void dis_1(){
	if(area_2_blink_buf! =  blink_flag){
		if(n >= 5){
			n = 0;
			dis_buf[area_2_addr] = dis_buf[area_2_addr] & (0x07);
		}
		else{
			area_2_blink_buf = blink_flag;
			dis_buf[area_2_addr] = dis_buf[area_2_addr] | (0x8<<n);
			//dis_buf[area_2_addr] = dis_buf[area_2_addr] ;
			n++;
		}

	}
}

void main(){
	//set TM to 4ms
	_tm1 = 1; //set to timer mode 
	_psc2 = 1;
	_psc1 = 1; //prescaler should be set to 1/64 psc = 110
	_tmr = 6;//the tmr should be 6 : 250 * 16 = 4000us for it is a count up 8 bit timer 
	_ton = 1;// open timer

	//init LCD
	TM1730_W_cmd(dis_16_8_int_0);
	TM1730_W_cmd(normal_on);

	while(1){
		dis_1();
		TM1730_W_byte(0x03,dis_buf[0x03]);
	}

}

void __attribute((interrupt(0x08))) ISR_tmr0 (void){
	static unsigned char time_count = 0;
	time_count ++;
	if(time_count >= 250){
		time_count = 0;
		blink_flag = ~blink_flag;
		/*if(key_heat_flag){
			key_heat_2_time++;
		}
		else{
			key_heat_2_time = 0;
		}*/
	}

}