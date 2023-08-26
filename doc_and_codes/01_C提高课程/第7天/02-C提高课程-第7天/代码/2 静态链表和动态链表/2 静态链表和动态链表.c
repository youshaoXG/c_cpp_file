#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//����Ľڵ�
struct teacher {
	int data;
	struct teacher *next;
};

//��̬����
void test1()
{
	struct teacher t1, t2, t3, t4, t5; //��̬�������еĽڵ㣬����Ԥ�ȿ�����ϵģ��ڵ�ĸ����ǹ̶��ġ�
	struct teacher *p = NULL; //���������ָ��

	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	t1.next = &t2;//t1->t2
	t2.next = &t3;//t1->t2->t3
	t3.next = &t4;//t1->t2->t3->t4
	t4.next = &t5;//t1->t2->t3->t4->t5
	t5.next = NULL;//t1->t2->t3->t4->t5->NULL

	//����һ����̬������
	for (p = &t1; p != NULL; p = p->next) {
		printf("p->data:%d\n", p->data);
	}
}

//��̬����
void test2()
{
	struct teacher *head = NULL; //ͷָ��
	struct teacher *last_node = NULL;//ʼ��ָ�����һ��Ԫ�ص�ָ��
	struct teacher *new_node = NULL;//��һ���´���������Ľڵ�ָ��
	struct teacher *p = NULL; //������������ʱָ��
	int data = 0;

	printf("������һ����ʦ��data: ");
	scanf("%d", &data);
	while (data != -1) {
		//��̬����һ������Ľڵ�
		new_node = (struct teacher *)malloc(sizeof(struct teacher));
		if (new_node == NULL) {
			return;
		}
		memset(new_node, 0, sizeof(struct teacher));

		new_node->data = data;
		new_node->next = NULL;

		//��new_node ��ӵ� head������
		if (head == NULL){
			head = new_node;
		}
		else {
			last_node->next = new_node;
			last_node = new_node;
		}

		last_node = new_node;

		printf("������һ����ʦ��data: ");
		scanf("%d", &data);
	}

	//����һ������
	for (p = head; p != NULL; p = p->next) {
		printf("%d\n", p->data);
	}

	//�ͷ����еĽڵ�
	for (p = head; p != NULL; )
	{
		head = p->next;
		free(p);
		p = head;
	}

	if (head == NULL) {
		printf("list is NULL\n");
	}
}

int main(void)
{
	//test1();
	test2();

	return 0;
}