#ifndef _NO_HEAD_LIST_H_
#define _NO_HEAD_LIST_H_

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

//��ʼ������Ľӿ�
void init_list(struct node **head_p);

//����һ���ڵ�Ľӿ�
struct node* make_node(int data);

//����һ���ڵ�
void free_node(struct node *node);

//���ڵ��������Ľӿ� �����������β����
int insert_node_to_end(struct node *new_node, struct node **head_p);

//���ڵ��������Ľӿ�(���������ͷ��)
int insert_node_from_begin(struct node *new_node, struct node **head_p);

//����һ������
void destory_list(struct node **head_p);

//ɾ��һ���ڵ�
int delete_node(struct node *del_node,  struct node**head_p);

//��ѯһ���ڵ�
struct node * search(struct node *head, int data);

//��������
void print_list(struct node *head);

#endif