#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
int pw(int a, int b) {
	int res = 1;
	for (int i = 1;i <= b;i++) {
		res = res * a;
	}
	return res;
}
int main() {
	int len;
	int k,  k2;
	char a[1000];

	scanf("%d %s%d", &k, &a, &k2);
	int temp = 0;
	len = strlen(a);
	for (int i = 0;a[i] != '\0';i++) {
		if (a[i] <= '9'&&a[i] >= '0') {
			temp += (a[i] - '0') * pw(k, len - i - 1);
		}
		else if (a[i] <= 'z' && a[i] >= 'a') {
			temp += (a[i] - 'a' + 10 ) * pw(k, len - i - 1);
		}
		else if (a[i] <= 'Z' && a[i] >= 'A') {
			temp += (a[i] - 'A' + 10) * pw(k, len - i - 1);
		}
	}
	int res;
	stack<char> s;
	while (temp != 0) {
		int t = temp % k2;
		if (t >= 10) {
			s.push((t - 10)+'A');
		}
		else
			s.push(t+'0');
		temp /= k2;
	}
	while (!s.empty()) {
		printf("%c", s.top());
		s.pop();
	}
	printf("\n");
}
