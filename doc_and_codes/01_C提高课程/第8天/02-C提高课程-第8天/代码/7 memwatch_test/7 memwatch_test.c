#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "memwatch.h"


int main(void)
{
	char * p = NULL;

	p = (char*)malloc(100); //是调用 memwatch的malloc

	strcpy(p, "abc");

	//如果不free 就会有内存泄露的的风险


	if (p != NULL) {
		free(p);
		p = NULL;
	}
	return 0;
}