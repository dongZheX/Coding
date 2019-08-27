#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
struct node
{
	double left,right; 
}order[1005];
bool compare(node a1,node a2)
{
	return a1.left<=a2.left;
}
int main()
{
	int island,r,q=0;
	while((cin>>island>>r)&&island&&r)
	{
		q++;
		const double R2=r*r;
		bool able=1;
		for(int i=1;i<=island;i++)
		{
			double x,y,delta;
			cin>>x>>y;
			delta=sqrt(R2-y*y);
			if(fabs(y)>r)
				able=0;
			order[i].left=x-delta,order[i].right=x+delta;
		}
		int ans=1;
		if(able)
		{
			sort(order+1,order+1+island,compare);
			double RIGHT=order[1].right;
			for(int i=2;i<=island;i++)
			{
				if(order[i].left>RIGHT)
				{
					ans++;
					RIGHT=order[i].right;
				}
				else if(order[i].right<RIGHT)
					RIGHT=order[i].right;
			}
		}
		else ans=-1;
		printf("Case %d: %d\n",q,ans);
	}
	return 0;
}
