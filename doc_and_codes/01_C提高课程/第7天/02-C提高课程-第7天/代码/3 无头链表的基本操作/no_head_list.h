#ifndef _NO_HEAD_LIST_H_
#define _NO_HEAD_LIST_H_

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

//初始化链表的接口
void init_list(struct node **head_p);

//创建一个节点的接口
struct node* make_node(int data);

//销毁一个节点
void free_node(struct node *node);

//将节点插入链表的接口 （插入链表的尾部）
int insert_node_to_end(struct node *new_node, struct node **head_p);

//将节点插入链表的接口(插入链表的头部)
int insert_node_from_begin(struct node *new_node, struct node **head_p);

//销毁一个链表
void destory_list(struct node **head_p);

//删除一个节点
int delete_node(struct node *del_node,  struct node**head_p);

//查询一个节点
struct node * search(struct node *head, int data);

//遍历链表
void print_list(struct node *head);

#endif