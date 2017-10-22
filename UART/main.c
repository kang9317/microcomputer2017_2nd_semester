#include <avr/io.h>    // AVR 입출력 관련 헤더파일을 포함합니다.
#define F_CPU 8000000UL    // 사용하고 있는 크리스탈 주파수 값을 상수로 설정합니다.
#include <util/delay.h>    // 지연 함수 관련 헤더파일을 포함합니다.

char rx_char(void)    // 문자형 rx_char 수신 사용자 함수를 생성합니다.
{
	while((UCSRA&0x80) == 0);    // 문자 수신이 완료될 때까지 대기 UCSRA의 RXC가 비트1 이 되면 다음라인으로
	return UDR;    // UDR 수신데이터 반환
}

void tx_char(char tx_data)    // 문자형 tx_char 송신 사용자 함수를 생성합니다.
{
	while((UCSRA&0x20) == 0);    // UDR레지스터가 빌 때까지 대기 UCSRA의 UDRE가 비트1 이 되면 다음라인으로
	UDR = tx_data;    // UDR레지스터에 입력한 tx_data 입력합니다.
}

int main(void)    // 메인함수를 호출합니다.
{
char  i, data;    // 부호없는 문자형 변수 i, data를 생성합니다.

DDRB=0xFF;    // B포트 8비트 전체를 출력으로 설정합니다.
PORTB=0x00;    // B포트 8비트 전체의 초기값을 논리0 (0V)로 설정합니다.

UCSRA=0x00;    // UART설정 레지스터A 별도 설정 없음
UCSRB=0x18;    // UART설정 레지스터B RXEN과 TXEN을 비트1로 설정해서 송수신기능을 활성화 합니다.
UCSRC=0x06;    // UART설정 레지스터C UCSZ1과 UCSZ0을 비트1로 설정해서 8비트 데이터 전송으로 설정합니다.
UBRRH=0x00;    // UBBR 통신속도 설정레지스터 상위 바이트로 8비트를 초과하지 않아 UBRRL에 모두 입력됩니다.
UBRRL=0xCF;    // UBRR 통신속도 설정레지스터 하위 바이트로 8Mhz크리스탈 2400bps속도로 207로 설정합니다.

while(1)    // 아래 구문을 무한 반복합니다.
	{
		data = rx_char();    // data 변수에 rx_char 사용자 함수사용으로 수신된 데이터를 저장합니다.
		
		if(data=='y')    // data변수와 문자y가 같으면
		{
			PORTB=0xFF;    // B포트 전체 논리1 (5V)를 출력합니다.
			tx_char('_');    // tx_char 사용자 함수 사용으로 _문자를 송신합니다.
			tx_char('o');    // tx_char 사용자 함수 사용으로 o문자를 송신합니다.
			tx_char('k');    // tx_char 사용자 함수 사용으로 k문자를 송신합니다.
		}
		if(data=='n')    // data변수와 문자n과 같으면
		{
			PORTB=0x00;    // B포트 전체 논리0 (0V)를 출력합니다.
			tx_char('_');    // tx_char 사용자 함수 사용으로 _문자를 송신합니다.
			tx_char('o');    // tx_char 사용자 함수 사용으로 o문자를 송신합니다.
			tx_char('k');    // tx_char 사용자 함수 사용으로 k문자를 송신합니다.
		}
		if(data=='b')    // data변수와 문자b가 같으면
		{
			for(i=0;i<3;i++)    // 아래구문을 3번 반복합니다.
			{
				PORTB=0xFF;    // B포트 전체 논리1 (5V)를 출력합니다.
				_delay_ms(200);    // 위 상태를 0.2초 동안 유지합니다.
				PORTB=0x00;    // B포트 전체 논리0 (0V)를 출력합니다.
				_delay_ms(200);    // 위 상태를 0.2초 동안 유지합니다.
			}
			tx_char('_');    // tx_char 사용자 함수 사용으로 _문자를 송신합니다.
			tx_char('o');    // tx_char 사용자 함수 사용으로 o문자를 송신합니다.
			tx_char('k');    // tx_char 사용자 함수 사용으로 k문자를 송신합니다.
		}
	}
	

return 0;    // 정상종료 값 0을 리턴합니다.
}


// origin : http://binworld.kr/61
