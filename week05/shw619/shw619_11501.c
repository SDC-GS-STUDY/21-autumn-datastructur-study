//�ں��� ������
//�� �ں��� ������ ���� ū ���� �켱 ã�� �� 
//ū �� - �� ���� �� �ϴ� ���ؼ� �����ָ� �ǰ���?
//��ȣ�ִ� 64bit ������ �̰� ���� ã�ƺ��� longlong������..! int�ȵǴ°ǰ���

#include<stdio.h>

int testcase;
int day;
int j[1000001] = { 0, };

int main(void) {

	//testcase �Է¹ް� 
	scanf_s("%d", &testcase);

	//��¥ �Է� �ޱ� (����Ʈ���̽����� ���� ���� ��Ÿ���� day ������ ��¥ �� �ְ��� ��Ÿ����
	for (int i = 0; i < testcase; i++) {
		scanf_s("%d", &day);

		for (int i = 1; i <= day; i++) {
			scanf_s("%d", &j[i]);
		}

		//��� �ֽ�
		int expensive = j[day];
		//�ִ� ���� ��
		long long answer = 0;

		for (int i = day - 1; i > 0; i--) {
			if (expensive < j[i])
				expensive = j[i];
			else if (expensive > j[i]) {
				answer += (expensive - j[i]);
			}

		}
		printf("%lld", answer);
	}
}