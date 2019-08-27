#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int main() {
	string input;
	while (cin >> input) {
		int size = input.size();
		int i;
		int res = 0;
		for (i = 1;i <= size;i++) {
			if (input == input.substr(i, size).append(input.substr(0, i))) {
				res++;
			}
		}
		cout << res << endl;
	}

}