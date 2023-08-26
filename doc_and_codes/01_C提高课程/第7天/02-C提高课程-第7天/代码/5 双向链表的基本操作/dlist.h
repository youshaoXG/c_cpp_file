#ifndef _D_LIST_H_
#define _D_LIST_H_

#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct node
{
	int data;//数据域
	struct node *next;//下一个节点
	struct node *prev;//上一个节点
};


//初始化一个双向链表
void init_list(struct node **head_p, struct node **tail_p);

//创建一个节点
struct node *make_node(int data);

//销毁一个节点
void free_node(struct node *node);

//插入一个节点
int insert_node(struct node *head, struct node *tail, struct node *new_node);

//遍历一个链表
void print_list(struct node *head, struct node *tail);

//顺序遍历
void print_list_1(struct node *head, struct node *tail);

//逆序遍历
void print_list_2(struct node *head, struct node *tail);

//查找一个节点
struct node *search(struct node *head, struct node *tail, int data);

//删除一个双向链表的节点
int delete_node(struct node*head, struct node *tail, struct node *del_node);

//销毁一个双向链表
void destory_list(struct node **head_p, struct node **tail_p);

#endif