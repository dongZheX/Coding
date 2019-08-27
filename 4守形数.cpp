#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int m = pow(n, 2);
		int k = 0;
		int tmp = pow(10, k);
		while (m / tmp > 0) {
			k++;
			tmp = pow(10, k);
		}
		int q = pow(10, k - 1);
		int last_m = m % q;
		if (n == last_m) {
			printf("Yes!\n");
		}
		else {
			printf("No!\n");
		}
	}
	return 0;
}