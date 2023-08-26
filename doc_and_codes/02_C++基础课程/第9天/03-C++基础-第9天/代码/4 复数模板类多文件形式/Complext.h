#pragma once
#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;


template <class T>
class Complex
{
public:
	Complex();
	~Complex();
	Complex(T a, T b);
	void pirntComplex();

	Complex operator+(Complex &another);

	Complex operator-(Complex &another);
private:
	T a;
	T b;
};

