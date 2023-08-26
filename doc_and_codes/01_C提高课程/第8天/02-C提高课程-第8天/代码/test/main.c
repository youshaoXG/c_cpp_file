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

	init_list(&head);//初始化了一个有头的链表的头结点


	for (i = 0; i < num; i++) {
		new_node = make_node(i + 10);
		//insert_node_from_begin(new_node, head);
		insert_node_to_end(new_node, head);
	}
	for_each(head, print_node);
	//print_list(head);

	LOG("给每个节点元素的值加1：\n");
	for_each(head, add_node);

	for_each(head, print_node);


	LOG("要删除的节点");
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
		printf("head 已经销毁\n");
	}


	// 以下是练习  

	/*
	一个整型（An integer）
	b) 一个指向整型的指针（A pointer to an integer）
	c) 一个指向指向整型的指针（A pointer to a pointer to an integer）
	d) 一个10个存放整型的数组（An array of 10 integers）
	e) 一个10个存放指向整型指针的数组
	（An array of 10 pointers to integers）
	f) 一个指向存放10个整型数组的指针
	（A pointer to an array of 10 integers）
	g) 一个指向 需要一个整型参数并且返回值是一个整型函数的指针
	（A pointer to a function that takes an integer as an argument and
	returns an integer）
	h) 一个存放10个 指向 需要一个整型参数并且返回值是一个整型函数的指针的
	数组
	（An array of ten pointers to functions that take an integer argument
	and return an integer）
	*/

#if 0
	int a;//一个整形a
	int*a;//一个指向整形的指针
	int * *a;//一个指向整形指针的 指针
	int a[10];// 一个存放10个整形的数组
	int *a[10];//一个数组 存放10个 指向整形的指针
	int(*a)[10];//一个指向   存放10个整形数组的 指针
	int(*a)(int); // 一个指向 需要一个整型参数并且返回值是一个整型函数的指针
	//函数指针数组
	typedef int(*FP)(int); //一个函数指针
	FP a[10];

	int(*fp[10])(int);
#endif
	return 0;
}