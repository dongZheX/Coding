#include<stdio.h>
int main() {
	int num;
	int num2;
	while (scanf("%d", &num) != EOF) {
		num2 = num * num;
		int temp = 1;
		while (num2/temp != 0) {
			temp *= 10;
		}
		temp /= 10;
		if (num2%temp == num) {
			printf("Yes!\n");
		}
		else {
			printf("No!\n");
		}
	}
}