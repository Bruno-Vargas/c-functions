#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int val;
	int priority;
	struct Node *next;
} Node;

typedef struct 
{
	struct Node *first;
	struct Node *last;
} Queue;

Queue * priority_queue_create ()
{

	Queue * q = (Queue *) malloc(sizeof (Queue));
	q->first = q->last = NULL;
	return q;
}

int priority_queue_get (Queue * q)
{
	if (q->first == NULL)
	{
		return NULL;
	}
	Node * n = q->first;
	q->first = n->next;
	
	int  value = n->val;
	free(n);
	return value; 
}

void priority_queue_print(Queue *q)
{
	Node *n;
	for (n = q->first ; n !=NULL ; n=n->next)
	{
		printf("%d - %d\n",n->val, n->priority);
	}
}



void priority_queue_insert (Queue * queue, int value, int priority)
{
	Node * aux, *aux2, *n = (Node *) malloc (sizeof(Node));

	n->val = value;
	n->priority = priority;
	n->next = NULL;
	aux = queue->first;
	if (queue->first == NULL || aux->priority <= priority)
	{
		n->next = queue->first;
		queue->first = n;

	}else {
		aux2 = aux ;
		while (aux != NULL  && aux->priority >= priority)
		{
			aux2 = aux;
			aux= aux->next;
		}
		n->next = aux;
		aux2->next = n;
	} 
}

int main () 
{
	Queue * q = priority_queue_create();

	priority_queue_insert(q, 3, 3);
	priority_queue_print(q);
printf("sai\n");
	priority_queue_insert(q, 4, 5);

	priority_queue_print(q);
	printf("sai\n");
	priority_queue_insert(q, 4, 5);
	priority_queue_print(q);
printf("sai\n");
	priority_queue_insert(q, 1, 2);

	priority_queue_print(q);
	printf("sai\n");
	printf(" peguei %d  \n", priority_queue_get(q));
	priority_queue_print(q);
	return 0;
}