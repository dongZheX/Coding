#include<stdio.h>
int a, b, c;
int max = -0x7fffffff;
int num[3];
int vis[100005];
int n;
int l[100005];
int tmax(int x, int y)
{
	return x < y ? y : x;
}
int tmin(int x, int y)
{
	return x > y ? y : x;
}
float judge(int x, int y, int z) {
	int ma =tmax(tmax(x, y), z);
	int mi = tmin(tmin(x, y), z);
	int md = x + y + z - ma - mi;
	if (mi + md > ma&&ma - mi < md && (mi*mi + md*md == ma*ma)) {
		return md*mi / 2.0;
	}
	else
		return 0;
}
void dfs(int cur,int start) {
	if (cur == 2) {
		int t = judge(num[0], num[1], num[2]);
		if (t > max) {
			max = t;
			a = tmin(tmin(num[0], num[1]), num[2]);
			c = tmax(tmax(num[0], num[1]), num[2]);
			b = num[0] + num[1] + num[2] - a - c;
		}
	}
	else {
		int i;
		for (i = start;i < n;i++) {
			if (vis[i] == false) {
				vis[i] = true;
				num[cur+1] = l[i];
				dfs(cur+1,i+1);
				vis[i] = false;
			}
			
		}
	}
}
int main() {
	int T;
	int i;
	int cur = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		max = -0x7fffffff;
		for (i = 0;i < n;i++)
		{
			scanf("%d", &l[i]);
			vis[i] = false;
		}
		for (i = 0;i < n;i++) {
			vis[i] = true;
			num[cur] = l[i];
			dfs(cur,i+1);
			vis[i] = false;
		}
		printf("%d %d %d\n", a, b, c);
	}
}