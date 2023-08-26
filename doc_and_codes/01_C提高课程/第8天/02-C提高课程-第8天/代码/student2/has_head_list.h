#ifndef _HAS_HEAD_H_
#define _HAS_HEAD_H_

#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG(format, ...) \
	fprintf(stderr, "[DEBUG][%s:%d][%s][%s]"format, __FUNCTION__, __LINE__, __DATE__, __TIME__, ##__VA_ARGS__);//__VA_ARGS__ === a,b
#define ERROR(format, ...)\
	fprintf(stderr, "[ERROR][%s:%d][%s][%s]"format, __FUNCTION__, __LINE__, __DATE__, __TIME__, ##__VA_ARGS__);
#define LOG(format, ...)\
	fprintf(stderr, "[LOG][%s:%d][%s][%s]"format, __FUNCTION__, __LINE__, __DATE__, __TIME__, ##__VA_ARGS__);



//����Ľڵ�
struct node
{
	int data;//������
	struct node *next;//ָ����
};

//��ʼ��һ����ͷ�����ͷ���
__declspec(dllexport)
int init_list(struct node **head_p);

//����һ���ڵ�Ľӿ�
__declspec(dllexport)
struct node* make_node(int data);

//����һ���ڵ�
__declspec(dllexport)
void free_node(struct node *node);

//��ͷ����ڵ�Ľӿ�
__declspec(dllexport)
int insert_node_from_begin(struct node *new_node, struct node *head);

//��β������ڵ�
__declspec(dllexport)
int insert_node_to_end(struct node *new_node, struct node *head);

//����һ����ͷ�ڵ������
__declspec(dllexport)
void print_list(struct node *head);

//����һ������Ľڵ�
__declspec(dllexport)
struct node *search(int data, struct node *head);

//ɾ����ͷ����Ԫ��
__declspec(dllexport)
int delete_node(struct node *del_node, struct node* head);

//����һ������
__declspec(dllexport)
void destory_list(struct node **head_p);


//����һ������
__declspec(dllexport)
int reverse(struct node *head);

//��ӡһ���ڵ�
__declspec(dllexport)
void print_node(struct node *node);

__declspec(dllexport)
void add_node(struct node *node);

//�����ͳһ�����ķ���
__declspec(dllexport)
void for_each(struct node *head, void(*fp)(struct node *node));


#endif