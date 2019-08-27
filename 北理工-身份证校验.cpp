#include<stdio.h>
int wi[] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
char ts[] = { '1','0','X','9','8','7','6','5','4','3','2','1' };
int main() {
	char id[20];
	while (scanf("%s", id) != EOF) {
		getchar();
		int sum = 0;
		for (int i = 0;i < 17;i++) {
			sum += (id[i] - '0')*wi[i];
		}
		int mod = sum % 11;
		if (ts[mod] == id[17]) {
			printf("%s 正确\n", id);
		}
		else
		{
			id[17] = ts[mod];
			printf("应为：%s\n", id);
		}
	}
}