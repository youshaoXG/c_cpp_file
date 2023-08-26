#include <iostream>
#include "SqQueue.hpp"
using namespace std;

struct Value
{
	int val;
};

void QueueTest()
{
	Value v[10];
	SqQueue<Value> q(30);

	for (int i = 0; i < 10; ++i)
	{
		v[i].val = i + 10;
		q.push(v[i]);
		cout << "push element : " << v[i].val << endl;
	}

	while (q.length() > 0)
	{
		Value t = q.front();
		cout << "stack top element: " << t.val << endl;
		q.pop();
	}
}

int main()
{
	QueueTest();

	cout << "Keyboard not found, press F1 to continue..." << endl;
	system("pause");
	return 0;
}