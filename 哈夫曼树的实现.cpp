#include<stdio.h>
#include<functional>
#include<queue>
using namespace std;
int main() {

	priority_queue<int, vector<int>, greater<int> >q;
	int n;
	int t1;
	int t2;
	int temp;
	int ans = 0;
	while (scanf("%d", &n) != EOF) {
		ans = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &temp);
			q.push(temp);
		}
		for (int i = 0; i < n-1; i++)
		{
			t1 = q.top();
			q.pop();
			t2 = q.top();
			q.pop();
			ans += t1 + t2;
			q.push(t1 + t2);
		}
		printf("%d\n", ans);
		q.pop();
		
	}
	
}