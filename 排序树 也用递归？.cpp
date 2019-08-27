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
	���ڷ��ֲ����ǽ�������Ҫ������־
	ֻ�����ñ���˳������ʱ���õ���
	����������������Ҫ
	�������涨��
	�κ�һ���ڵ�����������ϵ����нڵ�
	�κ�һ���ڵ�С���������ϵ����нڵ�
*/

//������� �����еݹ�
//�ظ��ĺ���
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
//������� ֱ��д�ݹ������
int main() {
	int n;
	int i;
	int temp;
	scanf("%d", &n);
	Tree tree = NULL;//����Ŀ�ʼһ��Ҫ����ʼֵ
	for (i = 0;i < n;i++) {
		scanf("%d", &temp);
		Insert(tree, temp);
	}
	In(tree);
	printf("\n");
	Cur(tree);
	//�������������
	printf("\n");
	Pre(tree);
	printf("\n");
	//����ж��������Ƿ���ȫ��ͬ�أ�
	//���������ͬ ����������ߺ�����ͬ
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