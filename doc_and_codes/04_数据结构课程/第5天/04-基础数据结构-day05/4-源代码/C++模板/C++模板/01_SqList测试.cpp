#include <iostream>
#include <string>
#include "SqList.hpp"
using namespace std;

void SeqListTest()
{
	//创建对象
	SqList<string> list(30);

	string array[] = {
		"我是字符串 --- 1",
		"我是字符串 --- 2",
		"我是字符串 --- 3",
		"我是字符串 --- 4",
		"我是字符串 --- 5",
		"我是字符串 --- 6",
		"我是字符串 --- 7",
		"我是字符串 --- 8",
		"我是字符串 --- 9",
		"我是字符串 --- 10"
	};
	for (int i = 0; i < 10; ++i)
	{
		//插入数据
		list.insert(i, array[i]);
	}

	//遍历容器
	for (int i = 0; i < list.length(); ++i)
	{
		string tmp = list.get(i);
		cout << tmp.data() << endl;
	}

	//删除所有元素
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