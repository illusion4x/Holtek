/*
read me first!
stact need : 1 (be care of u total stack usage!)
if the start_reg is same with the end reg, it is also ok 
in this case, it acted as byte write or read

*/

#ifndef _I2C_H
	#define _I2C_H

#include  <ht46f47e.h>

#define SDA 
#define SCL

#define I2C_delay(); _nop();_nop();_nop();

void I2C_start();
void I2C_stop();
bit I2C_seek_device(unsigned char device_addr);
bit I2C_W(unsigned char data);
unsigned char I2C_R();


	#endif
