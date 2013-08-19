/*
 * =====================================================================================
 *
 *       Filename:  CStack.c
 *
 *    Description:  implement fuctions
 *
 *        Version:  1.0
 *        Created:  08/16/2013 06:12:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */

#include "CStack.h"

#include <stdio.h>
#include <malloc.h>

CStack_t *CS_push(CStack_t **stack, int value)
{
	CStack_t * new_entry = (CStack_t *)malloc(sizeof(CStack_t));
	new_entry->value = value;
	new_entry->next = *stack;
	*stack = new_entry;

	return new_entry;
}

CStack_t *CS_pop(CStack_t **stack)
{
	if (stack == NULL || *stack == NULL)
		return NULL;
	
	CStack_t *top = *stack;

	*stack = (*stack)->next;
	return top;
}

/* *
 * Get the top element of stack
 * */
CStack_t *CS_top(CStack_t *stack)
{
	if (stack == NULL)
		return NULL;
	
	return stack;
}

/* *
 * Destroy the stack
 * */
int CS_destroy(CStack_t **stack)
{
	if(stack == NULL || *stack == NULL)
		return 0;

	CStack_t * pos = *stack, *next = pos->next;

	while (pos != NULL){
		next = pos->next;
		free(pos);
		pos = next;
	}

	*stack = NULL;
	return 1;
}

/* *
 * Get the size of the stack
 * */
int CS_size(CStack_t *stack)
{
	if (stack == NULL)
		return 0;

	int size = 0;
	CStack_t *pos = stack;
	
	while(pos != NULL){
		size++;
		pos = pos->next;
	}
	return size;
}

/* *
 * Print stack elements 
 * */
void CS_print(CStack_t *stack)
{
	if (stack == NULL)
		printf("The stack is NULL!\n");
	
	CStack_t *pos = stack;
	
	while (pos != NULL) {
		printf("%d ", pos->value);
		pos = pos->next;
	}
	printf("\n");
}
