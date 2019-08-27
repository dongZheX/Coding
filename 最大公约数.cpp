#include<cstdio>
int main() {
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF) {
		if (a == b){
			printf("%d\n", a);continue;
		}
		while (a > b&&a%b != 0 || a < b&&b%a != 0) {
			if (a > b)a = a % b;
			else if (a < b)b = b % a;
		}
		printf("%d\n", a < b ? a : b);
	}
}

//¹ØÓÚµÝ¹é
int gcd(int a, int b) {
	if (b == 0)return a;
	else return gcd(b, a%b);
}