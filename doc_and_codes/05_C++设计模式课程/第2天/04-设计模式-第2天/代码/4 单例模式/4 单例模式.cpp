#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

/*
class A
{
public:
private:
	A() {

	}
};
*/

/*
һ��ĳ����ֻ����һ��ʵ����
�������������д������ʵ����
��������������������ϵͳ�ṩ���ʵ����
*/

/*
����ģʽ��ʹ�ò��裺
a)	 ���캯��˽�л���// Ϊ����������ⲿ�ٴ���һ�������ʵ��
b)	 �ṩһ��ȫ�ֵľ�̬������ȫ�ַ��ʵ㣩����ȡ��������
c)	 �����ж���һ����ָ̬�룬ָ����ı����ľ�̬����ָ�� ��
*/


class Singleton
{
public:

	static Singleton* getInstance()
	{
		return instance;
	}

private:
	//��������ⲿ�ٴ���ʵ��
	Singleton() {

	}
	static Singleton* instance;//ָ����Ψһʵ����ָ�롣
};

/*
����ʽ  - �ڱ����ڼ���Ѿ�ȷ�����Ψһ��ʵ���ˡ�
*/
Singleton*  Singleton::instance = new Singleton; //����ڲ�


class Singleton2
{
public:
	static Singleton2* getInstance()
 	{
  		//����
		if (instance == NULL) {
			instance = new Singleton2;
		}
		//����
		return instance;
 	}

private:
	Singleton2() {

	}
	static Singleton2 * instance;
};


//����ʽ�ĳ�ʼ����ʽ
Singleton2 *Singleton2::instance = NULL;


int main(void)
{
	Singleton * s1 = Singleton::getInstance();
	Singleton *s2 = Singleton::getInstance();

	if (s1 == s2) {
		cout << "s1 == s2" << endl;
	}
	else {
		cout << "s1 != s2 " << endl;
	}

	Singleton2 *s3 = Singleton2::getInstance();
	Singleton2 *s4 = Singleton2::getInstance();

	if (s3 == s4) {
		cout << "s3 == s4" << endl;

	}
	else {
		cout << "s3 != s4" << endl;
	}
	
	return 0;
}