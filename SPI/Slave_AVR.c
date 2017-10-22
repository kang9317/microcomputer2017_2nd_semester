#include "iom128.h"

#define sbi(PORTX , BitX) PORTX |= (1 << BitX)  // 비트 SET 명령 정의
#define cbi(PORTX , BitX) PORTX &= ~(1 << BitX) // 비트 CLEAR 명령 정의

void Init_Main(void);
void Uart_Putch(unsigned char PutData);
unsigned char SPI_TxRx(unsigned char Data);

void main(void)
{  
    Init_Main ();
    while(1)
    {
        while(!(SPSR & (1<<SPIF))); // 송신 확인
        {
            SPDR=SPDR + 0x20;
        }
    }
}

void Init_Main (void)
{    
    cbi(SREG,7);                    // 모든 인터럽트 비활성화
    UBRR0H = 0; UBRR0L = 16;        // 57600bps (16MHz)
    UCSR0A = (0<<RXC0)|(1<<UDRE0);  // 수신,송신 상태비트 초기화
    UCSR0B = (1<<RXEN0)|(1<<TXEN0); // 수신,송신 기능 활성화
    UCSR0C = (3<<UCSZ00);           // START 1비트/DATA 8비트/STOP 1비트
    cbi(DDRE, 0);                   // RXD1 핀 입력으로 설정
    sbi(DDRE, 1);                   // TXD1 핀 출력으로 설정
    cbi(DDRB, 0);                   // /SS 입력으로 설정
    cbi(DDRB, 1);                   // SCK 입력으로 설정
    cbi(DDRB, 2);                   // MOSI 입력으로 설정
    sbi(DDRB, 3);                   // MISO 출력으로 설정
    SPCR = 0x40;                    // SPE, Slave Mode, SPI Mode0, SCK=fosc/4
    SPDR = 0xFF;                    // SPDR=0xFF으로 초기화
    sbi(SREG,7);                    // 모든 인터럽트 활성화
}

void Uart_Putch(unsigned char PutData)  // 시리얼로부터 1바이트 값을 보내는 함수
{    
    while(!( UCSR0A & (1<<UDRE0))  );   // 데이터가 빌 때까지 기다린다. 
    UDR0 = PutData;                     // 데이터를 전송한다. 
}

unsigned char SPI_TxRx(unsigned char Data)
{    
    SPDR = Data;                // Data 송신
    while(!(SPSR & (1<<SPIF))); // 송신 확인
    return SPDR;                // 수신 받은 데이터 반환
}

//origin : http://icbanq.tistory.com/entry/AVR-%EA%B8%B0%EC%B4%88-%EA%B0%95%EC%A2%8C-46-ATmega128%EC%9D%98-%EA%B8%B0%EB%8A%A5-%EB%B0%8F-%EC%A0%9C%EC%96%B4-6-SPI
