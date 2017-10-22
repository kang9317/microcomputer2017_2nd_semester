#include <mega128.h>
#include <delay.h>
void TWI_MW(unsigned char address, unsigned char data_buf){
  TWCR = 0xa4;
  while(((TWCR&0x80) == 0x00) || ((TWSR&0xf8) != 0x08));
  TWDR = address << 1;
  
  TWCR = 0x84;
  
  while(((TWCR&0x80) == 0x00) || ((TWSR&0xf8) != 0x18));
  
  TWDR = data_buf;
  TWCR = 0x84;
  while(((TWCR&0x80) == 0x00) || ((TWSR&0xf8) != 0x28));
  
  TWCR = 0x94;
}
void TWI_init(void){
  TWBR = 12;
  TWSR = 0x00;
}
void main(void){
  unsigned int i=0;
  TWI_init();
  delay_ms(10);
  
  for (i=0;i<10;i++){
    TWI_MW(0x01,i);
    
    delay_ms(10);
  }
}
