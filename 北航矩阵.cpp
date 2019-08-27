#include<stdio.h>
int main(){
	int st,dim;
	int i,j,k;
	int map[100][100];
	while(scanf("%d%d",&st,&dim)){
		for(i=1;i<=dim;i++){
			for(k=0;k<i-1;k++){
				map[k][i-1] = (st++);
			}
			for(k=i-1;k>=0;k--)
			{
				map[i-1][k] = (st++);
			}
		}
		for(i=0;i<dim;i++){
			for(j=0;j<dim-1;j++){
				printf("%d ",map[i][j]);	
			}
			printf("%d\n",map[i][j]);
		}
	}
}
