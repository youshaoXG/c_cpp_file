#pragma  once

template <typename T>
class SqQueue
{
public:
	SqQueue(int capacticy);
	~SqQueue();

	// �����
	void push(T &data);
	// ������
	void pop();
	// ��ȡ��ͷ
	T front();
	// ��β
	T back();
	// ����
	int length();

private:
	// ָ��
	T *m_array;
	int m_capacity;
	int m_rear;	// ��β
// 	int m_front = 0;
};

template <typename T>
int SqQueue<T>::length()
{
	return m_rear + 1;
}

template <typename T>
T SqQueue<T>::back()
{
	return m_array[m_rear];
}

template <typename T>
T SqQueue<T>::front()
{
	return m_array[0];
}

template <typename T>
void SqQueue<T>::pop()
{
	if (m_rear == -1)
	{
		return;
	}
	// ɾ��������0��λ��Ԫ��
	for (int i = 1; i <= m_rear; ++i)
	{
		m_array[i - 1] = m_array[i];
	}
	m_rear--;
}

// �����ͷ��Ϊ��ͷ, β����β
template <typename T>
void SqQueue<T>::push(T &data)
{
	if (m_rear == m_capacity - 1)
	{
		return;
	}
	// ��β����
	m_rear++;
	// ��ֵ
	m_array[m_rear] = data;
}

template <typename T>
SqQueue<T>::~SqQueue()
{
	delete[]m_array;
}

template <typename T>
SqQueue<T>::SqQueue(int capacticy)
{
	m_array = new T[capacticy];
	m_capacity = capacticy;
	m_rear = -1;
}
