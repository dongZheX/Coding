#include<stdio.h>
int main() {
	int n;
	long long a, b, c, k;
	scanf("%d", &n);
	while (n--) {
		scanf("%lld%lld%lld%lld", &a, &b, &c, &k);
		if (a + c == 2 * b) {
			long long d = b - a;
			a = ((a % 200907) + (((k - 1) % 200907)*(d % 200907))%200907)% 200907;
			printf("%lld\n", a);
		}
		else {
			long long  q = (b / a) % 200907;;
			long long res = 1;
			//res = a * q^(k-1)
			long long b = k - 1;
			while (b != 0) {
				if(b%2==1){
					res *= q;
					res %= 200907;
				}
				q *= q;
				b /= 2;
				q = q % 200907;
			}
			res = (res%200907 * a%200907)%200907;
			printf("%lld\n", res);
		}
	}
}