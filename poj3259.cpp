#include<stdio.h>
#include<string.h>
int v[5210];
int u[5210];
int w[5210];
int bellman_ford(int cnt,int n){
	int i,j;
	int d[521];
	for(i=2;i<=521;i++)
		d[i] = 0xffffffff; //这个最大值也能错 晕
		 
	d[1] = 0;
	for(i=1;i<n;i++){
		for(j=0;j<cnt;j++){
			if(d[u[j]]>d[v[j]]+w[j]){
				d[u[j]] = d[v[j]]+w[j];
			}
		}
	}
	for(j=0;j<cnt;j++){
		if(d[u[j]]>d[v[j]]+w[j]){
			return 1;
		}
	}
	return 0;
}
int main(){
	int i,j;
	int t;
	int n,m,k;
	scanf("%d",&t);
	while(t--){
		memset(v,0,sizeof(v));
		memset(u,0,sizeof(u));
		memset(w,0,sizeof(w));
		scanf("%d%d%d",&n,&m,&k);
		int cnt = 0;
		for(i=1;i<=m;i++){
			int t1,t2,t3;
			scanf("%d%d%d",&t1,&t2,&t3);
			v[cnt] = t1;
			u[cnt] = t2;
			w[cnt++] = t3;
			v[cnt] = t2;
			u[cnt] = t1;  
			w[cnt++] = t3;
		}
		for(i=1;i<=k;i++){
			int t1,t2,t3;
			scanf("%d%d%d",&t1,&t2,&t3);
			v[cnt] = t1;
			u[cnt] = t2;
			w[cnt++] = -t3;
		}
		int flag = bellman_ford(cnt,n);
		if(flag){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
		
	}
	return 0;

} 
