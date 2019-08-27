#include<stdio.h>
#include<string.h>
int s2n(char str[],int s,int e){
	int i = s;
	int res = 0;
	for(i=s;i<e;i++){
		res = res*10 + (str[s]-'0');
	}
	return res;
} 
int main(){
	char str[1001];
	int num[101] = {-1};//枚举变量的值
	int tms = 0;//枚举变量个数
	int i,j,k,h;//临时变量
	char res[100][100];//存储
	while(gets(str)!=NULL){
		tms = 0;
		for(i=0;i<101;i++)num[i] = -1;
		int len = strlen(str);
		for(i=0;i<len;i++){
			if(str[i] == '{')break;
		}
		for(j=0;j<len;j++){
			if(str[j] == '}')len = j+1;
		}
		//找到分割区间
		str[len-1] = ','; 
		k = i;
		for(;i<len;i++){
			//处理等好
			if(str[i]=='='){
				for(j=i;j<len;j++){
					if(str[j]==',')break;
				}
				num[tms] = s2n(str,i+1,j);
				//转化为数字
				h = j;
				for(j=k+1;j<i;j++){
					res[tms][j-k-1] = str[j];
				}
				res[tms][j-k-1] = '\0';
				tms++;
				i = h;
				k = h;
				//更新遍历位置
				continue;
			}
			if(str[i] == ','){
				for(j=k+1;j<i;j++){
					res[tms][j-k-1] = str[j];
				}
				res[tms][j - k - 1] = '\0';
				tms++;
				k = i;
			}
		}
		if(num[0]==-1){
			num[0] = 0;
		} 
		//枚举变量数值更新
		for(i=0;i<tms;){
			if(num[i]!=-1){
				for(j=i+1;j<tms;j++){
					if(num[j]!=-1){
						break;
					}
					else{	
						num[j] = num[j-1] + 1;
					}
				}
				i=j;
			}	
		} 
		for(i=0;i<tms;i++){
			printf("%s ",res[i]);
			printf("%d\n",num[i]); 
		}
	}	
}
