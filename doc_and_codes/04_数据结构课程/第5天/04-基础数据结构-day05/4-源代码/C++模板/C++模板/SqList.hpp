#pragma once

template <typename T>
class SqList
{
public:
	SqList(int capacity);
	~SqList();

	// ָ��λ�ò�������
	void insert(int pos, T &data);
	// ......ɾ��..
	T del(int pos);
	// ��ȡָ��....����
	T get(int pos);
	// ���
	void clear();
	// ��ȡ����
	int length();

private:
	T *m_array;	// ����
	int m_length;	// ��ǵ�ǰ������Ԫ�صĸ���
	int m_capacity;	// ����
};


template <typename T>
SqList<T>::SqList(int capacity)
{
	// ��̬��������
	m_array = new T[capacity];
	m_length = 0;
	m_capacity = capacity;

	cout << "SqList �������!" << endl;
}

template <typename T>
SqList<T>::~SqList()
{
	// �ͷ��ڴ�
	delete []m_array;

	cout << "SqList �������!" << endl;
}

template <typename T>
void SqList<T>::insert(int pos, T &data)
{
	if (pos <0 || pos > m_length)
	{
		return;
	}
	if (m_length >= m_capacity)
	{
		return;
	}
	// �� length-1 �� pos ���κ���
	for (int i = m_length - 1; i >= pos; --i)
	{
		m_array[i + 1] = m_array[i];
	}
	// ��ֵ
	m_array[pos] = data;
	// ����+1
	m_length++;
}

template <typename T>
T SqList<T>::del(int pos)
{
	T t = m_array[pos];
	// pos+1 �� ���һ�� ����ǰ��
	for (int i = pos + 1; i < m_length; ++i)
	{
		m_array[i - 1] = m_array[i];
	}
	// ����-1
	m_length--;

	return t;
}

template <typename T>
T SqList<T>::get(int pos)
{
	T t = m_array[pos];
	return t;
}

template <typename T>
void SqList<T>::clear()
{
	m_length = 0;
}

template <typename T>
int SqList<T>::length()
{
	return m_length;
}



