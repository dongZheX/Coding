#include<stdio.h>
long long Fn[22];
int main() {
	Fn[1] = 0;
	Fn[2] = 1;
	for (int i = 3;i < 22;i++) {
		Fn[i] = (i - 1)*Fn[i - 1] + (i - 1)*Fn[i - 2];
		/*
			第一步：将第n封信放入k，有n-1种方法
			第二步：
			①将k放入n，则剩下的n-2有F(n-2)中方法
			②k不放入n，（k相当于n不能放入n处），则有D(n-1)种
		*/
	}
	int n;
	while (scanf("%d", &n) != EOF) {
		printf("%lld\n",Fn[n]);
	}
}