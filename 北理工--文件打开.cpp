#include<stdio.h>
#include<stdlib.h>
typedef struct n {
	int val;
	struct n* next;
}*node;
int main() {
	node head = NULL,cur=NULL;
	node last = head;
	int size = 0;
	int input;
	while (scanf("%d", &input) != EOF) {
		cur = (node)malloc(sizeof(struct n));
		cur->val = input;
		cur->next = NULL;
		head = cur;
		head->next = last;
		last = cur;
		node p = head;
		printf("%d", p->val);
		p = p->next;
		for(int i = 1;i<3&&p!=NULL;) {
			if (p->val != input) {
				printf(" %d", p->val);
				i++;
			}
			p = p->next;
		}
		printf("\n");
		
	}
}