#pragma  once

template <typename T>
class SqQueue
{
public:
	SqQueue(int capacticy);
	~SqQueue();

	// 入队列
	void push(T &data);
	// 出队列
	void pop();
	// 获取队头
	T front();
	// 队尾
	T back();
	// 长度
	int length();

private:
	// 指针
	T *m_array;
	int m_capacity;
	int m_rear;	// 队尾
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
	// 删除的数组0号位置元素
	for (int i = 1; i <= m_rear; ++i)
	{
		m_array[i - 1] = m_array[i];
	}
	m_rear--;
}

// 数组的头部为队头, 尾部队尾
template <typename T>
void SqQueue<T>::push(T &data)
{
	if (m_rear == m_capacity - 1)
	{
		return;
	}
	// 队尾后移
	m_rear++;
	// 赋值
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
