#include "Complext.h"

//最终通过第二次编译生成class Complex<int> 是在cpp文件中展开
/*
class Complex<int> 
{
}
*/

template<class T>
Complex<T>::Complex()
{
	this->a = 0;
	this->b = 0;
}

template<class T>
Complex<T>::~Complex()
{
}

template<class T>
Complex<T>::Complex(T a, T b)
{
	this->a = a;
	this->b = b;
}

template<class T>
void Complex<T>::pirntComplex()
{
	cout << "a = " << a << "b = " << b << endl;
}

template<class T>
Complex<T> Complex<T>::operator+(Complex<T> &another)
{
	Complex temp(this->a + another.a, this->b + another.b);
	return temp;
}


template<class T>
Complex<T> Complex<T>::operator-(Complex<T> &another)
{
	Complex temp(this->a - another.a, this->b - another.b);
	return temp;
}
