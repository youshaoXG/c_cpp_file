#include "LinkList.h"

template <typename T>
LinkList<T>::LinkList()
{
	// 给头结点分配存储空间
	m_head = new ListNode<T>;
	// 初始化
	m_head->next = NULL;
	// 长度
	m_length = 0;

	cout << "LinkList 构造完成!" << endl;
}

template <typename T>
LinkList<T>::~LinkList()
{
	clear();
	// 释放头结点
	delete m_head;

	cout << "LinkList 析构完成!" << endl;
}

template <typename T>
void LinkList<T>::insert(int pos, T &data)
{
	if (pos < 0 || pos >m_length)
	{
		// 无效位置
		return;
	}
	// 辅助指针
	ListNode<T>* pCur = m_head;
	// 遍历 - 寻找pos-1
	for (int i = 0; i < pos; ++i)
	{
		pCur = pCur->next;
	}

	// 创建新节点
	ListNode<T>* pnew = new ListNode<T>;
	// 初始化
	pnew->data = data;

	// 新节点添加到链表
	pnew->next = pCur->next;
	pCur->next = pnew;

	//长度
	m_length++;
}

template <typename T>
T LinkList<T>::del(int pos)
{
	// 辅助指针
	ListNode<T>* pCur = m_head;
	// 遍历 - 寻找pos-1
	for (int i = 0; i < pos; ++i)
	{
		pCur = pCur->next;
	}
	// 辅助指针, 指向pos节点
	ListNode<T>* pDel = pCur->next;
	T t = pDel->data;

	// 从链表中删除节点
	pCur->next = pDel->next;

	// 释放内存
	delete pDel;

	m_length--;

	return t;
}

template <typename T>
T LinkList<T>::get(int pos)
{
	// 辅助指针
	ListNode<T>* pCur = m_head;
	// 遍历 - 寻找pos
	for (int i = 0; i <= pos; ++i)
	{
		pCur = pCur->next;
	}
	return pCur->data;
}

template <typename T>
void LinkList<T>::clear()
{
	// 清空所有数据节点
	// 删除数据节点
	while (m_length)
	{
		del(0);
	}
}

template <typename T>
int LinkList<T>::length()
{
	return m_length;
}