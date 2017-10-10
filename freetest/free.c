/*
### free test ###
name : free.c
date : 2017-10-10
author : 강정학
proj : 128바이트의 메모리를 확보여여 해제하는 프로그램
*/

#include <stdlib.h>
#include <stdio.h>

int main(void) {
	char *data;
	data = (char*)malloc(128);
	if (data == NULL) {
		printf("메모리 확보에 실패했습니다\n");
		exit(1);
	}
	printf("메모리를 확보했습니다\n");
	free(data);
	return 0;

}
