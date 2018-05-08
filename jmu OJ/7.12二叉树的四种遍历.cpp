#include <stdio.h>
#include <malloc.h>
#define Max 100
typedef struct node{
	char data;
	struct node* lchild;
	struct node* rchild;
}BTNode;
void CreatBT(BTNode *&b,char s[]);
void DispBTNode(BTNode *b);
void DestroyBTNode(BTNode *b);
void PreOrder(BTNode *b);
void PreOrder1(BTNode *b);
void InOrder(BTNode *b);
void InOrder1(BTNode *b);
void PostOrder(BTNode *b);
void PostOrder1(BTNode *b);
void TravLevel(BTNode *b);
void Print(void);
int n;
char r[Max];
int main()
{
	BTNode *b;
	char str[Max];
	scanf("%s",str);
	CreatBT(b,str);
	DispBTNode(b);
	printf("\n"); 
	n = 0;	PreOrder(b);	Print();
	n = 0;	PreOrder1(b);	Print();
	n = 0;	InOrder(b);	Print();
	n = 0;	InOrder1(b);	Print();
	n = 0;	PostOrder(b);	Print();
	n = 0;	PostOrder1(b);	Print();
	n = 0;	TravLevel(b);	Print();
	DestroyBTNode(b);
	
	return 0;
}
void CreatBT(BTNode *&b,char s[])
{
	int top = -1,k,j = 0;
	char ch;
	BTNode *st[Max],*p;
	b = NULL;
	ch = s[j];
	while(ch != '\0'){
		switch(ch){
			case '(':	top++;	st[top] = p; k = 1;	break;
			case ')':	top--;	break;
			case ',':	k = 2; 	break;
			default :	p = (BTNode *)malloc(sizeof(BTNode));
						p->data = ch;	p->lchild = p->rchild = NULL;
						if(!b)
							b = p;
						else{
							switch(k){
								case 1:	st[top]->lchild = p;	break;
								case 2:	st[top]->rchild = p;	break;
							}
						}
		}
		j++;
		ch = s[j];
	}
}
void DispBTNode(BTNode *b)
{
	if(b){
		printf("%c",b->data);
		if( b->lchild || b->rchild){
			printf("(");
			DispBTNode(b->lchild);
			if(b->rchild)	printf(",");
			DispBTNode(b->rchild);
			printf(")");
		}
	}
}
void DestroyBTNode(BTNode *b)
{
	if(b){
		DestroyBTNode(b->rchild);
		DestroyBTNode(b->lchild);
		free(b);
	}
}
void PreOrder(BTNode *b)
{
	if(b){
		r[n++] = b->data;
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}
void PreOrder1(BTNode *b)
{
	BTNode *st[Max],*p;
	int top = -1;
	if(b){
		top++;
		st[top] = b;
		while( top > -1){
			p = st[top];
			top--;
			r[n++] = p->data;
			if( p->rchild){
				top++;
				st[top] = p->rchild;
			}
			if( p->lchild){
				top++;
				st[top] = p->lchild;
			}
		}
	}
}
void InOrder(BTNode *b)
{
	if(b){
		InOrder(b->lchild);
		r[n++] = b->data;
		InOrder(b->rchild);
	}
}
void InOrder1(BTNode *b)
{
	BTNode *st[Max],*p;
	int top = -1;
	if(b){
		p = b;
		while( top > -1 || p){
			while(p){
				top++;
				st[top] = p;
				p = p->lchild;
			}
			if( top > -1){
				p = st[top];
				top--;
				r[n++] = p->data;
				p = p->rchild;
			}
		}
	}
}
void PostOrder(BTNode *b)
{
	if(b){
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		r[n++] = b->data;
	}
}
void PostOrder1(BTNode *b)
{
	BTNode *st[Max],*p;
	int flag,top = -1;
	if(b){
		do{
			while(b){
				top++;
				st[top] = b;
				b = b->lchild;
			}
			p = NULL;
			flag = 1;
			while( top != -1 && flag){
				b = st[top];
				if( b->rchild == p){
					r[n++] = b->data;
					top --;
					p = b;
				}
				else{
					b = b->rchild;
					flag = 0;
				}
			}
		}while(top != -1);
	}
}
void TravLevel(BTNode *b)
{
	BTNode *q[Max];
	int front,rear;
	front = rear = 0;
	if(b)
		r[n++] = b->data;
	rear++;
	q[rear] = b;
	while(rear != front){
		front = (front + 1) % Max;
		b = q[front];
		if( b->lchild){
			r[n++] = b->lchild->data;
			rear = (rear + 1) % Max;
			q[rear] = b->lchild;
		}
		if(b->rchild){
			r[n++] = b->rchild->data;
			rear = (rear + 1) % Max;
			q[rear] = b->rchild;
		}
	}
}
void Print(void)
{
	if(r[0])
		printf("%c",r[0]);
	for( int i = 1; i < n; i++)
		printf(" %c",r[i]);
	printf("\n");
}
