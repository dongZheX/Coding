#include<stdio.h>
int res;
int vis[100][100];
char oil[100][100];
int m, n;
int next[8][2] = { -1,1, -1,-1, -1,0, 1,0,1,-1,1,1,0,1,0,-1};
void dfs(int x, int y, int num) {
	vis[x][y] = true;
	int tx;
	int ty;
	int i;
	for (i = 0;i < 8;i++) {
		tx = x + next[i][0];
		ty = y + next[i][1];
		if (tx < 0 || tx >= m || ty < 0 || ty >= n)continue;
		if (vis[tx][ty] == false && oil[tx][ty] == '@') {
			dfs(tx, ty, num + 1);
		}
	}
}
int main() { 
	int i, j;
	while (scanf("%d%d", &m, &n) != EOF&&m != 0 && n != 0) {
		res = 0;
		getchar();
		for (i = 0;i < m;i++) {
			for (j = 0;j < n;j++) {
				scanf("%c", &oil[i][j]);
				vis[i][j] = false;
			}
			getchar();
		}
		for (i = 0;i < m;i++) {
			for (j = 0;j < n;j++) {
				if (vis[i][j] == false&&oil[i][j]=='@') {
					res++;
					dfs(i, j, 1);
				}
			}
		}
		printf("%d\n", res);

	}
}