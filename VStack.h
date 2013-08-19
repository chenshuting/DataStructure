/*
 * =====================================================================================
 *
 *       Filename:  CStack.h
 *
 *    Description:  define stack operations
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

typedef struct VStack{
	void * data;
	struct VStack *next;
}VStack_t;

void VS_push(VStack_t **stack, void *data);

void *VS_pop(VStack_t **stack);

void *VS_top(VStack_t *stack);

int VS_destroy(VStack_t **stack);

int VS_size(VStack_t *stack);

int is_empty(VStack_t *stack);
