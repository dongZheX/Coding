#include<stdio.h>
#include<vector>
using namespace std;
vector<int> edge[505];
int save[501];
int len = 0;
int vis[501];
vector<int> v;
//  1 为被发现，2为被加入排序队列，0为未被发现
void dfs(int i) {
	vis[i] = 1;
	for (int j = 0;j < edge[i].size();j++) {
		if (vis[edge[i][j]]==0) {
			dfs(edge[i][j]);
		}
		else if(vis[edge[i][j]]==1){
			return;//至少有一个节点不被输出
			//注意这里是2是有课程的

		}
	}
	save[len++] = i;
	vis[i] = 2;
	//此点在拓扑排序队列中必须早其子节点之前，这里反向其必须在子队列遍历完毕之后。
	//可以使用反正法，一个被指向节点可以在指向节点前面吗，不会，如果在前面，他在深度优先遍历的时候就在指向节点的前面，这是不可能的 important
}

int main() {
	int i, j;
	int n, m;
	int in[501];
	while (scanf("%d%d", &n, &m)!=EOF) {
		if (m == 0 && n == 0)break;
		len = 0;
		for (i = 0;i < n;i++) {
			edge[i].clear();
			save[i] = 0;
			vis[i] = 0;
		}
		v.clear();
		for (i = 0;i < n;i++)
			in[i] = 0;
		for (i = 0;i < m;i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			edge[a].push_back(b);
			in[b]++;
		}
		for (i = 0;i < n;i++) {
			if (in[i] == 0 && !vis[i]) {		
				dfs(i);
			}
		}
		if (len == n) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}