#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
typedef struct KKK{
	int start, end;
	bool operator < (const KKK &A)const{
	
		return start <A.start; 
	} 
}station;
int num[2][51000];
int k,n,c;
bool cmp(int a,int b){
	return a>b;
}
int work(station st[],int go_back){
	int i,j;
	int ca = c;
	vector<int> ape;
	int ct = 0;
	int res=0;
	int f;
	for(i=1;i<=n;i++){
		f = ca;
		for (j = 0;j < c-f;j++) {
			if(ape[j] == i){
				ape[j] = 0;
				ca++;
				res++;
			}
		}
		if(num[go_back][i]!=0){
			while(ca>0&&num[go_back][i]>0){
				ape.push_back(st[ct].end);
				ca--;
				num[go_back][i]--;
			}
			
			sort(ape.begin(),ape.end(),cmp);
			for(j=0;j<c-ca&&num[go_back][i]>0;j++){
				if(ape[j]>st[ct].end){
					ape[j] = st[ct].end;
					num[go_back][i]--;
				}
				else{
					break;
				}
			}
			ct++;
		}
	} 
	return res;
}
int main(){
	
	int i,j;
	station st1[51000],st2[51000];
	scanf("%d%d%d",&k,&n,&c);
	int t1=0,t2 = 0;
	
	for(i=0;i<2;i++){
		for(j=0;j<50009;j++)
			num[i][j] = 0;
	}
	for(i=1;i<=k;i++){
		int a,b,bb;
		scanf("%d%d%d",&a,&b,&bb);
		if(a<b){
			st1[t1].start = a;
			st1[t1++].end = b;
			num[0][a] += bb; 	
		}
		else{
			st2[t2].start = n - a + 1;
			st2[t2++].end = n - b + 1;
			num[1][n-a+1] = bb;
		}
		sort(st1,st1+t1);
		sort(st2,st2+t2); 
	}
	int ans = 0;
	ans += work(st1,0);
	ans += work(st2,1);
	printf("%d\n",ans);
}
//没 A 不做了