/*
 * =====================================================================================
 *
 *       Filename:  Slist.h
 *
 *    Description:  define the operations of singly linked list
 *
 *        Version:  1.0
 *        Created:  08/16/2013 03:54:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */

typedef struct SList{
	int value;
	struct SList *next;
}SList_t;

SList_t *SL_add_tail(SList_t **, int);

SList_t *SL_add(SList_t **, int);

int SL_delete(SList_t **, int);

void SL_print(SList_t *);

int SL_size(SList_t *);

void SL_destroy(SList_t **);

int SL_find(SList_t *, int);
