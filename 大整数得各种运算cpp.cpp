#include <stdio.h>
#include <string.h>
#define maxDigits 100
struct bigInteger { // �߾��������ṹ��
	int digit[maxDigits];
	int size;
	void init() {
		// ��ʼ��
		for (int i = 0; i < maxDigits; i++) digit[i] = 0;
		size = 0;
	}
	void set(int x) {
		// ��һ����ͨ������ʼ���߾�������
		init();
		do {
			digit[size++] = x % 10000;
			x /= 10000;
		} while (x != 0);
	}
	void output() {
		// ���
		for (int i = size - 1; i >= 0; i--) {
			if (i != size - 1) printf(" %04d", digit[i]);
			else if (" %d", digit[i]);
		}
		printf("\n");
	}
	bigInteger operator *(int x) const {
		//�������˷���ô��
		// �߾�����������ͨ�����ĳ˻�
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
		// �߾�������֮��ļ�
		//��  ����
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
		// �߾�������������ͨ����
		bigInteger ret; // ���صĸ߾�������
		ret.init(); // ����ֵ��ʼ��
		int remainder = 0; // ����  t
		for (int i = size - 1; i >= 0; i--) {
			// �����λ�����λ������ɼ���
			int t = (remainder * 10000 + digit[i]) / x; // ���㵱ǰλ��ֵ����
			//��λʣ��������ĺͶ�x��õ���
			int r = (remainder * 10000 + digit[i]) % x; // ���㵱ǰλ��ֵ����
			//��λʣ��������ĺͶ�x��ģ��õ�����
			ret.digit[i] = t; // ���汾λ��ֵ
			remainder = r; // ��������λΪֹ������
		}
		ret.size = 0; // ���ظ߾���������size ��ʼֵΪ0, ��������λ���ֶ�Ϊ0
			//ʱ, digit[0] ��0  ��������0, ��Ϊ�����Чλ, �߾���������Ϊ��
		for (int i = 0; i < maxDigits; i++) {
			if (digit[i] != 0) ret.size = i;
		} // �����ڷ�0λ, ȷ����ߵķ�0λ, ��Ϊ�����Чλ
		ret.size++; // �����Чλ����һλ��Ϊ��һ�����ǲ���ʹ�õ�digit ���鵥Ԫ, ȷ��Ϊsize��ֵ
		return ret; // ����
	}
	int operator % (int x) const {
		// �߾������� t ����ͨ����������
		int remaintder = 0; // ����  t
		for (int i = size - 1; i >= 0; i--) {
			int t = (remaintder * 10000 + digit[i]) / x;
			int r = (remaintder * 10000 + digit[i]) % x;
			remaintder = r;
		} // ����ͬ�߾�����������ͨ��������
		return remaintder; // ��������
	}
} a, b, c;
char str[10000];
char ans[10000];
int main() {
	int n, m, t;
	while (scanf(" %d%d", &m, &n) != EOF) {
		scanf(" %s", str); // ����m������
		int L = strlen(str);
		a.set(0); // a��ʼֵΪ0, ��������ת����10���Ƶ�m������
		b.set(1); // b��ʼֵΪ1, ��m������10����ת���Ĺ�����, ���δ���ÿһλ��Ȩ��
		for (int i = L - 1; i >= 0; i--) {
			// �ɵ�λ����λת��m����������Ӧ��10������
			int t;
			if (str[i] >= ' 0' && str[i] <= ' 9') {
				t = str[i] - ' 0';
			}
			else {
				t = str[i] - ' A' + 10; // ȷ����ǰλ�ַ����������
				a = a + b * t; // �ۼӵ�ǰ���ֳ˵�ǰλȨ�صĻ�
				b = b * m; // ������һλȨ��
			}
		}
		int size = 0; // ����ת��Ϊn���� t ����ַ�����
		do {
			// ��ת�����10����������n����ֵ
			int t = a % n; // ������
			if (t >= 10) ans[size++] = t - 10 + ' a';
			else ans[size++] = t + ' 0'; // ȷ����ǰλ�ַ�
			a = a / n; // ����
		} while (a.digit[0] != 0 || a.size != 1); // ��a��Ϊ0ʱ�ظ��ù���
		for (int i = size - 1; i >= 0; i--)
			printf(" %c", ans[i]);
		printf("\n"); // ���


	}
	return 0;
}