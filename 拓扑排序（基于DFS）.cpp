#include<stdio.h>
#include<vector>
using namespace std;
vector<int> edge[505];
int save[501];
int len = 0;
int vis[501];
vector<int> v;
//  1 Ϊ�����֣�2Ϊ������������У�0Ϊδ������
void dfs(int i) {
	vis[i] = 1;
	for (int j = 0;j < edge[i].size();j++) {
		if (vis[edge[i][j]]==0) {
			dfs(edge[i][j]);
		}
		else if(vis[edge[i][j]]==1){
			return;//������һ���ڵ㲻�����
			//ע��������2���пγ̵�

		}
	}
	save[len++] = i;
	vis[i] = 2;
	//�˵���������������б��������ӽڵ�֮ǰ�����ﷴ����������Ӷ��б������֮��
	//����ʹ�÷�������һ����ָ��ڵ������ָ��ڵ�ǰ���𣬲��ᣬ�����ǰ�棬����������ȱ�����ʱ�����ָ��ڵ��ǰ�棬���ǲ����ܵ� important
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