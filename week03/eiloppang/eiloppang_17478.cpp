#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int count = 0; // 영상에서 stack이 쌓임 숫자로

void printUnderBar(int n) {
	for (int i = 0; i < n; i++)
		printf("----"); // 걍 문자열 바로 복사해서 써야함
	// 어차피 내가 재귀함수에다가 printUnderBar 적어주면 되니까 범위 저렇게 설정해도 될 듯
}

void recursive(int n) {

	if (n == 0) {
		// 여기가 나는 찐이라고 생각함.. 다른 데는 없는 재귀함수에 대한 정의가 나와있음 그니까 여기는 최종의최종인거임.
		printUnderBar(count);
		printf("\"재귀함수가 뭔가요?\"\n");
		printUnderBar(count);
		printf("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n");
		printUnderBar(count);
		printf("라고 답변하였지.\n");
		count--; 
		return; // 모든 제어 경로에서 재귀적입니다. 함수로 인해 런타임 스택 오버플로가 발생합니다. 구문 없애려면 이걸 써야 하는데 의미는 모르겠음.
	}

	printUnderBar(count);
	printf("\"재귀함수가 뭔가요?\"\n");
	printUnderBar(count);
	printf("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n");
	printUnderBar(count);
	printf("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n");
	printUnderBar(count);
	printf("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n");
	count++; // 그냥 계속 반복됨 그래서 자꾸 스택 쌓임

	recursive(n - 1);
	printUnderBar(count);
	printf("라고 답변하였지.\n");
	count--; // 3:35:35에 보면 갑자기 반복 되면서 하나씩 줄어듦

}

int main() {
	int n;
	scanf("%d", &n);

	printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
	recursive(n);
}