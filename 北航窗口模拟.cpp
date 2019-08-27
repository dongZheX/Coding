#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
typedef struct window{
	int id;
	int x1,y1,x2,y2;
	int priority;
	bool operator < (const window &A)const{
		return priority > A.priority;
	} 
}Win;
int judge(int x,int y, Win win){
	int f1=0,f2=0;
	if(x<=win.x2&&x>=win.x1){f1 = 1;}
	if(y>=win.y1&&y<=win.y2){f2 = 1;}
	if(f1&&f2)return 1;
	else return 0;
}
int main(){
	Win wins[11];
	int n,k;
	int i,j;
	int px,py;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			scanf("%d%d%d%d%d",&wins[i].id,&wins[i].x1,&wins[i].y1,&wins[i].x2,&wins[i].y2);
			wins[i].priority = n-i;
		}
		scanf("%d",&k);
		while(k--){
			sort(wins,wins+n);
			scanf("%d%d",&px,&py);
			for(i=0;i<n;i++){
				if(judge(px,py,wins[i])==1){
					wins[i].priority = n;
					for(j=0;j<i;j++){
						wins[j].priority--;
					}
					break;
				}
			}
		} 
		sort(wins,wins+n);
		for(i=0;i<n-1;i++){
			printf("%d ",wins[i].id);
		}
		printf("%d\n",wins[i].id);
	}
		
	
}
