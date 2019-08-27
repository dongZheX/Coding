#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
#define N 100
typedef struct st {
	int s, a, b;
	int t;
}state;
queue<state> Q;
int vis[N][N][N];
int BFS(int, int, int);
void Atom(int &a, int &s, int &b, int sb);
int main() {
	int s, n, m;
	int i, j;
	while (scanf("%d%d%d",&s, &n, &m) != EOF&&s != 0 && n != 0 && m != 0) {
		if (s % 2!=0) {
			printf("NO\n");
			continue;
		}
		memset(vis, 0, sizeof(int)*N*N*N);
		while (Q.empty() == false)Q.pop();
		vis[s][0][0] = 1;
		state tmp;
		tmp.s = s;
		tmp.a = 0;
		tmp.b = 0;
		tmp.t = 0;
		Q.push(tmp);
		int res = BFS(s, n, m);
		if (res == -1)printf("NO\n");
		else printf("%d\n", res);
	}
}
int BFS(int s, int n, int m) {
	state tmp, next;
	int ss, a, b, t;
	int i, j;
	while (Q.empty() == false) {
		tmp = Q.front();
		Q.pop();
		// ss -> a
		ss = tmp.s;
		a = tmp.a;
		b = tmp.b;
		Atom(ss, s, a, n);
		if (vis[ss][a][b] == 0) {
			next.s = ss;
			next.a = a;
			next.b = b;
			next.t = tmp.t + 1;
			if (a == s / 2 && b == s / 2)return next.t;
			if (ss == s / 2 && a == s / 2)return next.t;
			if (ss == s / 2 && b == s / 2)return next.t;
			vis[ss][a][b] = 1;
			Q.push(next);
		}
		//ss->b
		ss = tmp.s;
		a = tmp.a;
		b = tmp.b;
		Atom(ss, s, b, m);
		if (vis[ss][a][b] == 0) {
			next.s = ss;
			next.a = a;
			next.b = b;
			next.t = tmp.t + 1;
			if (a == s / 2 && b == s / 2)return next.t;
			if (ss == s / 2 && a == s / 2)return next.t;
			if (ss == s / 2 && b == s / 2)return next.t;
			vis[ss][a][b] = 1;
			Q.push(next);
		}
		//a->b
		ss = tmp.s;
		a = tmp.a;
		b = tmp.b;
		Atom(a, s, b, m);
		if (vis[ss][a][b] == 0) {
			next.s = ss;
			next.a = a;
			next.b = b;
			next.t = tmp.t + 1;
			if (a == s / 2 && b == s / 2)return next.t;
			if (ss == s / 2 && a == s / 2)return next.t;
			if (ss == s / 2 && b == s / 2)return next.t;
			vis[ss][a][b] = 1;
			Q.push(next);
		}
		//b->a
		ss = tmp.s;
		a = tmp.a;
		b = tmp.b;
		Atom(b, s, a, n);
		if (vis[ss][a][b] == 0) {
			next.s = ss;
			next.a = a;
			next.b = b;
			next.t = tmp.t + 1;
			if (a == s / 2 && b == s / 2)return next.t;
			if (ss == s / 2 && a == s / 2)return next.t;
			if (ss == s / 2 && b == s / 2)return next.t;
			vis[ss][a][b] = 1;
			Q.push(next);
		}
		//a->ss
		ss = tmp.s;
		a = tmp.a;
		b = tmp.b;
		Atom(a, s,ss, s);
		if (vis[ss][a][b] == 0) {
			next.s = ss;
			next.a = a;
			next.b = b;
			next.t = tmp.t + 1;
			if (a == s / 2 && b == s / 2)return next.t;
			if (ss == s / 2 && a == s / 2)return next.t;
			if (ss == s / 2 && b == s / 2)return next.t;
			vis[ss][a][b] = 1;
			Q.push(next);
		}
		//b->ss
		ss = tmp.s;
		a = tmp.a;
		b = tmp.b;
		Atom(b, s,ss, s);
		if (vis[ss][a][b] == 0) {
			next.s = ss;
			next.a = a;
			next.b = b;
			next.t = tmp.t + 1;
			if (a == s / 2 && b == s / 2)return next.t;
			if (ss == s / 2 && a == s / 2)return next.t;
			if (ss == s / 2 && b == s / 2)return next.t;
			vis[ss][a][b] = 1;
			Q.push(next);
		}
	}
	return -1;
}
void Atom(int &a, int &s, int &b, int sb) {
	if (sb - b >= a) {
		b += a;
		a = 0;
	}
	else {
		a -= sb - b;
		b = sb;
	}
}