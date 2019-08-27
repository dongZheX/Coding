#include<stdio.h>
typedef struct s{
	int x,y;
}step;
int p,q;
int map[100][100];
step s[100];
int flag = 0;
int next[8][2] = {-2,-1,-2,1,-1,-2,-1,2,1,-2,1,2,2,-1,2,1};
int order = 1;
int judge(){
	for(int i = 1;i<=p;i++){
		for(int j = 1;j<=q;j++)
			if(map[i][j] == 0)
				return 0; 
	}
	return 1;
}
void dfs(int x,int y,int cur){
	if(flag)return;
	int i,j;

	if(judge()==1){
		flag = 1;
		printf("Scenario #%d:\n",order++);
		for(i=0;i<cur;i++){
			printf("%c%d",'A'+s[i].x-1,s[i].y);
		}
		printf("\n");
	}
	else{
		for(i=0;i<8;i++){
			int tx = x + next[i][0];
			int ty = y + next[i][1];
			if(tx<=0||tx>q||ty<=0||ty>p)continue;
			if(map[ty][tx] == 1)continue;
			s[cur].x = tx;
			s[cur].y = ty;
			map[ty][tx] = 1;
			dfs(tx,ty,cur+1);
			map[ty][tx] = 0;
		}
	}
}
int main(){
	int i,j;
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&p,&q);
		flag = 0;
		for(i=0;i<=p;i++){
			for(j=0;j<=q;j++)
				map[i][j] = 0;
		} 
		for(i=1;i<=q&&flag==0;i++){
			for(j=1;j<=p&&flag==0;j++){
				s[0].x = i;
				s[0].y = j;
				map[j][i] = 1;
				dfs(i,j,1);
				map[j][i] = 0;
			}
		} 
		if(flag==0)printf("Scenario #%d:\nimpossible\n",order++);
		if(n!=0)putchar('\n');
	}
}


