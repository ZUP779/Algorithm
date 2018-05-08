#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef struct{
	char data[MaxSize];
	int front,rear;
}SqQueue;
void InitQueue(SqQueue*& q);
void DestroyQueue(SqQueue*& q);
bool QueueEmpty(SqQueue* q);
bool enQueue(SqQueue*& q,char e);
bool deQueue(SqQueue*& q,char &e);
int main()
{
	SqQueue *q;
	int i,n1,n2,len1,len2;
	char ch;
	
	InitQueue(q);
	
	scanf("%d",&n1);
	char ch1[n1];
	for( i = 0; i < n1; i++){
		scanf(" %c",&ch1[i]);
	}
	
	scanf("%d",&n2);
	char ch2[n2];
	for( i = 0; i < n2; i++){
		scanf(" %c",&ch2[i]);
	}
	
	printf(QueueEmpty(q)?"yes\n":"no\n");
	
	for( i = 0; i < n1; i++)
		enQueue(q,ch1[i]);
	
	deQueue(q,ch);
	
	len1 = 0;
	for( i = q->front; i != q->rear; i = (i+1) % MaxSize)
		len1++;
	
	for( i = 0; i < n2; i++)
		enQueue(q,ch2[i]);
	
	len2 = 0;
	for( i = q->front; i != q->rear; i = (i+1) % MaxSize)
		len2++;
	
	
	printf("%c\n",ch);
	
	printf("%d\n%d\n",len1,len2);
	
	while(!QueueEmpty(q)){
		deQueue(q,ch);
		printf("%c ",ch);
	}
	
	DestroyQueue(q);
}
void InitQueue(SqQueue*& q)
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
}
void DestroyQueue(SqQueue*& q)
{
	free(q);
}
bool QueueEmpty(SqQueue* q)
{
	return(q->front == q->rear);
}
bool enQueue(SqQueue*& q,char e)
{
	if((q->rear + 1) % MaxSize == q->front)
		return false;
	q->rear = (q->rear + 1) % MaxSize;
	q->data[q->rear] = e;
	return true;
}
bool deQueue(SqQueue*& q,char &e)
{
	if( q->front == q->rear)
		return false;
	q->front = (q->front + 1) % MaxSize;
	e = q->data[q->front];
	return true;
}
