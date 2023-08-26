#include "dlist.h"


//初始化一个双向链表
void init_list(struct node **head_p, struct node **tail_p)
{
	struct node *head = NULL;
	struct node *tail = NULL;
	if (head_p == NULL || tail_p == NULL) {
		return;
	}

	head = (struct node *)malloc(sizeof(struct node));
	if (head == NULL) {
		return;
	}

	tail = (struct node *)malloc(sizeof(struct node));
	if (tail == NULL) {
		return;
	}

	head->data = tail->data = 0;
	head->next = tail;
	tail->prev = head;

	head->prev = tail->next = NULL;

	*head_p = head;
	*tail_p = tail;


	return;
}

//创建一个节点
struct node *make_node(int data)
{
	struct node *p = NULL;

	p = (struct node *)malloc(sizeof(struct node));
	if (p == NULL) {
		return NULL;
	}
	p->data = data;
	p->next = p->prev = NULL;

	return p;
}

//销毁一个节点
void free_node(struct node *node)
{
	if (node != NULL) {
		free(node);
	}
}

//插入一个节点
int insert_node(struct node *head, struct node *tail, struct node *new_node)
{
	if (head == NULL || tail == NULL || new_node == NULL) {
		return -1;
	}

	//改变new_node 的自身的指针
	new_node->next = head->next;
	new_node->prev = head;

	//改变new _node 两边的指针
	new_node->next->prev = new_node;
	new_node->prev->next = new_node;

	return 0;
}


//遍历一个链表
void print_list_1(struct node *head, struct node *tail)
{
	struct node *p = NULL;

	for (p = head->next; p != tail; p = p->next) {
		printf("data: %d\n", p->data);
	}
}

void print_list_2(struct node *head, struct node *tail)
{
	struct node *p = NULL;

	for (p = tail->prev; p != head; p = p->prev) {
		printf("data: %d\n", p->data);
	}
}

//查找一个节点
struct node *search(struct node *head, struct node *tail, int data)
{
	struct node *p = NULL;

	for (p = head->next; p != tail; p = p->next) {
		if (p->data == data) {
			return p;
		}
	}

	return NULL;
}

//删除一个双向链表的节点
int delete_node(struct node*head, struct node *tail, struct node *del_node)
{
	struct node *p = NULL;

	for (p = head->next; p != tail; p = p->next) {
		//遍历链表中除了 head 和tail的每一个元素
		if (p == del_node) {
			//p是删除的节点
			//应该改变 p的前驱节点 和 p的后继节点 ， p本身的两个指针不要动
			p->next->prev = p->prev;
			p->prev->next = p->next;
			free_node(p);
			break;
		}
	}

	return 0;
}

//销毁一个双向链表
void destory_list(struct node **head_p, struct node **tail_p)
{
	
	if (head_p == NULL || tail_p == NULL) {
		return;
	}

	struct node *head = *head_p;
	struct node *tail = *tail_p;
	struct node *p = NULL;

	for (p = head->next; p != tail;) {
		p->next->prev = p->prev;
		p->prev->next = p->next;
		free_node(p);
		p = head->next;
	}
	//以上就删除了 除了head 和tail的全部元素

	if (head->next == tail &&tail->prev == head) {
		printf("此时链表已经空 除了(head , tail)\n");
		free_node(head);
		free_node(tail);
		*head_p = NULL;
		*tail_p = NULL;
	}

	return;
}