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
		// ����
		if (isNumber(p[i]))
		{
			// ֱ�����
			cout << p[i];
		}
		// ������
		else if (isLeft(p[i]))
		{
			// ��ջ
			st.push(p[i]);
		}
		// �����
		else if (isOperator(p[i]))
		{
			// ���ȼ��ıȽ� 
			while (!st.empty() && priority(st.top()) >= priority(p[i]))
			{
				// ���
				cout << st.top();
				st.pop();
			}
			// ��ջ
			st.push(p[i]);
		}
		// ������
		else if (isRight(p[i]))
		{
			// �������������, ���������
			while (!isLeft(st.top()))
			{
				cout << st.top();
				st.pop();
			}
			// ����������
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