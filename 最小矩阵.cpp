#include<stdio.h>
int sum[101][101];
int dp[101];
int max(int x, int y) {
	return x < y ? y : x;
}
int main() {
	int N;
	int i;
	int j;
	int k;
	int a[101][101];
	
	while (scanf("%d\n", &N) != EOF) {
		for (i = 1;i <= N;i++) {
			for (j = 1;j <= N;j++) {
				scanf("%d", &a[i][j]);
				sum[i][j] = a[i][j] + sum[i][j-1];
			}
		}
		int tmax = -0x7ffffff;
		for (i = 1;i <= N;i++) {
			for (j = i;j <= N;j++) {
				for (k = 1;k <= N;k++) {
					int tmp = sum[k][j] - sum[k][i - 1];
					if (dp[k - 1] < 0)
						dp[k] = tmp;
					else
						dp[k] = dp[k - 1] + tmp;
					if (tmax < dp[k]) {
						tmax = dp[k];
						printf("´ËÊ±¾ØÕó£ºi=%d,j=%d,k=%d,tmax=%d\n", i, j, k,tmax);
						
					}
					
				}
			}
		}
		printf("%d\n", tmax);

	}

}