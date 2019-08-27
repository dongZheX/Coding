#include<stdio.h>
using namespace std;
#define N 1001
int Tree[1001];
void init() {
	for (int i = 0;i < N;i++) {
		Tree[i] = -1;
	}
}
int findFa(int a) {
	if (Tree[a] == -1)return a;
	else {
		int tmp = findFa(Tree[a]);
		Tree[a] = tmp;
		return tmp;
	}
}
void Union(int a, int b) {
	int tmp1 = findFa(a);
	int tmp2 = findFa(b);
	if (tmp1 != tmp2) {
		Tree[tmp1] = tmp2;
	}
}
int main() {
	int n, m;
	int i;
	int j;
	while (scanf("%d%d", &n,&m) != EOF) {
		init();
		for (i = 0; i < m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			Union(a, b);
		}
		int tmp1 = findFa(1);
		bool flag = false;
		for(i = 2;i <= n;i++){
			if (findFa(i) != tmp1) {
				printf("NO\n");
				flag = true;
				break;
			}
		}
		if (!flag)
			printf("YES\n");
	}
}