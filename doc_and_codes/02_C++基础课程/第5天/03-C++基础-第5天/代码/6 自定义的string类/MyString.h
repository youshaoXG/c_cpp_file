#pragma once
#define  _CRT_SECURE_NO_WARNINGS 

#include <iostream>
using namespace std;

class MyString
{
public:
	MyString();
	~MyString();
	MyString(int len); //开辟len个长度的字符串 全部设置为0
	MyString(const MyString &another); //拷贝构造函数
	MyString & operator=(const MyString &another); //显示的=操作符
	MyString(const char *str);// 根据str字符串初始化mystring

	char & operator[](int index); //重载【】操作符

	bool operator ==(const MyString &another);
	bool operator !=(const MyString &another);
	bool operator>(const MyString &myString);
	bool operator<(const MyString &myString);

	friend ostream &  operator <<(ostream &os, MyString &s);
	friend istream & operator>>(istream &is, MyString &s);

	int getLen();

private:
	char *str;//指向在堆上开辟字符串空间首地址
	int len;//当前字符串的长度
};

