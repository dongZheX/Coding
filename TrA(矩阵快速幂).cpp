#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void mul(int input[][11], int input2[][11], int res[][11], int n);
int quickmul(int input[][11], long long k, int n);
int main() {
	int T;            //测试用例个数
	int n;            //dim
	long long k;      //幂
	int input[11][11];//输入矩阵
	int res[11][11];  //结果矩阵
	int i;
	int j;

	scanf("%d", &T);

	while (T--) {
		scanf("%d%lld", &n, &k);

		//输入
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				scanf("%d", &input[i][j]);
			}
		}
		printf("%d\n", quickmul(input, k, n));
	}
}
void mul(int input[][11], int input2[][11],int res[][11], int n) {
	int i;
	int j;
	int k;
	int result = 0;
	int temp[11][11];//支持自乘
	int temp2[11][11];
	for (i = 0;i < n;i++) {
		for (j = 0;j < n;j++) {
			temp[i][j] = input[i][j];
		}
	}
	for (i = 0;i < n;i++) {
		for (j = 0;j < n;j++) {
			temp2[i][j] = input2[i][j];
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			result = 0;
			for (k = 0; k < n; k++) {
				result += (temp[i][k] * temp2[k][j])%9973;
				result %= 9973;
			}
			res[i][j] = result;
		}
	}
}
int quickmul(int input[][11], long long k, int n) {
	int i;
	int j;
	int ans[11][11];
	int res = 0;
	//单元矩阵是 主对角线矩阵
	for (i = 0;i < n;i++) {
		for (j = 0;j < n;j++) {
			if (i == j)
				ans[i][j] = 1;
			else
				ans[i][j] = 0;
		}
	}
	while (k != 0) {
		if (k % 2 == 1) {
			mul(input, ans, ans, n);
			//满足交换律
		}
		k /= 2;
		mul(input, input, input, n);
	}

	for (i = 0; i < n; i++) {
		res += ans[i][i];
		res %= 9973;
	}
	return res;
}
//快速幂入门题目
/*
A为一个方阵，则Tr A表示A的迹（就是主对角线上各项的和），现要求Tr(A^k)%9973。

输入：
数据的第一行是一个T，表示有T组数据。
每组数据的第一行有n(2 <= n <= 10)和k(2 <= k < 10^9)两个数据。接下来有n行，每行有n个数据，每个数据的范围是[0,9]，表示方阵A的内容。

输出：
对应每组数据，输出Tr(A^k)%9973。

样例输入：
2
2 2
1 0
0 1
3 99999999
1 2 3
4 5 6
7 8 9
样例输出：
2
2686

*/