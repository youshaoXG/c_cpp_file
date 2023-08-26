#include "has_head_list.h"

int init_list(struct node **head_p)
{
	struct node *head = NULL;

	head = (struct node*)malloc(sizeof(struct node));
	if (head == NULL) {
		fprintf(stderr, "malloc head error\n");
		return -1;
	}

	head->data = 0;
	head->next = NULL;

	*head_p = head;

	return 0;
}

//����һ���ڵ�Ľӿ�
struct node* make_node(int data)
{
	struct node *new_node = NULL;

	new_node = (struct node*)malloc(sizeof(struct node));
	if (new_node == NULL) {
		return NULL;
	}

	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}

//����һ���ڵ�
void free_node(struct node *node)
{
	if (node != NULL) {
		free(node);
	}
}

int insert_node_from_begin(struct node *new_node, struct node *head)
{
	if (new_node == NULL || head == NULL) {
		return -1;
	}

	new_node->next = head->next;
	head->next = new_node;

	return 0;
}

int insert_node_to_end(struct node *new_node, struct node *head)
{
	struct node *last_node = NULL;

	if (new_node == NULL || head == NULL) {
		return -1;
	}

	//�ҵ����һ���ڵ�ĵ�ַ����last_node ָ����
	for (last_node = head; last_node->next != NULL; last_node = last_node->next);

	//��֤new_node��next ָ��NULL
	new_node->next = last_node->next;

	last_node->next = new_node;

	return 0;
}

//����һ������Ľڵ�
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

//ɾ����ͷ����Ԫ��
int delete_node(struct node *del_node, struct node* head)
{
	struct node *p = NULL;

	if (del_node == NULL || head == NULL) {
		return -1;
	}

	for (p = head; p->next != NULL; p = p->next) {
		if (p->next == del_node) {
			//�ҵ��˱�ɾ���Ľڵ� ����p->next
			p->next = p->next->next;
			free_node(del_node);
			break;
		}
	}

	return 0;
}

//����һ����ͷ�ڵ������
void print_list(struct node *head)
{
	struct node *p = NULL;

	for (p = head->next; p != NULL; p = p->next) {
		printf("data: %d\n", p->data);
	}
}

//����һ������
void destory_list(struct node **head_p)
{
	struct node * p = NULL;
	struct node *head = NULL;

	if (head_p == NULL) {
		return;
	}

	head = *head_p;

	for (p = head->next; p != NULL;) {
		//p����Ҫɾ���Ľڵ�
		head->next = p->next;
		free_node(p);
		p = head->next;
	}

	//���ѭ���˳���˵�� head->next = NULL
	if (head != NULL) {
		free_node(head);
		*head_p = NULL;
	}
}