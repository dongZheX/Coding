#include<stdio.h>
#include<algorithm>
int graph[101][101];
#define mod 100000
long long ans[101][101];
long long pows(long long, long long);
int main() {
	int n,m;
	int i;
	int j;
	int k;
	scanf("%d%d", &n,&m);
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			if (i != j)
				ans[i][j] = -1;
			else
				ans[i][j] = 0;
		}
	}
	for (i = 0;i < m;i++) {
		long long x, y;
		scanf("%lld%lld", &x, &y);
		int mosd = pows(2, i);
		ans[x][y] = ans[y][x] = mosd;
	}
	for (k = 0;k < n;k++) {
		for (i = 0;i < n;i++)
		{
			for (j = 0;j < n;j++)
			{
				if (ans[k][j] == -1 || ans[i][k] == -1)continue;
				else if (ans[i][j] == -1 || ans[i][j] > (ans[i][k] + ans[k][j])%mod) {
					ans[i][j] = (ans[i][k] + ans[k][j]) % mod;
				}
			}
		}
	}
	for (i = 1;i < n;i++) {
		printf("%lld\n", ans[0][i]);
	}
}
long long  pows(long long  x, long long y) {
	long long res = 1;
	while (y != 0) {
		if (y % 2 == 1) {
			res *= x;
			res = res % mod;
		}
		y /= 2;
		x *= x;
		x %= mod;
	}
	return res;
}