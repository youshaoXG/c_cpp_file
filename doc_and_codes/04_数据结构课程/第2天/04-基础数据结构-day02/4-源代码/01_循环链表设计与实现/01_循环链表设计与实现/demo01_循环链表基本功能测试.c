#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircleList.h"

typedef struct tag_value
{
	CircleListNode circleNode;
	int v;
}Value;

#if 0
int main()
{
	int i;
	//����Value�ṹ������
	Value val[10];	//����ѭ������
	CircleList* list = CircleList_Create();

	//ѭ����ʼ������
	for (i = 0; i < sizeof(val) / sizeof(Value); ++i)
	{
		val[i].v = i + 20;
		//��ѭ�������в�������
		CircleList_Insert(list, (CircleListNode*)&val[i], i);
	}
	//����ѭ������
	//************* ��ô֤����ѭ������? *************
	for (i = 0; i < CircleList_Length(list) * 2; ++i)	//��ӡ����
	{
		Value *pVal = (Value*)CircleList_Get(list, i);
		printf("Value %d = %d\n", i, pVal->v);
	}
	//ɾ���ڵ�
	while (CircleList_Length(list) > 0)
	{
		Value *pVal = (Value*)CircleList_Delete(list, 0);
		printf("Delete Value: val = %d\n", pVal->v);
	}
	//����ѭ������
	CircleList_Destroy(list);

	return 0;
}
#endif