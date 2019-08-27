#include <stdio.h>
#include <string.h>
#define maxDigits 100
struct bigInteger { // 高精度整数结构体
	int digit[maxDigits];
	int size;
	void init() {
		// 初始化
		for (int i = 0; i < maxDigits; i++) digit[i] = 0;
		size = 0;
	}
	void set(int x) {
		// 用一个普通整数初始化高精度整数
		init();
		do {
			digit[size++] = x % 10000;
			x /= 10000;
		} while (x != 0);
	}
	void output() {
		// 输出
		for (int i = size - 1; i >= 0; i--) {
			if (i != size - 1) printf(" %04d", digit[i]);
			else if (" %d", digit[i]);
		}
		printf("\n");
	}
	bigInteger operator *(int x) const {
		//大整数乘法怎么做
		// 高精度整数与普通整数的乘积
		bigInteger ret;
		ret.init();
		int carry = 0;
		for (int i = 0; i < size; i++) {
			int tmp = x * digit[i] + carry;
			carry = tmp / 10000;
			tmp %= 10000;
			ret.digit[ret.size++] = tmp;
		}
		if (carry != 0) {
			ret.digit[ret.size++] = carry;
		}
		return ret;
	}
	bigInteger operator +(const bigInteger &A) const {
		// 高精度整数之间的加
		//算  法运
		bigInteger ret;
		ret.init();
		int carry = 0;
		for (int i = 0; i < A.size || i < size; i++) {
			int tmp = A.digit[i] + digit[i] + carry;
			carry = tmp / 10000;
			tmp %= 10000;
			ret.digit[ret.size++] = tmp;
		}
		if (carry != 0) {
			ret.digit[ret.size++] = carry;
		}
		return ret;
	}
	bigInteger operator / (int x) const {
		// 高精度整数除以普通整数
		bigInteger ret; // 返回的高精度整数
		ret.init(); // 返回值初始化
		int remainder = 0; // 余数  t
		for (int i = size - 1; i >= 0; i--) {
			// 从最高位至最低位依次完成计算
			int t = (remainder * 10000 + digit[i]) / x; // 计算当前位数值加上
			//高位剩余的余数的和对x求得的商
			int r = (remainder * 10000 + digit[i]) % x; // 计算当前位数值加上
			//高位剩余的余数的和对x求模后得的余数
			ret.digit[i] = t; // 保存本位的值
			remainder = r; // 保存至本位为止的余数
		}
		ret.size = 0; // 返回高精度整数的size 初始值为0, 即当所有位数字都为0
			//时, digit[0] 字0  代表数字0, 作为最高有效位, 高精度整数即为数
		for (int i = 0; i < maxDigits; i++) {
			if (digit[i] != 0) ret.size = i;
		} // 若存在非0位, 确定最高的非0位, 作为最高有效位
		ret.size++; // 最高有效位的下一位即为下一个我们不曾使用的digit 数组单元, 确定为size的值
		return ret; // 返回
	}
	int operator % (int x) const {
		// 高精度整数 t 对普通整数求余数
		int remaintder = 0; // 余数  t
		for (int i = size - 1; i >= 0; i--) {
			int t = (remaintder * 10000 + digit[i]) / x;
			int r = (remaintder * 10000 + digit[i]) % x;
			remaintder = r;
		} // 过程同高精度整数对普通整数求商
		return remaintder; // 返回余数
	}
} a, b, c;
char str[10000];
char ans[10000];
int main() {
	int n, m, t;
	while (scanf(" %d%d", &m, &n) != EOF) {
		scanf(" %s", str); // 输入m进制数
		int L = strlen(str);
		a.set(0); // a初始值为0, 用来保存转换成10进制的m进制数
		b.set(1); // b初始值为1, 在m进制向10进制转换的过程中, 依次代表每一位的权重
		for (int i = L - 1; i >= 0; i--) {
			// 由低位至高位转换m进制数至相应的10进制数
			int t;
			if (str[i] >= ' 0' && str[i] <= ' 9') {
				t = str[i] - ' 0';
			}
			else {
				t = str[i] - ' A' + 10; // 确定当前位字符代表的数字
				a = a + b * t; // 累加当前数字乘当前位权重的积
				b = b * m; // 计算下一位权重
			}
		}
		int size = 0; // 代表转换为n进制 t 后的字符个数
		do {
			// 对转换后的10进制数求其n进制值
			int t = a % n; // 求余数
			if (t >= 10) ans[size++] = t - 10 + ' a';
			else ans[size++] = t + ' 0'; // 确定当前位字符
			a = a / n; // 求商
		} while (a.digit[0] != 0 || a.size != 1); // 当a不为0时重复该过程
		for (int i = size - 1; i >= 0; i--)
			printf(" %c", ans[i]);
		printf("\n"); // 输出


	}
	return 0;
}