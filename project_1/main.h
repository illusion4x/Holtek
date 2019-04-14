#define _MAIN_H

#ifndef _MAIN_H
	#define _MAIN_H



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

const u8 num_coding_67910[10] = {0x77,0x24,0x5D,0x6D,0x2E,0X6B,0xFB,0x25,0xEF,0x2F};//0-9
const u8 num_coding_1234[10] = {0x6E,0xBC,0xD6,0xDA,0x78,0xBA,0xBE,0xC8,0xFE,0xF8};//0-9




typedef unsigned char u8;
typedef unsigned int u16;

typedef struct{
	volatile u8 b0:1;
	volatile u8 b1:1;
	volatile u8 b2:1;
	volatile u8 b3:1;
	volatile u8 b4:1;
	volatile u8 b5:1;
	volatile u8 b6:1;
	volatile u8 b7:1;
}bits;

typedef union{
	bits B;
	u8 data;
}key_group;

key_group key_group1;

#define  key_heat_up      key_group1.B.b1
#define  key_cool_down    key_group1.B.b2
#define  key_set          key_group1.B.b3
#define  key_ok           key_group1.B.b4
#define  key_heat_2       key_group1.B.b5 

typedef struct{
	u8 hot;
	u8 cool;
}temp_struct;

temp_struct temp_real;//2B
temp_struct temp_set;//2B

typedef struct {	
	u8 hour;
	u8 min;
}time_struct;

time_struct time_real;//2B
time_struct time_on;//2B
time_struct time_off;//2B

u8 time_setting;

bit heat_flag;
bit cool_flag;


#define heat_pin 
#define cool_pin
#define temp_hot_pin
#define temp_cool_pin
#define buzzer_pin 











