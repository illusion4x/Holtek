#include 'main.h'

void main(){
	


	//adc part
	_acsr = ADC_speed_2fast;
	_pcr1 = 1; // set PB0-PB1 to AN0-AN1
	_eadi = 1; // open ADC_isr
	_eti =  1; // open TM_isr
	_emi = 1; // open global isr
	

	//set TM to 1ms
	_tm1 = 1; //set to timer mode 
	_psc2 = 1;
	_psc1 = 1; //prescaler should be set to 1/64 psc = 110
	_tmr = 6;//the tmr should be 6 : 250 * 16 = 4000us for it is a count up 8 bit timer 
	_ton = 1;// open timer


	
	while(1){



	}
}

void 


void key_process(){
	
	key_group1 = TM1730_R_key();

	if(key_heat_up){//key_time 

	}
	
	switch(mode){
		case normal_mode :
			if(key_heat_up){
				heat_flag = !heat_flag;
				key_heat_up = 0;
			}
			
			if(key_cool_down){
				cool_flag = !cool_flag;
				key_cool_down = 0;
			}
				
			if(key_set){
				mode = 1;
				key_set = 0;
			}

			if(key_heat_2){
				heat_2_flag = !heat_2_flag;
			}

			//enter sunday mode
			
			break;

		case hot_set_mode:
			//key 
			if(key_heat_up){
				temp_set.hot++;
				key_heat_up = 0;
			}
			else if(key_cool_down){
				temp_set.hot--;
				key_cool_down = 0;
			}

			if(temp_set.hot<52){
				temp_set.hot = 52;
			}
			else if(temp_set.hot>95){
				temp_set.hot = 95;
			}

			//display and blink

			if(key_set){
				key_set = 0;
			}
			if(key_ok){
				mode ++;
				EEPROM_W(temp_set_hot_addr,temp_set.hot);//save to eeprom
				key_ok = 0
			}

			if(time_setting){
				EEPROM_W(temp_set_hot_addr,temp_set.hot);//save to eeprom
				mode = 1;
			}

			break;
			
		case cool_set_mode:
			if(key_heat_up){
				temp_set.cool++;
				key_heat_up = 0;
			}
			else if(key_cool_down){
				temp_set.cool--;
				key_cool_down = 0;
			}

			if(temp_set.cool<4){
				temp_set.hot = 4;
			}
			else if(temp_set.hot>15){
				temp_set.hot = 15;
			}

			//display and blink
			if(key_set){
				key_set = 0;
			}

			if(key_ok){
				mode ++;
				EEPROM_W(temp_set_cool_addr,temp_set.cool);//save to eeprom
				key_ok = 0
			}
			//>10s
			if(time_setting){
				EEPROM_W(temp_set_cool_addr,temp_set.cool);//save to eeprom
				mode = 1;
			}
			break;

		
		case time_real_hour_set_mode : 
			if(key_heat_up){
				time_real.hour;++;
				key_heat_up = 0;
			}
			else if(key_cool_down){
				time_real.hour--;
				key_cool_down = 0;
			}

			if(time_real.hour>23){
				time_real.hour = 0;
			}
			else if(time_real.hour){
				time_real.hour = 23;
			}

			//display and blink

			if(key_set){
				mode ++;
				key_set = 0;
			}

			if(key_ok){
				key_ok = 0;
			}
			//>10s
			if(time_setting){
				//quit
			}
			break;
			
		case time_real_min_set_mode : 
			if(key_heat_up){
				time_real.min;++;
				key_heat_up = 0;
			}
			else if(key_cool_down){
				time_real.min--;
				key_cool_down = 0;
			}

			if(time_real.min>59){
				time_real.min = 0;
			}
			else if(time_real.min<0){
				time_real.min = 59;
			}

			//display and blink
			if(key_set){
				key_set = 0;
			}

			if(key_ok){
				mode ++;
				
				key_ok = 0;
			}
			//>10s
			if(time_setting){
				
			}
			break;
			
		case time_on_hour_set_mode : 
			if(key_heat_up){
				time_on.hour;++;
				key_heat_up = 0;
			}
			else if(key_cool_down){
				time_on.hour--;
				key_cool_down = 0;
			}

			
			if(time_on.hour>23){
				time_on.hour = 0;
			}
			else if(time_on.hour<0){
				time_on.hour =23;
			}

			//display and blink
			if(key_ok){
				key_ok = 0;
			}

			if(key_set){
				mode ++;
				EEPROM_W(time_on_min_addr,time_on.hour);//save to eeprom
				key_set = 0;
			}
			//>10s
			if(time_setting){
				EEPROM_W(time_on_hour_addr,time_on.hour);//save to eeprom
			}
			break;
			
		case time_on_min_set_mode : 
			if(key_heat_up){
				time_on.min;++;
				key_heat_up = 0;
			}
			else if(key_cool_down){
				time_on.min--;
				key_cool_down = 0;
			}

			if(time_on.min>59){
				time_on.min = 0;
			}
			else if(time_on.min<0){
				time_on.min = 59;
			}

			//display and blink
			if(key_set){
				key_set = 0;
			}

			if(key_ok){
				mode ++;
				EEPROM_W(time_on_min_addr,time_on.min);//save to eeprom
				key_ok = 0;
			}
			//>10s
			if(time_setting){
				EEPROM_W(time_on_min_addr,time_on.min);//save to eeprom
			}
			break;

		case time_off_hour_set_mode : 
			if(key_heat_up){
				time_off.hour;++;
				key_heat_up = 0;
			}
			else if(key_cool_down){
				time_off.hour--;
				key_cool_down = 0;
			}

			
			if(time_off.hour>23){
				time_off.hour = 0;
			}
			else if(time_off.hour<0){
				time_off.hour =23;
			}

			//display and blink
			if(key_set){
				key_ok = 0;
			}

			if(key_set){
				mode ++;
				EEPROM_W(time_off_hour_addr,time_off.hour);//save to eeprom
				key_set = 0;
			}
			//>10s
			if(time_setting){
				EEPROM_W(time_off_hour_addr,time_off.hour);//save to eeprom
			}
			break;
			
		case time_off_min_set_mode : 
			if(key_heat_up){
				time_off.min;++;
				key_heat_up = 0;
			}
			else if(key_cool_down){
				time_off.min--;
				key_cool_down = 0;
			}

			if(time_off.min>59){
				time_off.min = 0;
			}
			else if(time_off.min<0){
				time_off.min = 59;
			}

			//display and blink
			if(key_set){
				key_set = 0;
			}

			if(key_ok){
				mode ++;
				EEPROM_W(time_off_min_addr,time_off.min);//save to eeprom
				key_ok = 0;
			}
			//>10s
			if(time_setting){
				EEPROM_W(time_off_min_addr,time_off.min);//save to eeprom
			}
			break;

		case sunday_mode :
			if(key_set){
				mode = 1;
				key_set = 0;
			}
			
			//clear key
			key_ok = 0;
			key_cool_down = 0;
			key_heat_up = 0;
	
			//key to quit sunday_mode
		 
		default:
			mode = 0;
			break;

	}
}



void __attribute((interrupt(0x08))) ISR_tmr0 (void){
	timer_count
}

void __attribute((interrupt(0x0C))) ISR_adc (void){

}
