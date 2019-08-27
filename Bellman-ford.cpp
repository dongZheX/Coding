#include<stdio.h>
int v[1000];//边终点
int u[1000];//边起点
int w[1000];//权值
int d[1000];//距离
int d2[1000][1000]
#define INF 0x7fffffff
void bellman_ford(int n) {
	int k, m;
	int i;
	for (i = 1;i <= n;i++)
		d[i] = INF;
	d[1] = 0;//起点为1
	for (k = 0;k < n - 1;k++) {
		for (i = 0;i < n;i++) {
			if (d[v[i]] < d[u[i]] + w[i]) {
				d[v[i]] = d[u[i]] + w[i];
			}
		}
	}
	/*
		证明：
		设顶点为 v0,v1,……,vn
		其中最短路径为v0,s1,s2,……，sk
		k<=n-1
		如果k>n-1，这是不可能的，说明最短路径中存在环，如果为负环，则不存在最短路径，如果为正环，则一定存在小于n的路径
		经过第一次松弛，可定可以确定v0-s1最短边，且不再变化（当时不知道是最短边，但是确实是最短边，且不再变化）
		然后以此类推，n-1次后可以全部确定
		如果进行第n次松弛，还可以更新，说明存在负环，这个更新的位置，处在环尾到环头的部分

		//同理可以用其寻找正环，poj1860
	*/
}
void floyd(int n) {
	int i, j, k;

}