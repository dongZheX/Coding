#include<algorithm>
#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;
#define N 10000
struct Point {
	double x, y;
	double getDistance(const Point& A)const {
		return sqrt((A.x - x)*(A.x - x) + (A.y - y)*(A.y - y));
	}
}points[N];
struct edge {
	int a, b;
	double cost;
	bool operator < (const edge &A)const {
		return cost < A.cost;
	}
}edges[N];
 int Tree[N];
int findFather(int a) {
	if (Tree[a] == -1)return a;
	else {
		int tmp = findFather(Tree[a]);
		Tree[a] = tmp;
		return tmp;
	}
}
int main() {
	int n;
	int i;
	int j;
	int len = 0;
	scanf("%d", &n);
	for (i = 0;i < n;i++) {
		scanf("%lf%lf", &points[i].x, &points[i].y);
	}
	for(i=0;i<N;i++){
		Tree[i] = -1;
	}
	for (i = 0;i < n;i++) {
		for (j = i + 1;j < n;j++) {
			edges[len].a = i;
			edges[len].b = j;
			edges[len].cost = points[i].getDistance(points[j]);
			len++;
		}
	}
	sort(edges, edges + (n - 1)*n / 2);
	int times = 0;
	double ans = 0;
	for (i = 0;times < n - 1;i++) {
		int a = edges[i].a;
		int b = edges[i].b;
		int x = findFather(a), y = findFather(b);
		if (x != y) {
			ans += edges[i].cost;
			Tree[x] = y;
			times++;
		}
	}
	printf("%.2lf\n", ans);
}