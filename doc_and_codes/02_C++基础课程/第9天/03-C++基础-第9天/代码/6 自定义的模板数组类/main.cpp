#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "MyVector.h"

using namespace std;

void test1()
{
	MyVector<int> myVector1(10);

	for (int i = 0; i < 10; i++)
	{
		myVector1[i] = 10 + i;
	}
	cout << "vector1" << endl;
	cout << myVector1 << endl;

	MyVector<int> myVector2(myVector1); //��������  

	cout << "vector2" << endl;
	cout << myVector2 << endl;

	MyVector<int> myVector3;
	myVector3 = myVector2;// �������=�Ÿ�ֵ

	cout << "vector3" << endl;
	cout << myVector3 << endl;
}

void test2()
{
	MyVector<char> myVector1(10);

	for (int i = 0; i < 10; i++)
	{
		myVector1[i] = 'a' + i;
	}
	cout << "vector1" << endl;
	cout << myVector1 << endl;

	MyVector<char> myVector2(myVector1); //��������  

	cout << "vector2" << endl;
	cout << myVector2 << endl;

	MyVector<char> myVector3;
	myVector3 = myVector2;// �������=�Ÿ�ֵ

	cout << "vector3" << endl;
	cout << myVector3 << endl;
}


//test3   ����Զ������������teacher
class Teacher
{
public:
	friend ostream & operator<<(ostream & os, Teacher &t);
	Teacher()
	{
		this->name = NULL;
		this->id = 0;
	}
	Teacher(int id, char *name)
	{
		this->id = id;

		int len = strlen(name);
		this->name = new char[len + 1];
		strcpy(this->name, name);
	}
	~Teacher()
	{
		if (this->name != NULL) {
			delete[] this->name;
			this->name = NULL;
			this->id = 0;
		}
	}
	//��ɿ������캯����ʵ�����
	Teacher(const Teacher &t)
	{
		this->id = t.id;
		int len = strlen(t.name);

		this->name = new char[len + 1];
		strcpy(this->name, t.name);
	}
	//��ɵȺŲ����� �� ʵ�����
	Teacher & operator=(const Teacher &t)
	{
		if (this->name != NULL) {
			delete[]this->name;
			this->name = NULL;
			this->id = 0;
		}

		this->id = t.id;
		int len = strlen(t.name);
		this->name = new char[len + 1];
		strcpy(this->name, t.name);

		return *this;
	}

	void printTeacher()
	{
		cout << "id = " << this->id << ", name = " << this->name << endl;
	}
private:
	int id;
	char* name;
};

ostream & operator<<(ostream & os, Teacher &t)
{
	t.printTeacher();
	return os;
}


void test3()
{
	//����һЩTeacher����
	Teacher t1(0, "zhang3");
	Teacher t2(0, "zhang4");
	Teacher t3(0, "zhang5");
	Teacher t4(0, "zhang6");
	Teacher t5(0, "zhang7");

	MyVector<Teacher> myVector1(5);

	myVector1[0] = t1; //myVector.operator[](0) = t1;
	myVector1[1] = t2;
	myVector1[2] = t3;
	myVector1[3] = t4;
	myVector1[4] = t5;

	for (int i = 0; i < 5; i++) {
		cout << myVector1[i];
	}
}


int main(void)
{
	test3();

	return 0;
}