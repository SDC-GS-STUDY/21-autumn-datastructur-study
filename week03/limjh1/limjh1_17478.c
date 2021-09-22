#include <stdio.h>

int n = 0;

void Output(int num) {
	for (int i = 0; i < num; i++) 
	{
		printf("____");
	}
}

void RecursionFunc(int num) {
	if (num == 0) {		// 재귀 안할 때 or 마지막
		Output(n);
		printf("\"재귀함수가 뭔가요?\"\n");
		Output(n);
		printf("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n");
		Output(n);
		printf("라고 답변하였지.\n");		
		n--; // 답변~에서 ____출력--
		return;
	}
	else {
		Output(n);
		printf("\"재귀함수가 뭔가요?\"\n");
		Output(n);
		printf("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n");
		Output(n);
		printf("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n");
		Output(n);
		printf("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n");
		n++; // ____출력++
		RecursionFunc(num - 1);
		Output(n);
		printf("라고 답변하였지.\n");
		n--; // 쌓여있는 재귀함수 다 끝내고 라고 답변 ____출력 --
	}
}

int main(void) {

	int num;
	scanf_s("%d", &num);

	printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
	RecursionFunc(num);

	return 0;
}