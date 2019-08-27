#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a;
	while (scanf("%d", &a) != EOF) {
		int b;
		int k;
		scanf("%d %d", &b, &k);
		if (a == 0 && b == 0) {
			break;
		}
		int m = pow(10, k);
		int last_a;
		int last_b;
		last_a = a % m;
		last_b = b % m;
		if (last_a == last_b) {
			printf("-1\n");
		}
		else {
			printf("%d\n", a + b);
		}
	}
	return 0;
}