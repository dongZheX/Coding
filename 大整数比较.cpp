#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
typedef struct bigInteger {
	int digit[1000];
	int size;
	void init()
	{
		for (int i = 0; i < 1000; i++) { digit[i] = 0; }
		size = 0;
	}
	void set(char str[]) {
		init();
		int L = strlen(str);
		for (int i = L - 1; i >= 0; i-=4) {
			int store=0;
			for (int j = 3; j >= 0; j--) {
				if (i - j < 0)continue;
				else store = store * 10 + (str[i-j] - '0');
			}
			digit[size++] = store;
		}
	}
	bool operator < (const  bigInteger &A)const {
		int res = true;
		if (A.size != size) {
			return size < A.size;
		}
		else {
			for (int i = size-1;i >=0;i--) {
				if (A.digit[i] != digit[i])
				{
					return digit[i] < A.digit[i];
				}
			}
		}
	}
	void output() {
		for (int i = size - 1;i >= 0;i--) {
			if (i == size - 1)printf("%d", digit[size - 1]);
			else printf("%04d", digit[i]);
		}
		printf("\n");
	}
}BigInteger;
int main() {
	BigInteger nums[101];
	int  n;
	char str[1010];
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		nums[i].set(str);
	}
	sort(nums, nums + n);
	for (int i = 0; i < n; i++) {
		nums[i].output();
	}
}