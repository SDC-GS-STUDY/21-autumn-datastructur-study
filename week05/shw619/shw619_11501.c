//뒤부터 돌리자
//음 뒤부터 돌려서 가장 큰 값을 우선 찾은 뒤 
//큰 값 - 그 날의 값 싹다 구해서 더해주면 되겠지?
//부호있는 64bit 정수형 이게 뭔지 찾아보니 longlong쓰란다..! int안되는건가봄

#include<stdio.h>

int testcase;
int day;
int j[1000001] = { 0, };

int main(void) {

	//testcase 입력받고 
	scanf_s("%d", &testcase);

	//날짜 입력 받기 (데스트케이스별로 날의 수를 나타나는 day 다음은 날짜 별 주가를 나타내는
	for (int i = 0; i < testcase; i++) {
		scanf_s("%d", &day);

		for (int i = 1; i <= day; i++) {
			scanf_s("%d", &j[i]);
		}

		//비싼 주식
		int expensive = j[day];
		//최대 이윤 값
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