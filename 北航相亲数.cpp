#include<stdio.h>
//ÏàÇ×Êý 
int main(){
	int a,b;
	int i,j;
	int s1,s2;
	while(scanf("%d%d",&a,&b)!=EOF){
		s1 = s2 = 0;
		printf("%d,",a);
		int flag = 1;
		for(i=a-1;i>=1;i--){
			if(a%i==0){
				if(flag){
					printf("%d",i);
					flag = 0;
				}
				else {
					printf("+%d",i);
				}
				s1+=i;
			}
		} 
		printf("=%d\n",s1);
		flag = 1;
		printf("%d,",b);
		for(i=b-1;i>=1;i--){
			if(b%i==0){
				if(flag){
					printf("%d",i);
					flag = 0;
				}
				else {
					printf("+%d",i);
				}
				s2+=i;
			}
		} 
		printf("=%d\n",s2);
		if(s1==b&&a==s2){
			printf("1\n");
		}
		else{
			printf("0\n");
		}
	}
	 

}
