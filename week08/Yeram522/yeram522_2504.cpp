#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<char> s;
	stack<int> result;
	char* exp = new char[30];// array of postfix expression
	
	scanf("%s", exp);

	for (int i = 0;i< s.size();i++)
	{
		int temp;
		switch (exp[i])
		{
		case '(':case '[':
			s.push(exp[i]);
		case ')':
			if (exp[i - 1] == '(')//() 리면
			{
				int sum;
				if (result.empty() || exp[i + 1] == ']' || exp[i + 1] == ')')
				{
					result.push(2);
					s.pop();
					break;
				}
				sum = result.top();
				result.pop();
				result.push(2 + sum);
				s.pop();
			}
			else if (exp[i - 1] == ')' || exp[i - 1] == ']')
			{
				temp = result.top();
				result.pop();
				result.push(temp * 2);
			}
			s.pop(); // stack에서 ( 제거
			
		case ']':
			if (exp[i - 1] == '[')//() 리면
			{
				int sum;
				if (result.empty()|| exp[i + 1]==']' || exp[i + 1] == ')')
				{
					result.push(3);
					s.pop();
					break;
				}
				sum = result.top();
				result.pop();
				result.push(3 + sum);
				s.pop();
			}
			else if (exp[i - 1] == ']'|| exp[i - 1] == ')')
			{
				temp = result.top();
				result.pop();
				result.push(temp * 3);
			}
			s.pop(); // stack에서 ( 제거		
		}

		
	}



}