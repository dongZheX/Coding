/*
*文件名：二叉树遍历，cpp
*注意：该文件所有节点存储的都是字符
*文件描述：实现二叉树建造，和三种顺序遍历方法的6中实现形式，深入理解递归和非递归方法的异同。
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
	//getchar();//吸收键盘缓存区的空格
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
	//最优实现之一
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
		//当该节点需要被遍历，则不需要继续遍历左树
		while (p&&(pre!=p->rchild&&(pre!= p->lchild||p->rchild != NULL)||pre == NULL)) {
			
			p = p->lchild;
			s.push(p);
		}
		if(p==NULL)
		s.pop();
		//only the NoNullP can in the if
		if (!s.empty()) {
			p = s.top();
			//处理可能遇到的各种情况
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
				if (!s.empty())//确保右树遍历结束后完成
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
//本函数对非递归后续遍历算法实现方法进行优化
Status RPreOrderPrintFe(BiTree Bt) {
	//第一个实现方式在递归转化的地方做了较大的冗杂操作，本函数将修改入栈的方法对其进行优化;
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
			//保证每个节点输出前其左右子节点任务已经 完成
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
	//第一个实现方式在递归转化的地方做了较大的冗杂操作，本函数将修改入栈的方法对其进行优化;
	BiTree pre = NULL, p;
	stack<BiTree> s;
	s.push(Bt);
	while (!s.empty()) {
		    p = s.top();		
			printf("%c", p->data);
		
			s.pop();
		
		
			//保证每个节点输出前其左右子节点任务已经 完成
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
请按任意键继续. . .
*/