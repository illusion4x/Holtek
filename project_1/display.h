#ifndef _DISPLAY_H
#define _DISPLAY_H

	#include 'config.h'

#define cool_pattern 0x80
#define heat_pattern 0x80
#define area_2_addr 0x03


extern bit blink_flag;

bit area_2_blink_buf = 0;

//Define the display area 
const unsigned char num_coding_67910[10] = {0x77,0x24,0x5D,0x6D,0x2E,0X6B,0xFB,0x25,0xEF,0x2F};//0-9
const unsigned char num_coding_1234[10] = {0x6E,0xBC,0xD6,0xDA,0x78,0xBA,0xBE,0xC8,0xFE,0xF8};//0-9



void dis_scan();


#endif // !_DISPLAY_H
