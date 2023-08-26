#include "no_head_list.h"


void init_list(struct node **head_p)
{
	*head_p = NULL;
}

struct node* make_node(int data)
{
	struct node *new_node = NULL;

	new_node = (struct node *)malloc(sizeof(struct node));
	if (new_node == NULL) {
		fprintf(stderr, "make node malloc new_node error\n");
		return NULL;
	}
	memset(new_node, 0, sizeof(struct node));

	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}

//销毁一个节点
void free_node(struct node *node)
{
	if (node != NULL) {
		free(node);
	}
}

//插入一个节点到head中
int insert_node_to_end(struct node *new_node, struct node **head_p)
{
	struct node *head = NULL;
	struct node *last_node = NULL;

	if (new_node == NULL  || head_p == NULL) {
		return 0;
	}
	head = *head_p;

	if (head == NULL) {
		//链表此时是空链表
		head = new_node;
		//无头链表 的特点需要对head是否为空 进行判断
	}
	else {
		//找到这个last_node
		//last_node->next = new_node;
		for (last_node = head; last_node->next != NULL; last_node = last_node->next);

		last_node->next = new_node;
	}

	*head_p = head;

	return 0;
}

int insert_node_from_begin(struct node *new_node, struct node **head_p)
{
	if (new_node == NULL || head_p == NULL) {
		return -1;
	}

	struct node *head = *head_p;

	//插入的操作
	if (head == NULL) {
		head = new_node;
	}
	else {
		new_node->next = head;
		head = new_node;
	}


	*head_p = head;

	return 0;
}


void print_list(struct node *head)
{
	struct node *p = NULL;

	for (p = head; p != NULL; p = p->next) {
		printf("%d\n", p->data);
	}
}

//销毁一个链表
void destory_list(struct node **head_p)
{
	struct node *head = *head_p;
	struct node *p = NULL;

	while (head != NULL) {
		//链表还有元素
		p = head;
		head = head->next;
		free_node(p);
	}


	*head_p = head;
}

//删除一个节点，根据要删除节点的指针来删除
int delete_node(struct node *del_node, struct node  **head_p)
{
	struct node *head = *head_p;
	struct node *p = NULL;


	if (head == del_node) {
		//如果要删除的节点是首届点
		head = head->next;
		free_node(del_node);
		*head_p = head;

		return 0;
	}

	//要删除的不是头结点
	for (p = head; p != NULL; p = p->next) {
		if (p->next == del_node) {
			//找到了要删除的节点，此时p是这个要删除节点前驱节点
			p->next = p->next->next;
			free_node(del_node);
			break;
		}
	}

	*head_p = head;
	return 0;
}


//查询一个节点
struct node * search(struct node *head, int data)
{
	struct node *p = NULL;

	for (p = head; p != NULL; p = p->next) {
		if (p->data == data) {
			return p;
		}
	}

	return NULL;
}


