#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define N 10000
int Tree[N];
int findFather(int a) {
	if (Tree[a] == -1) return a;
	else {
		int tmp = findFather(Tree[a]);
		Tree[a] = tmp;
		return tmp;
	}
}
void Union(int a, int b) {
	int tmp1 = findFather(a);
	int tmp2 = findFather(b);
	if (tmp1 != tmp2) {
		Tree[tmp1] = tmp2;
	}
}
struct Edge {
	int a, b;
	int val;
	bool operator < (const Edge &A)const {
		return val < A.val;
	}
}edges[N];
int main() {
	int n;
	int i;
	int j;
	int res;
	int times;
	while (scanf("%d", &n) != EOF && n!=0) {
		res = 0;
		for (i = 0;i < N;i++)
			Tree[i] = -1;
		for (i = 0;i < ((n - 1) * n / 2);i++) {
			scanf("%d%d%d", &edges[i].a, &edges[i].b, &edges[i].val);
		}
		sort(edges, edges + (n - 1) * n / 2);
		for (i = 0, times = 0; times < n -1;i++) {
			int a = edges[i].a;
			int b = edges[i].b;
			int x = findFather(a), y = findFather(b);
			if (x != y) {
				res += edges[i].val;
				Tree[x] = y;
				times++;
			}
		}
		printf("%d\n", res);
	}
}