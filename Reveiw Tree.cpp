#include<stdio.h>
#include<stack>
#include<stdlib.h>
using namespace std;
typedef struct BTree {
	char data;
	BTree* lchild;
	BTree* rchild;
}BTreeNode,*Tree;

void initTree(Tree &t) {
	char c;
	scanf("%c", &c);
	if (c == '0') {
		t = NULL;
	}
	else {
		t = (BTreeNode*)malloc(sizeof(BTreeNode));
		t->data = c;
		initTree(t->lchild);
		initTree(t->rchild);
	}
}
void In(Tree t) {
	if (t!=NULL) {
		printf("%c", t->data);
		In(t->lchild);
		In(t->rchild);
	}
}
void Cur(Tree t) {
	if (t!=NULL) {
		Cur(t->lchild);
		printf("%c", t->data);
		Cur(t->rchild);
	}
}
void Pre(Tree t) {
	if (t!=NULL) {
		Pre(t->lchild);
		Pre(t->rchild);
		printf("%c", t->data);
	}
}
void InFe(Tree b) {
	stack<Tree> s;
	Tree p;
	s.push(b);
	while (!s.empty()) {
		p = s.top();
		while (p) {
			printf("%c", p->data);
			p = p->lchild;
			s.push(p);
		}
		s.pop();
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			p = p->rchild;
			s.push(p);
		}
	}
}
void PerfectInFe(Tree t){
	stack<Tree> s;
	Tree b;
	s.push(t);
	while (!s.empty()) {
		b = s.top();
		printf("%c", b->data);
		s.pop();
		if (b->rchild != NULL) {
			s.push(b->rchild);
		}
		if (b->lchild != NULL) {
			s.push(b->lchild);
		}
	}
}
void CurFe(Tree b) {
	stack<Tree> s;
	Tree p;
	s.push(b);
	while (!s.empty()) {
		p = s.top();
		while (p) {
			p = p->lchild;
			s.push(p);
		}
		s.pop();
		if (!s.empty())
		{
			p = s.top();
			printf("%c", p->data);
			s.pop();
			p = p->rchild;
			s.push(p);
		}
	}
}
void PreFe(Tree b) {
	Tree pre = NULL, p;
	stack<Tree> s;
	s.push(b);
	while (!s.empty()) {
		p = s.top();
		if ((p->lchild == NULL&& p->rchild == NULL) || (pre != NULL && (p->lchild == pre || p->rchild == pre))) {
			printf("%c", p->data);
			pre = p;
			s.pop();
		}
		else
		{
			//保证每个节点输出前其左右子节点任务已经 完成
			if (p->rchild != NULL) {
				s.push(p->rchild);
			}
			if (p->lchild != NULL) {
				s.push(p->lchild);
			}
		}
	}
}
int main()
{
	Tree b;
	initTree(b);
	InFe(b);
	printf("\n");
	PerfectInFe(b);
	printf("\n");
	CurFe(b);
	printf("\n");
	Pre(b);
	printf("\n");
}