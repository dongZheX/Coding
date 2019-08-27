#include<stdio.h>
int num[1000001] = {0};
int prime[1000000];
int len = 0;
int main(){
	int i,j;
	int in;
	prime[1] = prime[0] = 1;
	for(i=2;i<=1000000;i++){
		if(num[i]==0){prime[len++]=i;}
		for(j=0;j<len&&prime[j]*i<=1000000;j++){
			num[prime[j]*i] = 1;
			if(i%prime[j]==0)break;
		}
	}
	while(scanf("%d",&in)&&in!=0){
		for(i = 0;i<len&&in>prime[i];i++){
			if(num[in-prime[i]]==0){
				printf("%d = %d + %d\n",in,prime[i],in-prime[i]);
				break;
			}
		}
	}
}
