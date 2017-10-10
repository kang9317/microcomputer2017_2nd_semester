/*
### malloc test ###
name : main.c
date : 2017-10-10
author : ������
proj : 100����Ʈ�� �Ҵ�޾Ƽ� ���⿡ ���ĺ� ���ڸ� ������� �������Ŀ� ȭ�鿡 ����ϱ�
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *pc = NULL;
	int i = 0;

	pc = (char *)malloc(100 * sizeof(char));

	if (pc == NULL) {
		printf("�޸� �Ҵ� ����\n");
		exit(1);
	}

	for (i = 0; i < 26; i++) {
		pc[i] = 'a' + i;
	}
	pc[i] = 0; // NULL ���� �߰�
	printf("%s\n", pc);
	free(pc);

	return 0;
}