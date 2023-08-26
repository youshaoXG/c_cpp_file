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
// 		// ����
// 		if (isNumber(p[i]))
// 		{
// 			// ֱ�����
// 			cout << p[i];
// 		}
// 		// ������
// 		else if (isLeft(p[i]))
// 		{
// 			// ��ջ
// 			st.push(p[i]);
// 		}
// 		// �����
// 		else if (isOperator(p[i]))
// 		{
// 			// ���ȼ��ıȽ� 
// 			while (!st.empty() && priority(st.top()) >= priority(p[i]))
// 			{
// 				// ���
// 				cout << st.top();
// 				st.pop();
// 			}
// 			// ��ջ
// 			st.push(p[i]);
// 		}
// 		// ������
// 		else if (isRight(p[i]))
// 		{
// 			// �������������, ���������
// 			while (!isLeft(st.top()))
// 			{
// 				cout << st.top();
// 				st.pop();
// 			}
// 			// ����������
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
	��׺ת��׺�㷨��
	������׺���ʽ�е����ֺͷ��ţ�
		�������֣�ֱ�����
		���ڷ��ţ�
			�����ţ���ջ
			������ţ���ջ�����Ž������ȼ��Ƚ�
					��ջ���������ȼ��ͣ��˷��Ž�ջ
					��Ĭ��ջ�����������ţ����������ȼ���ͣ�
					��ջ���������ȼ����ͣ���ջ�����ŵ����������֮���ջ
			�����ţ���ջ�����ŵ����������ֱ��ƥ��������
	������������ջ�е����з��ŵ��������
	*/
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
			// ���ȼ��Ƚ�
			// ��ǰ�ַ����ȼ���, ֱ�ӽ�ջ
// 			if (priority(st.top() < priority(p[i])))
// 			{
// 				// ֱ�ӽ�ջ
// 				st.push(p[i]);
// 			}
			// ��ջ���������ȼ�����
			while (!st.empty() && priority(st.top()) >= priority(p[i]))
			{
				// ���
				cout << st.top();
				// ����ջ��
				st.pop();
			}
			// ��ǰ�ַ���ջ
			st.push(p[i]);
		}
		else if (isRight(p[i]))
		{
			// Ѱ��������
			while (!st.empty() && !isLeft(st.top()))
			{
				// ���
				cout << st.top();
				// ����ջ������
				st.pop();
			}
			if (!st.empty())
			{
				// ����������
				st.pop();
			}
		}
		i++;
	}

	// ��������
	if (p[i] == '\0')
	{
		// ��������
		while (!st.empty())
		{
			// ���
			cout << st.top();
			// ����
			st.pop();
		}
	}
	else
	{
		cout << "����û�����..." << endl;
	}
}

// ��׺���ʽ�ļ���
/*
	�������
	������׺���ʽ�е����ֺͷ���
	�������֣���ջ
	���ڷ��ţ�
	��ջ�е����Ҳ�����
	��ջ�е����������
	���ݷ��Ž�������
	��������ѹ��ջ��
	����������ջ�е�Ψһ����Ϊ������
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
		// ����
		if (isNumber(p[i]))
		{
			// ��ջ
			st.push(p[i]-'0');
		}
		else if (isOperator(p[i]))
		{
			// �Ҳ�����
			int right = st.top();
			st.pop();
			// �������
			int left = st.top();
			st.pop();
			// ����
			int res = express(left, right, p[i]);
			// ���ѹ��ջ��
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
	cout << "������: " << compute("831-5*+") << endl;

	system("pause");
}