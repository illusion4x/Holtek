
void mode_fun(){
	
	switch(mode){
		case normal_mode :
			if(key_heat_up){
				//heat_up
				key_heat_up = 0;
			}

			if(key_cool_down){
				//interval 5min
				//cool down
				key_cool_down = 0;
			}

			if(key_set){

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

		case time_set : 
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
		case time_real_set : 
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
		case time_on_set : 
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
		case time_set : 
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
		case time_set : 
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

		case sys_off:
		 


	}
}

void key_scan(){
	
	//read from chip
	
	
	
}