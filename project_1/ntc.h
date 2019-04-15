
#ifndef _NTC_H
	#define _NTC_H
	
#define hot_sensor_pin
#define cool_sensor_pin


#define ADC_speed_2fast 0x01
#define ADC_speed_3slow 0x02

void ntc_init();//init adc
unsigned int ntc_convert(ch);//start adc convert
unsigned char temp_convert(); //calculate the temp via table


#endif