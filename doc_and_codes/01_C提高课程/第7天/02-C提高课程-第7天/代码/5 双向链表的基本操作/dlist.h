#ifndef _D_LIST_H_
#define _D_LIST_H_

#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct node
{
	int data;//������
	struct node *next;//��һ���ڵ�
	struct node *prev;//��һ���ڵ�
};


//��ʼ��һ��˫������
void init_list(struct node **head_p, struct node **tail_p);

//����һ���ڵ�
struct node *make_node(int data);

//����һ���ڵ�
void free_node(struct node *node);

//����һ���ڵ�
int insert_node(struct node *head, struct node *tail, struct node *new_node);

//����һ������
void print_list(struct node *head, struct node *tail);

//˳�����
void print_list_1(struct node *head, struct node *tail);

//�������
void print_list_2(struct node *head, struct node *tail);

//����һ���ڵ�
struct node *search(struct node *head, struct node *tail, int data);

//ɾ��һ��˫������Ľڵ�
int delete_node(struct node*head, struct node *tail, struct node *del_node);

//����һ��˫������
void destory_list(struct node **head_p, struct node **tail_p);

#endif