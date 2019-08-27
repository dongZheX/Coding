#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
int main() {
	stack<int> recoder;
	char str[101];
	char temp[101];
	while (scanf("%s", str) != EOF)
	{
		printf("%s\n", str);
		strcpy(temp, str);
		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] == '(') {
				recoder.push(i);
				temp[i] = '&';
			}
			else if (str[i] == ')') {
				if (recoder.empty()) {
					temp[i] = '?';
				}
				else {
					temp[recoder.top()] = ' ';
					recoder.pop();
					temp[i] = ' ';
				}
			}
			else {
				temp[i] = ' ';
			}
		}
		printf("%s\n", temp);
	}
}
//input:  )(rttyy())sss)(
//output: ?            ?&  