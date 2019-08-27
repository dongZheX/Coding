#include<stdio.h>
#include<string.h>
#include<math.h>
long long Prime[10000000];
bool vis1[1000000] = { true };//普通筛法
bool vis2[1000000] = { true };//用于区间筛
bool vis3[1000000] = { true };//用于区间筛
bool vis4[1000000] = { true };//用于线性筛
void print(int);
//朴素求质数
void getPrime1(int n) {
	long long  i, j;
	for (i = 2;i <= n;i++) {
		bool flag = true;
		for (j = 2;j*j <= i&&flag;j++) {
			if (i%j == 0)
				flag = false;
		}
		if (flag)printf("%lld\n", i);
	}

}
//朴素素数筛法
int getPrime2(int n) {
	int i;
	int j;
	int len = 0;
	for (i = 0;i < 1000000;i++)vis1[i] = true;
	for (i = 2;i <= n;i++) {
		if (vis1[i]) {
			Prime[len++] = i;
			//这个i*i 真像sqrt，4*5 真像 5*4
			for (j = i*i;j <= n;j += i) {
				vis1[j] = false;
			}
		}
	}
	return len;
}
//线性筛法
int getPrime3(int n) {
	//基于欧拉线性筛法，原理我也不知道
	int i;
	int j;
	int len = 0;
	for (i = 0;i < 1000000;i++)vis2[i] = true;
	for (i = 2;i <= n;i++) {
		if (vis2[i])Prime[len++] = i;
		//4 * 2 之后,4 * 3就不要筛了，因为在（4/2）*3筛选得时候就会被筛 也是说Prime[i]在以后也会把他筛
		for (j = 0;j < len&&i*Prime[j]<=n;j++) {
			vis2[i*Prime[j]] = false;
			if (i%Prime[j] == 0)break;
		}
	}
	return len;
}

//区间筛法
int getPrime4(int a, int b) {
	int i;
	int j;
	int len = 0;
	for (i = 0;i < 1000000;i++)vis3[i] = true;
	for (i = 0;i < 1000000;i++)vis4[i] = true;
	//大于sqrt得数都不用再筛选了，因为前面筛选过，这也就是i*i起步得原因
	for (i = 2;i*i < b;i++) {
		if (vis3[i]) {
			for (j = i*i;j*j < b;j += i)vis3[j] = false; //用于筛出sqrt(b)内的质数
			for (j = fmax(2, (a + i - 1) / i)*i;j < b;j += i)vis4[j - a] = false;
			//着重解释 max（2，（a+i-1)
			/*
				最小是i的两倍不用解释
				a这个数肯定是出于i*k,在i*(k+1)之间的，我们要做的是求出(k+1)或者k ,仅当对于a=i*k时为k
				i*k <= a < i*(k+1)   单边界
				i(k+1)-1 <= a+i-1 < i(k+2)-1
				k+1-1/i <= (a+i-1)/i < k+2-1/i 仅当a = ki时，取得k+1-1/i（向下取整为k),对于其他情况 ki+n(1<=n<i)+i-1 取得k+1
				这个画图可能更明白
			*/
		}
	}
	for (i = a;i < b;i++) {
		if (vis4[i - a])Prime[len++] = i;
	}
	return len;
}
int main() {
	getPrime1(100);
	printf("\n");
	print(getPrime4(40,100));
}
void print(int len) {
	int i;
	for (i = 0; i < len; i++) {
		printf("%d ", Prime[i]);
		if ((i+1) % 10 == 0)printf("\n");
	}
}