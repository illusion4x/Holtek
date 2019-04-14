#include 'main.h'

void main(){
	
}




void key_process(){
	
	switch(mode){
		case normal_mode :
			if(key_heat_up){
				if(temp_real<95){
					
				}
				else{
					
				}//heat_up
				key_heat_up = 0;
			}
			
			if(key_cool_down){
				if(temp_real>4&&)//interval 5min
				//cool down
				key_cool_down = 0;
			}
				
			if(key_set){
				mode = 1;
				key_set = 0;
			}

			if(key_heat_2){
		
			}
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


			if(key_ok){
				mode ++;
				//save to eeprom
				key_ok = 0
			}

			if(time_setting){
				//save to eeprom
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

			if(key_ok){
				mode ++;
				//save to eeprom
				key_ok = 0
			}
			//>10s
			if(time_setting){
				//save to eeprom
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
				//save to eeprom
				key_set = 0;
			}
			//>10s
			if(time_setting){
				//save to eeprom
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

			if(key_ok){
				mode ++;
				//save to eeprom
				key_ok = 0;
			}
			//>10s
			if(time_setting){
				//save to eeprom
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

			if(key_set){
				mode ++;
				//save to eeprom
				key_set = 0;
			}
			//>10s
			if(time_setting){
				//save to eeprom
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

			if(key_ok){
				mode ++;
				//save to eeprom
				key_ok = 0;
			}
			//>10s
			if(time_setting){
				//save to eeprom
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
				mode ++;
				//save to eeprom
				key_set = 0;
			}
			//>10s
			if(time_setting){
				//save to eeprom
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

			if(key_ok){
				mode ++;
				//save to eeprom
				key_ok = 0;
			}
			//>10s
			if(time_setting){
				//save to eeprom
			}
			break;
		 
		default:
			mode = 0;
			break;

	}
}

