#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 17
int Prime[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,47 };
int num[N];
int n;
int vis[N];
int len = 1;
bool judge(int n) {
	if (binary_search(Prime, Prime + 14, n))return true;
	else return false;
}
void print() {
	if (judge(num[n] + num[1]) == false)return;
	else {
		for (int i = 1;i <= n - 1;i++) {
			printf("%d ", num[i]);;
		}
		printf("%d\n", num[n]);
	}
}
void dfs(int nt) {
	int i;
	if (nt > 1) {
		if (judge(num[nt] + num[nt - 1]) == false) {
			return;
		}
	}
	if (nt == n) {
		print();
		return;
	}
	else {
		for (i = 2;i <= n;i++) {
			if (vis[i] == false) {
				num[nt + 1] = i;
				vis[i] = true;
				dfs(nt + 1);
				vis[i] = false;
			}
		}
	}
}
int main() {
	int i, j;
	while (scanf("%d", &n) != EOF) {
		for (i = 0;i < N;i++)vis[i] = false;
		vis[1] = true;	
		num[1] = 1;
		printf("Case %d:\n",len++);
		dfs(1);
		printf("\n");
	}
}