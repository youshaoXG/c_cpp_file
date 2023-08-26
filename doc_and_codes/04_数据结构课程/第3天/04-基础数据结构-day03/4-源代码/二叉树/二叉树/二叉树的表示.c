#include <stdio.h>
#include <stdlib.h>

// ����ṹ
// ���������ʾ��
typedef struct _tag_BitTNode
{
	// ������
	char data;
	// ����
	struct _tag_BitTNode* lChild;
	// �Һ���
	struct _tag_BitTNode* rChild;
}BiTNode;

// �������
void xianxuBL(BiTNode* root)
{
	// �ݹ����������
	if (root == NULL)
	{
		// �սڵ����
		return;
	}
	// ���ʸ��ڵ�
	printf("%c ", root->data);
	// ����������
	xianxuBL(root->lChild);
	// ����������
	xianxuBL(root->rChild);
}

// ����
void zhongxuBL(BiTNode* root)
{
	// �ݹ����������
	if (root == NULL)
	{
		// �սڵ����
		return;
	}
	// ����������
	zhongxuBL(root->lChild);
	// ���ʸ��ڵ�
	printf("%c ", root->data);
	// ����������
	zhongxuBL(root->rChild);
}

// ����
void houxuBL(BiTNode* root)
{
	// �ݹ����������
	if (root == NULL)
	{
		// �սڵ����
		return;
	}
	// ����������
	houxuBL(root->lChild);
	// ����������
	houxuBL(root->rChild);
	// ���ʸ��ڵ�
	printf("%c ", root->data);
}

void main()
{
	// ����һ�Ŷ�����
	BiTNode nodeA, nodeB, nodeC, nodeD, nodeE, nodeF, nodeG;
	// ��ʼ��
	memset(&nodeA, 0, sizeof(BiTNode));
	memset(&nodeB, 0, sizeof(BiTNode));
	memset(&nodeC, 0, sizeof(BiTNode));
	memset(&nodeD, 0, sizeof(BiTNode));
	memset(&nodeE, 0, sizeof(BiTNode));
	memset(&nodeF, 0, sizeof(BiTNode));
	memset(&nodeG, 0, sizeof(BiTNode));

	// ������
	nodeA.data = 'A';
	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeC;

	nodeB.data = 'B';
	nodeB.lChild = &nodeD;
	nodeB.rChild = &nodeE;

	nodeC.data = 'C';
	nodeC.lChild = &nodeF;
	nodeC.rChild = &nodeG;

	nodeD.data = 'D';
	nodeE.data = 'E';
	nodeF.data = 'F';
	nodeG.data = 'G';


	// �������
	printf("�������: \n");
	xianxuBL(&nodeA);

	// �������
	printf("�������: \n");
	zhongxuBL(&nodeA);


	// �������
	printf("�������: \n");
	houxuBL(&nodeA);

}