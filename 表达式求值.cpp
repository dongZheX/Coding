#include<stack>
#include<stdio.h>
#include<string.h>
using namespace std;
/*
	����˵һ���㷨
	���������ּ�������ջ
	����������� ��������ȼ��������ջ��������ȼ��߻���ջΪ�� �ͼ��������ջ
	             ����ͣ��򵯳��������������֣�������������ٽ����������ջ���ظ��ж�
	����������������Ǹ����ȼ�������Ļ������ܻ���ִ������ǿ��Դ�ջ���������㣨��֤�����ȼ����ޣ�������-���ţ�
*/
int getPriority(char op) {
	if (op == '-' || op == '+') {
		return 0;
	}
	else
	{
		return 1;
	}
}
double doop(char c, double a, double b) {
	switch (c)
	{
		case '+':return a + b;break;
		case '-':return a - b;break;
		case '*':return a * b;break;
		case '/':return a/ b;break;
		default:
			break;
	}
}
int main() {
	char str[1000];
	stack<char> op;
	stack<double> num;
	while (scanf("%s", &str) != EOF) 
	{
		for (int i = 0; str[i] != '\0'; i++)
		{
			int res = 0;
			bool isnum = false;
			while (str[i] <= '9'&&str[i] >= '0')
			{
				isnum = true;
				res = res * 10 + (str[i] - '0');
				i++;
			}
			if (isnum) {
				num.push(res);
				i--;
				continue;
			}
			
			if (op.empty() || getPriority(op.top()) <= getPriority(str[i])) {
				op.push(str[i]);
				continue;
			}
			while(op.empty()==false&&( getPriority(op.top()) > getPriority(str[i]))) {
				char o = op.top();
				op . pop();
				double t1 = num.top();
				num.pop();
				double t2 = num.top();
				num.pop();
				num.push(doop(o, t2, t1));
			}
			op.push(str[i]);

		}
		while (!op.empty()) {
			char o = op.top();
			op.pop();
			double t1 = num.top();
			num.pop();
			double t2 = num.top();
			num.pop();
			if(getPriority(o)==1||op.empty())
				num.push(doop(o, t2, t1));
			else {
				if (op.top() == '-') {
					num.push(doop('-' + '+' - o, t2, t1));
				}
				else {
					num.push(doop(o, t2, t1));
				}
			}
		}
		printf("%.2f\n", num.top());
		num.pop();
	}
}