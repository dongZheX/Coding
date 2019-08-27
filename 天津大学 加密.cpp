#include<stdio.h>
#include<string.h>
int main() {
	int n;
	char str[10000];
	scanf("%d", &n);
	while (n--) {
		scanf("%s", str);
		int len = strlen(str);
		for (int i = 0;i < len;i++) {
			if (str[i] <= 'z'&&str[i] >= 'a') {
				str[i]++;
				if (str[i] > 'z') {
					str[i] = 'a';
				}
			}
			else if (str[i] <= 'Z'&& str[i] <= 'A') {
				str[i] = str[i] - ('A' - 'a');
			}
		}
		printf("%s\n", str);
	}
}