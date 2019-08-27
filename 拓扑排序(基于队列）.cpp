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
		//���������Ϊ0�Ľڵ������У������������
		/*
			Ȼ���������ǰ�ˣ���������ڵ������ͨ���Ľڵ�����-1������ýڵ����Ϊ0��������У�ֱ������Ϊ��
			����������Ϊn��������ɹ�
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