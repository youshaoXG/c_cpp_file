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



//链表的节点
struct node
{
	int data;//数据域
	struct node *next;//指针域
};

//初始化一个有头链表的头结点
__declspec(dllexport)
int init_list(struct node **head_p);

//创建一个节点的接口
__declspec(dllexport)
struct node* make_node(int data);

//销毁一个节点
__declspec(dllexport)
void free_node(struct node *node);

//从头插入节点的接口
__declspec(dllexport)
int insert_node_from_begin(struct node *new_node, struct node *head);

//从尾部插入节点
__declspec(dllexport)
int insert_node_to_end(struct node *new_node, struct node *head);

//遍历一个带头节点的链表
__declspec(dllexport)
void print_list(struct node *head);

//查找一个链表的节点
__declspec(dllexport)
struct node *search(int data, struct node *head);

//删除带头结点的元素
__declspec(dllexport)
int delete_node(struct node *del_node, struct node* head);

//销毁一个链表
__declspec(dllexport)
void destory_list(struct node **head_p);


//逆序一个链表
__declspec(dllexport)
int reverse(struct node *head);

//打印一个节点
__declspec(dllexport)
void print_node(struct node *node);

__declspec(dllexport)
void add_node(struct node *node);

//链表的统一遍历的方法
__declspec(dllexport)
void for_each(struct node *head, void(*fp)(struct node *node));


#endif