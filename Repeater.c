#include<stdio.h>
#include<string.h>
int N;
char pre[3000][3000];
char now[3000][3000];
char tem[6][6];
int H;
void printNow();
int main() {
	int i, j;
	int size;
	while (scanf("%d", &N) && N != 0) {
		getchar();
		memset(now, '\0', sizeof(char) * 3000 * 3000);
		for (i = 0;i < N;i++) {
			gets(tem[i]);
			strcpy(pre[i], tem[i]);
			strcpy(now[i], tem[i]);
		}		
		scanf("%d", &H);
		while (H != 1) {
			printNow();
			H--;
		}
		int size = strlen(now[0]);
		for (i = 0;i < size;i++) {
			printf("%s\n", now[i]);
		}
	}

}
void printNow() {
	int i, j;
	int size;
	int h, k;
	for (i = 0;i < N;i++) {
		for (j = 0; j < N;j++) {
			if (tem[i][j] == ' ')
			{
				int size = strlen(pre[0]);
				for (int k = 0;k < size;k++) {
					for (int h = 0;h < size;h++) {
						now[i*size + k][j*size + h] = ' ';
					}
				}				
			}
			else {
				size = strlen(pre[0]);
				for (k = 0;k < size;k++) {
					for (h = 0;h < size;h++) {
						now[i*size + k][j*size + h] = pre[k][h];
					}
				}
			}
		}
	}
	size = strlen(now[0]);
	for (int k = 0;k < size;k++) {
		strcpy(pre[k], now[k]);
	}
}
