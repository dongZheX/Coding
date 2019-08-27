#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
typedef struct BigInteger{
	int num[1000];
	int size;
	void set(char str[]){
		int len = strlen(str);
		for(int i = len-1;i>=0;i-=4){
			int c = 1;
			int sum = 0;
			for(int j=0;j<4&&(i-j)>=0;j++){
				sum = sum + (str[i-j]-'0')*c;
				c *= 10;
			}
			num[size++] = sum;
		}
	}
	void init(){
		size = 0;
		for(int i =0;i<1000;i++){
			num[i] = 0;
		}
	}
	BigInteger operator + (const BigInteger &A)const{
		int s1 = size;
		int s2 = A.size;
		int s =  s1>s2?s1:s2;
		int carry = 0;
		BigInteger res;
		res.init();
		for(int i = 0;i<s;i++){
			res.num[res.size++] = (num[i] + A.num[i] + carry)%10000;
			carry =  (num[i] + A.num[i] + carry)/10000;
		}
		if(carry!=0){
			res.num[res.size++] = carry;
		}
		return res;
	}
	void output(){
		for(int i =size-1;i>=0;i--){
			if(i==size-1)
				printf("%d",num[i]);
			else{
				printf("%04d",num[i]);
			}
		}
		printf("\n");
	}
} bt;
int main(){
	bt result;
	result.init();
	char str[101];
	while(scanf("%s",str)&&strcmp(str,"0")!=0){
		bt temp;
		temp.init();
		temp.set(str);
		result = result + temp;
	}
	result.output();
}
