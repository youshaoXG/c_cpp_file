#pragma  once
template <typename T>
class SqStack
{
public:
	SqStack(int capacity);
	~SqStack();

	// 进栈
	void push(T &data);
	// 出栈
	void pop();
	// 栈顶元素
	T top();
	// 大小
	int size();

private:
	// 指针
	T *m_array;
	int m_top;	// 栈顶
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
	// 栈顶下移
	m_top--;
}

template <typename T>
void SqStack<T>::push(T &data)
{
	// 数组尾部放数据
	// 已满
	if (m_top == m_capacity - 1)
	{
		return;
	}
	m_top++;	// 栈顶上移
	m_array[m_top] = data;
}

template <typename T>
SqStack<T>::~SqStack()
{
	// 释放内存
	delete []m_array;
}

template <typename T>
SqStack<T>::SqStack(int capacity)
{
	// 动态创建数组
	m_array = new T[capacity];
	// 
	m_top = -1;
	m_capacity = capacity;
}

