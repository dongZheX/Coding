#include<stdio.h>
#include<string.h>
int main(){
	int n;
	int m;
	int i,j;
	scanf("%d",&n);
	char str[100000];
	int mark[100000] = {0};
	int pk[25],wk[25];
	while(n--){
		for(i=0;i<100000;i++)mark[i] = 0;
		scanf("%d",&m);
		pk[0] = 0;
		for(i=0;i<m;i++){
			scanf("%d",&pk[i+1]);
		}
		j=0;
		int kk; 
		for(i=1;i<=m;i++){
			for(kk=0;kk<pk[i]-pk[i-1];kk++){
				str[j++] = '(';
			}
			str[j++] = ')';
		}
		str[j++] = '\0'; 
		int h = 0;
		for(i=0;str[i]!='\0';i++){
			int sum = 1;
			if(str[i] == ')'){
				for(j=i-1;j>=0;j--){
					if(str[j]=='('&&mark[j] == 0){
						wk[h++] = sum;
						mark[j] = 1;
						break;
					}
					else if(str[j]=='('&&mark[j] == 1){
						sum++;
					}
				}
			}
		}
		for(i=0;i<h-1;i++){
			printf("%d ",wk[i]);
		}
		printf("%d\n",wk[i]);
	}

} 
