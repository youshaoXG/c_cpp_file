#pragma  once
template <typename T>
class SqStack
{
public:
	SqStack(int capacity);
	~SqStack();

	// ��ջ
	void push(T &data);
	// ��ջ
	void pop();
	// ջ��Ԫ��
	T top();
	// ��С
	int size();

private:
	// ָ��
	T *m_array;
	int m_top;	// ջ��
	int m_capacity;
};

template <typename T>
T SqStack<T>::top()
{
	return m_array[m_top];
}

template <typename T>
int SqStack<T>::size()
{
	return m_top + 1;
}

template <typename T>
void SqStack<T>::pop()
{
	if (m_top == -1)
	{
		return;
	}
	// ջ������
	m_top--;
}

template <typename T>
void SqStack<T>::push(T &data)
{
	// ����β��������
	// ����
	if (m_top == m_capacity - 1)
	{
		return;
	}
	m_top++;	// ջ������
	m_array[m_top] = data;
}

template <typename T>
SqStack<T>::~SqStack()
{
	// �ͷ��ڴ�
	delete []m_array;
}

template <typename T>
SqStack<T>::SqStack(int capacity)
{
	// ��̬��������
	m_array = new T[capacity];
	// 
	m_top = -1;
	m_capacity = capacity;
}

