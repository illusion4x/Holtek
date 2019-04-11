
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
