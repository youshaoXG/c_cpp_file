#pragma once

template <typename T>
class SqList
{
public:
	SqList(int capacity);
	~SqList();

	// 指定位置插入数据
	void insert(int pos, T &data);
	// ......删除..
	T del(int pos);
	// 获取指定....数据
	T get(int pos);
	// 清空
	void clear();
	// 获取长度
	int length();

private:
	T *m_array;	// 数组
	int m_length;	// 标记当前数组中元素的个数
	int m_capacity;	// 容量
};


template <typename T>
SqList<T>::SqList(int capacity)
{
	// 动态创建数组
	m_array = new T[capacity];
	m_length = 0;
	m_capacity = capacity;

	cout << "SqList 构造完成!" << endl;
}

template <typename T>
SqList<T>::~SqList()
{
	// 释放内存
	delete []m_array;

	cout << "SqList 析构完成!" << endl;
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
	// 从 length-1 到 pos 依次后移
	for (int i = m_length - 1; i >= pos; --i)
	{
		m_array[i + 1] = m_array[i];
	}
	// 赋值
	m_array[pos] = data;
	// 长度+1
	m_length++;
}

template <typename T>
T SqList<T>::del(int pos)
{
	T t = m_array[pos];
	// pos+1 到 最后一个 依次前移
	for (int i = pos + 1; i < m_length; ++i)
	{
		m_array[i - 1] = m_array[i];
	}
	// 长度-1
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



