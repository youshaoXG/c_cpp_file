#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// 求叶子节点数目
void leafNum(BiTNode* root, int* num)
{
	if (root == NULL)
	{
		// 递归结束的条件, 空树
		return;
	}
	// 遍历左子树
	leafNum(root->lChild, num);
	// 遍历右子树
	leafNum(root->rChild, num);
	// 叶子节点
	if (root->lChild == NULL && root->rChild == NULL)
	{
		(*num)++;
	}
}

// 求树的高度
int treeDepth(BiTNode* root)
{
	// 空树
	if (root == NULL)
	{
		// 高度为0
		return 0;
	}
	// 计算左子树高度
	int left = treeDepth(root->lChild);
	// 计算右子树高度
	int right = treeDepth(root->rChild);
	// 求出左右子树比较高的一个
	int max = left > right ? left : right;

	return max + 1;
}

// 拷贝二叉树
BiTNode* copyTree(BiTNode* root)
{
	// 空树
	if (root == NULL)
	{
		return NULL;
	}
	// 拷贝左子树
	BiTNode* left = copyTree(root->lChild);
	// 拷贝右子树
	BiTNode* right = copyTree(root->rChild);
	// 创建一个新节点
	BiTNode* pNew = (BiTNode*)malloc(sizeof(BiTNode));
	// 初始化
	pNew->data = root->data;
	// 指针域
	pNew->lChild = left;
	pNew->rChild = right;

	return pNew;
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

	int number = 0;
	leafNum(&nodeA, &number);
	printf("\n树的叶子节点数: %d\n", number);

	// 树的高度
	int depth = DepthF(&nodeA);
	printf("\n树的高度: %d\n", depth);

	BiTNode* root = copyTree(&nodeA);
	printf("遍历拷贝的二叉树 -- 中序: \n");
	zhongxuBL(root);
	printf("\n");



	system("pause");
}

