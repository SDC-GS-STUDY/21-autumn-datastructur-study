#include <stdio.h>

int cnumber = 0;

void Countline(int cnumber) {
	for (int i = 0; i < cnumber; i++)
		printf("____");
}

void Rfunc(int n) {
	
	if (n == 0) {
		Countline(cnumber);
		printf("����Լ��� ������?\n");
		Countline(cnumber);
		printf("����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\n");
		Countline(cnumber);
		printf("��� �亯�Ͽ���\n");
		cnumber--;
	}
	else
	{
		Countline(cnumber);
		printf("\"����Լ��� ������?\"\n");
		Countline(cnumber);
		printf("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���. \n");
		Countline(cnumber);
		printf("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־��� \n");
		Countline(cnumber);
		printf("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\" \n");
		cnumber++;

		Rfunc(n - 1);
		Countline(cnumber);
		printf("��� �亯�Ͽ���.\n");
		cnumber--;
	}
}

int main(void) {
	int a;
	scanf_s("%d", &a);

	printf("��� �� ��ǻ�� ���а� �л��� ������ �������� ã�� ���� ������.\n");
	Rfunc(a);

	return 0;
}