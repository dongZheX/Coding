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
	//���
	for (int i = 0; i < N; i++)
		edge[i].clear();
	//���
	Edge tmp;
	tmp.nextNode = 3;
	tmp.cost = 38;
	edge[1].push_back(tmp);
	//��ѯ
	for (int i = 0; i < edge[2].size();i++) {
		int nextNode = edge[2][i].nextNode;
		int cost = edge[i][i].cost;
	}
	//���
	edge[1].erase(edge[1].begin(), edge[1].begin() + 1);

}