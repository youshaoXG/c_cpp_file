#include <iostream>
#include "LinkList.h"
#include "LinkList.cpp"

using namespace std;

struct Student
{
	int age;
	string name;
};

void LinkListTest()
{
	//��������
	LinkList<Student> list;
	//
	Student stu[10];
	//��ʼ��
	for (int i = 0; i < 10; ++i)
	{
		stu[i].age = i + 20;
		stu[i].name = "Student";
		//�����ݷ���������
		list.insert(i, stu[i]);
	}

	//����
	for (int i = 0; i < list.length(); ++i)
	{
		Student s = list.get(i);
		cout << "student age : " << s.age << endl;
	}

	//ɾ�����нڵ�
	while (list.length() > 0)
	{
		Student s = list.del(0);
		cout << "delete --- Student age: " << s.age << endl;
	}
}

int main02()
{
	LinkListTest();

	cout << "Keyboard not found, press F1 to continue..." << endl;
	system("pause");
	return 0;
}