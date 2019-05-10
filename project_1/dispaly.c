 //this file define function to display 
#include 'display.h'

Byte_group dis_buf[12] ;

//display center parton
void dis_1(){
	if(area_2_blink_buf! =  blink_flag){
		if(n >= 5){
			n = 0;
			dis_buf[area_2_addr] = dis_buf[area_2_addr] & (0x07);
		}
		else{
			area_2_blink_buf = blink_flag;
			dis_buf[area_2_addr] = dis_buf[area_2_addr] | (0x8<<n);
			n++;
		}

	}
}

/*
//when normal display
void dis_ram(){
	
	siwtch(mode){
		case normal_mode:
		case hot_set_mode:
		case cool_set_mod:
	}


}

*/

