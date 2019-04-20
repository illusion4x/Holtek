#include 'TM1730.h'

void TM1730_W_cmd(unsigned char cmd){
  
   	I2C_start();
   	if(I2C_seek_device(TM1730_addr_W)){
   		I2C_W(cmd);
   	}
   	I2C_stop();

}

void TM1730_W_byte(){

}

void TM1730_W_page(){

}


void TM1730_W_RAM(unsigned char RAM_addr,unsigned char data){
    unsigned char mask ;
   
	//start 
	SDA = 1;
	SCL = 1;
	delay_nop();
	SDA = 0;
	delay_nop();
	SCL = 0;

	//seek device
	for(mask = 0x80; mask != 0; mask>>1){
		if(TM1730_addr_W && 0x80)
			SDA = 1;
		else 
			SDA = 0;

		SCL = 1;
		delay_nop();
		SCL = 0;
	}

	SDA = 1;
	delay_nop();
	SCL = 1;
	delay_nop();
	SCL = 0;

	//write RAM addr
	for(mask = 0x80; mask != 0; mask>>1){
		if(RAM_addr && 0x80)
			SDA = 1;
		else 
			SDA = 0;

		SCL = 1;
		delay_nop();
		SCL = 0;
	}

	SDA = 1;
	delay_nop();
	SCL = 1;
	delay_nop();

	// write data
	for(mask = 0x80; mask != 0; mask>>1){
		if(data && 0x80)
			SDA = 1;
		else 
			SDA = 0;

		SCL = 1;
		delay_nop();
		SCL = 0;
	}

	SDA = 1;
	delay_nop();
	SCL = 1;
	delay_nop();

	
    // stop
	SCL = 0;
	SDA = 0;
	delay_nop();
	SCL = 1;
	delay_nop();
	SDA = 1;

}

//not generous purpose function
unsigned char TM1730_R_key(){
	unsigned char mask ;
    unsigned char dat;
	//start 
	SDA = 1;
	SCL = 1;
	delay_nop();
	SDA = 0;
	delay_nop();
	SCL = 0;

	//seek device
	for(mask = 0x80; mask != 0; mask>>1){
		if(TM1730_addr_W && 0x80)
			SDA = 1;
		else 
			SDA = 0;

		SCL = 1;
		delay_nop();
		SCL = 0;
	}

	SDA = 1;
	delay_nop();
	SCL = 1;
	delay_nop();
	SCL = 0;

	//write RAM addr
	for(mask = 0x80; mask != 0; mask>>1){
		if(key_addr1 && 0x80)
			SDA = 1;
		else 
			SDA = 0;

		SCL = 1;
		delay_nop();
		SCL = 0;
	}

	SDA = 1;
	delay_nop();
	SCL = 1;
	delay_nop();


	// stop
	SCL = 0;
	SDA = 0;
	delay_nop();
	SCL = 1;
	delay_nop();
	SDA = 1;
	
	delay_nop();

	//start 
	SDA = 1;
	SCL = 1;
	delay_nop();
	SDA = 0;
	delay_nop();
	SCL = 0;

	//seek device
	for(mask = 0x80; mask != 0; mask>>1){
		if(TM1730_addr_W && 0x80)
			SDA = 1;
		else 
			SDA = 0;

		SCL = 1;
		delay_nop();
		SCL = 0;
	}

	SDA = 1;
	delay_nop();
	SCL = 1;
	delay_nop();
	SCL = 0;

	//0x20 Read
	for(mask = 0x80; mask != 0; mask>>1){
		delay_nop();
		SCL = 1;
		if(SDA == 0)
			dat &= ~mask;
		else
			dat |= mask;;

		delay_nop();
		SCL = 0;
	}

	//send ack 
	SDA = 0;
	delay_nop();
	SCL = 1;
	delay_nop();
	SCL = 0;
	//0x21
	for(mask = 0x80; mask != 0; mask>>1){
		delay_nop();
		SCL = 1;
		/*if(SDA == 0)
			dat &= ~mask;
		else
			dat |= mask;;
		*/
		delay_nop();
		SCL = 0;

	}
	
	//send ack 
	SDA = 0;
	delay_nop();
	SCL = 1;
	delay_nop();
	SCL = 0;

	//0x22
	for(mask = 0x80; mask != 0; mask>>1){
		delay_nop();
		SCL = 1;
		/*if(SDA == 0)
			dat &= ~mask;
		else
			dat |= mask;;
		*/
		delay_nop();
		SCL = 0;
	}

	//send ack 
	SDA = 0;
	delay_nop();
	SCL = 1;
	delay_nop();
	SCL = 0;


    // stop
	SCL = 0;
	SDA = 0;
	delay_nop();
	SCL = 1;
	delay_nop();
	SDA = 1;

	return dat;

}









