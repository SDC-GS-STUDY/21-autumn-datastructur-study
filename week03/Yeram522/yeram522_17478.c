#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


void print_line(int _count)
{
	for (int i = 0; i < _count; i++)
		printf("____");

	return;
}


void Chat_Bot(int _count,int _num)
{
	printf("\"����Լ��� ������?\"\n");

	if (_count == 0)
	{
		print_line(_num);
		printf("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n");
		print_line(_num);
		printf("��� �亯�Ͽ���.\n");
		return;		
	}
	else
	{
		print_line(_num);
		printf("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n");
		print_line(_num);
		printf("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n");
		print_line(_num);
		printf("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n");
	}

	_count--;
	_num++;
	print_line(_num);
	Chat_Bot(_count, _num);
	print_line(_num-1);
	printf("��� �亯�Ͽ���.\n");	
}

int main()
{
	int count;
	scanf("%d", &count,0);

	printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
	Chat_Bot(count,0);
}