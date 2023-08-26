#pragma once

// ����ڵ�Ľṹ
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

	// ��ջ
	void push(T &data);
	// ��ջ
	void pop();
	// ջ��Ԫ��
	T top();
	// ��С
	int size();

private:
	// ָ��ջ�� - �����ͷ����ջ��
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
	// m_top ����
	m_top = m_top->next;

	// �ͷ��ڴ�
	delete pDel;

	m_length--;
}

template <typename T>
void LinkStack<T>::push(T &data)
{
	// �����ڵ�
	StackNode<T>* pNew = new StackNode<T>;
	// ��ʼ��
	pNew->data = data;
	pNew->next = NULL;

	// �½ڵ�, ����ͷ��
	pNew->next = m_top;
	// m_top ָ���һ���ڵ�
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
