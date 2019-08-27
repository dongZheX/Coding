#include<stdio.h>
#define N 1000
#define INF 0x7fffffff
int max(int a, int b) {
	return a < b ? b : a;
}
int dp[N][N];
int main() {
	int time[N];
	int val[N];
	
	int t, n;
	int i, j;
	while (scanf("%d%d", &t, &n) != EOF) {
		for (i = 1;i <= n;i++) {
			scanf("%d%d", &time[i], &val[i]);
		}
		//初始化一定要正确

		for (i = 0;i <= n;i++) {
			for (j = 0;j <= t;j++)
				dp[i][j] = 0;
		}
		for (i = 1;i <= n;i++) {
			for (j = 1;j<= t;j++) {
				if (time[i] > j)
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = max(dp[i-1][j], dp[i-1][j - time[i]] + val[i]);
			}
			/*
			for (j = t;j >= 1;j--) {
				if(time[i]<=j)
				dp[j] = max(dp[j], dp[j - time[i]] + val[i]);
			}
			*/
			/*
			完全背包
			初始化 除了00处其他都是无穷大
			for (j = 1;j<= t;j++) {
				if(j<time[i])dp[i][j] = dp[i-1][j];
				if(dp[i][j-time[i]]!=INF){
					dp[i][j] = min(dp[i][j],dp[i][j-time[i]]+val[i]);
				}
			}
			*/
		}
		printf("%d\n", dp[n][t]);
	}
}