#include<stdio.h>
#include<stack>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define BTreeType int
typedef struct BTree {
	BTreeType val;
	BTree *lchild;
	BTree *rchild;
}BTreeNode,*Tree;

bool Compare(Tree a, Tree b) {
	if (a == NULL&&b == NULL)
	{
		return true;
	}
	else if (a == NULL || b == NULL) {
		return false;
	}
	else {
		return Compare(a->lchild, b->lchild) && Compare(a->rchild, b->rchild);
	}
}

void insert(Tree& tree, BTreeType val) {
	if (tree == NULL) {
		tree = (Tree)malloc(sizeof(BTreeNode));
		tree->rchild = NULL;
		tree->lchild = NULL;
		tree->val = val;
	}
	else if(tree->val < val) {
		insert(tree->rchild, val);
	}
	else if (tree->val > val) {
		insert(tree->lchild, val);
	}
}
int main() {
	int n;
	int i;
	int j;
	Tree t = NULL;
	Tree tree = NULL;
	while (scanf("%d", &n) && n != 0) {
		char str[11];
		getchar();
		gets_s(str);
		int len = strlen(str);
		for (i = 0;i < len;i++) {
			insert(t, str[i] - '0');
		}
		for (i = 0; i < n; i++) {
			gets_s(str);
			len = strlen(str);
			for (j = 0;j < len;j++) {
				insert(tree, str[j] - '0');
			}
			if (Compare(t, tree)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
			free(tree);
			tree = NULL;
		}	
	}
}