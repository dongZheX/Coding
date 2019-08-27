#include<stdio.h>
#include<string.h>
int main() {
	int a;
	char Center, Out;
	char kuang[81][81];
	int n=1;
	while (scanf("%d %c %c", &a, &Center, &Out) != EOF) {
		getchar();
		char temp = Center;
		if (n != 1)
			printf("\n");
		memset(kuang, ' ', sizeof(char) * 81 * 81);
		if ((a + 1) / 2 % 2 != 0) {
			temp = Center;
			Center = Out;
			Out = temp;
		}
		for (int i = 0; i < (a-1)/2; i++) 
		{
			for (int j = i;j < a - i;j++) {
				if (i % 2 == 0)
				{
					kuang[i][j] = Out;
					kuang[a - i - 1][j] = Out;
					kuang[j][i] = Out;
					kuang[j][a - i - 1] = Out;
				}			
				else
				{
					kuang[i][j] = Center;
					kuang[a - i - 1][j] = Center;
					kuang[j][i] = Center;
					kuang[j][a - i - 1] = Center;
				}	
			}
		}
		if (a != 1 && a != 2) {
			kuang[0][0] = ' ';
			kuang[0][a - 1] = ' ';
			kuang[a - 1][0] = ' ';
			kuang[a - 1][a - 1] = ' ';
		}
		kuang[(a - 1) / 2][(a - 1) / 2] = temp;
		for (int i = 0;i < a;i++)
		{
			for (int j = 0;j < a;j++)
				printf("%c", kuang[i][j]);
			printf("\n");
		}
		n++;
	}
}