#ifndef ___HAS___HEAD___LIST___
#define ___HAS___HEAD___LIST___

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable:4996)

//链表的节点
typedef struct Student {
	int data;
	int id;
	int age;
	float score;
	char sex[4];
	char name[16];
	//上面是数据域，下面是指针域
	struct Student *prios, *next;
}St_t;

//初始化一个有头的链表的头节点
__declspec(dllexport)
int has_headlist(St_t **node_head);

//创建一个节点的接口
__declspec(dllexport)
St_t *make_node();

//销毁一个节点
__declspec(dllexport)
void free_node(St_t *node);

//从头部插入一个节点
__declspec(dllexport)
int insert_node_begin(St_t *head);

//遍历带头节点的链表,返回一个节点，如果flg的值为0不打印，为其它值打印，如果data_p的值为NULL,返回一个尾节点，不为空返回查找到的节点
__declspec(dllexport)
St_t *print_head_list(St_t *head,int flg,void *data_p,int type_flg);

//从尾部插入一个节点
__declspec(dllexport)
int insert_node_end(St_t *head);

#endif
