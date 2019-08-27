#include<stdio.h>
#define N 101
int max(int a, int b) {
	return a < b ? b : a;
}
int main() {
	int dp1[N];
	int dp2[N];
	int a[N];
	int i, j;
	int n;
	while (scanf("%d", &n) != EOF) {
		dp1[0] = dp2[0] = 0;
		for (i = 1;i <= n;i++)
			scanf("%d", &a[i]);
		for (i = 1;i <= n;i++) {
			int dmax=1;
			for (int j = 1;j <i;j++) {
				if (a[j] < a[i])
					dmax = max(dmax, dp1[j] + 1);
			}
			dp1[i] = dmax;
		}
		for (i = n;i >= 1;i--) {
			int dmax = 1;
			for (int j = n;j > i;j--) {
				if (a[j] < a[i])
					dmax = max(dmax, dp2[j] + 1);
			}
			dp2[i] = dmax;
		}
		int dmax = 0;
		for (i = n;i >= 1;i--) {
			dmax = max(dp1[i] + dp2[i] -1,dmax);
		}
		printf("%d\n", n-dmax);
	}
	

}