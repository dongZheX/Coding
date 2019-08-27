#include <stdio.h>
#include<algorithm>
using namespace std;
#define N 200110
int Tree[N];
struct magic {
	int a, b;
	long long V;
	bool operator < (const magic &A)const {
		return V < A.V;
	}
}magics[N];
int findFather(int a) {
	if (Tree[a] == -1)return a;
	else {
		int tmp =  findFather(Tree[a]);
		Tree[a] = tmp;
		return tmp;
	}
}
int main() {
	int n, m;
	int i;
	int j;
	int temp;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (i = 0;i < m;i++) {
			scanf("%d%d%lld", &magics[i].a, &magics[i].b, &magics[i].V);
		}
		for (i = 0;i < N;i++) {
			Tree[i] = -1;
		}
		sort(magics, magics + m);
		for (i = 0;i<m;i++) {
			int a = magics[i].a;
			int b = magics[i].b;
			int x = findFather(a);
			int y = findFather(b);
			if (x != y) {
				temp = magics[i].V;
				Tree[x] = y;
			}
		}
		long long ans = 0;
		for (i = 0;i < N;i++) {
			Tree[i] = -1;
		}
		for (i = m-1;i>=0;i--) {
			//最大值可能
			if (magics[i].V <= temp) {
				int a = magics[i].a;
				int b = magics[i].b;
				int x = findFather(a);
				int y = findFather(b);
				if (x != y) {
					ans += magics[i].V;
					Tree[x] = y;
				}
			}
			
		}

		printf("%lld\n", ans);
	}

	return 0;
}