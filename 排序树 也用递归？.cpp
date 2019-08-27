#include<stdio.h>
#include<stack>
#include<stdlib.h>
using namespace std;
typedef struct BTree {
	int val;
	BTree *lchild;
	BTree *rchild;
}BTreeNode,*Tree;
/*
	现在发现并不是建立树都要结束标志
	只是在用遍历顺序建树的时候用到过
	现在排序树并不需要
	排序树规定：
	任何一个节点大于左子树上的所有节点
	任何一个节点小于右子树上的所有节点
*/

//插入操作 ，含有递归
//重复的忽略
void Insert(Tree &t, int val) {
	
	if (t == NULL) {
		t = (Tree)malloc(sizeof(BTreeNode));
		t->lchild = NULL;
		t->rchild = NULL;
		t->val = val;
	}
	else if (val < (t->val)) {
		
		Insert(t->lchild, val);
	}
	else if (val > (t->val)) {
		Insert(t->rchild, val);
	}
}

void In(Tree tree) {
	if (tree != NULL) {
		printf("%d ", tree->val);
		In(tree->lchild);
		In(tree->rchild);
	}
}
void Cur(Tree tree) {
	if (tree != NULL) {
		Cur(tree->lchild);
		printf("%d ", tree->val);
		Cur(tree->rchild);
	}
}
void Pre(Tree tree) {
	if (tree != NULL) {
		Pre(tree->lchild);
		Pre(tree->rchild);
		printf("%d ", tree->val);
	}
}
//这里遍历 直接写递归遍历了
int main() {
	int n;
	int i;
	int temp;
	scanf("%d", &n);
	Tree tree = NULL;//尼玛的开始一定要赋初始值
	for (i = 0;i < n;i++) {
		scanf("%d", &temp);
		Insert(tree, temp);
	}
	In(tree);
	printf("\n");
	Cur(tree);
	//中序遍历是排序
	printf("\n");
	Pre(tree);
	printf("\n");
	//如何判断两个树是否完全相同呢：
	//中序输出相同 并且先序或者后序相同
	/*
		bool compare(const Node *root1,const Node *root2){
	if (root1==NULL&&root2==NULL)
	{
		return true;
	}
	else if(root1==NULL||root2==NULL)
	{
		return false;
	}
 
	if (root1->data!=root2->data)
	{
		return false;
	}
 
	bool left=false,right=false;
	left=compare(root1->left,root2->left);
	right=compare(root1->right,root2->right);
	return left&&right;
}
	*/
}