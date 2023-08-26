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
// 	int i = 0;
// 	stack<char> st;
// 	while (p[i] != '\0')
// 	{
// 		// 数字
// 		if (isNumber(p[i]))
// 		{
// 			// 直接输出
// 			cout << p[i];
// 		}
// 		// 左括号
// 		else if (isLeft(p[i]))
// 		{
// 			// 进栈
// 			st.push(p[i]);
// 		}
// 		// 运算符
// 		else if (isOperator(p[i]))
// 		{
// 			// 优先级的比较 
// 			while (!st.empty() && priority(st.top()) >= priority(p[i]))
// 			{
// 				// 输出
// 				cout << st.top();
// 				st.pop();
// 			}
// 			// 进栈
// 			st.push(p[i]);
// 		}
// 		// 右括号
// 		else if (isRight(p[i]))
// 		{
// 			// 如果不是左括号, 弹出并输出
// 			while (!isLeft(st.top()))
// 			{
// 				cout << st.top();
// 				st.pop();
// 			}
// 			// 弹出左括号
// 			st.pop();
// 		}
// 		i++;
// 	}
// 
// 	while (!st.empty())
// 	{
// 		cout << st.top();
// 		st.pop();
// 	}

	/*
	中缀转后缀算法：
	遍历中缀表达式中的数字和符号：
		对于数字：直接输出
		对于符号：
			左括号：进栈
			运算符号：与栈顶符号进行优先级比较
					若栈顶符号优先级低：此符号进栈
					（默认栈顶若是左括号，左括号优先级最低）
					若栈顶符号优先级不低：将栈顶符号弹出并输出，之后进栈
			右括号：将栈顶符号弹出并输出，直到匹配左括号
	遍历结束：将栈中的所有符号弹出并输出
	*/
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
			// 优先级比较
			// 当前字符优先级低, 直接进栈
// 			if (priority(st.top() < priority(p[i])))
// 			{
// 				// 直接进栈
// 				st.push(p[i]);
// 			}
			// 若栈顶符号优先级不低
			while (!st.empty() && priority(st.top()) >= priority(p[i]))
			{
				// 输出
				cout << st.top();
				// 弹出栈顶
				st.pop();
			}
			// 当前字符进栈
			st.push(p[i]);
		}
		else if (isRight(p[i]))
		{
			// 寻找左括号
			while (!st.empty() && !isLeft(st.top()))
			{
				// 输出
				cout << st.top();
				// 弹出栈顶符号
				st.pop();
			}
			if (!st.empty())
			{
				// 弹出左括号
				st.pop();
			}
		}
		i++;
	}

	// 遍历结束
	if (p[i] == '\0')
	{
		// 遍历结束
		while (!st.empty())
		{
			// 输出
			cout << st.top();
			// 弹出
			st.pop();
		}
	}
	else
	{
		cout << "遍历没有完成..." << endl;
	}
}

// 后缀表达式的计算
/*
	计算规则
	遍历后缀表达式中的数字和符号
	对于数字：进栈
	对于符号：
	从栈中弹出右操作数
	从栈中弹出左操作数
	根据符号进行运算
	将运算结果压入栈中
	遍历结束：栈中的唯一数字为计算结果
*/

int express(int left, int right, char op)
{
	int ret = -1000000;
	switch (op)
	{
	case '+':
		ret = left + right;
		break;
	case '-':
		ret = left - right;
		break;
	case '*':
		ret = left * right;
		break;
	case '/':
		ret = left / right;
		break;
	default:
		break;
	}
	return ret;
}


int compute(const char* p)
{
	int i = 0;
	stack<int> st;
	while (p[i] != '\0')
	{
		// 数字
		if (isNumber(p[i]))
		{
			// 进栈
			st.push(p[i]-'0');
		}
		else if (isOperator(p[i]))
		{
			// 右操作数
			int right = st.top();
			st.pop();
			// 左操作数
			int left = st.top();
			st.pop();
			// 计算
			int res = express(left, right, p[i]);
			// 结果压入栈中
			st.push(res);
		}
		i++;
	}

	if (p[i] == '\0' && st.size() == 1)
	{
		return st.top();
	}
	else
	{
		return -100000;
	}
}

void main()
{
	Transform("8+(3-1)*5");

	cout << endl;
	cout << "计算结果: " << compute("831-5*+") << endl;

	system("pause");
}