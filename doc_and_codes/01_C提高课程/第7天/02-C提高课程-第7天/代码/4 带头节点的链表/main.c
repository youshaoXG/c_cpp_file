#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "has_head_list.h"

int main(void)
{
	struct node *head = NULL;
	struct node *new_node = NULL;
	struct node *del_node = NULL;
	int num = 10;
	int data = 0;
	int i = 0;

	init_list(&head);//��ʼ����һ����ͷ�������ͷ���


	for (i = 0; i < num; i++) {
		new_node = make_node(i + 10);
		//insert_node_from_begin(new_node, head);
		insert_node_to_end(new_node, head);
	}
	print_list(head);


	printf("Ҫɾ���Ľڵ�");
	scanf("%d", &data);
	del_node = search(data, head);
	if (del_node != NULL) {
		delete_node(del_node, head);
	}

	print_list(head);


	destory_list(&head);

	if (head == NULL) {
		printf("head �Ѿ�����\n");
	}


	return 0;
}