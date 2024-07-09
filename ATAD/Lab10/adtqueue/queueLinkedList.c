/**
 * @file queueLinkedList.c
 *
 * @brief Provides an implementation of the ADT Queue with a
 * doubly-linked list with sentinels as the underlying
 * data structure.
 *
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node *PtNode;

typedef struct node
{
	QueueElem element;
	PtNode prev;
	PtNode next;
} Node;

typedef struct queueImpl
{
	PtNode header;
	PtNode trailer;
	int size;
} QueueImpl;

PtQueue queueCreate()
{
	PtQueue queue = (PtQueue)malloc(sizeof(QueueImpl));
	if (queue == NULL)
		return NULL;

	queue->header = (PtNode)malloc(sizeof(Node));
	if (queue->header == NULL)
	{
		free(queue);
		return NULL;
	}

	queue->trailer = (PtNode)malloc(sizeof(Node));
	if (queue->trailer == NULL)
	{
		free(queue->header);
		free(queue);
		return NULL;
	}

	queue->header->prev = NULL;
	queue->header->next = queue->trailer;

	queue->trailer->prev = queue->header;
	queue->trailer->next = NULL;

	queue->size = 0;

	return queue;
}

int queueDestroy(PtQueue *ptQueue)
{
	PtQueue queue = (*ptQueue);
	if (queue == NULL)
		return QUEUE_NULL;

	PtNode currentNode = queue->header->next;
	while (currentNode != queue->trailer)
	{
		free(currentNode);
		currentNode = currentNode->next;
	}

	free(queue->header);
	free(queue->trailer);
	free(queue);

	*ptQueue = NULL;

	return QUEUE_OK;
}

int queueEnqueue(PtQueue queue, QueueElem elem)
{
	if (queue == NULL)
		return QUEUE_NULL;

	PtNode newNode = (PtNode)malloc(sizeof(Node));
	if (newNode == NULL)
		return QUEUE_NO_MEMORY;

	PtNode node = queue->trailer->prev;

	newNode->element = elem;
	newNode->next = queue->trailer;
	newNode->prev = node;

	node->next = newNode;
	queue->trailer->prev = newNode;

	queue->size++;

	return QUEUE_OK;
}

int queueDequeue(PtQueue queue, QueueElem *ptElem)
{
	if (queue == NULL)
		return QUEUE_NULL;

	if (queueIsEmpty(queue))
		return QUEUE_EMPTY;

	PtNode front = queue->header->next;
	PtNode newFront = front->next;

	*ptElem = front->element;

	queue->header->next = newFront;
	newFront->prev = queue->header;

	free(front);

	queue->size--;

	return QUEUE_OK;
}

int queueFront(PtQueue queue, QueueElem *ptElem)
{
	if (queue == NULL)
		return QUEUE_NULL;

	*ptElem = queue->header->next->element;

	return QUEUE_OK;
}

int queueSize(PtQueue queue, int *ptSize)
{
	if (queue == NULL)
		return QUEUE_NULL;

	*ptSize = queue->size;

	return QUEUE_OK;
}

bool queueIsEmpty(PtQueue queue)
{
	if (queue == NULL || queue->size == 0)
		return true;

	return false;
}

int queueClear(PtQueue queue)
{
	if (queue == NULL)
		return QUEUE_NULL;

	QueueElem elem;
	while (!queueIsEmpty(queue))
	{
		queueDequeue(queue, &elem);
	}

	return QUEUE_OK;
}

void queuePrint(PtQueue queue)
{
	if (queue == NULL)
	{
		printf("(Queue NULL) \n");
	}
	else if (queue->header->next == queue->trailer)
	{
		printf("(Queue Empty) \n");
	}
	else
	{
		printf("Queue contents (front to end): \n");
		PtNode current = queue->header->next;
		while (current != queue->trailer)
		{
			queueElemPrint(current->element);
			printf(" ");
			current = current->next;
		}
		printf("\n------------------------------ \n");
	}
}
