#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> edge[501];
queue<int> Q;
int main() {
	int in[101];
	int m, n;
	int i,j;
	while (scanf("%d%d", &n, &m) != EOF) {
		if (n == 0 && m == 0)break;
		for (i = 0;i < n;i++) {
			edge[i].clear();
			in[i] = 0;
		}
			
		for (i = 0;i < m;i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			edge[a].push_back(b);
			in[b]++;
		}
		while (Q.empty() == false)Q.pop();
		for (i = 0;i < n;i++) {
			if (in[i] == 0)
				Q.push(i);
		}
		//将所有入度为0的节点加入队列，他们最先输出
		/*
			然后输出队列前端，将该输出节点可以连通到的节点的入度-1，如果该节点入度为0，加入队列，直到队列为空
			如果输出个数为n，则排序成功
		*/
		int cnt = 0;
		while (!Q.empty()) {
			int temp = Q.front();
			cnt++;
			Q.pop();
			for (i = 0;i < edge[temp].size();i++) {
				in[edge[temp][i]]--;
				if (in[edge[temp][i]] == 0) {
					Q.push(edge[temp][i]);
				}
			}
		}
		if (cnt == n) {
			printf("YES\n");
		}
		else
			printf("NO\n");
	}
}