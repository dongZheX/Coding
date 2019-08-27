#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int main() {
	float t = 200, d=200;
	char c;
	float h=200;
	while (1) {
		h = t = d = 200;
		for (int i = 0;i < 2;i++) {
			cin >> c;
			if (c == 'E')
				return 0;
			else if (c == 'T') {
				scanf("%f", &t);
			}
			else if (c == 'H') {
				scanf("%f", &h);
			}
			else if (c == 'D') {
				scanf("%f", &d);
			}
		
		}
		if (h == 200) {
			h = t + 0.5555*((6.11*exp(5417.7530 * (1 / 273.16 - 1 / (d + 273.16))))-10);
		}
		else if (t == 200) {
			t = h - 0.5555*((6.11*exp(5417.7530 * (1 / 273.16 - 1 / (d + 273.16)))) - 10);
		}
		else if (d == 200) {
			d = 1 / ((1 / 273.16) - ((log((((h - t) / 0.5555) + 10.0) / 6.11)) / 5417.7530)) - 273.16;
		}
		printf("T %.1f D %.1f H %.1f\n", t, d, h);
	}
}