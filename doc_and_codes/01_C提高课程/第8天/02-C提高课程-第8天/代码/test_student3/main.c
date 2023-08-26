#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "headlist.h"

int main(void)
{
	struct DT * head = NULL;
	struct DT *tail = NULL;
	int ret = 0;

	struct DT * new_node = NULL;

	ret =  init_dlist2(&head, &tail);
	if (ret != 0) {
		fprintf(stderr, "init_dlist2 error\n");
	}
	else {
		printf("init_dlist2 succ!\n");
	}
	
	ret = make_node2(&new_node);
	if (ret != 0) {
		fprintf(stderr, "make node error\n");

	}


	return 0;
}