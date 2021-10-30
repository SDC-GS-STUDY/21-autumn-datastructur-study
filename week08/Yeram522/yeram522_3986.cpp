#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<char> stack;
	string words;
	int num;
	int count=0;

	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf("%s", &words);

		for (int j = 0; j < words.length(); j++)
		{ 
			if(stack.empty()) stack.push(words[i]);
			else
			{
				if (words[i] == stack.top()) stack.pop();
				else stack.push(words[i]);
			}
			
		}
		
		if(stack.empty()) count++;
		
	}

	printf("%d", count);
		
	return 0;
}