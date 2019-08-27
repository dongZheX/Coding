#include<stdio.h>
#define N 60
#include<math.h>
int main(){
	int sum = 1;
	int i;
	int j;
	int wan[60];
	int len1=0;
	int ying[60];
	int len2=0;
	for(i=2;i<=N;i++){
		sum = 1;
		for(j=2;j<=sqrt(i);j++){
			if(i%j==0){
				if(j!=i/j){
					sum = sum + j + i / j;
				}
				else
					sum += j;
			}
			
		}
		if(sum==i)wan[len1++] = i;
			else if(sum>i)ying[len2++] = i; 
	}
	printf("E:");
	for(i=0;i<len1;i++){
		printf(" %d",wan[i]);
	}
	putchar('\n');
	printf("G:");
	for(i=0;i<len2;i++){
		printf(" %d",ying[i]);
	}
	putchar('\n');
} 
