//version 1.0
//it do not care if it is success or not
#ifndef _TM1730_H
	#define _TM1730_H

	#include <ht46F47.h>
	#include 'I2C.h'
	
#define TM1730_addr_W 0xE6 // contain the R/W bit
#define TM1730_addr_R 0xE7

#define key_addr1 0x20 
#define key_addr2 0x21
#define key_addr3 0x22
//define CMD

#define normal_on   0x83
#define normal_off  0x81
#define idle_on     0x82
#define idle_off    0x80


#define dis_20_4_int_0 0xA2
#define dis_20_4_int_1 0xA6
#define dis_20_4_com_0 0xA0
#define dis_16_8_int_0 0xA3
#define dis_16_8_int_1 0xA7
#define dis_16_8_com_0 0xA5

#define key_scan 0xF8

void TM1730_W_cmd(unsigned char cmd);
void TM1730_W_byte(unsigned char reg_addr,unsigned char dat );
void TM1730_W_page(unsigned char start_reg,unsigned char end_reg, unsigned char *dat );
unsigned char TM1730_R_key();//typical for the key group
	
#endif	