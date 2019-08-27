#include<stdio.h>
#include<string.h>
char s1[100];
char s2[100];
int dp[100][100];
int max(int a, int b) {
	return a < b ? b : a;
}
void print(int a,int b) {
	if (a < 1 || b < 1)return;
	if (dp[a][b] == dp[a - 1][b - 1] + 1) {
		print(a - 1, b - 1);
		printf("%c", s1[a-1]);//最后输出
	}
	else
		dp[a - 1][b] > dp[a][b - 1] ? print(a - 1, b) : print(a, b - 1);
}
int main() {
	
	gets(s1);
	gets(s2);
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	
	for (int i = 0;i < len1;i++)
		dp[i][0] = 0;
	for (int i = 0;i < len2;i++)
		dp[0][i] = 0;
	for (int i = 1;i <= len1;i++) {
		for (int j = 1;j <= len2;j++) {
			if (s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);//最长公共子序列
				// dp[i][j] = 0;  // 最长公共子串
			}
		}
	}
	printf("%d\n", dp[len1][len2]);
	print(len1, len2);
	printf("\n");
}