#include<stdio.h>
#include<string.h>
int main() {
	char str[10000];
	while (scanf("%s", str) != EOF) {
		int len = strlen(str);
		int res = 0;
		for (int i = 0; i < len; i++) {
			res += (str[i] - '0');
		}
		while (res >= 10) {
			int temp = res;
			res = 0;
			len = 0;
			while (temp != 0) {
				str[len++] = temp % 10 + '0';
				temp /= 10;
			}
			str[len] = '\0';
			len = strlen(str);
			for (int i = 0; i < len;i++) {
				res += (str[i] - '0');
			}
		}
		printf("%d\n", res);
	}
}