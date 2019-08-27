#include<stdio.h>
int main(){
	int map[100][100];
	int i,j;
	char instruction[100][100];
	int n,m,t;
	while(scanf("%d%d%d",&n,&m,&t)&&(n!=0||m!=0||t!=0)){
		getchar();
		for(i=1;i<=n;i++)
		{
			scanf("%s",instruction[i]);
			getchar();
		}
		for(i=0;i<=n;i++){
			for(j=0;j<=m;j++){
				map[i][j] = -1;
			}
		}
		int px=1,py=t;
		int res = 0; 
		int flag = 0;
		while(px>=1&&px<=n&&py>=1&&py<=m){
			if(map[px][py] == -1){
				map[px][py] = res++;
			}
			else{
				flag = 1;
				break;
			}
			char ins = instruction[px][py-1];
			if(ins=='S'){
				px++;
			}
			else if(ins == 'N'){
				px--;
			}
			else if(ins == 'E'){
				py++;
			}
			else{
				py--;
			}
		}
		if(flag){
			printf("%d step(s) before a loop of %d step(s)\n",map[px][py],res-map[px][py]);
		}
		else{
			printf("%d step(s) to exit\n",res);
		}
		
		
	} 
} 
