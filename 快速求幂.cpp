#include<stdio.h>
/*
	a^(b)
	a^(1*k0+2^1*k1+2^2*k2+.....2^n+kn)    b = k1k2k3k4k5k6(������) kn = 1 �� 0
*/
int main() {
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF) {
		if (a == 0 && b == 0)break;
		int ans = 1;
		while (b != 0) {
			if (b % 2 == 1) {
				ans *= a;
				ans %= 1000;
			}
			b /= 2;
			a *= a;//����a^(2k) a,a^2,a^4,a^8   1 2 4 8 �ֱ�Ϊ2^1,2^2,2^3 ��Ӧ���� ���Ҫ��⼸��
			a %= 1000;
		}
		printf("%d\n", ans);
	}
}