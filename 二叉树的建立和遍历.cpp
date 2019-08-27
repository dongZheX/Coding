/*
*�ļ�����������������cpp
*ע�⣺���ļ����нڵ�洢�Ķ����ַ�
*�ļ�������ʵ�ֶ��������죬������˳�����������6��ʵ����ʽ���������ݹ�ͷǵݹ鷽������ͬ��
*/
#include<stdlib.h>
#include<stack>
#include<math.h>
#define BElemType char
#define ERROR false
#define OK true
#define Status bool
using namespace std;
typedef struct BiNode {
	BElemType data;
	BiNode *lchild, *rchild;
}BiNode, *BiTree;

//initial BiTree
Status Initial_BiTree(BiTree &Bt) {
	char c;
	
	scanf("%c", &c);
	//getchar();//���ռ��̻������Ŀո�
	if (c == '0')
	{
		Bt = NULL;
	}
	else
	{
		Bt = (BiNode*)malloc(sizeof(BiNode));		
		Bt->data = c;
		Initial_BiTree(Bt->lchild);
		Initial_BiTree(Bt->rchild);

	}
	
	return OK;
}
// In order print Fact
Status InOrderPrint(BiTree Bt) {
	if (Bt != NULL) {
		printf("%c", Bt->data);
		InOrderPrint(Bt->lchild);
		InOrderPrint(Bt->rchild);
	}
	return OK;
}
//In order print feFact
Status InOrderPrintFe(BiTree Bt) {
	//we can use a temp Bt to prevent null tree goto the stacK,this method can help us to understand
	stack<BiTree> s;
	BiTree p;
	s.push(Bt);
	while (!s.empty()) {
		p = s.top();
		while (p) {
			printf("%c", p->data);
			p = p->lchild;
			s.push(p);
		}
		s.pop();//delete null tree
		if (!s.empty()) {
			p = s.top();//get cur tree
			s.pop();
			p = p->rchild;
			s.push(p);
		}
		
	}
	return OK;
}
//cur order Print Fact
Status CurOrderPrint(BiTree Bt) {
	if (Bt != NULL) {
		CurOrderPrint(Bt->lchild);
		printf("%c", Bt->data);
		CurOrderPrint(Bt->rchild);
	}
	return OK;
}
//cur Order Print feFact
Status CurOrderPrintFe(BiTree Bt) {
	//����ʵ��֮һ
	stack<BiTree> s;
	BiTree p;
	s.push(Bt);
	while (!s.empty()) {
		p = s.top();
		while (p) {
			p = p->lchild;
			s.push(p);
		}
		s.pop();
		if (!s.empty()) {
			p = s.top();
			printf("%c", p->data);
			s.pop();
			p = p->rchild;
			s.push(p);
		}
		
	}
	return OK;
}
//pre Order Print Fact
Status PreOrderPrint(BiTree Bt) {
	if (Bt != NULL) {
		PreOrderPrint(Bt->lchild);
		PreOrderPrint(Bt->rchild);
		printf("%c",Bt->data);
	}
	return OK;
}
//pre Order Print feFact
Status PreOrderPrintFe(BiTree Bt) {
	stack<BiTree> s;
	BiTree p, pre=NULL;
	s.push(Bt);
	while (!s.empty()) {
		p = s.top();
		//���ýڵ���Ҫ������������Ҫ������������
		while (p&&(pre!=p->rchild&&(pre!= p->lchild||p->rchild != NULL)||pre == NULL)) {
			
			p = p->lchild;
			s.push(p);
		}
		if(p==NULL)
		s.pop();
		//only the NoNullP can in the if
		if (!s.empty()) {
			p = s.top();
			//������������ĸ������
			if ((p->lchild == NULL && p->rchild == NULL)||(pre == p->rchild)) {
				printf("%c", p->data);
				s.pop();
				pre = p;
				if (!s.empty())
				p = s.top();
				else break;
				if (pre != p->rchild) {
					p = p->rchild;
					s.push(p);
				}
			}			
			else if ( (pre == p->lchild&&p->rchild == NULL)) {
				printf("%c", p->data);
				s.pop();
				pre = p;
				if (!s.empty())//ȷ�������������������
				p = s.top();
				else break;
			}		
			else
			{
				p = p->rchild;
				s.push(p);
			}				
		}
	}
	return OK;
}
//�������Էǵݹ���������㷨ʵ�ַ��������Ż�
Status RPreOrderPrintFe(BiTree Bt) {
	//��һ��ʵ�ַ�ʽ�ڵݹ�ת���ĵط����˽ϴ�����Ӳ��������������޸���ջ�ķ�����������Ż�;
	BiTree pre = NULL, p;
	stack<BiTree> s;
	s.push(Bt);
	while (!s.empty() ){
		p = s.top();
		if ((p->lchild == NULL&& p->rchild == NULL) || (pre != NULL && (p->lchild == pre || p->rchild == pre))) {
			printf("%c", p->data);
			pre = p;
			s.pop();
		}
		else
		{
			//��֤ÿ���ڵ����ǰ�������ӽڵ������Ѿ� ���
			if (p->rchild != NULL) {
				s.push(p->rchild);
			}
			if (p->lchild != NULL) {
				s.push(p->lchild);
			}
		}	
	}
	return OK;

}
Status RInOrderPrintFe(BiTree Bt) {
	//��һ��ʵ�ַ�ʽ�ڵݹ�ת���ĵط����˽ϴ�����Ӳ��������������޸���ջ�ķ�����������Ż�;
	BiTree pre = NULL, p;
	stack<BiTree> s;
	s.push(Bt);
	while (!s.empty()) {
		    p = s.top();		
			printf("%c", p->data);
		
			s.pop();
		
		
			//��֤ÿ���ڵ����ǰ�������ӽڵ������Ѿ� ���
			if (p->rchild != NULL) {
				s.push(p->rchild);
			}
			if (p->lchild != NULL) {
				s.push(p->lchild);
		
		}
	}
	return OK;
}
void ji() {
	BiTree  B;
	Initial_BiTree(B);	
	
	PreOrderPrint(B);
	printf("\n");
	PreOrderPrintFe(B);
	printf("\n");
	CurOrderPrint(B);
	printf("\n");
	CurOrderPrintFe(B);
	printf("\n");
	InOrderPrint(B);
	printf("\n");
	InOrderPrintFe(B);
	printf("\n");
	RInOrderPrintFe(B);
	printf("\n");
}
/*
12400570800030600
48752631
48752631
42785136
42785136
12457836
12457836
�밴���������. . .
*/