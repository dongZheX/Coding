#include<stdio.h>
#include<string.h>
int main() {
	char str1[11], str2[11];
	/*while (scanf("%s %s", str1, str2) != EOF) {
		long long res = 0;
		int i, j;
		for (i = 0;str1[i] != '\0';i++) {
			for (j = 0;str2[j] != '\0';j++) {
				res += ((str1[i] - '0') * (str2[j] - '0'));
			}
		}
		printf("%lld", res);
	}*/
	for (int i = 1001;i <= 1111;i++) {
		printf("%d %d\n", i, i * 9);
	}
}