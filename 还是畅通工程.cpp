#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 1000000
int Tree[N];
struct node {
	int a;
	int b;
	int val;
	int is;
	bool operator < (const node &A)const {
		return val < A.val;
	}
}road[N];
int findRoot(int a) {
	if (Tree[a] != a) {
		Tree[a] = findRoot(Tree[a]);
	}
	return Tree[a];
}
int main() {
	int n;
	int i;
	int j;
	while (scanf("%d", &n) != EOF&&n!=0) {
		for (i = 0;i < N;i++) {
			Tree[i] = i;
		}
		for (i = 0;i < n*(n-1)/2;i++) {
			scanf("%d%d%d%d", &road[i].a, &road[i].b, &road[i].val, &road[i].is);
			if (road[i].is == 1) {
				int x = findRoot(road[i].a);
				int y = findRoot(road[i].b);
				if (x != y)
					Tree[x] = y;
			}
		}
		sort(road, road + n * (n - 1) / 2);
		int ans = 0;
		for (i = 0;i < n*(n - 1) / 2;i++) {
			if (road[i].is == 0) {
				int x = findRoot(road[i].a);
				int y = findRoot(road[i].b);
				if (x != y) {
					Tree[x] = y;
					ans += road[i].val;
				}
					
			}
		}
		printf("%d\n", ans);
	}
}