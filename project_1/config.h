#ifndef _CONFIG_H
	#define _CONFIG_H
#include <ht46F47.h>
#define normal_mode 0
#define hot_set_mode 1
#define cool_set_mod 2
#define time_real_hour_set_mode 3
#define time_real_min_set_mode 4
#define time_on_hour_set_mode 5
#define time_on_min_set_mode 6
#define time_off_hour_set_mode 7
#define time_off_min_set_mode 8

//the definition of LCD display ram address 


//coding for LCD

const unsigned char num_coding_67910[10] = {0x77,0x24,0x5D,0x6D,0x2E,0X6B,0xFB,0x25,0xEF,0x2F};//0-9
const unsigned char num_coding_1234[10] = {0x6E,0xBC,0xD6,0xDA,0x78,0xBA,0xBE,0xC8,0xFE,0xF8};//0-9


typedef struct{
	volatile unsigned char b0:1;
	volatile unsigned char b1:1;
	volatile unsigned char b2:1;
	volatile unsigned char b3:1;
	volatile unsigned char b4:1;
	volatile unsigned char b5:1;
	volatile unsigned char b6:1;
	volatile unsigned char b7:1;
}bits;

typedef union{
	bits B;
	unsigned char data;
}key_group;

key_group key_group1;

#define  key_heat_up      key_group1.B.b1
#define  key_cool_down    key_group1.B.b2
#define  key_set          key_group1.B.b3
#define  key_ok           key_group1.B.b4
#define  key_heat_2       key_group1.B.b5 

typedef struct{
	unsigned char hot;
	unsigned char cool;
}temp_struct;

temp_struct temp_real;//2B
temp_struct temp_set;//2B

typedef struct {	
	unsigned char hour;
	unsigned char min;
}time_struct;

time_struct time_real;//2B
time_struct time_on;//2B
time_struct time_off;//2B

unsigned char time_setting;

bit heat_flag;
bit cool_flag;


#define heat_pin
#define cool_pin
#define buzzer_pin

volatile 










