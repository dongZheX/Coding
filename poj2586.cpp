#include<stdio.h>
int main() {
	int s, d;
	int i, j;
	while (scanf("%d%d", &s, &d) != EOF) {
		int min = 5 * d / (d + s);
		//5���������м���ӯ��
		int sn = min * 2 + (min<=2?min:2);
		//ӯ������
		//sssdd sssdd ss
		//sdddd sdddd sd
		//��������
		int dn = 12 - sn;
		int sum = sn*s - dn*d;
		if (sum >= 0) { printf("%d\n", sum); }
		else printf("Deficit\n");
	}
}