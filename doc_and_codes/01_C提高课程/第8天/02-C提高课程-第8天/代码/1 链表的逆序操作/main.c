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
	for_each(head, print_node);
	//print_list(head);

	LOG("��ÿ���ڵ�Ԫ�ص�ֵ��1��\n");
	for_each(head, add_node);

	for_each(head, print_node);


	LOG("Ҫɾ���Ľڵ�");
	scanf("%d", &data);
	del_node = search(data, head);
	if (del_node != NULL) {
		delete_node(del_node, head);
	}

	//print_list(head);
	for_each(head, print_node);


	printf("====== reverse  =====\n");
	reverse(head);
	//print_list(head);
	for_each(head, print_node);

	destory_list(&head);

	if (head == NULL) {
		printf("head �Ѿ�����\n");
	}


	// ��������ϰ  

	/*
	    һ�����ͣ�An integer��
	 b) һ��ָ�����͵�ָ�루A pointer to an integer��
	 c) һ��ָ��ָ�����͵�ָ�루A pointer to a pointer to an integer��
	 d) һ��10��������͵����飨An array of 10 integers��
	 e) һ��10�����ָ������ָ�������
	 ��An array of 10 pointers to integers��
	 f) һ��ָ����10�����������ָ��
	 ��A pointer to an array of 10 integers��
	 g) һ��ָ�� ��Ҫһ�����Ͳ������ҷ���ֵ��һ�����ͺ�����ָ��
	 ��A pointer to a function that takes an integer as an argument and
	 returns an integer��
	 h) һ�����10�� ָ�� ��Ҫһ�����Ͳ������ҷ���ֵ��һ�����ͺ�����ָ���
	 ����
	 ��An array of ten pointers to functions that take an integer argument
	 and return an integer��
	*/

#if 0
	int a;//һ������a
	int*a;//һ��ָ�����ε�ָ��
	int * *a;//һ��ָ������ָ��� ָ��
	int a[10];// һ�����10�����ε�����
	int *a[10];//һ������ ���10�� ָ�����ε�ָ��
	int(*a)[10];//һ��ָ��   ���10����������� ָ��
	int(*a)(int); // һ��ָ�� ��Ҫһ�����Ͳ������ҷ���ֵ��һ�����ͺ�����ָ��
	//����ָ������
	typedef int(*FP)(int); //һ������ָ��
	FP a[10];

	int(*fp[10])(int);
#endif
	return 0;
}