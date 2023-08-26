#include <stdio.h>
#include <stdlib.h>

// 定义结构
// 二叉链表表示法
typedef struct _tag_BitTNode
{
	// 数据域
	char data;
	// 左孩子
	struct _tag_BitTNode* lChild;
	// 右孩子
	struct _tag_BitTNode* rChild;
}BiTNode;

// 先序遍历
void xianxuBL(BiTNode* root)
{
	// 递归结束的条件
	if (root == NULL)
	{
		// 空节点结束
		return;
	}
	// 访问根节点
	printf("%c ", root->data);
	// 遍历左子树
	xianxuBL(root->lChild);
	// 遍历右子树
	xianxuBL(root->rChild);
}

// 中序
void zhongxuBL(BiTNode* root)
{
	// 递归结束的条件
	if (root == NULL)
	{
		// 空节点结束
		return;
	}
	// 遍历左子树
	zhongxuBL(root->lChild);
	// 访问根节点
	printf("%c ", root->data);
	// 遍历右子树
	zhongxuBL(root->rChild);
}

// 后序
void houxuBL(BiTNode* root)
{
	// 递归结束的条件
	if (root == NULL)
	{
		// 空节点结束
		return;
	}
	// 遍历左子树
	houxuBL(root->lChild);
	// 遍历右子树
	houxuBL(root->rChild);
	// 访问根节点
	printf("%c ", root->data);
}

void main()
{
	// 构建一颗二叉树
	BiTNode nodeA, nodeB, nodeC, nodeD, nodeE, nodeF, nodeG;
	// 初始化
	memset(&nodeA, 0, sizeof(BiTNode));
	memset(&nodeB, 0, sizeof(BiTNode));
	memset(&nodeC, 0, sizeof(BiTNode));
	memset(&nodeD, 0, sizeof(BiTNode));
	memset(&nodeE, 0, sizeof(BiTNode));
	memset(&nodeF, 0, sizeof(BiTNode));
	memset(&nodeG, 0, sizeof(BiTNode));

	// 构建树
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


	// 先序遍历
	printf("先序遍历: \n");
	xianxuBL(&nodeA);

	// 中序遍历
	printf("中序遍历: \n");
	zhongxuBL(&nodeA);


	// 后序遍历
	printf("后序遍历: \n");
	houxuBL(&nodeA);

}