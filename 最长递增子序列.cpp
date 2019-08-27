#include<stdio.h>
#include<math.h>
#define N 30000
int max(int a, int b) {
	return a < b ? b : a;
}
int main() {
	int h[N];
	int dp[N];
	int n;
	while (scanf("%d", &n) != EOF) {
		h[0] = 0;
		for (int i = 1; i <= n;i++) {
			scanf("%d", &h[i]);
		}
		for (int i = 1;i <= n;i++) {
			int dmax = 1;
			for (int j = 1;j < i;j++) {
				if (h[j] < h[i]) {
					dmax = max(dmax, dp[j] + 1);
				}
			}
			dp[i] = dmax;
			//dp[i]表示用几号系统
		}
		int dmax = 0;
		for (int i = 1;i <= n;i++) {
			dmax = max(dmax, dp[i]);
		}
		if (n)
			printf("%d\n", dmax);
	}
	
} 
