#pragma once

// 链表节点的结构
template <typename T>
struct StackNode
{
	// data
	T data;
	StackNode* next;
};

template <typename T>
class LinkStack
{
public:
	LinkStack();
	~LinkStack();

	// 进栈
	void push(T &data);
	// 出栈
	void pop();
	// 栈顶元素
	T top();
	// 大小
	int size();

private:
	// 指向栈顶 - 链表的头部做栈顶
	StackNode<T> *m_top;
	int m_length;
};

template <typename T>
int LinkStack<T>::size()
{
	return m_length;
}

template <typename T>
T LinkStack<T>::top()
{
	return m_top->data;
}

template <typename T>
void LinkStack<T>::pop()
{
	if (m_length == 0)
	{
		return;
	}
	StackNode<T>* pDel = m_top;
	// m_top 后移
	m_top = m_top->next;

	// 释放内存
	delete pDel;

	m_length--;
}

template <typename T>
void LinkStack<T>::push(T &data)
{
	// 创建节点
	StackNode<T>* pNew = new StackNode<T>;
	// 初始化
	pNew->data = data;
	pNew->next = NULL;

	// 新节点, 插入头部
	pNew->next = m_top;
	// m_top 指向第一个节点
	m_top = pNew;

	m_length++;
}

template <typename T>
LinkStack<T>::~LinkStack()
{
	while (m_length)
	{
		pop();
	}
}

template <typename T>
LinkStack<T>::LinkStack()
{
	m_length = 0;
	m_top = NULL;
}
