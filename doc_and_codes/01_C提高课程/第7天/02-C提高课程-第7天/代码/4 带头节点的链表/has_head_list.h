#ifndef _HAS_HEAD_H_
#define _HAS_HEAD_H_

#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//����Ľڵ�
struct node
{
	int data;//������
	struct node *next;//ָ����
};

//��ʼ��һ����ͷ�����ͷ���
int init_list(struct node **head_p);

//����һ���ڵ�Ľӿ�
struct node* make_node(int data);

//����һ���ڵ�
void free_node(struct node *node);

//��ͷ����ڵ�Ľӿ�
int insert_node_from_begin(struct node *new_node, struct node *head);

//��β������ڵ�
int insert_node_to_end(struct node *new_node, struct node *head);

//����һ����ͷ�ڵ������
void print_list(struct node *head);

//����һ������Ľڵ�
struct node *search(int data, struct node *head);

//ɾ����ͷ����Ԫ��
int delete_node(struct node *del_node, struct node* head);

//����һ������
void destory_list(struct node **head_p);



#endif