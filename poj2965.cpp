//poj 2965
#include<stdio.h>
#include<string.h>
int map[4][4];
int ans = 999999;
int px[17];
int py[17];
int rx[17];
int ry[17];

int judge(){
	
	for(int i = 0;i<4;i++){
		for(int j = 0;j<4;j++){
			if(map[i][j]==0)
				return 0;
		}
	}
	return 1;
} 
void flip(int x, int y){
	int i;
	for(i=0;i<4;i++){
		map[x][i] = !map[x][i];
		map[i][y] = !map[i][y];
		
	}
	map[x][y] = !map[x][y]; 
}
void dfs(int x,int y, int t){
	if(judge()==1){
		
		if(t<ans){
			ans = t;
			for(int i = 0;i<t;i++){
				rx[i] = px[i];
				ry[i] = py[i];
			}
		}
	}
	if(x>=4)return;
	int nx,ny;
	nx = x + (y+1)/4;
	ny = (y+1)%4;
	dfs(nx,ny,t);
	flip(x,y);
	px[t] = x;
	py[t] = y;
	dfs(nx,ny,t+1);
	flip(x,y);
}
int main(){
	int i,j;
	for(i=0;i<4;i++){
		char str[5];
		gets(str);
		for(j=0;j<4;j++){
			if(str[j]=='+'){map[i][j] = 0;}
			else map[i][j] = 1;
		}
	}
	dfs(0,0,0);
	printf("%d\n",ans);
	if(ans == 999999){
		return 0;
	}
	for(i=0;i<ans;i++){
		printf("%d %d\n",rx[i]+1,ry[i]+1);
	}
	return 0;
}	
