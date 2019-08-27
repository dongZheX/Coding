#include<stdio.h>
#include<algorithm>
using namespace std;
struct tv {
	int s;
	int e;
	bool operator < (const struct tv & A) const {
		return e < A.e;
	}
}tvs[101];

int main() {
	int n;
	while (scanf("%d", &n) && n != 0) {
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &tvs[i].s, &tvs[i].e);
		}
		sort(tvs, tvs + n);
		int temp = tvs[0].e;
		int res = 1;
		for (int i = 1;i < n;i++)
		{
			if (tvs[i].s >= temp) {
				temp = tvs[i].e;
				res++;
			}
		}
		printf("%d\n", res);
	}
}
//data
/*
12
1 3
3 4
0 7
3 8
15 19
15 20
10 15
8 18
6 12
5 10
4 14
2 9
5
*/