#include 'TM1730.h'

void TM1730_W_cmd(unsigned char cmd){
  
   	I2C_start();
   	I2C_seek_device(TM1730_addr_W);
   	I2C_W(cmd);
   	I2C_stop();

}

void TM1730_W_byte(unsigned char reg_addr,unsigned char dat){

	I2C_start();
   	I2C_seek_device(TM1730_addr_W);
   	I2C_W(reg_addr);
      I2C_W(dat);
   	I2C_stop();
}
void TM1730_W_page(unsigned char start_reg,unsigned char end_reg,unsigned char * dat){
	
   dat = dat+start_reg;

   I2C_start();
   I2C_seek_device(TM1730_addr_W);
   I2C_W(start_reg);

   for(;start_reg<=end_reg;start_reg ++){
   	I2C_W(*dat);
   	dat++;
   }

   	I2C_stop();
}

unsigned char TM1730_R_key(){
	unsigned char key;
	I2C_start();
   	I2C_seek_device(TM1730_addr_W);
   	I2C_W(key_addr1);
   	I2C_stop();

   	I2C_start();
   	I2C_seek_device(TM1730_addr_R);
   	key = I2C_R();
   	I2C_R();
   	I2C_R();

   	I2C_stop();

   	return key;

}

unsigned char TM1730_R_int(){
	unsigned char int_u8;
	I2C_start();
   	I2C_seek_device(TM1730_addr_W);
   	I2C_W(int_addr);
   	I2C_stop(); 

   	I2C_start();
   	I2C_seek_device(TM1730_addr_R);
   	int_u8 = I2C_R();
      I2C_stop();

   	return int_u8;
}



