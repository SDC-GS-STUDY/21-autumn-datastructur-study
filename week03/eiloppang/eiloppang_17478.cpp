#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int count = 0; // ���󿡼� stack�� ���� ���ڷ�

void printUnderBar(int n) {
	for (int i = 0; i < n; i++)
		printf("----"); // �� ���ڿ� �ٷ� �����ؼ� �����
	// ������ ���� ����Լ����ٰ� printUnderBar �����ָ� �Ǵϱ� ���� ������ �����ص� �� ��
}

void recursive(int n) {

	if (n == 0) {
		// ���Ⱑ ���� ���̶�� ������.. �ٸ� ���� ���� ����Լ��� ���� ���ǰ� �������� �״ϱ� ����� �����������ΰ���.
		printUnderBar(count);
		printf("\"����Լ��� ������?\"\n");
		printUnderBar(count);
		printf("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n");
		printUnderBar(count);
		printf("��� �亯�Ͽ���.\n");
		count--; 
		return; // ��� ���� ��ο��� ������Դϴ�. �Լ��� ���� ��Ÿ�� ���� �����÷ΰ� �߻��մϴ�. ���� ���ַ��� �̰� ��� �ϴµ� �ǹ̴� �𸣰���.
	}

	printUnderBar(count);
	printf("\"����Լ��� ������?\"\n");
	printUnderBar(count);
	printf("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n");
	printUnderBar(count);
	printf("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n");
	printUnderBar(count);
	printf("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n");
	count++; // �׳� ��� �ݺ��� �׷��� �ڲ� ���� ����

	recursive(n - 1);
	printUnderBar(count);
	printf("��� �亯�Ͽ���.\n");
	count--; // 3:35:35�� ���� ���ڱ� �ݺ� �Ǹ鼭 �ϳ��� �پ��

}

int main() {
	int n;
	scanf("%d", &n);

	printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
	recursive(n);
}