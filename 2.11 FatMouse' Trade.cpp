#include<stdio.h>
#include<algorithm>
using namespace std;
struct item {
	double p;
	double w;
}items[1000];
bool cmp(struct item a, struct item b) {
	return (a.w / a.p) > (b.w / b.p);
}
int main() {
	int M, N;
	int id = 0;
	double res = 0;
	while (scanf("%d%d", &M, &N) && M != -1 && N != -1) {
		id = 0;
		res = 0;
		for (int i = 0; i < N; i++) {
			scanf("%lf%lf", &items[i].w, &items[i].p);
		}
		sort(items, items + N, cmp);
		while (id < N && M > 0) {
			if (M >= items[id].p) {
				res += items[id].w;
				M -= items[id].p;
				
			}
			else {
				res += (M / items[id].p)*items[id].w;
				M = 0;
			}
			id++;
		}
		printf("%.3lf\n", res);
	}
	
}