#include<stdio.h>
#include<vector>
#include<set>
using namespace std;
#define N 1000
int Tree[N];
void init(int a[]){
	int i;
	for (i = 0; i < N;i++) {
		a[i] = -1;
	}
}
//递归查找
int findFather(int a)
{
	if (Tree[a] == -1)return a;
	else {
		int tmp = findFather(Tree[a]);
		Tree[a] = tmp;//路径压缩
		return tmp;
	} 
}
//非递归查找
int FefindFather(int a) {
	int tmp = a;
	int ret;
	while (Tree[tmp] != -1) {
		tmp = Tree[tmp];
	}
	ret = tmp;
	tmp = a;
	//路径压缩
	while (Tree[tmp] != -1) {
		int t = Tree[tmp];
		Tree[tmp] = ret;
		tmp = t;

	}
	return ret;
}
//合并
void Union(int a, int b) {
	int tmp1;
	int tmp2;
	tmp1 = findFather(a);
	tmp2 = findFather(b);
	if (tmp1 != tmp2) {
		Tree[tmp1] = tmp2;
	}
}
//一个测试 关于畅通工程
int main() {
	set<int> s;
	int n, m;
	while (scanf("%d", &n) != EOF&&n != 0) {
		scanf("%d", &m);
		init(Tree);
		for (int i = 0; i < m;i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			Union(a, b);
		}
		s.clear();
		for (int i = 1; i <= n; i++) {
			s.insert(findFather(i));
		}
		printf("%d\n", s.size() - 1);
	}
}