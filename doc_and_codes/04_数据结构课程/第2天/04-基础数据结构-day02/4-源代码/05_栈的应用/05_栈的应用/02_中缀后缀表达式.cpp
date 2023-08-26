#include <iostream>
#include <stack>
using namespace std;

bool isNumber(char c)
{
	return c >= '0' && c <= '9';
}

bool isLeft(char c)
{
	return c == '(';
}

bool isRight(char c)
{
	return c == ')';
}


bool isOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int priority(char c)
{
	int ret = 0;
	switch (c)
	{
	case '+':
	case '-':
		ret = 1;
		break;
	case '*':
	case '/':
		ret = 2;
		break;
	default:
		break;
	}
	return ret;
}

void Transform(const char* p)
{
	int i = 0;
	stack<char> st;
	while (p[i] != '\0')
	{
		// 数字
		if (isNumber(p[i]))
		{
			// 直接输出
			cout << p[i];
		}
		// 左括号
		else if (isLeft(p[i]))
		{
			// 进栈
			st.push(p[i]);
		}
		// 运算符
		else if (isOperator(p[i]))
		{
			// 优先级的比较 
			while (!st.empty() && priority(st.top()) >= priority(p[i]))
			{
				// 输出
				cout << st.top();
				st.pop();
			}
			// 进栈
			st.push(p[i]);
		}
		// 右括号
		else if (isRight(p[i]))
		{
			// 如果不是左括号, 弹出并输出
			while (!isLeft(st.top()))
			{
				cout << st.top();
				st.pop();
			}
			// 弹出左括号
			st.pop();
		}
		i++;
	}

	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
}

void main()
{
	Transform("8+(3-1)*5");
	system("pause");
}