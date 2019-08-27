#include<stdio.h>
// W= (d+1+2*m+3*(m+1)/5+y+y/4-y/100+y/400) mod 7
int main() {
	int d, y, m;
	while (scanf("%d%d%d", &d, &m, &y) != EOF) {
		if (m == 1 || m == 2) {
			m += 12;
			y -= 1;
		}
		printf("%d", (d + 1 + 2 * m + 3 * (m + 1) / 5 + y+y / 4 - y / 100 + y / 400)%7);
	}
}