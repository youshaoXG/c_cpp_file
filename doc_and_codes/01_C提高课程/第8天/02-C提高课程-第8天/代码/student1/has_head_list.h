#ifndef ___HAS___HEAD___LIST___
#define ___HAS___HEAD___LIST___

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable:4996)

//����Ľڵ�
typedef struct Student {
	int data;
	int id;
	int age;
	float score;
	char sex[4];
	char name[16];
	//������������������ָ����
	struct Student *prios, *next;
}St_t;

//��ʼ��һ����ͷ�������ͷ�ڵ�
__declspec(dllexport)
int has_headlist(St_t **node_head);

//����һ���ڵ�Ľӿ�
__declspec(dllexport)
St_t *make_node();

//����һ���ڵ�
__declspec(dllexport)
void free_node(St_t *node);

//��ͷ������һ���ڵ�
__declspec(dllexport)
int insert_node_begin(St_t *head);

//������ͷ�ڵ������,����һ���ڵ㣬���flg��ֵΪ0����ӡ��Ϊ����ֵ��ӡ�����data_p��ֵΪNULL,����һ��β�ڵ㣬��Ϊ�շ��ز��ҵ��Ľڵ�
__declspec(dllexport)
St_t *print_head_list(St_t *head,int flg,void *data_p,int type_flg);

//��β������һ���ڵ�
__declspec(dllexport)
int insert_node_end(St_t *head);

#endif
