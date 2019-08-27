#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int a[1001];
	int n;
	while (scanf("%d", &n) != EOF) {
		
		for (int i = 0;i<n;i++) {
			scanf("%d", &a[i]);
		}
		if (n == 1) {
			printf("%d\n", a[0]);
			printf("-1\n");
			continue;
		}
		sort(a, a + n);
		printf("%d\n", a[n - 1]);
		for (int i = 0;i<n - 2;i++) {
			printf("%d ", a[i]);
		}
		printf("%d\n", a[n - 2]);
	}
}