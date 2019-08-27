#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#define INF 0x3f3f3f3f
int limit_region[101];
int map[111][111];
int n,limit;
int pr[111];
int level[11];
int dijkstra(){
	int d[101];
	int mark[101];
	int i,j;
	for(i=1;i<=n;i++){
		d[i] = i==1?0:INF;
		mark[i] = i==1?1:0;
	}
	int k = 1;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(limit_region[j]){
				d[j] = (d[j] > (d[k] + map[k][j])?(d[k] + map[k][j]):d[j]);
			}
		}
		int mm = INF;
		for(j=1;j<=n;j++){
			if(limit_region[j]&&mark[j]==0&&d[j]!=INF&&d[j]<mm){
				mm = d[j];
				k = j;
			}
		}
		mark[k] = 1;
	}
	int mini = INF;
	for(i=1;i<=n;i++){
		d[i] += pr[i];
		if(d[i]<mini){
			mini = d[i];
		}
	}
	return mini;
}
int main(){
	int i,j;
	scanf("%d%d",&limit,&n);
	for(i = 0; i <= n; i ++)
        for(j = 0; j <= n; j ++) 
            map[i][j] = (i == j ? 0 : INF);
	for(i=1;i<=n;i++){
		int t;
		scanf("%d%d%d",&pr[i],&level[i],&t);
		for(j=1;j<=t;j++){
			int te,val;
			scanf("%d%d",&te,&val);
			map[i][te] = val;
		}
	}
	int kl = level[1];
	int min = INF; 
	int cost;
	for(i=0;i<=limit;i++){
		memset(limit_region,0,sizeof(limit_region)); 
		for(j=1;j<=n;j++){
			if(level[j] <= kl+i&& level[j] >= kl-(limit-i))//加入寻路的允许等级 
				limit_region[j] = 1;
		}
		cost = dijkstra();
		if(cost<min)
			min = cost;	
	}
	printf("%d\n",min); 

}
