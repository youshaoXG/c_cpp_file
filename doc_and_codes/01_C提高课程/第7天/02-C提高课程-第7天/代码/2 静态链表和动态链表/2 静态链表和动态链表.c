#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//链表的节点
struct teacher {
	int data;
	struct teacher *next;
};

//静态链表
void test1()
{
	struct teacher t1, t2, t3, t4, t5; //静态链表所有的节点，都是预先开辟完毕的，节点的个数是固定的。
	struct teacher *p = NULL; //遍历链表的指针

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

	//遍历一个静态的链表
	for (p = &t1; p != NULL; p = p->next) {
		printf("p->data:%d\n", p->data);
	}
}

//动态链表
void test2()
{
	struct teacher *head = NULL; //头指针
	struct teacher *last_node = NULL;//始终指向最后一个元素的指针
	struct teacher *new_node = NULL;//是一个新创建的链表的节点指针
	struct teacher *p = NULL; //遍历遍历的临时指针
	int data = 0;

	printf("请输入一个老师的data: ");
	scanf("%d", &data);
	while (data != -1) {
		//动态创建一个链表的节点
		new_node = (struct teacher *)malloc(sizeof(struct teacher));
		if (new_node == NULL) {
			return;
		}
		memset(new_node, 0, sizeof(struct teacher));

		new_node->data = data;
		new_node->next = NULL;

		//将new_node 添加到 head链表中
		if (head == NULL){
			head = new_node;
		}
		else {
			last_node->next = new_node;
			last_node = new_node;
		}

		last_node = new_node;

		printf("请输入一个老师的data: ");
		scanf("%d", &data);
	}

	//遍历一个链表
	for (p = head; p != NULL; p = p->next) {
		printf("%d\n", p->data);
	}

	//释放所有的节点
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