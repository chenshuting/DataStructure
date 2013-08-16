/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  Implement the unit test
 *
 *        Version:  1.0
 *        Created:  08/16/2013 04:56:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <math.h>
#include <time.h>

#include "test.h"
#include "SList.h"

void print_choice()
{
	printf("Choice to run test unit!\n");	
	printf("%d. SList test\n", SLIST);
	printf("0. quit unit test\n");
}

void _SList_print()
{
	printf("Choice to operate list:\n");
	printf("1. find element in list\n");
	printf("2. insert new element to end\n");
	printf("3. insert new element to head\n");
	printf("4. delete element from list\n");
	printf("5. destroy list\n");
	printf("6. create list\n");
	printf("0. Quit test SList\n");
}

void SList_test()
{
	SList_t *head = NULL;
	int list_size = 0, num = 0, i = 0, choice = 0;
	printf("----------------SList test----------------\n");	
	_SList_print();
	do {	
		printf("Enter to choose operations:>");
		scanf("%d", &choice);
		if (choice == 0)
			break;
		switch(choice){
		case 1:
			{
				printf("Enter num to find:>");
				scanf("%d", &num);
				int ret = SL_find(head, num); 
				if (ret)
					printf("Find num:%d\n", num);
				else	
					printf("Not find num:%d\n", num);
			}
			break;
		case 2:
			{
				printf("Enter num to insert to end:>");
				scanf("%d", &num);
				SL_add_tail(&head, num); 
				SL_print(head);
			}
			break;
		case 3:
			{
				printf("Enter num to insert to end:>");
				scanf("%d", &num);
				SL_add(&head, num); 
				SL_print(head);
			}
			break;
		case 4:
			{
				SL_print(head);
				printf("Enter num to delete element:>");
				scanf("%d", &num);
				SL_delete(&head, num); 
				SL_print(head);
			}
			break;
		case 5:
			{
				printf("SList is destroyed!\n");
				SL_destroy(&head);
				SL_print(head);
			}
			break;
		case 6:
			{
				do {
					printf("Enter list size:>");
					scanf("%d", &list_size);
					if (list_size < 0)
						printf("Please enter positive number!\n");
				}while(list_size <= 0);

				printf("Start create list....\n");
				srand((unsigned)time(NULL));
				for (i = 0; i < list_size; i++) {
					num = rand() % 100;			
					SL_add_tail(&head, num);
				}
				SL_print(head);
			}
			break;
		default:
			_SList_print();
			break;
		}
	} while(choice > 0);
	printf("--------------------------------------------------\n\n");
}
