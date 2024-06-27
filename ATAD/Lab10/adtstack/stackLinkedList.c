/**
 * @file stackLinkedList.c
 *
 * @brief Provides an implementation of the ADT Stack with a
 * doubly-linked list with sentinels as the underlying
 * data structure.
 *
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node *PtNode;

typedef struct node
{
    StackElem element; /* element to store at node */
    PtNode next;       /* pointer to next node */
    PtNode prev;       /* pointer to previous node */
} Node;

typedef struct stackImpl
{
    PtNode header;
    PtNode trailer;
    int size;
} StackImpl;

PtStack stackCreate()
{
    PtStack stack = (PtStack)malloc(sizeof(StackImpl));
    if (stack == NULL)
        return NULL;

    stack->header = (PtNode)malloc(sizeof(Node));
    if (stack->header == NULL)
    {
        free(stack);
        return NULL;
    }
    stack->trailer = (PtNode)malloc(sizeof(Node));
    if (stack->trailer == NULL)
    {
        free(stack->header);
        free(stack);
        return NULL;
    }

    stack->header->prev = NULL;
    stack->header->next = stack->trailer;

    stack->trailer->next = NULL;
    stack->trailer->prev = stack->header;

    stack->size = 0;

    return stack;
}

int stackDestroy(PtStack *ptStack)
{
    PtStack stack = (*ptStack);

    if (stack == NULL)
        return STACK_NULL;

    PtNode current = stack->header->next;
    while (current != stack->trailer)
    {
        current = current->next;
        free(current->prev);
    }

    free(stack->header);
    free(stack->trailer);
    free(stack);

    *ptStack = NULL;

    return STACK_OK;
}

int stackPush(PtStack stack, StackElem elem)
{
    if (stack == NULL)
        return STACK_NULL;

    PtNode newNode = (PtNode)malloc(sizeof(Node));
    if (newNode == NULL)
        return STACK_NO_MEMORY;

    PtNode node = stack->header->next;

    newNode->element = elem;
    newNode->prev = stack->header;
    newNode->next = node;

    stack->header->next = newNode;
    node->prev = newNode;

    stack->size++;

    return STACK_OK;
}

int stackPop(PtStack stack, StackElem *ptElem)
{
    if (stack == NULL)
        return STACK_NULL;

    if (stack->size == 0)
        return STACK_EMPTY;

    PtNode top = stack->header->next;

    *ptElem = top->element;

    stack->header->next = top->next;
    top->next->prev = stack->header;

    free(top);

    stack->size--;

    return STACK_OK;
}

int stackPeek(PtStack stack, StackElem *ptElem)
{
    if (stack == NULL)
        return STACK_NULL;

    if (stack->size == 0)
        return STACK_EMPTY;

    *ptElem = stack->header->next->element;

    return STACK_OK;
}

int stackSize(PtStack stack, int *ptSize)
{
    if (stack == NULL)
        return STACK_NULL;

    *ptSize = stack->size;

    return STACK_OK;
}

bool stackIsEmpty(PtStack stack)
{
    if (stack == NULL)
        return true;

    return (stack->size == 0);
}

int stackClear(PtStack stack)
{
    if (stack == NULL)
        return STACK_NULL;

    PtNode current = stack->header->next;
    while (current != stack->trailer)
    {
        current = current->next;
        free(current->prev);
    }

    stack->header->next = stack->trailer;
    stack->trailer->prev = stack->header;

    stack->size = 0;

    return STACK_OK;
}

void stackPrint(PtStack stack)
{
    if (stack == NULL)
    {
        printf("(Stack NULL)");
    }
    else if (stack->size == 0)
    {
        printf("(Stack Empty)");
    }
    else
    {
        printf("Stack contents (top to bottom): \n");

        PtNode currentNode = stack->header->next;
        while (currentNode != stack->trailer)
        {
            stackElemPrint(currentNode->element);
            currentNode = currentNode->next;
        }

        printf("--- bottom --- \n");
    }
    printf("\n");
}
