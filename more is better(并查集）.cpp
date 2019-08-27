#include<stdio.h>
#include<vector>
#include<set>
using namespace std;
#define N 10000001
int Tree[N];
int sum[N] = { 0 };
void init(int a[]) {
	int i;
	for (i = 0; i < N;i++) {
		a[i] = -1;
		sum[i] = 0;
	}
}
//�ݹ����
int findFather(int a)
{
	if (Tree[a] == -1)return a;
	else {
		int tmp = findFather(Tree[a]);
		Tree[a] = tmp;//·��ѹ��
		return tmp;
	}
}
//�ǵݹ����
int FefindFather(int a) {
	int tmp = a;
	int ret;
	while (Tree[tmp] != -1) {
		tmp = Tree[tmp];
	}
	ret = tmp;
	tmp = a;
	//·��ѹ��
	while (Tree[tmp] != -1) {
		int t = Tree[tmp];
		Tree[tmp] = ret;
		tmp = t;
	}
	return ret;
}
//�ϲ�
void Union(int a, int b) {
	int tmp1;
	int tmp2;
	tmp1 = findFather(a);
	tmp2 = findFather(b);
	if (tmp1 != tmp2) {
		Tree[tmp1] = tmp2;
	}
}
int main() {
	int i;
	int j;
	int n;
	while (scanf("%d", &n) != EOF) {
		int ans = -1;
		int max = 0;
		init(Tree);
		if (n == 0) {
			printf("1\n");
			continue;
		}
		for (i = 0;i < n;i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			if (a > max)max = a;
			if (b > max)max = b;
			Union(a, b);
		}
		for (i = 1;i <=max;i++) {
			sum[findFather(i)]++;
		}
		for (i = 1;i <=max;i++) {
			if (sum[i] > ans) {
				ans = sum[i];
			}
		}
		printf("%d\n", ans);
	}
}