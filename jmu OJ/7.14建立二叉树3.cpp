#include <stdio.h>
#include <iostream>
#include <malloc.h>
#define Max 1000
using namespace std;
typedef struct node{
	char data;
	struct node* lchild;
	struct node* rchild;
}BTNode;
void InOrder(BTNode *b);
int main()
{
	int i,k,n,front,rear;
	char str[Max],ch;
	BTNode *b,*p,*t,*q[Max];
	//scanf("%d",&k);
	cin>>k;
	while(k--){
		//scanf(" %d",&n);
		cin>>n;
		front = rear = -1;
		//scanf(" %c",&ch);
		cin>>ch;
		b = (BTNode*)malloc(sizeof(BTNode));
		b->data = ch;
		b->lchild = b->rchild = NULL;
		rear++;
		q[rear] = b;
		n--;
		while(n--){
			//scanf("%s",str);
			cin>>str;
			for( i = 0; str[i] != '\0' && front != rear; i += 2){
				front++;
				p = q[front];
				if( str[i] != '*'){
					t = (BTNode*)malloc(sizeof(BTNode));
					t->lchild = t->rchild = NULL;
					t->data = str[i];
					p->lchild = t;
					rear++;
					q[rear] = t;
				}
				if( str[i+1] != '*'){
					t = (BTNode*)malloc(sizeof(BTNode));
					t->lchild = t->rchild = NULL;
					t->data = str[i+1];
					p->rchild = t;
					rear++;
					q[rear] = t;
				}
			}
		}
		InOrder(b);
		printf("\n");
	}
}
void InOrder(BTNode *b)
{
	if(b){
		InOrder(b->lchild);
		printf("%c",b->data);
		InOrder(b->rchild);
	}
}
