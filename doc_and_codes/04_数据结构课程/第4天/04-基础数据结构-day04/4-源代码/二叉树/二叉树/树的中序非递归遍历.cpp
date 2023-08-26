#include <iostream>
#include <stack>
using namespace std;

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

/*
	����1��
	�����������������ý����ջ��
	������û�������������ʸý�㣻
	����2��
	�����������������ظ�����1��
	������û������������������ϣ�������ջ��ָʾ���ˣ�����ջ��Ԫ�أ����������������ظ�����1
	���ջΪ�գ���ʾ����������

*/
// ����1
BiTNode* FindLeft(BiTNode* root, stack<BiTNode*> &st)
{
	if (root == NULL)
	{
		return NULL;
	}
	// Ѱ������Ľڵ�
	while (root->lChild != NULL)
	{
		// �ýڵ���ջ
		st.push(root);
		// ��ǰָ��ָ������
		root = root->lChild;
	}
	// ����û�����ӵĽڵ�
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
		// ����
		cout << left->data;
		// �ж�left��û��������
		if (left->rChild)
		{
			left = FindLeft(left->rChild, st);
		}
		else
		{
			// û��������
			// �ж�ջ�Ƿ�Ϊ��
			if (!st.empty())
			{
				// ȡ��ջ��Ԫ��
				left = st.top();
				// ����
				st.pop();
			}
			else
			{
				cout << "��������!" << endl;
				break;
			}
		}
	}
}


// ���ŷ������� -- ��������ķ�ʽ
BiTNode* createTree()
{
	char c;
	// ����ڵ�����
	cin >> c;
	if (c == '#')
	{
		return NULL;
	}
	// �ȴ������ڵ�
	BiTNode* root = new BiTNode;
	// ��ʼ��
	root->data = c;
	// ����������
	root->lChild = createTree();
	// ����������
	root->rChild = createTree();

	return root;
}
// ������
void destroyTree(BiTNode* root)
{
	// ��������ķ�ʽ���� - ����
	if (root == NULL)
	{
		return;
	}
	// ����������
	destroyTree(root->lChild);
	// ����������
	destroyTree(root->rChild);
	cout << root->data << endl;
	// �ͷŸ��ڵ�
	delete root;
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

	printf("��������ǵݹ�: \n");
	MyOrder(&nodeA);

	//
	cout << "���ŷ�������: ABDH#K###E##CFI###G#J##";
	BiTNode* root = createTree();
	cout << "�������: ";
	MyOrder(root);
	cout << endl;

	destroyTree(root);

	system("pause");

}