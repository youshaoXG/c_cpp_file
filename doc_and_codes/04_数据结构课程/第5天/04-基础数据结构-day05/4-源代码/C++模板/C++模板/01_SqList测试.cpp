#include <iostream>
#include <string>
#include "SqList.hpp"
using namespace std;

void SeqListTest()
{
	//��������
	SqList<string> list(30);

	string array[] = {
		"�����ַ��� --- 1",
		"�����ַ��� --- 2",
		"�����ַ��� --- 3",
		"�����ַ��� --- 4",
		"�����ַ��� --- 5",
		"�����ַ��� --- 6",
		"�����ַ��� --- 7",
		"�����ַ��� --- 8",
		"�����ַ��� --- 9",
		"�����ַ��� --- 10"
	};
	for (int i = 0; i < 10; ++i)
	{
		//��������
		list.insert(i, array[i]);
	}

	//��������
	for (int i = 0; i < list.length(); ++i)
	{
		string tmp = list.get(i);
		cout << tmp.data() << endl;
	}

	//ɾ������Ԫ��
	while (list.length() > 0)
	{
		string tmp = list.del(0);
		cout << "delete -- " << tmp.data() << endl;
	}
}

int main01()
{
	SeqListTest();

	cout << "Keyboard not found, press F1 to continue..." << endl;
	system("pause");
	return 0;
}