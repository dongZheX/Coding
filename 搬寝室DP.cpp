#include<cstdio>
#include<algorithm>
using namespace std;
int dp[1001][2002];
int main() {
	int k;
	int n;
	int i;
	int j;
	int list[2002];
	while(scanf("%d%d", &n, &k) != EOF) {
		for (i = 1;i <= n;i++)
			scanf("%d", &list[i]);
		for (i = 0;i <= n;i++)
			dp[0][i] = 0;
		sort(list+1, list + n + 1);
		for (i = 1;i <= k;i++) {
			for (j = 2 * i;j <= n;j++) {
				//dp[i][j]表示前j物品搬i对的最小疲劳度
				if (j == 2 * i) {
					dp[i][j] = dp[i - 1][j - 2] + (list[j] - list[j - 1])*(list[j] - list[j - 1]);
				}
				else {
					int x = dp[i][j - 1];
					int y = dp[i - 1][j - 2] + (list[j] - list[j - 1])*(list[j] - list[j - 1]);
					//看新加入的j的影响，而且他必须跟他前面的配对，所以状态方程就是比较j-1个物品和前j个物品且用了倒数两个的情况 或者直接可以说第j个用还是不用
					dp[i][j] = x > y ? y : x;
				}
			}
		}
		printf("%d\n", dp[k][n]);
	}

}