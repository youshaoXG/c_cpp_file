#pragma once
#define  _CRT_SECURE_NO_WARNINGS 

#include <iostream>
using namespace std;

class MyString
{
public:
	MyString();
	~MyString();
	MyString(int len); //����len�����ȵ��ַ��� ȫ������Ϊ0
	MyString(const MyString &another); //�������캯��
	MyString & operator=(const MyString &another); //��ʾ��=������
	MyString(const char *str);// ����str�ַ�����ʼ��mystring

	char & operator[](int index); //���ء���������

	bool operator ==(const MyString &another);
	bool operator !=(const MyString &another);
	bool operator>(const MyString &myString);
	bool operator<(const MyString &myString);

	friend ostream &  operator <<(ostream &os, MyString &s);
	friend istream & operator>>(istream &is, MyString &s);

	int getLen();

private:
	char *str;//ָ���ڶ��Ͽ����ַ����ռ��׵�ַ
	int len;//��ǰ�ַ����ĳ���
};

