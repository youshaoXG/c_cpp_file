#pragma once

#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

//自顶一个一个模板数组类
//1 该数组能够存放int ， double  还有自定义类型
//2 []   array[i] = ???   ; array[i]
//3 cout <<array;
//4 array1 = array2
//5 array1(array2)
//6 array[i] = array[j]

template <class T>
class MyVector
{
public:
	//friend ostream & operator<< <T> (ostream &os, MyVector<T> &v);
	friend ostream & operator<<(ostream &os, MyVector<T> &v)
	{
		for (int i = 0; i < v.len; i++) {
			os << v[i] << " "; 
		}
		return os;
	}
	//无参的构造
	MyVector();
	MyVector(int num); //num 代表整个数组在初始化的连续开辟多少个元素
	MyVector(const MyVector & v); //拷贝构造函数
	~MyVector();


	//重写[]操作符
	T & operator[](int index);
	//array1 = array2 = array3
	MyVector & operator=(const MyVector &v);

private:
	int len;
	T *space;
};

template<class T>
MyVector<T>::MyVector()
{
	len = 0;
	this->space = NULL;
}

template<class T>
MyVector<T>::MyVector(int num)
{
	len = num;
	this->space = new T[num]; //在堆上连续开辟了 sizeof(T)*num
}

template<class T>
MyVector<T>::MyVector(const MyVector & v)
{
	this->len = v.len;
	this->space = new T[this->len];
	//copy数组中每一个元素
	for (int i = 0; i < this->len; i++) {
		this->space[i] = v.space[i]; //Teacher1 = teacher2  //如果存放对象，那么对象应该实现深拷贝
	}
}

template <class T>
MyVector<T> & MyVector<T>::operator=(const MyVector &v)
{
	if (this->space != NULL) {
		//存在之前旧数据 需要清理
		delete[] this->space;
		this->space = NULL;
		this->len = 0;
	}

	this->len = v.len;
	this->space = new T[this->len];//深拷贝动作

	//copy 数据
	for (int i = 0; i < this->len; i++) {
		this->space[i] = v.space[i];
	}

	return *this;
}

template<class T>
MyVector<T>::~MyVector()
{
	if (this->space != NULL) {
		delete[] this->space;
		this->len = 0;
	}
}

template <class T>
T & MyVector<T>::operator[](int index)
{
	return this->space[index];
}

/*
template <class T>
ostream & operator<<(ostream &os, MyVector<T> &v)
{
	for (int i = 0; i < v.len; i++) {
		os << v[i] << " ";
	}
	return os;
}
*/