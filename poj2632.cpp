#include<string.h>
#include<stdio.h>
typedef struct r{
	int x,y;
	int id;
	int direction;//1E2W3S4W
}robot;
int w,h;
int map[101][101];
robot rs[101];
char dir[4] = {'W','S','E','N'};
int move[4][2] = {-1,0,0,-1,1,0,0,1};
int flag = 0;
void action(int id,char ins, int repeat){
	if(flag==1)return;
	int i,j;
	if(ins=='L'){
		rs[id].direction = (rs[id].direction+repeat)%4;
	}
	else if(ins=='R'){
		rs[id].direction = (rs[id].direction + repeat*4-repeat)%4;
	}
	else if(ins=='F'){
		int tx = rs[id].x;
		int ty = rs[id].y;
		for(i=0;i<repeat;i++){
			tx += move[rs[id].direction][0];
			ty += move[rs[id].direction][1];
			if(tx<=0||tx>w||ty<=0||ty>h){
				printf("Robot %d crashes into the wall\n",id);
				flag = 1;
				return;
			}
			if(map[tx][ty] != -1){
				printf("Robot %d crashes into robot %d\n",id,map[tx][ty]);
				flag = 1;
				return;
			}
		}
		map[rs[id].x][rs[id].y] = -1;
		rs[id].x = tx;
		rs[id].y = ty;
		map[tx][ty] = id;
	} 
}
int main(){
	int k;
	int i,j;
	int n,m;
	scanf("%d",&k);
	while(k--){
		flag = 0;
		scanf("%d%d",&w,&h);
		scanf("%d%d",&n,&m);
		for(i=0;i<101;i++)
			for(j=0;j<101;j++)
				map[i][j] = -1;
		for(i=1;i<=n;i++){
			int x,y;
			char c;
			scanf("%d%d %c",&x,&y,&c);
			rs[i].x = x;
			rs[i].y = y;
			rs[i].id = i;
			switch(c){
				case 'W':rs[i].direction = 0;break;
				case 'S':rs[i].direction = 1;break;
				case 'E':rs[i].direction = 2;break;
				case 'N':rs[i].direction = 3;break;
			}
			map[x][y] = i;
		} 
		int ii[101];
		int cc[101];
		int rr[101];
		for(i=0;i<m;i++){
			scanf("%d %c%d",&ii[i],&cc[i],&rr[i]);
		}
		for(i=0;i<m;i++){
			action(ii[i],cc[i],rr[i]);
		}
		if(flag == 0){
			printf("OK\n");
		}
	}
} 
