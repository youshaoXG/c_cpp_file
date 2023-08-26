#include "LinkList.h"

template <typename T>
LinkList<T>::LinkList()
{
	// ��ͷ������洢�ռ�
	m_head = new ListNode<T>;
	// ��ʼ��
	m_head->next = NULL;
	// ����
	m_length = 0;

	cout << "LinkList �������!" << endl;
}

template <typename T>
LinkList<T>::~LinkList()
{
	clear();
	// �ͷ�ͷ���
	delete m_head;

	cout << "LinkList �������!" << endl;
}

template <typename T>
void LinkList<T>::insert(int pos, T &data)
{
	if (pos < 0 || pos >m_length)
	{
		// ��Чλ��
		return;
	}
	// ����ָ��
	ListNode<T>* pCur = m_head;
	// ���� - Ѱ��pos-1
	for (int i = 0; i < pos; ++i)
	{
		pCur = pCur->next;
	}

	// �����½ڵ�
	ListNode<T>* pnew = new ListNode<T>;
	// ��ʼ��
	pnew->data = data;

	// �½ڵ���ӵ�����
	pnew->next = pCur->next;
	pCur->next = pnew;

	//����
	m_length++;
}

template <typename T>
T LinkList<T>::del(int pos)
{
	// ����ָ��
	ListNode<T>* pCur = m_head;
	// ���� - Ѱ��pos-1
	for (int i = 0; i < pos; ++i)
	{
		pCur = pCur->next;
	}
	// ����ָ��, ָ��pos�ڵ�
	ListNode<T>* pDel = pCur->next;
	T t = pDel->data;

	// ��������ɾ���ڵ�
	pCur->next = pDel->next;

	// �ͷ��ڴ�
	delete pDel;

	m_length--;

	return t;
}

template <typename T>
T LinkList<T>::get(int pos)
{
	// ����ָ��
	ListNode<T>* pCur = m_head;
	// ���� - Ѱ��pos
	for (int i = 0; i <= pos; ++i)
	{
		pCur = pCur->next;
	}
	return pCur->data;
}

template <typename T>
void LinkList<T>::clear()
{
	// ����������ݽڵ�
	// ɾ�����ݽڵ�
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