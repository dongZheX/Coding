#include<iostream>
#include<algorithm> 
using namespace std; 
int main(){
	int n;
	int m;
	int i,j;
	int co[200];
	cin>>n;
	while(n--){
		for(i=0;i<200;i++)co[i] = 0;
		cin>>m;
		while(m--){
			int a,b;
			int t;
			cin>>a>>b;
			if(a>b){
				t = a;
				a = b;
				b = t;
			}
			for(i = (a-1)/2;i<=(b-1)/2;i++){
				co[i]++;
			}
		
		}
			int max = -1;
			for(i=0;i<200;i++){
				if(co[i]>max){
					max = co[i];
				}
			}
			cout<<max*10<<endl;
	}


}

