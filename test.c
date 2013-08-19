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
#include "CStack.h"
#include "BTree.h"

void print_choice()
{
	printf("Choice to run test unit!\n");	
	printf("%d. SList test\n", SLIST);
	printf("%d. CStack test\n", CSTACK);
	printf("%d. BTree test\n", BTREE);
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

void _CStack_print()
{
	printf("Choice to operate stack:\n");
	printf("1. Create size\n");
	printf("2. push element into stack\n");
	printf("3. pop element from stack\n");
	printf("4. get the top element of stack\n");
	printf("5. destroy stack\n");
	printf("6. print stack\n");
	printf("0. Quit test CStack\n");
}

void CStack_test()
{
	CStack_t *stack = NULL, *pos = NULL;
	int stack_size = 0, num = 0, i = 0, choice = 0;
	printf("----------------CStack test----------------\n");	
	_CStack_print();

	do {	
		printf("Enter to choose operations:>");
		scanf("%d", &choice);
		if (choice == 0)
			break;
		switch(choice){
		case 1:
			printf("Create stack by size\n");
			do{
				printf("Enter stack size:>");
				scanf("%d", &stack_size);
			}while(stack_size <= 0);

			srand((unsigned)time(NULL));
			for (i = 0; i < stack_size; i++) {
				num = rand() % 100;
				CS_push(&stack, num);
			}
			CS_print(stack);
			break;
		case 2:
			printf("Enter stack element:>");
			scanf("%d", &num);
			CS_push(&stack, num);
			CS_print(stack);
			break;
		case 3:
			printf("Pop stack\n");
			pos = CS_pop(&stack);
			printf("The pop element is %d\n", pos->value);
			CS_print(stack);
			break;
		case 4:
			printf("Top of stack\n");
			pos = CS_top(stack);
			printf("The top element is %d\n", pos->value);
			CS_print(stack);
			break;
		case 5:
			printf("Desctroy the stack\n");
			CS_destroy(&stack);
			CS_print(stack);
			break;
		case 6:
			CS_print(stack);
			break;
		default:
			_CStack_print(stack);
			break;
		}
	}while(choice != 0);	
	printf("-------------------------------------------\n");
}

void _Btree_print()
{
	printf("Operate Binary Tree\n");		
	printf("1. Create Binary tree by size\n");
	printf("2. Insert element into binary tree\n");
	printf("3. Delete element from binary tree\n");
	printf("4. print binary tree in prev order recursively\n");
	printf("5. print binary tree in mid order recursively\n");
	printf("6. print binary tree in post order recursively\n");
	printf("7. print binary tree in prev order by stack\n");
	printf("8. print binary tree in mid order by stack\n");
	printf("9. print binary tree in post order by stack\n");
	printf("10.Destroy binary tree\n");
	printf("0. Quit Binary Tree test\n");
}

void BTree_test()
{
	BinaryNode_t *root = NULL, *pos = NULL;
	int bt_size = 0, num = 0, i = 0, choice = 0;
	printf("----------------Btree test----------------\n");	
	_Btree_print();	

	do {	
		printf("Enter to choose operations:>");
		scanf("%d", &choice);
		if (choice == 0)
			break;
		switch(choice){
		case 1:
			printf("Create binary tree by size\n");
			do{
				printf("Enter binary tree size:>");
				scanf("%d", &bt_size);
			}while(bt_size <= 0);

			srand((unsigned)time(NULL));
			for (i = 0; i < bt_size; i++) {
				num = rand() % 100;
				BN_insert(&root, num);
			}
			break;
		case 2:
			printf("Enter element num and insert to BT:>");
			scanf("%d", &num);
			BN_insert(&root, num);
			break;
		case 3:
			printf("Enter element num and delete from BT:>");
			scanf("%d", &num);
			BN_delete(&root, num);
			break;
		case 4:
			printf("Previous Order:\n");
			BN_prev_print_r(root, 'T', 0);
			break;
		case 5:
			printf("Middle Order:\n");
			BN_mid_print_r(root, 'T', 0);
			break;
		case 6:
			printf("Post Order:\n");
			BN_post_print_r(root, 'T', 0);
			break;
		case 7:
			printf("Previous Order use stack:\n");
			BN_prev_print(root);
			break;
		case 8:
			printf("Middle Order use stack:\n");
			BN_mid_print(root);
			break;
		case 9:
			printf("Post Order use stack:\n");
			BN_post_print(root);
			break;
		case 10:
			printf("Binary tree is destoyed!\n");
			BN_destroy(&root);
			break;
		default:
			_Btree_print();
			break;
		}
	}while(choice != 0);	
	printf("-------------------------------------------\n");
}
