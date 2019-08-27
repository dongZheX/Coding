#include<stdio.h>
int main(){
	long long n,m;
	int k,i,j,h,flag;
	while(scanf("%lld",&n)!=EOF){
		k = n;
		m = 0;
		h = 0;
		flag = 1;
		while(k!=0){
			m = k % 10 + m * 10;
			if(k%10==0&&flag==1){
				h++;
			}
			else if(k%10!=0&&flag==1){
				flag = 0;
			}
			k /= 10;

		}
		if(m%n==0){
			printf("%lld*%lld=%lld\n",n,m/n,m);
		}
		else{
		
			printf("%lld ",n);
			for(i=0;i<h;i++){
				printf("0");
			}
			printf("%lld\n",m);
		}
	}
} 
