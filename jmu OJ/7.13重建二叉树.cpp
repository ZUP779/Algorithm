#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef struct node{
	char data;
	struct node* lchild;
	struct node* rchild;
}BTNode;
BTNode* CreateBT(char *pre,char *in,int n)
{
	BTNode *s;
	char *p;
	int k;
	if( n <= 0)	return NULL;
	s = (BTNode*)malloc(sizeof(BTNode));
	s->data = *pre;
	for( p = in; p < in +n; p++)
		if( *p == *pre)
			break;
	k = p - in;
	s->lchild = CreateBT(pre+1,in,k);
	s->rchild = CreateBT(pre+k+1,p+1,n-k-1);
	return s;
}
void PostOrder(BTNode *b)
{
	if(b){
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		printf("%c",b->data);
	}
}
int main()
{
	int len; 
	char pre[100],in[100];
	BTNode *b;
	while(scanf("%s%s",pre,in)==2){
		len = strlen(pre);
		b = CreateBT(pre,in,len);
		PostOrder(b);
		printf("\n");
	}
	
	return 0;
}
