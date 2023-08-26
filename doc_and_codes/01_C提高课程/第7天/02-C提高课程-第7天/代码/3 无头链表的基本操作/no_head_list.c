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

//����һ���ڵ�
void free_node(struct node *node)
{
	if (node != NULL) {
		free(node);
	}
}

//����һ���ڵ㵽head��
int insert_node_to_end(struct node *new_node, struct node **head_p)
{
	struct node *head = NULL;
	struct node *last_node = NULL;

	if (new_node == NULL  || head_p == NULL) {
		return 0;
	}
	head = *head_p;

	if (head == NULL) {
		//�����ʱ�ǿ�����
		head = new_node;
		//��ͷ���� ���ص���Ҫ��head�Ƿ�Ϊ�� �����ж�
	}
	else {
		//�ҵ����last_node
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

	//����Ĳ���
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

//����һ������
void destory_list(struct node **head_p)
{
	struct node *head = *head_p;
	struct node *p = NULL;

	while (head != NULL) {
		//������Ԫ��
		p = head;
		head = head->next;
		free_node(p);
	}


	*head_p = head;
}

//ɾ��һ���ڵ㣬����Ҫɾ���ڵ��ָ����ɾ��
int delete_node(struct node *del_node, struct node  **head_p)
{
	struct node *head = *head_p;
	struct node *p = NULL;


	if (head == del_node) {
		//���Ҫɾ���Ľڵ����׽��
		head = head->next;
		free_node(del_node);
		*head_p = head;

		return 0;
	}

	//Ҫɾ���Ĳ���ͷ���
	for (p = head; p != NULL; p = p->next) {
		if (p->next == del_node) {
			//�ҵ���Ҫɾ���Ľڵ㣬��ʱp�����Ҫɾ���ڵ�ǰ���ڵ�
			p->next = p->next->next;
			free_node(del_node);
			break;
		}
	}

	*head_p = head;
	return 0;
}


//��ѯһ���ڵ�
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


