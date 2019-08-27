#include<stdio.h>
int main() {
	char str[1000000];
	for (int i = 0; i < 256;i++) {
		int temp = i * i;
		int len = 0;
		while (temp != 0) {
			str[len++] = temp % 10 + '0';
			temp /= 10;
		}
		bool flag = false;
		for (int i = 0, j = len - 1;i < j;i++, j--) {
			if (str[i] != str[j]) {
				flag = true;break;
			}	
		}
		if (!flag)
			printf("%d\n", i);
	}
}