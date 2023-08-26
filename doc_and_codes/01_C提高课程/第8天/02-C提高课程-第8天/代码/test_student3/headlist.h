#ifndef _HEADLIST_H_C_
#define _HEADLIST_H_C_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DT
{
	int id;
	struct DT *prev_link;
	struct DT *next_link;
};

__declspec(dllexport)
int init_dlist2(struct DT **head,struct DT **end);

__declspec(dllexport)
int make_node2(struct DT **node);

__declspec(dllexport)
int search2(int num, struct DT *head, struct DT *end);

__declspec(dllexport)
int insert_node_to_head2(struct DT *node, struct DT *head, struct DT *end );

__declspec(dllexport)
int delete_node2(struct DT *node, struct DT *head, struct DT *end);

__declspec(dllexport)
void free_node2(struct DT *head);

__declspec(dllexport)
void printf_node2(struct DT *head, struct DT *end);

#endif