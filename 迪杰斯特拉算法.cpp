#include<vector>
#include<algorithm>
#include<vector>
using namespace std;
typedef struct E {
	int next;
	int val;
}edge;
vector<E> edges[101];
int dis[101];
bool mark[101];
int main() {
	int n, m;
	int i, j, k;
	while (scanf("%d%d", &n, &m) != EOF) {
		if (n == 0 && m == 0)break;
		//初始化
		for (i = 1;i <= n;i++)edges[i].clear();
		for (i = 1;i <= n;i++) {
			dis[i] = -1;
			mark[i] = false;
		}
		for (i = 0;i < m;i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			edge e;
			e.next = b;
			e.val = c;
			edges[a].push_back(e);
			e.next = a;
			edges[b].push_back(e);
		}
		mark[1] = true;
		dis[1] = 0;
		k = 1;
		//贪心和动态规划好难
		for (i = 1;i < n;i++) {
			for (j = 0;j < edges[k].size();j++) {
				edge temp = edges[k][j];
				if (mark[temp.next])continue;
				if (dis[temp.next] == -1 || dis[temp.next] > dis[k] + temp.val) {
					dis[temp.next] = dis[k] + temp.val;
				}
			}
			int min = 123123123;
			for (j = 1;j <= n;j++) {
				if (mark[j] == true)continue;
				if (dis[j] == -1)continue;
				if (dis[j] < min) {
					min = dis[j];
					k = j;
				}
			}
			mark[k] = true;
		}
		printf("%d\n", dis[n]);
	}
}