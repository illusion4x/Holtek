
#define normal_mode
#define hot_set_mode
#define cool_set_mod=-0-76
#define time_real_set
#define time_on_setting

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

#define key_group1.b1 key_heat_up
#define key_group1.b2 key_cool_down
#define key_group1.b3 key_set
#define key_group1.b4 key_ok
#define key_group1.b5 key_heat_2

typedef struct{
	u8 hot;
	u8 cool;
}temp_struct;

time_struct temp_real;//2B
time_struct temp_set;//2B

typedef struct {	
	u8 hour;
	u8 min;
}time_struct;

time_struct time_real;//2B
time_struct time_on;//2B
time_struct time_off;//2B

u8 time_setting;kk







