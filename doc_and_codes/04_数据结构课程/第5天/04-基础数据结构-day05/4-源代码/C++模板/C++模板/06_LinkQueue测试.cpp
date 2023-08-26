#include <iostream>
#include "LinkQueue.h"
using namespace std;

struct Value
{
	int val;
};

void QueueTest1()
{
	Value v[10];
	LinkQueue<Value> q;

	for (int i = 0; i < 10; ++i)
	{
		v[i].val = i + 10;
		q.push(v[i]);
		cout << "push element : " << v[i].val << endl;
	}

	while (q.size() > 0)
	{
		Value t = q.front();
		cout << "stack top element: " << t.val << endl;
		q.pop();
	}
}

int main06()
{
	QueueTest1();

	cout << "Keyboard not found, press F1 to continue..." << endl;
	system("pause");
	return 0;
}