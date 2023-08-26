#include <iostream>
#include <stack>
using namespace std;

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

/*
	步骤1：
	如果结点有左子树，该结点入栈；
	如果结点没有左子树，访问该结点；
	步骤2：
	如果结点有右子树，重复步骤1；
	如果结点没有右子树（结点访问完毕），根据栈顶指示回退，访问栈顶元素，并访问右子树，重复步骤1
	如果栈为空，表示遍历结束。

*/
// 步骤1
BiTNode* FindLeft(BiTNode* root, stack<BiTNode*> &st)
{
	if (root == NULL)
	{
		return NULL;
	}
	// 寻找最左的节点
	while (root->lChild != NULL)
	{
		// 该节点入栈
		st.push(root);
		// 当前指针指向左孩子
		root = root->lChild;
	}
	// 返回没有左孩子的节点
	return root;
}

void MyOrder(BiTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	stack<BiTNode*> st;
	BiTNode* left = FindLeft(root, st);

	while (left != NULL)
	{
		// 访问
		cout << left->data;
		// 判断left又没有右子树
		if (left->rChild)
		{
			left = FindLeft(left->rChild, st);
		}
		else
		{
			// 没有右子树
			// 判断栈是否为空
			if (!st.empty())
			{
				// 取出栈顶元素
				left = st.top();
				// 弹出
				st.pop();
			}
			else
			{
				cout << "遍历结束!" << endl;
				break;
			}
		}
	}
}


// 井号法创建树 -- 先序遍历的方式
BiTNode* createTree()
{
	char c;
	// 输入节点数据
	cin >> c;
	if (c == '#')
	{
		return NULL;
	}
	// 先创建根节点
	BiTNode* root = new BiTNode;
	// 初始化
	root->data = c;
	// 创建左子树
	root->lChild = createTree();
	// 创建右子树
	root->rChild = createTree();

	return root;
}
// 销毁树
void destroyTree(BiTNode* root)
{
	// 后序遍历的方式销毁 - 必须
	if (root == NULL)
	{
		return;
	}
	// 销毁左子树
	destroyTree(root->lChild);
	// 销毁右子树
	destroyTree(root->rChild);
	cout << root->data << endl;
	// 释放根节点
	delete root;
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

	printf("树的中序非递归: \n");
	MyOrder(&nodeA);

	//
	cout << "井号法创建树: ABDH#K###E##CFI###G#J##";
	BiTNode* root = createTree();
	cout << "中序遍历: ";
	MyOrder(root);
	cout << endl;

	destroyTree(root);

	system("pause");

}