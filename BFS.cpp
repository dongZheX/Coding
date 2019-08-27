#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
#define N 51
int T;
int a, b, c;
int vis[N][N][N];
int graph[N][N][N];
int movet[6][3] = {
	{1,0,0},
	{-1,0,0},
	{0,1,0},
	{0,-1,0},
	{0,0,1 },
	{0,0,-1}
};
typedef struct pos {
	int x, y, z;
	int t;
}Pos;
queue<Pos> Q;
int BFS();
int main() {
	int n;
	int i, j, k;
	scanf("%d", &n);
	while (n--) {
		while (!Q.empty())Q.pop();
		scanf("%d%d%d%d", &a, &b, &c,&T);
		for (i = 0;i < a;i++) {
			for (j =0;j < b;j++) {
				for (k = 0;k < c;k++) {
					scanf("%d", &graph[i][j][k]);
					vis[i][j][k] = 0;
				}
			}
		}
		vis[0][0][0] = 1;
		Pos tmp;
		tmp.x = tmp.y = tmp.z = 0;
		tmp.t = 0;
		Q.push(tmp);
		int res = BFS();
		if (res > T)
			printf("-1\n");
		else
			printf("%d\n", res);
	}
	return 0;
}
int BFS() {
	
	int i, j;
	Pos tmp,next;
	while (!Q.empty()) {
		tmp = Q.front();
		Q.pop();
		for (i = 0;i < 6;i++) {
			next.x = tmp.x + movet[i][0];
			next.y = tmp.y + movet[i][1];
			next.z = tmp.z + movet[i][2];
			if (next.x < 0 || next.x >= a || next.y < 0 || next.y >= b || next.z < 0 || next.z >= c)continue;
			if (graph[next.x][next.y][next.z]==1|| vis[next.x][next.y][next.z]==1)continue;
			else{
				vis[next.x][next.y][next.z] == 1;
				next.t = tmp.t + 1;
				Q.push(next);
				if (next.x == a - 1 && next.y == b - 1 && next.z == c - 1) {
					return  next.t;
				}
			}
			
		}
	}
	return -1;
}