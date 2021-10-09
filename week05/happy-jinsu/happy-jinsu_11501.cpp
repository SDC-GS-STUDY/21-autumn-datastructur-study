#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1000001
typedef long long ll;
int StockPrices[1000001] = { 0 };

int main()
{
    int i, j, T, N, Buy = 0, Max = 0;

    scanf("%d", &T);
    for (i = 0; i < T; i++) 
    {
        scanf("%d", &N); 
        for (j = 0; j < N; j++)
            scanf("%d", &StockPrices[j]);
        
        Max = StockPrices[N - 1]; 
        ll Buy = 0;
        for (j = N - 2; j >= 0; j--)
        {
            if (StockPrices[j] > Max)
                Max = StockPrices[j];

            else if (StockPrices[j] < Max)
                Buy += ((ll)Max - (ll)StockPrices[j]);
        }
        printf("%llu\n", Buy);
    }
}
