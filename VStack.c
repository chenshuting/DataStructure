/*
 * =====================================================================================
 *
 *       Filename:  CStack.c
 *
 *    Description:  implement fuctions
 *
 *        Version:  1.0
 *        Created:  08/19/2013 06:35:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */

#include "VStack.h"
#include "BTree.h"

#include <stdio.h>
#include <malloc.h>

void VS_push(VStack_t **stack,void * data)
{
	VStack_t * new_entry = (VStack_t *)malloc(sizeof(VStack_t));
	new_entry->data = data;
	new_entry->next = *stack;
	*stack = new_entry;
}

void *VS_pop(VStack_t **stack)
{
	if (stack == NULL || *stack == NULL)
		return NULL;
	
	VStack_t *top = *stack;
	void *data = (void *)top->data;
	free(top);
	top = NULL;

	*stack = (*stack)->next;
	return data;
}

/* *
 * Get the top element of stack
 * */
void *VS_top(VStack_t *stack)
{
	if (stack == NULL)
		return NULL;
	
	return stack->data;
}

/* *
 * Destroy the stack
 * */
int VS_destroy(VStack_t **stack)
{
	if(stack == NULL || *stack == NULL)
		return 0;

	VStack_t * pos = *stack, *next = pos->next;

	while (pos != NULL){
		next = pos->next;
		if (pos->data != NULL) {
			free(pos->data);
			pos->data = NULL;
		}
		free(pos);
		pos = next;
	}

	*stack = NULL;
	return 1;
}

/* *
 * Get the size of the stack
 * */
int VS_size(VStack_t *stack)
{
	if (stack == NULL)
		return 0;

	int size = 0;
	VStack_t *pos = stack;
	
	while(pos != NULL){
		size++;
		pos = pos->next;
	}
	return size;
}

/* *
 * Check if stack is empty
 * */
int is_empty(VStack_t *stack)
{
	if (stack == NULL)
		return 1;
	return 0;
}
