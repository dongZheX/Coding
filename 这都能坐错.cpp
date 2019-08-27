#include<stdio.h>
int main() {
	int N, K;
	while (scanf("%d%d", &N, &K) != EOF) {
		float base = 200.0;
		float salary = 0;
		int flag = 0;
		for (int i = 1;i <= 21;i++) {
			base = base*1.0 + base*(K / 100.0);
			salary = salary + N;
			printf("%lf %lf\n", base, salary);
			if (base <= salary) {
				printf("%d\n", i);
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			printf("Impossible\n");
		}
	}
}