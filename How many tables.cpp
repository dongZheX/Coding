#include<stdio.h>
#include<set>
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
	//数据结构 中的霍夫曼编码需要复习
	int n, m;
	int T;
	int i;
	int j;
	set<int> s;
	scanf("%d", &T);
	bool flag = true;
	while (T--) {
		//if (flag) { flag = false; }
		//else printf("\n");
		init();
		scanf("%d%d", &n,&m);
		for (i = 0; i < m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			Union(a, b);
		}
		for (int i = 1;i <= n;i++) {
			s.insert(findFa(i));
		}
		printf("%d\n", s.size());
		s.clear();
	}
}