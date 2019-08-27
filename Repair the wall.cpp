#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(long long a, long long b)
{
	return a > b;
}
int main() {
	long long len;
	int n;
	long long blocks[610];
	int i, j;
	int res;
	while (scanf("%lld%d", &len, &n) != EOF) 
	{
		res = 0;
		for (i = 0; i < n; i++) {
			scanf("%lld", &blocks[i]);
		}
		sort(blocks, blocks + n, cmp);
		for (i = 0; i < n; i++) {
			res++;
			len -= blocks[i];
			if (len <= 0)
				break;
		}
		if (len > 0) {
			printf("impossible\n");
		}
		else{
			printf("%d\n", res);
			//负数也可以
		}

	}
}