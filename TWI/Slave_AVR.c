#include <mega128.h>
#include <delay.h>
#include "lcdchoi.h"  // LCD 출력하는 헤더파일
unsigned char TWI_SR(unsigned char address){
  unsigned char data_buf;
  
  TWAR = address << 1;
  TWCR = x44;
  while(((TWCR&0x80) == 0x00) || ((TWSR&0xf8) != 0x60));
  
  TWCR = 0xc4;
  
  while(((TWCR&0x80) == 0x00) || ((TWSR&0xf8) != 0x80));
  
  data_buf = TWDR;
  TWCR = 0xc4;
  while(((TWCR&0x80) == 0x00) || ((TWSR&0xf8) != 0xa0));
  
  TWCR = 0xc4;
  return data_buf;
}

void TWI_init(void){
  TWSR = 0x00;
}

void main(void){
  unsigned int data_buf;
  
  TWI_init();
  lcd_init();
  lcd_ln11();
  lcd_str("TWI EXAM-1");
  lcd_ln21();
  delay_ms(10);
  for(;;){
    data_buf = TWI_SR(0x01);
    lcd_dat('0'+data_buf);
    delay_ms(10);
  }
}
  
