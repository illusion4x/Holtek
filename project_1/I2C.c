#include 'I2C.h'



void I2C_start(){
	SDA = 1;
	SCL = 1;
	I2C_delay();
	SDA = 0;
	I2C_delay();
	SCL = 0;

}

void I2C_stop(){
	SCL = 0;
	SDA = 0; 
	I2C_delay();
	SDA = 1;
	I2C_delay();
	SCL = 1;
}

bit I2C_seek_device(unsigned char device_addr){
	unsigned char mask;
	for(mask = 0x80; mask != 0; mask>>=1){
			if((device_addr&0x80) != 0)
				SDA = 1;
			else 
				SDA = 0;

			SCL = 1;
			I2C_delay();
			SCL = 0;
		}

		SDA = 1;
		I2C_delay();
		SCL = 1;
		I2C_delay();
		
		if(SDA != 0){//if not detect the device return fail
			I2C_stop();
			return 0;
		}

		SCL = 0;	

		return 1;
}

bit I2C_W(unsigned char dat){
	unsigned char mask;

	for(mask = 0x80; mask != 0; mask>>=1){
		if((dat & 0x80) != 0)
			SDA = 1;
		else 
			SDA = 0;

		SCL = 1;
		I2C_delay();
		SCL = 0;
	}

	SDA = 1;
	I2C_delay();
	SCL = 1;
	I2C_delay();
	if(SDA != 0){//if not detect the device return fail
		return 0;
	}
	SCL = 0;

	return 1;
}

unsigned char I2C_R(){
	unsigned char mask ;
	unsigned char dat = 0 ;

	for(mask = 0x80; mask != 0; mask>>=1){
		I2C_delay();
		SCL = 1;	
		if(SDA == 0)
			 dat &= ~mask;
		else
			 dat |= mask;;
		I2C_delay();
		SCL = 0;
		
	}

	SDA = 0;
	I2C_delay();
	SCL = 1;
	I2C_delay();
	SCL = 0;
	SDA = 1;

	return dat;
}

	
