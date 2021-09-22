#include <stdio.h>

int n = 0;

void Output(int num) {
	for (int i = 0; i < num; i++) 
	{
		printf("____");
	}
}

void RecursionFunc(int num) {
	if (num == 0) {		// ��� ���� �� or ������
		Output(n);
		printf("\"����Լ��� ������?\"\n");
		Output(n);
		printf("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n");
		Output(n);
		printf("��� �亯�Ͽ���.\n");		
		n--; // �亯~���� ____���--
		return;
	}
	else {
		Output(n);
		printf("\"����Լ��� ������?\"\n");
		Output(n);
		printf("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n");
		Output(n);
		printf("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n");
		Output(n);
		printf("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n");
		n++; // ____���++
		RecursionFunc(num - 1);
		Output(n);
		printf("��� �亯�Ͽ���.\n");
		n--; // �׿��ִ� ����Լ� �� ������ ��� �亯 ____��� --
	}
}

int main(void) {

	int num;
	scanf_s("%d", &num);

	printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
	RecursionFunc(num);

	return 0;
}