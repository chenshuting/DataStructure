/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/19/2013 07:07:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */

#include "test.h"
#include <stdio.h>

int main()
{
	int choice = 0;
	printf("Thank you for using data structure module!\n");
	print_choice();

	do{
		printf(">");
		scanf("%d", &choice);
		if(choice == 0)
			break;

		switch(choice) {
		case SLIST:
			SList_test();
			break;
		case CSTACK:
			CStack_test();
			break;
		case BTREE:
			BTree_test();
			break;
		default:
			print_choice();
			break;
		}
	}while(choice != 0);
}
