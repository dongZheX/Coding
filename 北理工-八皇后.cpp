#include<stdio.h>
#include<math.h> 
#include<algorithm>
using namespace std;
long long store[100];
int len = 0;
int num[9] = { 0,3,6,4,2,5,8,5,7 };
int check(int x, int y, int cur){
	int i;
	for(i=1;i<cur;i++){
		if(num[i] == y)return 0;
		if(abs(y-num[i])/(abs(x-i)*1.0) == 1) return 0;  //精度问题啊 大大大大哥
	}
	return 1;
}
void dfs(int x, int y,int cur){
	int i;
	if(cur == 8){
		int sum = 0;
		for(i=1;i<=8;i++){
			sum = sum * 10 + num[i];
		}
		store[len++] = sum;
	}
	else{
		for(i=1;i<=8;i++){
			if (check(cur + 1, i, cur + 1) == 1) {
				num[cur + 1] = i;
				dfs(cur + 1, i, cur + 1);
			}
			
		}
	}
}

int main(){
	int i = 1;
	int b;
	for(i=1;i<=8;i++){
		num[1] = i;
		dfs(1,i,1);
	}
	sort(store,store+len);
	scanf("%d",&b);
	printf("%lld\n",store[b-1]);

}
