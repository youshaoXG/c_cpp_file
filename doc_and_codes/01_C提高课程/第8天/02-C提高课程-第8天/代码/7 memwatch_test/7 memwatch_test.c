#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "memwatch.h"


int main(void)
{
	char * p = NULL;

	p = (char*)malloc(100); //�ǵ��� memwatch��malloc

	strcpy(p, "abc");

	//�����free �ͻ����ڴ�й¶�ĵķ���


	if (p != NULL) {
		free(p);
		p = NULL;
	}
	return 0;
}