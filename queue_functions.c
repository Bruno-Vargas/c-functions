#include <stdio.h>


typedef struct 
{
	int val;
	struct Node *next;
} Node;

typedef struct 
{
	struct Node *first;
	struct Node *last;
} Queue;

Queue * queue_create ()
{

	Queue * q = (Queue *) malloc(sizeof (Queue));
	q->first = q->last = NULL;
	return q;
}

void queue_insert (Queue * queue, int value)
{
	Node * n = (Node *) malloc (sizeof(Node));
	n->val = value;
	n->next = NULL; 
	
	if (queue->last != NULL)
	{	Node * aux = queue->last;
		aux->next = n;
	}
	
	queue->last = n;
	if(queue->first == NULL)
	{
		queue->first = n;
	} 
}

int queue_get (Queue * q)
{
	if (q->first == NULL)
	{
		return NULL;
	}

	Node * n = q->first;
	if(n->next == NULL)
	{
		q->last = NULL;
	} else {
		q->first = n->next;
	}

	int  value = n->val;
	free(n);
	return value; 
}
void queue_print(Queue *q)
{
	Node *n;
	for (n = q->first ; n !=NULL ; n=n->next)
	{
		printf("%d\n",n->val);
	}
}

int main () 
{
	Queue * q = queue_create();

	queue_insert(q, 3);
	queue_insert(q, 4);

	queue_print(q);
	printf(" peguei %d  ", queue_get(q));
	queue_print(q);
	return 0;
}