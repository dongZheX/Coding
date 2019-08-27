#include<stdio.h>
#include<stdlib.h>
#include<stack>
using namespace std;
typedef struct BTree {
	int val;
	BTree *lchild;
	BTree *rchild;
}BTreeNode,*Tree;
//之后后序+前序 或者 前序加中序 可以确定一颗二叉树 hhh
void CreateByInCur(int a[], int b[],Tree &t, int n) {
	//1 2 4 7 3 5 8 9 6
	//0 1 2 3 4 5 6 7 8
	//4 7 2 1 8 5 9 3 6
	int i = 0;
	bool flag = false;
	for (i = 0; i < n;i++) {
		if (a[0] == b[i]) {
			flag = true;
			t = (Tree)malloc(sizeof(BTreeNode));
			t->lchild = NULL;
			t->rchild = NULL;
			t->val = a[0];
			CreateByInCur(a + 1, b, t->lchild, i);
			//左子树长度
			CreateByInCur(a + i + 1, b + i + 1, t->rchild, n - i - 1 );
			break;
		}
	}
	if (!flag) {
		t = NULL;
	}
	
}
void Pre(Tree t) {
	Tree pre;
	Tree p;
	stack<Tree> s;
	s.push(t);
	bool first = false;;
	while (!s.empty()) {
		p = s.top();
		if ((p->lchild == NULL&&p->rchild == NULL) || (pre != NULL && (pre == p->lchild || pre == p->rchild))) {
			if (!first) {
				printf("%d", p->val);
				first = true;
			}	
			else {
				printf(" %d", p->val);
			}
			pre = p;
			s.pop();
		}
		else {
			if (p->rchild != NULL) {
				s.push(p->rchild);
			}
			if (p->lchild != NULL) {
				s.push(p->lchild);
			}
		}
	}
}
//由中序+后序 求出树
void CreateByCurPre(int a[], int b[], Tree &t, int n) {
	//4 7 2 1 8 5 9 3 6  中序
	//0 1 2 3 4 5 6 7 8
	//7 4 2 8 9 5 6 3 1  后序
	int i = 0;
	bool flag = false;
	for (i = 0; i < n;i++) {
		if (a[n-1] == b[i]) {
			flag = true;
			t = (Tree)malloc(sizeof(BTreeNode));
			t->val = a[n - 1];
			CreateByCurPre(a, b, t->lchild, i);
			//左子树长度
			CreateByCurPre(a+i, b + i + 1, t->rchild, n-i-1);
			break;
		}
	}
	if (!flag) {
		t = NULL;
	}
}
int main() {
	Tree tree;
	int n;
	int a[1001], b[1001];
	int i;
	int j;
	while (scanf("%d", &n) != EOF) {
		
		for (i = 0;i < n;i++) {
			scanf("%d", &a[i]);
		}
		for (j = 0;j < n;j++) {
			scanf("%d", &b[j]);
		}
		CreateByCurPre(a, b, tree, n);
		Pre(tree);
		printf("\n");
	}
}