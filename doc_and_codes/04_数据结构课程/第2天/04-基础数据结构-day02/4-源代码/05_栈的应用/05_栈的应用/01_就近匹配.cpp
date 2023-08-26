#include <iostream>
#include <stack>
using namespace std;

// �ж�������
bool isLeft(char c)
{
	bool bl;
	switch (c)
	{
	case '[':
	case '(':
	case '{':
	case '<':
		bl = true;
		break;
	default:
		bl = false;
		break;
	}
	return bl;
}

bool isRight(char c)
{
	bool bl;
	switch (c)
	{
	case ']':
	case ')':
	case '}':
	case '>':
		bl = true;
		break;
	default:
		bl = false;
		break;
	}
	return bl;
}

bool match(char left, char right)
{
	bool bl;
	switch (left)
	{
	case '[':
		bl = right == ']';
		break;
	case '(':
		bl = right == ')';
		break;
	case '{':
		bl = right == '}';
		break;
	case '<':
		bl = right == '>';
		break;
	default:
		bl = false;
		break;
	}
	return bl;
}


void Jiujinpipei(const char* p)
{
	int i = 0;
	stack<char> st;
	while (p[i] != '\0')
	{
		// �����������
		if (isLeft(p[i]))
		{
			// ѹջ
			st.push(p[i]);
		}
		// ������
		else if (isRight(p[i]))
		{
			if (!st.empty())
			{
				// ջ������
				char top = st.top();
				// ƥ��
				if (!match(top, p[i]))
				{
					cout << "ƥ��ʧ��!" << endl;
					break;
				}
				st.pop();
			}
			else
			{
				cout << "ȱ��������..." << endl;
				break;
			}
		}
		i++;
	}
	if (p[i] == '\0' && st.empty())
	{
		cout << "ƥ��ɹ���...." << endl;
	}
	else
	{
		cout << "ƥ��ʧ��!!!" << endl;
	}
}

void main()
{
	// 
	Jiujinpipei("#include <stdio.h> int main()  int a[4][4]; int (*p)[4]; p = a[0]; return 0;}");
	system("pause");
}