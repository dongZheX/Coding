#include <stdio.h>
#include <iostream>
using namespace std;

#define maxn 110

typedef struct node {
	int num;
	struct node* left;
	struct node* right;
}node;

node Tree[maxn];
int loc = 0;

void preOrder(node* head) {
	if (head == NULL) {
		return;
	}
	printf("%d ", head->num);
	if (head->left != NULL) {
		preOrder(head->left);
	}
	if (head->right != NULL) {
		preOrder(head->right);
	}
}

node* create(int num) {
	Tree[loc].num = num;
	Tree[loc].left = NULL;
	Tree[loc].left = NULL;
	loc++;
	return &Tree[loc - 1];
}

node* insert(node* head, int num) {
	node* this_node = create(num);
	if (head == NULL) {
		head = this_node;
	}
	else if (num < head ->num) {
		head ->left = insert(head->left, num);
	}
	else if (num > head ->num){ //根据提目要求，若结点值相同直接忽略
		head->right = insert(head->right, num);
	}
	return head;
}

int main() {
	int n;
	cin >> n;
	node* head = NULL;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		head = insert(head, a);
	}
	preOrder(head);
	printf("\n");
}