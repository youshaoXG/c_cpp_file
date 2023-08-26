#include <iostream>
#include "LinkStack.h"
using namespace std;

void Mytest()
{
	LinkStack<int> list;

	int array[10];
	for (int i = 0; i < 10; ++i)
	{
		array[i] = i + 10;
		list.push(array[i]);
		cout << "push element : " << array[i] << endl;
	}

	while (list.size() > 0)
	{
		int t = list.top();
		cout << "stack top element: " << t << endl;
		list.pop();
	}
}

int main04()
{
	Mytest();

	cout << "Keyboard not found, press F1 to continue..." << endl;
	system("pause");
	return 0;
}