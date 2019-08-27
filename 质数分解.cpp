#include<stdio.h>
bool visit[100000];
long long Prime[100000];
int getPrime(int n) {
	int len = 0;
	int i;
	int j;
	for (i = 0;i < 100000;i++)visit[i] = true;
	for (i = 2; i < n; i++) {
		if (visit[i])Prime[len++] = i;
		for (j = 0; j < len && Prime[j] * i < n;j++) {
			visit[i*Prime[j]] = false;
			if (i%Prime[j]==0)break;
		}
	}
	return len;
}
int main() {
	long long n;
	int len = getPrime(100000);
	int i;
	int j;
	int res;
	while (scanf("%lld", &n) != EOF) {
		res = 0;
		for (i = 0;i < len && n!=1;i++) {
			while(n%Prime[i]==0){
				res++;
				n /= Prime[i];
			}
		}
		if (n != 1) {
			res++;
		}
		printf("%d\n", res);
	}
	
}