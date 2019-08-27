#include<stdio.h>
#include<string.h>
#include<math.h>
long long Prime[10000000];
bool vis1[1000000] = { true };//��ͨɸ��
bool vis2[1000000] = { true };//��������ɸ
bool vis3[1000000] = { true };//��������ɸ
bool vis4[1000000] = { true };//��������ɸ
void print(int);
//����������
void getPrime1(int n) {
	long long  i, j;
	for (i = 2;i <= n;i++) {
		bool flag = true;
		for (j = 2;j*j <= i&&flag;j++) {
			if (i%j == 0)
				flag = false;
		}
		if (flag)printf("%lld\n", i);
	}

}
//��������ɸ��
int getPrime2(int n) {
	int i;
	int j;
	int len = 0;
	for (i = 0;i < 1000000;i++)vis1[i] = true;
	for (i = 2;i <= n;i++) {
		if (vis1[i]) {
			Prime[len++] = i;
			//���i*i ����sqrt��4*5 ���� 5*4
			for (j = i*i;j <= n;j += i) {
				vis1[j] = false;
			}
		}
	}
	return len;
}
//����ɸ��
int getPrime3(int n) {
	//����ŷ������ɸ����ԭ����Ҳ��֪��
	int i;
	int j;
	int len = 0;
	for (i = 0;i < 1000000;i++)vis2[i] = true;
	for (i = 2;i <= n;i++) {
		if (vis2[i])Prime[len++] = i;
		//4 * 2 ֮��,4 * 3�Ͳ�Ҫɸ�ˣ���Ϊ�ڣ�4/2��*3ɸѡ��ʱ��ͻᱻɸ Ҳ��˵Prime[i]���Ժ�Ҳ�����ɸ
		for (j = 0;j < len&&i*Prime[j]<=n;j++) {
			vis2[i*Prime[j]] = false;
			if (i%Prime[j] == 0)break;
		}
	}
	return len;
}

//����ɸ��
int getPrime4(int a, int b) {
	int i;
	int j;
	int len = 0;
	for (i = 0;i < 1000000;i++)vis3[i] = true;
	for (i = 0;i < 1000000;i++)vis4[i] = true;
	//����sqrt������������ɸѡ�ˣ���Ϊǰ��ɸѡ������Ҳ����i*i�𲽵�ԭ��
	for (i = 2;i*i < b;i++) {
		if (vis3[i]) {
			for (j = i*i;j*j < b;j += i)vis3[j] = false; //����ɸ��sqrt(b)�ڵ�����
			for (j = fmax(2, (a + i - 1) / i)*i;j < b;j += i)vis4[j - a] = false;
			//���ؽ��� max��2����a+i-1)
			/*
				��С��i���������ý���
				a������϶��ǳ���i*k,��i*(k+1)֮��ģ�����Ҫ���������(k+1)����k ,��������a=i*kʱΪk
				i*k <= a < i*(k+1)   ���߽�
				i(k+1)-1 <= a+i-1 < i(k+2)-1
				k+1-1/i <= (a+i-1)/i < k+2-1/i ����a = kiʱ��ȡ��k+1-1/i������ȡ��Ϊk),����������� ki+n(1<=n<i)+i-1 ȡ��k+1
				�����ͼ���ܸ�����
			*/
		}
	}
	for (i = a;i < b;i++) {
		if (vis4[i - a])Prime[len++] = i;
	}
	return len;
}
int main() {
	getPrime1(100);
	printf("\n");
	print(getPrime4(40,100));
}
void print(int len) {
	int i;
	for (i = 0; i < len; i++) {
		printf("%d ", Prime[i]);
		if ((i+1) % 10 == 0)printf("\n");
	}
}