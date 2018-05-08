#include <stdio.h>
#include <malloc.h>
#define Max 10000
typedef struct node{
	struct node* lchild;
	struct node* rchild;
}BTNode;
int BTNDepth(BTNode* b);
int main()
{
	int i,n,l,r;
	int rear,front;
	BTNode *b,*p,*t;
	BTNode *q[Max];
	rear = front = -1;
	b = (BTNode*)malloc(sizeof(BTNode));
	b->lchild = b->rchild = NULL;
	rear++;
	q[rear] = b;
	scanf("%d",&n);
	for( i = 0; i < n && rear != front; i++){
		front++;
		p = q[front];
		scanf("%d%d",&l,&r);
		if(l != -1){
			t = (BTNode*)malloc(sizeof(BTNode));
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			rear++;
			q[rear] = t;
		}
		if(r != -1){
			t = (BTNode*)malloc(sizeof(BTNode));
			t->lchild = t->rchild = NULL; 
			p->rchild = t;
			rear++;
			q[rear] = t;
		}
		
	}
	printf("%d",BTNDepth(b));
	
	return 0;
}
int BTNDepth(BTNode* b)
{
	if( b == NULL)
		return 0;
	int ldep,rdep;
	ldep = BTNDepth(b->lchild);
	rdep = BTNDepth(b->rchild);
	return( ldep > rdep ? (ldep + 1) : (rdep + 1));
}
