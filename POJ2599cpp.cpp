#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int a[26] = { 0 };
	int b[26] = { 0 };
	char str1[101], str2[101];
	scanf("%s", str1);
	scanf("%s", str2);
	int len = strlen(str1);
	for (int i = 0;i < len;i++) {
		a[str1[i] - 'A'] += 1;
		b[str2[i] - 'A'] += 1;
	}
	sort(a, a + 26, cmp);
	sort(b, b + 26, cmp);
	for (int i = 0;i < 26;i++) {
		if (a[i] != b[i]) {
			printf("NO\n");
			return 0;
		}
			
	}
	printf("YES\n");
}