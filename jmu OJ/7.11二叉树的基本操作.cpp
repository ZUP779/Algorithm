#include <stdio.h>
#include <malloc.h>
#define Max 100
typedef struct node{
	char data;
	struct node *lchild;
	struct node *rchild;
}BTNode;
void CreatBT(BTNode *&b,char s[]);
void DispBTNode(BTNode *b);
int BTNodeDepth(BTNode *b);
int BTNWidth(BTNode *b);
int Nodes(BTNode *b);
int LeafNodes(BTNode *b);
void DestroyBTNode(BTNode *b);
BTNode *FindNode(BTNode *b,char x);
int main()
{
	BTNode *b,*p;
	char str[100],ch;
	int n,i;
	scanf("%s%d",str,&n);
	
	CreatBT(b,str);
	DispBTNode(b);	printf("\n");
	
	for( i = 0; str[i] != '\0' && n > 0; i++)
		if( str[i] >= 'A' && str[i] <= 'Z')
			n--;
		
	ch = str[i-1];
	p = FindNode(b,ch);

	if(p->lchild && p->rchild)
		printf("%c %c\n",p->lchild->data,p->rchild->data);
	else if(p->lchild)
		printf("%c no rightchild\n",p->lchild->data);
	else if(p->rchild)
		printf("no leftchild %c\n",p->rchild->data);
	else
		printf("no leftchild no rightchild\n");
	printf("%d\n%d\n%d\n%d\n",BTNodeDepth(b),BTNWidth(b),Nodes(b),LeafNodes(b));
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
int BTNodeDepth(BTNode *b)
{
	int ldep,rdep;
	if(!b)
		return 0;
	ldep = BTNodeDepth(b->lchild);
	rdep = BTNodeDepth(b->rchild);
	return (ldep > rdep ? (ldep + 1) : (rdep + 1));
}
int BTNWidth(BTNode *b)
{
	struct{
		int lno;
		BTNode *p;
	}Qu[Max];
	int front,rear;
	int lnum,max,i,n;
	front = rear = 0;
	if(b){
		rear ++;
		Qu[rear].p = b;
		Qu[rear].lno = 1;
		while(rear != front){
			front++;
			b = Qu[front].p;
			lnum = Qu[front].lno;
			if( b->lchild){
				rear++;
				Qu[rear].p = b->lchild;
				Qu[rear].lno = lnum + 1;
			}
			if( b->rchild){
				rear++;
				Qu[rear].p = b->rchild;
				Qu[rear].lno = lnum + 1;
			}
		}
		max = 0;	lnum = 1;	i = 1;
		while( i <= rear){
			n = 0;
			while( i <= rear && Qu[i].lno == lnum){
				n++;	i++;
			}
			lnum = Qu[i].lno;
			if( n > max)	max = n;
		}
		return max;
	}
	return 0;
}
int Nodes(BTNode *b)
{
	int num1,num2;
	if(!b)
		return 0;
	if(b->lchild == NULL && b->rchild == NULL)
		return 1;
	num1 = Nodes(b->lchild);
	num2 = Nodes(b->rchild);
	return num1 + num2 + 1;
}
int LeafNodes(BTNode *b)
{
	int num1,num2;
	if(!b)
		return 0;
	if(b->lchild == NULL && b->rchild == NULL)
		return 1;
	num1 = LeafNodes(b->lchild);
	num2 = LeafNodes(b->rchild);
	return num1 + num2;
}
void DestroyBTNode(BTNode *b)
{
	if(b){
		DestroyBTNode(b->rchild);
		DestroyBTNode(b->lchild);
		free(b);
	}
}
void DispChild(BTNode *b,int n)
{
	if( b == NULL)
		return;
	BTNode* data[Max];
	bool flag = false;
	int rear,front,count = 0;
	rear = front = -1;
	BTNode *p = b;
	rear++;
	data[rear] = p;
	if( rear + 1 != n){
		while( rear <= n){
			front++;
			p = data[front];
			if( front > rear)
				break;
			if( p->lchild){
				rear++;
				data[rear] = p->lchild;
				if( rear + 1 == n){
					flag = true;
					break;
				}
			}
			if(p->rchild){
				rear++;
				data[rear] = p->rchild;
				if( rear + 1 == n){
					flag = true;
					break;
				}
			}
		}
	}
	else
		flag = true;
	if(flag){
		p = data[rear];
		if(p->lchild && p->rchild)
			printf("%c %c\n",p->lchild->data,p->rchild->data);
		else if(p->lchild)
			printf("%c no rightchild\n",p->lchild->data);
		else if(p->rchild)
			printf("no leftchild %c\n",p->rchild->data);
		else
			printf("no leftchild no rightchild\n");
	}
	else	printf("no leftchild no rightchild\n");
	
}
BTNode *FindNode(BTNode *b,char x)
{
	BTNode *p;
	
	if(b==NULL)
		return NULL;
		
	else if(b->data==x)
		return b;
		
	else
	{
		p=FindNode(b->lchild,x);
		
		if(p!=NULL)
			return p;
		else
			return FindNode(b->rchild,x);
	}
}

