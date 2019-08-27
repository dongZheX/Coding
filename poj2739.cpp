#include<stdio.h>
int prime[10000];
int len = 0;
int num[10001] = { 0 };
int main() {
	
	
	
	int i, j;
	for (i = 2;i <= 10000;i++) {
		if (num[i] == 0)
			prime[len++] = i;
		for (j = 0;j<len&&i*prime[j]<=10000;j++) {
			num[i*prime[j]] = 1;
			if (i%prime[j] == 0)break;
		}
	}
	int input;
	while (scanf("%d", &input) && input != 0) {
		int result=0;
		for (i = 0;i < len;i++) {
			int sum = 0;
			for (j = i;j < len;j++) {
				sum += prime[j];
				if (sum > input)break;
				else if (sum == input)
					result++;
			}
		}
		printf("%d\n", result);
	}
}