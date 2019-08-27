#include<stdio.h>
int main() {
	int s, d;
	int i, j;
	while (scanf("%d%d", &s, &d) != EOF) {
		int min = 5 * d / (d + s);
		//5天里至少有几天盈利
		int sn = min * 2 + (min<=2?min:2);
		//盈利天数
		//sssdd sssdd ss
		//sdddd sdddd sd
		//亏损天数
		int dn = 12 - sn;
		int sum = sn*s - dn*d;
		if (sum >= 0) { printf("%d\n", sum); }
		else printf("Deficit\n");
	}
}