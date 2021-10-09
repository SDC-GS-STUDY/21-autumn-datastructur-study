#include<stdio.h>

//배열 뒤부터 생각해서 풀어야됨

int main(void) {

    int n;
    int a[101];
    int cnt = 0;

    scanf_s("%d", &n);

    for (int i = 0; i < n; i++)
        scanf_s("%d", &a[i]);

    //뒤부터 생각해서 앞에 있는 값이 나보다 클 경우는 1씩 감소시켜서 계속 계산시키 ㅁ
    // 머야 이거 다시풀어야겠당 -값 나오는것도 다시 다시 다시 
    for (int i = n - 1; i > 0; i--) {
        if (a[i - 1] >= a[i]) {
            cnt += a[i - 1] - (a[i] - 1);
            a[i - 1] = a[i] - 1;
        }
    }

   

    printf("%d", cnt);

}
