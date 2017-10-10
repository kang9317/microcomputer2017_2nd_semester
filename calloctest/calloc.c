/*
### calloc test ###
name : calloc.c
date : 2017-10-10
author : 강정학
proj : double형 변수 5개로 사용할 배열의 기억공간이 필요할때 사용하는 코드
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	double *ap;	// 할당 받은 기억공간을 연결할 포인터변수
	int i;	// 반복 제어변수

	ap = (double *)calloc(5, sizeof(double)); // calloc 함수로 메모리 할당
	for (i = 0; i < 5; i++) {
		printf("%lf\n", ap[i]);	// 반복문으로 할당 받은 기억공간의 값을 출력한다.
	}
}
