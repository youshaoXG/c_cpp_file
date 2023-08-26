#pragma once

#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

//�Զ�һ��һ��ģ��������
//1 �������ܹ����int �� double  �����Զ�������
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
	//�޲εĹ���
	MyVector();
	MyVector(int num); //num �������������ڳ�ʼ�����������ٶ��ٸ�Ԫ��
	MyVector(const MyVector & v); //�������캯��
	~MyVector();


	//��д[]������
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
	this->space = new T[num]; //�ڶ������������� sizeof(T)*num
}

template<class T>
MyVector<T>::MyVector(const MyVector & v)
{
	this->len = v.len;
	this->space = new T[this->len];
	//copy������ÿһ��Ԫ��
	for (int i = 0; i < this->len; i++) {
		this->space[i] = v.space[i]; //Teacher1 = teacher2  //�����Ŷ�����ô����Ӧ��ʵ�����
	}
}

template <class T>
MyVector<T> & MyVector<T>::operator=(const MyVector &v)
{
	if (this->space != NULL) {
		//����֮ǰ������ ��Ҫ����
		delete[] this->space;
		this->space = NULL;
		this->len = 0;
	}

	this->len = v.len;
	this->space = new T[this->len];//�������

	//copy ����
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