#include<stdio.h>
#include<string.h>
int main(){
	char str[256];
	while(gets(str)&&strcmp(str,"#")!=0){
		int sum = 0;
		int len = strlen(str);
		for(int i = 0;i<len;i++){
			if(str[i]!=' '){
				sum+=(i+1)*(str[i]-'A'+1);
			} 
		}
		printf("%d\n",sum);
	
	}
	
}
