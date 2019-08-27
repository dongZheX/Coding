#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void mul(int input[][11], int input2[][11], int res[][11], int n);
int quickmul(int input[][11], long long k, int n);
int main() {
	int T;            //������������
	int n;            //dim
	long long k;      //��
	int input[11][11];//�������
	int res[11][11];  //�������
	int i;
	int j;

	scanf("%d", &T);

	while (T--) {
		scanf("%d%lld", &n, &k);

		//����
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
	int temp[11][11];//֧���Գ�
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
	//��Ԫ������ ���Խ��߾���
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
			//���㽻����
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
//������������Ŀ
/*
AΪһ��������Tr A��ʾA�ļ����������Խ����ϸ���ĺͣ�����Ҫ��Tr(A^k)%9973��

���룺
���ݵĵ�һ����һ��T����ʾ��T�����ݡ�
ÿ�����ݵĵ�һ����n(2 <= n <= 10)��k(2 <= k < 10^9)�������ݡ���������n�У�ÿ����n�����ݣ�ÿ�����ݵķ�Χ��[0,9]����ʾ����A�����ݡ�

�����
��Ӧÿ�����ݣ����Tr(A^k)%9973��

�������룺
2
2 2
1 0
0 1
3 99999999
1 2 3
4 5 6
7 8 9
���������
2
2686

*/