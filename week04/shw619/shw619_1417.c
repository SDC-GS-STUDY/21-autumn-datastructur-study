#include <stdio.h>

int main() {

	//주어진 후보의 수를 일단 입력받음
	int N;
	scanf_s("%d", &N);

	//최솟값 세기 위한 
	int cnt = 0;
	// 1000보다 작거나 같은 수의 배열 만들어주고 초기화
	int v[1001] = { 0, };

	// n명의 후보에게 투표된 수를 찾기 위해
	for (int i = 0; i < N; i++) {
		scanf_s("%s", &v[i]);
	}

	//매수할 최소값을 구하는거니깐 
	while (1) {
		//최다 득표 수 선언 및 초기화
		int votenum = 0;

		//최다 득표수 찾아보고 일단 최다득표자에게서 매수해서 빼와야됨 
		for (int i = 0; i < N; i++) {
			if(v[votenum] <= v[i]) {
				votenum = i;
			}
		}

		// 다른 후보들 보다 다솜이의 표가 가장 많지면 그만 하고 나왕
		if (votenum == 0)
			break;

		v[0]++; //다솜이는 1번이니깐 득표수 +1해주고
		v[votenum]--; // 최다 득표자 득표수는 -1 되는거
		cnt++; // 다솜이가 매수한 표의 수
	}

	printf("%d", cnt);

}