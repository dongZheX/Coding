#include<stdio.h>
long long Fn[22];
int main() {
	Fn[1] = 0;
	Fn[2] = 1;
	for (int i = 3;i < 22;i++) {
		Fn[i] = (i - 1)*Fn[i - 1] + (i - 1)*Fn[i - 2];
		/*
			��һ��������n���ŷ���k����n-1�ַ���
			�ڶ�����
			�ٽ�k����n����ʣ�µ�n-2��F(n-2)�з���
			��k������n����k�൱��n���ܷ���n����������D(n-1)��
		*/
	}
	int n;
	while (scanf("%d", &n) != EOF) {
		printf("%lld\n",Fn[n]);
	}
}