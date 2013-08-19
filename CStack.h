/*
 * =====================================================================================
 *
 *       Filename:  CStack.h
 *
 *    Description:  define stack operations
 *
 *        Version:  1.0
 *        Created:  08/16/2013 06:05:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */

typedef struct CStack{
	int value;
	struct CStack *next;
}CStack_t;

CStack_t *CS_push(CStack_t **stack, int value);

CStack_t *CS_pop(CStack_t **stack);

CStack_t *CS_top(CStack_t *stack);

int CS_destroy(CStack_t **stack);

int CS_size(CStack_t *stack);

void CS_print(CStack_t *stack);
