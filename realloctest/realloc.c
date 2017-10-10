/*
### realloc test ###
name : realloc.c
date : 2017-10-10
author : 강정학
proj : realloc 함수를 사용하여 양수값을 마음껏 입력할 수 있도록 작성한 프로그램
*/

#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int *ip;
	int size = 5;
	int cnt = 0;
	int num;
	int i;

	ip = (int*)calloc(size, sizeof(int));
	while (1) {
		printf("양수를 입력하세요 => ");
		scanf("%d", &num);
		if (num <= 0) break;
		if (cnt < size) {
			ip[cnt++]=num;
		}
		else {
			size += 5;
			ip = (int *)realloc(ip, size * sizeof(int));
			ip[cnt++] = num;
		}
	}

	for (i = 0; i < cnt; i++) {
		printf("%5d", ip[i]);
	}
	free(ip);
	return 0;
}
