#ifndef _HAS_HEAD_H_
#define _HAS_HEAD_H_

#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//链表的节点
struct node
{
	int data;//数据域
	struct node *next;//指针域
};

//初始化一个有头链表的头结点
int init_list(struct node **head_p);

//创建一个节点的接口
struct node* make_node(int data);

//销毁一个节点
void free_node(struct node *node);

//从头插入节点的接口
int insert_node_from_begin(struct node *new_node, struct node *head);

//从尾部插入节点
int insert_node_to_end(struct node *new_node, struct node *head);

//遍历一个带头节点的链表
void print_list(struct node *head);

//查找一个链表的节点
struct node *search(int data, struct node *head);

//删除带头结点的元素
int delete_node(struct node *del_node, struct node* head);

//销毁一个链表
void destory_list(struct node **head_p);



#endif