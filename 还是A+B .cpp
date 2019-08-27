#include<stdio.h>
int main() {
	int a, b, k;
	while (scanf("%d%d%d", &a, &b, &k) && a != 0 && b != 0) {
		int i;
		int temp = 1;
		bool is = true;
		for (i = 0;i < k;i++) {
			temp *= 10;
		}
		if (a%temp == b% temp) {
			is = false;
		}
		if (!is) {
			printf("-1\n");
		}
		else {
			printf("%d\n", a + b);
		}
	}
}