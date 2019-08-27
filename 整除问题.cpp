#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
int Prime[1020];
bool vis[1020];
//关于分解我们可以轻易地把n！分解成小于1000的一些质数相乘，这是显而易见的，
int cnt[1020];
int cnt2[1020];
//这里假设小于1010的质数
int getPrime() {
	int i;
	int j;
	int len = 0;
	for (i = 0;i < 1010;i++)vis[i] = true;
	for(i = 2;i<=1010;i++){
		if (vis[i])Prime[len++] = i;
		for (j = 0; j < len&&Prime[j] * i <= 1010;j++) {
			vis[Prime[j] * i] = false;
			if (i%Prime[j] == 0)break;
		}
	}
	return len;
}
int main() {
	int a, n, k;
	int i;
	int j;
	int len = getPrime();
	int len1 = 0;
	scanf("%d%d", &n, &a);



	//分解a
	//可以进一步优化再Prime得个数上，但是不太方便，优化效果不太明显
	int temp = a;
	for (j = 0;j < len&&temp!=1;j++) {
		while (temp%Prime[j] == 0) {
			cnt[Prime[j]]++;
			temp /= Prime[j];
		}

	}

	//分解n!
	for (i = 2;i <= n;i++) {
		int temp = i;
		for (j = 0;j < len;j++) {
			while (temp%Prime[j] == 0) {
				cnt2[Prime[j]]++;
				temp /= Prime[j];
			}
		}
	}

	//求k
	int min = 123123;
	for (i = 0;i < 1010;i++) {
		if (cnt[i] > 0) {
			//printf("%d:%d %d:%d\n", i, cnt[i], i, cnt2[i]);
			if ((cnt2[i] / cnt2[i]) < min)
				min = cnt2[i] / cnt[i];
		}
	}
	printf("%d\n", min);
}


//这题的关键问题还在分解质因数上，n! 比起 ak的每个质因数的幂要大