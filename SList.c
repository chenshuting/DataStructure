/*
 * =====================================================================================
 *
 *       Filename:  SList.c
 *
 *    Description:  implemente the operations of singly linked list
 *
 *        Version:  1.0
 *        Created:  08/16/2013 04:01:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */

#include "SList.h"
#include <malloc.h>

/* *
 * Insert a new entry with value data to the end of the list 
 * */
SList_t *SL_add_tail(SList_t **head, int data)
{
	SList_t *new_entry = (SList_t *)malloc(sizeof(SList_t));
	new_entry->value = data;
	new_entry->next = NULL;

	if ( head == NULL || *head == NULL){
		*head = new_entry;
	} else {
		SList_t *pos = *head;
		while(pos->next != NULL) {
			pos = pos->next;
		}
		pos->next = new_entry;
	}

	return new_entry;
}

/* *
 * Insert a new entry with value data after head
 * */
SList_t *SL_add(SList_t **head, int data)
{
	SList_t *new_entry = (SList_t *)malloc(sizeof(SList_t));
	new_entry->value = data;
	new_entry->next = *head;

	*head = new_entry;
	return new_entry;
}

/* *
 * delete an entry with value data
 * return:
 * 	0: not find;
 * 	1: find and delete
 * */
int SL_delete(SList_t **head, int data)
{
	SList_t *pos = *head, *prev = *head;
	int result = 0;

	while(pos != NULL) {
		
		if (pos->value == data) {
			if (pos == prev) {
				//Delete head
				*head = pos->next;
				free(pos);
				pos = NULL;
				result = 1;
				break;
			}
		}
		prev = pos;
		pos = pos->next;
	}

	return result;
}

/* *
 * Print SList
 * */
void SL_print(SList_t *head)
{
	if (head == NULL){
		printf("SList is NULL\n");
		return;
	}
	
	SList_t *pos = head;
	printf("Print SList>:\n");
	while (pos != NULL) {
		printf("%d ", pos->value);
		pos = pos->next;
	}
	printf("\n");
}

/* *
 * Get the size of SList
 * */
int SL_size(SList_t *head) {
	int ret = 0;
	SList_t *pos = head;

	while(pos != NULL) {
		ret++;
		pos = pos->next;
	}

	return ret;
}

/* *
 * destroy the SList
 * */
void SL_destroy(SList_t **head)
{
	if(head == NULL || *head == NULL)
		return;

	SList_t *pos = *head, *next = pos;

	while( pos != NULL) {
		next = pos->next;
		pos->next = NULL;
		free(pos);
		pos = next;
	}
	*head = NULL;
}

/* *
 * Check if data is in SList
 * return:
 * 	0: not find
 * 	1: find
 * */
int SL_find(SList_t *head, int data)
{
	int ret = 0;
	SList_t *pos = head;

	while (pos != NULL) {
		if (pos->value == data) {
			ret = 1;
			break;
		}
		pos = pos->next;
	}

	return ret;
}
