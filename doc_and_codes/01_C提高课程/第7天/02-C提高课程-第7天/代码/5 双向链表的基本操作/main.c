#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dlist.h"

int main(void)
{
	struct node *head = NULL;//±íÍ·
	struct node *tail = NULL;//±íÎ²
	struct node *new_node = NULL;
	struct node *del_node = NULL;

	int num = 10;
	int i = 0;
	int data = 0;

	init_list(&head, &tail);

	for (i = 0; i < num; i++) {
		new_node = make_node(i + 10);
		insert_node(head, tail, new_node);
	}

	print_list_1(head, tail);
	printf("====\n");
	print_list_2(head, tail);
	printf("====\n");

	printf("data: ");
	scanf("%d", &data);

	del_node = search(head, tail, data);
	if (del_node != NULL) {
		delete_node(head, tail, del_node);
	}

	printf("====\n");

	print_list_2(head, tail);


	destory_list(&head, &tail);

	if (head == NULL) {
		printf("head== NULL\n");
	}

	if (tail == NULL) {
		printf("tail == NULL\n");
	}


	return 0;
}