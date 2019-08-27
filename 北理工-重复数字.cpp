#include<stdio.h>
#include<map>
#include<iostream>
#include<string>
using namespace std;
int main() {
	map<string, int> m;
	int i;
	int j;
	string input;
	while (cin >> input) {
		m.clear();
		int len = 0;
		int temp = 0;
		input.append(",");
		string res = "-1";
		for (i = 0;i < input.size();i++) {
			if (input.at(i) == ',') {
				string t = input.substr(temp, i-temp);
				if (m.find(t) != m.end()) {
					m[t]++;
					res = t;
				}
				else
					m[t] = 1;
				temp = i + 1;
			}
		}
		cout << res << endl;
	}
}