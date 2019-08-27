#include<stdio.h>
#include<string.h>
using namespace std;
#define max 1000
//在java中已经支持大整数类，要看清楚机试编译器是否支持java，这里只是简单支持乘法
//本题是一种好的思想
typedef struct bigInteger {
	//低位对应低位
	int digit[max];
	int size;
	void init() {
		for (int i = 0;i < max;i++)
		{
			digit[i] = 0;
		}
		size = 0;
	}
	void set(char str[]) {
		init();
		int l = strlen(str);
		int i;
		int j;
		int store;
		for (i = l - 1;i >= 0;i -= 4) {
			store = 0;
			for (j = 3;j >= 0;j--) {
				if (i - j < 0)continue;
				store = store * 10 + (str[i - j] - '0');
			}
			digit[size++] = store;
		}
		
	}
	bigInteger operator + (const bigInteger& A)const {
		bigInteger res;
		res.init();
		int carry = 0;
		int len = A.size > size ? A.size : size;
		for (int i = 0;i < len;i++) {
			res.digit[res.size++] = (A.digit[i] + digit[i] + carry)%10000;
			carry = (A.digit[i] + digit[i] + carry) / 10000;
		}
		
		if (carry != 0) {
			res.digit[res.size++] = carry;
		}
		return res;
	}
	void output() {
		int i;
		for (i = size - 1;i >= 0;i--) {
			if (i == size - 1)printf("%d", digit[i]);
			else printf("%04d", digit[i]);
		}
		printf("\n");
	}
}BigInteger;
int main() {
	BigInteger a, b, c;
	char str1[1002], str2[1002];
	while (scanf("%s %s", str1, str2) != EOF) {
		a.set(str1);
		b.set(str2);
		c = a + b;
		c.output();
	}
	
}