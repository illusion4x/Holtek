#include 'TM1730.h'


//via I2C
//all no ACK
//all no sub-fun

void TM1730_W_CMD(unsigned char CMD){
    unsigned char  mask ;
   
	//start 
	SDA = 1;
	SCL = 1;
	_nop();_nop();_nop();
	SDA = 0;
	_nop();_nop();_nop();
	SCL = 0;

	//seek device
	for(mask = 0x80; mask != 0; mask>>1){
		if(TM1730_addr_W && 0x80)
			SDA = 1;
		else 
			SDA = 0;

		SCL = 1;
		_nop();_nop();_nop();
		SCL = 0;
	}

	SDA = 1;
	_nop();_nop();_nop();
	SCL = 1;
	_nop();_nop();_nop();
	SCL = 0;

	for(mask = 0x80; mask != 0; mask>>1){
		if(CMD && 0x80)
			SDA = 1;
		else 
			SDA = 0;

		SCL = 1;
		_nop();_nop();_nop();
		SCL = 0;
	}

	SDA = 1;
	_nop();_nop();_nop();
	SCL = 1;
	_nop();_nop();_nop();
	
    // stop
	SCL = 0;
	SDA = 0;
	_nop();_nop();_nop();
	SCL = 1;
	_nop();_nop();_nop();
	SDA = 1;

}


void TM1730_W_RAM(unsigned char RAM_addr,unsigned char data){
    unsigned char mask ;
   
	//start 
	SDA = 1;
	SCL = 1;
	_nop();_nop();_nop();
	SDA = 0;
	_nop();_nop();_nop();
	SCL = 0;

	//seek device
	for(mask = 0x80; mask != 0; mask>>1){
		if(TM1730_addr_W && 0x80)
			SDA = 1;
		else 
			SDA = 0;

		SCL = 1;
		_nop();_nop();_nop();
		SCL = 0;
	}

	SDA = 1;
	_nop();_nop();_nop();
	SCL = 1;
	_nop();_nop();_nop();
	SCL = 0;

	//write RAM addr
	for(mask = 0x80; mask != 0; mask>>1){
		if(RAM_addr && 0x80)
			SDA = 1;
		else 
			SDA = 0;

		SCL = 1;
		_nop();_nop();_nop();
		SCL = 0;
	}

	SDA = 1;
	_nop();_nop();_nop();
	SCL = 1;
	_nop();_nop();_nop();

	// write data
	for(mask = 0x80; mask != 0; mask>>1){
		if(data && 0x80)
			SDA = 1;
		else 
			SDA = 0;

		SCL = 1;
		_nop();_nop();_nop();
		SCL = 0;
	}

	SDA = 1;
	_nop();_nop();_nop();
	SCL = 1;
	_nop();_nop();_nop();

	
    // stop
	SCL = 0;
	SDA = 0;
	_nop();_nop();_nop();
	SCL = 1;
	_nop();_nop();_nop();
	SDA = 1;

}

//not generous purpose function
unsigned char TM1730_R_key(){
	unsigned char mask ;
    unsigned char dat;
	//start 
	SDA = 1;
	SCL = 1;
	_nop();_nop();_nop();
	SDA = 0;
	_nop();_nop();_nop();
	SCL = 0;

	//seek device
	for(mask = 0x80; mask != 0; mask>>1){
		if(TM1730_addr_W && 0x80)
			SDA = 1;
		else 
			SDA = 0;

		SCL = 1;
		_nop();_nop();_nop();
		SCL = 0;
	}

	SDA = 1;
	_nop();_nop();_nop();
	SCL = 1;
	_nop();_nop();_nop();
	SCL = 0;

	//write RAM addr
	for(mask = 0x80; mask != 0; mask>>1){
		if(key_addr1 && 0x80)
			SDA = 1;
		else 
			SDA = 0;

		SCL = 1;
		_nop();_nop();_nop();
		SCL = 0;
	}

	SDA = 1;
	_nop();_nop();_nop();
	SCL = 1;
	_nop();_nop();_nop();


	// stop
	SCL = 0;
	SDA = 0;
	_nop();_nop();_nop();
	SCL = 1;
	_nop();_nop();_nop();
	SDA = 1;
	
	_nop();_nop();_nop();

	//start 
	SDA = 1;
	SCL = 1;
	_nop();_nop();_nop();
	SDA = 0;
	_nop();_nop();_nop();
	SCL = 0;

	//seek device
	for(mask = 0x80; mask != 0; mask>>1){
		if(TM1730_addr_W && 0x80)
			SDA = 1;
		else 
			SDA = 0;

		SCL = 1;
		_nop();_nop();_nop();
		SCL = 0;
	}

	SDA = 1;
	_nop();_nop();_nop();
	SCL = 1;
	_nop();_nop();_nop();
	SCL = 0;

	//0x20 Read
	for(mask = 0x80; mask != 0; mask>>1){
		_nop();_nop();_nop();
		SCL = 1;
		if(SDA == 0)
			dat &= ~mask;
		else
			dat |= mask;;

		_nop();_nop();_nop();
		SCL = 0;
	}

	//send ack 
	SDA = 0;
	_nop();_nop();_nop();
	SCL = 1;
	_nop();_nop();_nop();
	SCL = 0;
	//0x21
	for(mask = 0x80; mask != 0; mask>>1){
		_nop();_nop();_nop();
		SCL = 1;
		/*if(SDA == 0)
			dat &= ~mask;
		else
			dat |= mask;;
		*/
		_nop();_nop();_nop();
		SCL = 0;

	}
	
	//send ack 
	SDA = 0;
	_nop();_nop();_nop();
	SCL = 1;
	_nop();_nop();_nop();
	SCL = 0;

	//0x22
	for(mask = 0x80; mask != 0; mask>>1){
		_nop();_nop();_nop();
		SCL = 1;
		/*if(SDA == 0)
			dat &= ~mask;
		else
			dat |= mask;;
		*/
		_nop();_nop();_nop();
		SCL = 0;
	}

	//send ack 
	SDA = 0;
	_nop();_nop();_nop();
	SCL = 1;
	_nop();_nop();_nop();
	SCL = 0;


    // stop
	SCL = 0;
	SDA = 0;
	_nop();_nop();_nop();
	SCL = 1;
	_nop();_nop();_nop();
	SDA = 1;

	return dat;

}









