#include<stack>
#include<stdio.h>
using namespace std;
int main() {
	long long a, b,k;
	stack<int> s;
	while (scanf("%d", &k) != EOF&&k != 0) {
		scanf("%lld%lld", &a, &b);
		long long  res = a + b;
		while (res > 0) {
			s.push(res%k);
			res /= k;
		}
		if (s.empty()) {
			printf("0\n");
			continue;
		}
		while (!s.empty()) {
			printf("%lld", s.top());
			s.pop();
		}
		printf("\n");
	}

}