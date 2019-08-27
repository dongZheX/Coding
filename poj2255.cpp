#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stack>
using namespace std;
typedef struct BTree {
	char val;
	BTree *lchild;
	BTree *rchild;
}BTreeNode,*Tree;
//之后后序+前序 或者 前序加中序 可以确定一颗二叉树 hhh
void CreateByInCur(char a[], char b[],Tree &t, int n) {
	//1 2 4 7 3 5 8 9 6
	//0 1 2 3 4 5 6 7 8
	//4 7 2 1 8 5 9 3 6
	int i = 0;
	bool flag = false;
	for (i = 0; i < n;i++) {
		if (a[0] == b[i]) {
			flag = true;
			t = (Tree)malloc(sizeof(BTreeNode));
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
	while (!s.empty()) {
		p = s.top();
		if ((p->lchild == NULL&&p->rchild == NULL) || (pre != NULL && (pre == p->lchild || pre == p->rchild))) {
			printf("%c", p->val);
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
int main(){
	char str1[30],str2[30];
	while(scanf("%s",str1)!=EOF){
		scanf("%s",str2);
		Tree res;
		int len = strlen(str1);
		CreateByInCur(str1,str2,res,len);
		Pre(res);
		printf("\n");
	}
}
