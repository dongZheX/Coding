#include<stdio.h>
int main() {
	int h;
	int low, high;
	scanf("%d", &h);
	high = h;
	low = high + (h - 1) * 2;
	for (int i = 1; i <= h;i++) {
		for (int j = 1;j <= low;j++) {
			if (j <= low - (high + (i - 1) * 2))
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}

}