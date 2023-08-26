#include "has_head_list.h"
__declspec(dllexport)
int init_list(struct node **head_p)
{
	struct node *head = NULL;

	head = (struct node*)malloc(sizeof(struct node));
	if (head == NULL) {
		ERROR("malloc head error\n");
		return -1;
	}

	head->data = 0;
	head->next = NULL;

	*head_p = head;

	LOG("init list over\n");

	return 0;
}

//创建一个节点的接口
__declspec(dllexport)
struct node* make_node(int data)
{
	struct node *new_node = NULL;

	new_node = (struct node*)malloc(sizeof(struct node));
	if (new_node == NULL) {
		ERROR("malloc %d error\n", data);
		return NULL;
	}

	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}

//销毁一个节点
__declspec(dllexport)
void free_node(struct node *node)
{
	if (node != NULL) {
		free(node);
	}
}
__declspec(dllexport)
int insert_node_from_begin(struct node *new_node, struct node *head)
{
	if (new_node == NULL || head == NULL) {
		ERROR("new_node == NULL || head == NULL");
		return -1;
	}

	new_node->next = head->next;
	head->next = new_node;

	return 0;
}
__declspec(dllexport)
int insert_node_to_end(struct node *new_node, struct node *head)
{
	struct node *last_node = NULL;

	if (new_node == NULL || head == NULL) {
		return -1;
	}

	//找到最后一个节点的地址，用last_node 指向他
	for (last_node = head; last_node->next != NULL; last_node = last_node->next);

	//保证new_node的next 指向NULL
	new_node->next = last_node->next;

	last_node->next = new_node;

	return 0;
}

//查找一个链表的节点
__declspec(dllexport)
struct node *search(int data, struct node *head)
{
	struct node *p = NULL;

	for (p = head->next; p != NULL; p = p->next) {
		if (p->data == data) {
			return p;
		}
	}

	return NULL;
}

//删除带头结点的元素
__declspec(dllexport)
int delete_node(struct node *del_node, struct node* head)
{
	struct node *p = NULL;

	if (del_node == NULL || head == NULL) {
		return -1;
	}

	for (p = head; p->next != NULL; p = p->next) {
		if (p->next == del_node) {
			//找到了被删除的节点 就是p->next
			p->next = p->next->next;
			free_node(del_node);
			break;
		}
	}

	return 0;
}

//遍历一个带头节点的链表
__declspec(dllexport)
void print_list(struct node *head)
{
	struct node *p = NULL;

	for (p = head->next; p != NULL; p = p->next) {
		DEBUG("data: %d\n", p->data);
	}
}
__declspec(dllexport)
void print_node(struct node *node)
{
	DEBUG("data: %d\n", node->data);
}
__declspec(dllexport)
void add_node(struct node *node)
{
	node->data += 1;
}


//链表的统一遍历的方法
__declspec(dllexport)
void for_each(struct node *head, void(*fp)(struct node *node)) //fp = print_node
{
	struct node *p = NULL;

	for (p = head->next; p != NULL; p = p->next) {
		//遍历一个链表 找到每个元素的节点
		//分别调用 fp 传进来的方法 去执行每个节点的业务
		fp(p);//printf_node(p);
	}
}

//销毁一个链表
__declspec(dllexport)
void destory_list(struct node **head_p)
{
	struct node * p = NULL;
	struct node *head = NULL;

	if (head_p == NULL) {
		return;
	}

	head = *head_p;

	for (p = head->next; p != NULL;) {
		//p就是要删除的节点
		head->next = p->next;
		free_node(p);
		p = head->next;
	}

	//如果循环退出，说明 head->next = NULL
	if (head != NULL) {
		free_node(head);
		*head_p = NULL;
	}
}

//逆序一个链表
__declspec(dllexport)
int reverse(struct node *head)
{
	struct node *p = NULL; //准备逆序的节点
	struct node *prev_p = NULL;//p的前驱
	struct node *next_p = NULL;//p的后继

	//初始化
	prev_p = head;
	p = head->next;

	while (p != NULL) {
		//向让next_p 指向p的后继
		next_p = p->next;
		//改变p的后继为p的前驱
		p->next = prev_p;

		//让p的前驱等于p
		prev_p = p;
		
		//让p等于 原先p的后继 next_p
		p = next_p;
	}

	//先改变原先首元素的写一个地址
	head->next->next = NULL;
	
	//将头结点 指向目前的 prev_p 也就是新的首元素地址
	head->next = prev_p;

	return 0;
}