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

}

bit I2C_W(unsigned char data){
	unsigned char mask;

	for(mask = 0x80; mask != 0; mask>>=1){
		if((data & 0x80) != 0)
			SDA = 1;
		else 
			SDA = 0;

		SCL = 1;
		delay_nop();
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
}

unsigned char I2C_R(){

	
}
	
/*

unsigned char I2C_R_byte(unsigned char device_addr,unsigned char reg,unsigned char *data){
	unsigned char mask ;
	
	I2C_start();

	//seek device
	device_addr = (device_addr<<1)|0x00; // write reg
	if(I2C_seek_device() == 0){
		I2C_stop();
		return 0;
	}

	I2C_delay();

    // send reg addr
	for(mask = 0x80; mask != 0; mask>>=1){
		if((reg & 0x80) != 0)
			SDA = 1;
		else 
			SDA = 0;

		SCL = 1;
		delay_nop();
		SCL = 0;
	}


	SDA = 1;
	I2C_delay();
	SCL = 1;
	if(SDA != 0){//if not detect the device return fail
		return 0;
	}

	I2C_stop();

	I2C_delay();

	I2C_start();

	//seek device
	device_addr = (device_addr<<1)|0x01;//read =1
	if(I2C_seek_device() == 0){
		I2C_stop();
		return 0;
	}

	I2C_delay();

	for(mask = 0x80; mask != 0; mask>>=1){
		SCL = 1;

		if(SDA == 0)
			*data &= ~mask;
		else
			*data |= mask;;
		I2C_delay();
		SCL = 0;	
	}
	//send ack 
	SDA = 0;
	delay_nop();
	SCL = 1;
	delay_nop();
	SCL = 0;

	I2C_stop();

	return 1;
}

unsigned char I2C_R_page(unsigned char device_addr,unsigned char start_reg,unsigned char end_reg,unsigned char *data){
	unsigned char mask ;
    unsigned char lenth = 0;

	if(start_reg == end_reg){
		length = 1;
	}
	else{
		length = end_reg - start_reg;
	}

	device_addr = (device_addr<<1)|0x01;
	I2C_start();

	//seek device
	device_addr = (device_addr<<1)|0x00;//write reg
	if(I2C_seek_device() == 0){
		I2C_stop();
		return 0;
	}

	I2C_delay();

    // send reg addr
	for(mask = 0x80; mask != 0; mask>>=1){
		if(reg && 0x80)
			SDA = 1;
		else 
			SDA = 0;

		SCL = 1;
		delay_nop();
		SCL = 0;
	}


	SDA = 1;
	I2C_delay();
	SCL = 1;
	if(SDA != 0){//if not detect the device return fail
		return 0;
	}

	I2C_stop();

	I2C_delay();

	I2C_start();

	//seek device
	device_addr = (device_addr<<1)|0x01; //write
	if(I2C_seek_device() == 0){
		I2C_stop();
		return 0;
	}

	I2C_delay();

	for(;length != 0;length --){
		for(mask = 0x80; mask != 0; mask>>=1){
			SCL = 1;

			if(SDA == 0)
				*data &= ~mask;
			else
				*data |= mask;;
			I2C_delay();
			SCL = 0;	
		}
		//send ack 
		SDA = 0;
		delay_nop();
		SCL = 1;
		delay_nop();
		SCL = 0;

		data++;
	}

	I2C_stop();

}
unsigned char I2C_W_CMD(unsigned char device_addr,unsigned char cmd){
	unsigned char mask;


}
unsigned char I2C_W_byte(unsigned char device_addr,unsigned char reg, unsigned char data){
	unsigned mask ;
	device_addr = (device_addr<<1)|0x00;
	
	I2C_start();
	I2C_seek_device();

	if(mask = 0x80; mask != 0; mask>>=1){
		if()
	}

}
unsigned char I2C_W_page(unsigned char device_addr,unsigned char start_reg,unsigned char end_reg,unsigned char *data);
*/
