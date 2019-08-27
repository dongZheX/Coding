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
				//dp[i][j]��ʾǰj��Ʒ��i�Ե���Сƣ�Ͷ�
				if (j == 2 * i) {
					dp[i][j] = dp[i - 1][j - 2] + (list[j] - list[j - 1])*(list[j] - list[j - 1]);
				}
				else {
					int x = dp[i][j - 1];
					int y = dp[i - 1][j - 2] + (list[j] - list[j - 1])*(list[j] - list[j - 1]);
					//���¼����j��Ӱ�죬�������������ǰ�����ԣ�����״̬���̾��ǱȽ�j-1����Ʒ��ǰj����Ʒ�����˵������������ ����ֱ�ӿ���˵��j���û��ǲ���
					dp[i][j] = x > y ? y : x;
				}
			}
		}
		printf("%d\n", dp[k][n]);
	}

}