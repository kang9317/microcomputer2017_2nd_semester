/*
### malloc test ###
name : main.c
date : 2017-10-10
author : 강정학
proj : 100바이트를 할당받아서 여기에 알파벳 문자를 순서대로 저장한후에 화면에 출력하기
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *pc = NULL;
	int i = 0;

	pc = (char *)malloc(100 * sizeof(char));

	if (pc == NULL) {
		printf("메모리 할당 오류\n");
		exit(1);
	}

	for (i = 0; i < 26; i++) {
		pc[i] = 'a' + i;
	}
	pc[i] = 0; // NULL 문자 추가
	printf("%s\n", pc);
	free(pc);

	return 0;
}
