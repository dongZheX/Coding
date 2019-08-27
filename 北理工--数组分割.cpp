#include<stdio.h>
long long dp[100000];
int main() {
	
	long long data[100000];
	char str[100000];
	while (gets_s(str) != NULL) {
		long long num = 0;
		int len = 0;
		int i = 0;
		int flag = 0;
		long long  sum = 0;
		while (str[i] != '\0') {
			if (str[i] == ' ') {
				data[len++] = num;
				sum += num;
				num = 0;
				i++;
				continue;
			}
			if (str[i] <= '9'&&str[i] >= '0') {
				num = str[i] - '0' + num * 10;
			}
			else {
				flag = 1;
				break;
			}
			i++;
		}
		data[len++] = num;
		sum += num;
		if (flag) {
			printf("ERROR\n");
			continue;
		}
		long long j;
		for (i = 0;i < len;i++) {
			for (j = sum/2;j >= data[i];j--) {
				dp[j] = dp[j] < dp[j -data[i]] + data[i] ? dp[j - data[i]] + data[i] : dp[j];
			}
		}
		printf("%ld %ld\n", dp[sum/2], sum - dp[sum/2]);
	}
}