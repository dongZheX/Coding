#include<stdio.h>
#include<algorithm>
using namespace std;
int ans[110][110];
int path[110][110];
void print(int i, int j);
int main() {
	int m, n;
	int i, j, k;
	while (scanf("%d%d", &n, &m)!=EOF) {
		if (m == 0 || n == 0)break;
		for (i = 0;i <= n;i++) {
			for (j = 0; j <= n; j++) {
				if (i != j) {
					ans[i][j] = -1;
					path[i][j] = -1;
				}
				else {
					ans[i][i] = 0;
					path[i][j] = -1;
				}
					
			}
		}
		for (i = 0;i < m;i++){
			int t1, t2, t3;
			scanf("%d%d%d", &t1, &t2, &t3);
			ans[t1][t2] = ans[t2][t1] =  t3;
		}
		//状态转移方程
		/*
			ans[k][i][j] = min(ans[k-1][i][j],ans[k-1][i][k]+ans[k-1][k][j])
		*/
		//先求局部最优解
		for (k = 0;k < n;k++) {
			for (i = 0;i < n;i++) {
				for (j = 0;j < n;j++) {
					if (ans[i][k] == -1 || ans[k][j] == -1) continue;
					else if (ans[i][j] == -1 || ans[i][j] > ans[i][k] + ans[k][j]) {
						ans[i][j] = ans[i][k] + ans[k][j];
						path[i][j] = k;
					}
						
				}
			}
		}
		printf("%d\n0", ans[0][n-1]);
		print(0, n-1);
		printf("\n");
		
	}
	
}
void print(int i, int j) {
	if (path[i][j] != -1) {
		print(i, path[i][j]);
		print(path[i][j], j);
	}
	else {
		printf("->%d", j);
	}
}