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

//����һ���ڵ�Ľӿ�
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

//����һ���ڵ�
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

	//�ҵ����һ���ڵ�ĵ�ַ����last_node ָ����
	for (last_node = head; last_node->next != NULL; last_node = last_node->next);

	//��֤new_node��next ָ��NULL
	new_node->next = last_node->next;

	last_node->next = new_node;

	return 0;
}

//����һ������Ľڵ�
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

//ɾ����ͷ����Ԫ��
__declspec(dllexport)
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


//�����ͳһ�����ķ���
__declspec(dllexport)
void for_each(struct node *head, void(*fp)(struct node *node)) //fp = print_node
{
	struct node *p = NULL;

	for (p = head->next; p != NULL; p = p->next) {
		//����һ������ �ҵ�ÿ��Ԫ�صĽڵ�
		//�ֱ���� fp �������ķ��� ȥִ��ÿ���ڵ��ҵ��
		fp(p);//printf_node(p);
	}
}

//����һ������
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

//����һ������
__declspec(dllexport)
int reverse(struct node *head)
{
	struct node *p = NULL; //׼������Ľڵ�
	struct node *prev_p = NULL;//p��ǰ��
	struct node *next_p = NULL;//p�ĺ��

	//��ʼ��
	prev_p = head;
	p = head->next;

	while (p != NULL) {
		//����next_p ָ��p�ĺ��
		next_p = p->next;
		//�ı�p�ĺ��Ϊp��ǰ��
		p->next = prev_p;

		//��p��ǰ������p
		prev_p = p;
		
		//��p���� ԭ��p�ĺ�� next_p
		p = next_p;
	}

	//�ȸı�ԭ����Ԫ�ص�дһ����ַ
	head->next->next = NULL;
	
	//��ͷ��� ָ��Ŀǰ�� prev_p Ҳ�����µ���Ԫ�ص�ַ
	head->next = prev_p;

	return 0;
}