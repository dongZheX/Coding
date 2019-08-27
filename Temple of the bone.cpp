#include<stdio.h>
int m, n, t;
int dx, dy;
int sx, sy;
char map[8][8];
int flag;
int vis[8][8];
int next[4][2] = { 1,0,-1,0,0,1,0,-1 };
void dfs(int x, int y, int time) {
	if (flag)return;
	int tx = 0;
	int ty = 0;
	for (int i = 0;i < 4;i++) {
		tx = x + next[i][0];
		ty = y + next[i][1];
		if (tx < 0 || tx >= n || ty < 0 || ty >= m)continue;
		if (vis[tx][ty] == 0 && map[tx][ty] != 'X')
		{
			if (map[tx][ty] == 'D') {
				if (time + 1 == t) {
					flag = 1;
					return;
				}
				else
					continue;
			}
			
			vis[tx][ty] = 1;
			dfs(tx, ty, time + 1);
			vis[tx][ty] = 0;
			
		}
	}
}
int main() {
	int i,j;
	while (scanf("%d%d%d", &n, &m, &t) != EOF&&n != 0 && m != 0 && t != 0) {
		getchar();
		flag = 0;
		for (i = 0;i < n;i++)
		{
			for (j = 0;j < m;j++) {
				vis[i][j] = 0;
				scanf("%c", &map[i][j]);
				if (map[i][j] == 'D')dx = i, dy = j;
				if (map[i][j] == 'S')sx = i, sy = j;
			}
			getchar();
		}
		if (((sx + sy) % 2 != (dx + dy) % 2&&t%2!=1)|| ((sx + sy) % 2 == (dx + dy) % 2 && t % 2 == 1)) {
			printf("NO\n");
			continue;
		}
		
		else {
			vis[sx][sy] = 1;
			dfs(sx, sy, 0);
		}
		if (flag) {
			printf("YES\n");
		}
		else
			printf("NO\n");
	}
}