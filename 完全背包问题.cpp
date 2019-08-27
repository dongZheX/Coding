#include<stdio.h>
#define maxn 10000
long long dp[7][maxn+1];
int main() {
	int i, j;
	int w[7] = { 0, 1 ,5, 10, 20, 50, 100 };
	for (i = 0;i <= 6;i++)
		dp[i][0] = 1;
	for (j = 0;j <= maxn;j++)
		dp[0][j] = 0;
	for (i = 1;i <= 6;i++)
	{
		for (j = 1; j <= maxn;j++)
		{
			if (j >= w[i])
				dp[i][j] = dp[i][j - w[i]] + dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	printf("%lld\n", dp[6][maxn]);
}