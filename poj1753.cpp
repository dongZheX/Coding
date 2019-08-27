#include<stdio.h>
#include<string.h>
int ans = 999999;
int map[4][4];
int isOk(){
	int i,j;
	int key = map[0][0];
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(key!=map[i][j]){
				return 0;
			}
		}
	}
	return 1;
}
void flip(int x, int y){
	map[x][y] = !map[x][y];
	if(x>=1)
		map[x-1][y] = !map[x-1][y];
	if(x<=2)
		map[x+1][y] = !map[x+1][y];
	if(y>=1)
		map[x][y-1] = !map[x][y-1];
	if(y<=2)
		map[x][y+1] = !map[x][y+1];

}
void dfs(int x,int y, int t)
{
	if(isOk()==1)
	{
		if(t<ans){
			ans = t;
		}
		return;
	}	
	if(x>=4||y>=4)return;
	int nx,ny;
	nx = x + (y+1)/4;
	ny = (y+1)%4;
	dfs(nx,ny,t);
	flip(x,y);
	dfs(nx,ny,t+1);
	flip(x,y);
}
int main(){
	int i,j;
	for(i=0;i<4;i++){
		char temp[5];
		gets_s(temp);
		for(j=0;j<4;j++){
			if(temp[j] == 'b'){
				map[i][j] = 1;
			}
			else{
				map[i][j] = 0;
			}
		} 
	}
	dfs(0,0,0);
	if(ans==999999){
		printf("Impossible\n");
	}
	else
		printf("%d\n",ans);
} 
