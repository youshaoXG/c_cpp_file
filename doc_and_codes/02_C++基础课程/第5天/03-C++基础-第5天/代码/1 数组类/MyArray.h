#pragma once

#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

class MyArray
{
public:
	//�޲ι��캯��
	MyArray();

	//�ڸ������ʼ����ʱ�򣬿��ٶ��ٸ�Ԫ�ؿռ�
	MyArray(int len);

	//�������캯��
	MyArray(const MyArray& another);

	//��ʾ���ṩ=�Ų�����
	MyArray & operator=(const MyArray &another);

	//���ز�����[]
	int& operator[](int index) const;

	//���� == ������
	bool operator==(const MyArray & array); // array.operator==(array2)
	bool operator!=(const MyArray &array);

	int getLen();

	//index ����Ҫ��ֵ��������±�, data ����
	void setData(int index, int data);

	int getData(int index);



	~MyArray();

	friend ostream & operator<<(ostream &os, const  MyArray &array);
	friend istream & operator >> (istream &is, MyArray &array);

private:
	int length; //����Ŀǰ��Ԫ�ظ���
	int *space; //space ���ڶ��Ͽ�������ռ����Ԫ�ص�ַ��
};

