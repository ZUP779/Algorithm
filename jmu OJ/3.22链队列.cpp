#include <stdio.h>
#include <stdlib.h>
typedef struct qnode{
	char data;
	struct qnode* next;
}QNode;
typedef struct{
	QNode* front;
	QNode* rear;
}LiQueue;

void InitQueue(LiQueue *&q);
void DestroyQueue(LiQueue *&q);
bool QueueEmpty(LiQueue *q);
void enQueue(LiQueue *&q,char e);
bool deQueue(LiQueue *&q,char &e);

int main()
{
	LiQueue *q;
	QNode *t;
	int n,i;
	char ch;
	
	InitQueue(q);
	printf(QueueEmpty(q)?"yes\n":"no\n");
	
	scanf("%d",&n);
	for( i = 0; i < n; i++){
		scanf(" %c",&ch);
		enQueue(q,ch);
	}
	
	deQueue(q,ch);
	printf("%c\n",ch);
	
	n = 0;
	t = q->front;
	while(t){
		t = t->next;
		n++;
	}
	printf("%d\n",n);
	
	scanf("%d",&n);
	for( i = 0; i < n; i++){
		scanf(" %c",&ch);
		enQueue(q,ch);
	}
	
	n = 0;
	t = q->front;
	while(t){
		t = t->next;
		n++;
	}
	printf("%d\n",n);
	
	while(!QueueEmpty(q)){
		deQueue(q,ch);
		printf("%c ",ch);
	}
	DestroyQueue(q);
}

void InitQueue(LiQueue *&q)
{
	q = (LiQueue *)malloc(sizeof(LiQueue));
	q->front = q->rear = NULL;
}
void DestroyQueue(LiQueue *&q)
{
	QNode *p = q->front,*r;
	if(p){
		r = p->next;
		while(r){
			free(p);
			p = r;
			r = p->next;
		}
		free(p);
	}
	free(q);
}
bool QueueEmpty(LiQueue *q)
{
	return(q->rear == NULL);
}
void enQueue(LiQueue *&q,char e)
{
	QNode *p;
	p = (QNode*)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	if(q->rear == NULL)
		q->front = q->rear = p;
	else{
		q->rear->next = p;
		q->rear = p;
	}
}
bool deQueue(LiQueue *&q,char &e)
{
	QNode *t;
	if( q->rear == NULL)
		return false;
	t = q->front;
	if( q->front == q->rear)
		q->front = q->rear = NULL;
	else
		q->front = q->front->next;
	e = t->data;
	free(t);
	return true;
}
