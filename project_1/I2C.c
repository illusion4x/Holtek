//I2C
//start fun is contained in the read or write function
//typical for 4M HT46F47E
//t = 1us-2us

#include 'I2C.h'

u8 I2C_R_Byte(u8 Decive_addr,u8 Reg_addr){
	
	//start 
	SDA = 1;
	SCL = 1;
	_delay();
	SDA = 0;
	_delay();
	SCL = 0;
	
	//Device addr
	for(mask = 0x80; mask != 0;)
	
	
	
	
	
}
