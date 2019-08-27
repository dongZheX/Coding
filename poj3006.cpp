#include<stdio.h>
int prime[1000000] = {0};
	int num[1000000] = {0};
int main(){
	
	int len = 0;
	int a,d,n;
	int i,j;
	num[1] = num[0] = 1;
	for(i= 2;i<1000000;i++){
		if(num[i]==0)prime[len++] = i;
		for(j=0;j<len&&i*prime[j]<=1000000;j++){
			num[prime[j]*i] = 1;
			if(i%prime[j]==0)break;
		}
	}
	while(scanf("%d%d%d",&a,&d,&n)&&(a!=0||d!=0||n!=0)){
		int t = 0;
		for(i=0;;i++){
			int tmp = a + i*d;
			if(num[tmp]==0)t++;
			if(t==n){
				printf("%d\n",tmp);
				break;
			}
				
		}
	} 
}
