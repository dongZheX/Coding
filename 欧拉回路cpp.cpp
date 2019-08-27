#include<stdio.h>
#include<vector>
using namespace std;
vector<int> edge[1000];
int main() {
	int N, M;
	int i;
	int j;
	while (scanf("%d", &N) != EOF&&N != 0) {
		scanf("%d\n", &M);
		for (i = 0;i < 1000;i++) {
			edge[i].clear();
		}
		for (i = 0;i < M;i++) {
			int tmp1, tmp2;
			scanf("%d%d", &tmp1,&tmp2);
			edge[tmp1].push_back(tmp2);
			edge[tmp2].push_back(tmp1);
		}
		int flag = 1;
		for (i = 1;i <= N;i++) {
			if (edge[i].size() % 2 != 0) {
				flag = 0;
				break;
			}
		}
		printf("%d\n", flag);
	}
}