#include <iostream>
#include "SqStack.hpp"
using namespace std;

void test()
{
	SqStack<int> st(30);
	int tmp;
	for (int i = 0; i < 10; ++i)
	{
		tmp = i + 10;
		st.push(tmp);
		cout << "push element: " << tmp << endl;
	}

	cout << "stack size = " << st.size() << endl;
	

	while (st.size() > 0)
	{
		int t = st.top();
		cout << "stack top element " << t << endl;
		st.pop();
	}
}

int main03()
{
	test();

	cout << "Keyboard not found, press F1 to continue..." << endl;
	system("pause");
	return 0;
}