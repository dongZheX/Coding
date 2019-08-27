#include<stdio.h>
#include<vector>
using namespace std;
#define N 100
struct Edge {
	int nextNode;
	int cost;
};
int main() {
	vector<Edge> edge[N];
	//清除
	for (int i = 0; i < N; i++)
		edge[i].clear();
	//添加
	Edge tmp;
	tmp.nextNode = 3;
	tmp.cost = 38;
	edge[1].push_back(tmp);
	//查询
	for (int i = 0; i < edge[2].size();i++) {
		int nextNode = edge[2][i].nextNode;
		int cost = edge[i][i].cost;
	}
	//清除
	edge[1].erase(edge[1].begin(), edge[1].begin() + 1);

}