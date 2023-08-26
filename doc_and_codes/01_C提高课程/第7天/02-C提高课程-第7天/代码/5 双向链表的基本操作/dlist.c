#include "dlist.h"


//��ʼ��һ��˫������
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

//����һ���ڵ�
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

//����һ���ڵ�
void free_node(struct node *node)
{
	if (node != NULL) {
		free(node);
	}
}

//����һ���ڵ�
int insert_node(struct node *head, struct node *tail, struct node *new_node)
{
	if (head == NULL || tail == NULL || new_node == NULL) {
		return -1;
	}

	//�ı�new_node �������ָ��
	new_node->next = head->next;
	new_node->prev = head;

	//�ı�new _node ���ߵ�ָ��
	new_node->next->prev = new_node;
	new_node->prev->next = new_node;

	return 0;
}


//����һ������
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

//����һ���ڵ�
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

//ɾ��һ��˫������Ľڵ�
int delete_node(struct node*head, struct node *tail, struct node *del_node)
{
	struct node *p = NULL;

	for (p = head->next; p != tail; p = p->next) {
		//���������г��� head ��tail��ÿһ��Ԫ��
		if (p == del_node) {
			//p��ɾ���Ľڵ�
			//Ӧ�øı� p��ǰ���ڵ� �� p�ĺ�̽ڵ� �� p���������ָ�벻Ҫ��
			p->next->prev = p->prev;
			p->prev->next = p->next;
			free_node(p);
			break;
		}
	}

	return 0;
}

//����һ��˫������
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
	//���Ͼ�ɾ���� ����head ��tail��ȫ��Ԫ��

	if (head->next == tail &&tail->prev == head) {
		printf("��ʱ�����Ѿ��� ����(head , tail)\n");
		free_node(head);
		free_node(tail);
		*head_p = NULL;
		*tail_p = NULL;
	}

	return;
}