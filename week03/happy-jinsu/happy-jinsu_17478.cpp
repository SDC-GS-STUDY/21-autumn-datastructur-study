#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void UnderBar(int);
void repeat(int);

int num;
int main() 
{
	int n;
	scanf("%d", &n);

	printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
	repeat(n);
}

void UnderBar(int n) 
{
	for (int i = 0; i < n; i++)
		printf("----");
}

void repeat(int n) {

	if (n == 0) {
		UnderBar(num);
		printf("\"����Լ��� ������?\"\n");
		UnderBar(num);
		printf("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n");
		UnderBar(num);
		printf("��� �亯�Ͽ���.\n");
		num--;
		return; 
	}

	UnderBar(num);
	printf("\"����Լ��� ������?\"\n");
	UnderBar(num);
	printf("\"�� ����. �������� �� �� ����⿡ �� ���� ��� ������ ����� ������ �־���.\n");
	UnderBar(num);
	printf("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n");
	UnderBar(num);
	printf("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n");
	num++;

	repeat(n - 1);
	UnderBar(num);
	printf("��� �亯�Ͽ���.\n");
	num--; 
}