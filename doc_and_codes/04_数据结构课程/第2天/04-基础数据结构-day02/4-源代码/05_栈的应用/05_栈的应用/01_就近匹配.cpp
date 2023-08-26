#include <iostream>
#include <stack>
using namespace std;

// ÅÐ¶Ï×óÀ¨ºÅ
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
		// Èç¹ûÊÇ×óÀ¨ºÅ
		if (isLeft(p[i]))
		{
			// Ñ¹Õ»
			st.push(p[i]);
		}
		// ÓÒÀ¨ºÅ
		else if (isRight(p[i]))
		{
			if (!st.empty())
			{
				// Õ»¶¥·ûºÅ
				char top = st.top();
				// Æ¥Åä
				if (!match(top, p[i]))
				{
					cout << "Æ¥ÅäÊ§°Ü!" << endl;
					break;
				}
				st.pop();
			}
			else
			{
				cout << "È±ÉÙ×óÀ¨ºÅ..." << endl;
				break;
			}
		}
		i++;
	}
	if (p[i] == '\0' && st.empty())
	{
		cout << "Æ¥Åä³É¹¦ÁË...." << endl;
	}
	else
	{
		cout << "Æ¥ÅäÊ§°Ü!!!" << endl;
	}
}

void main()
{
	// 
	Jiujinpipei("#include <stdio.h> int main()  int a[4][4]; int (*p)[4]; p = a[0]; return 0;}");
	system("pause");
}