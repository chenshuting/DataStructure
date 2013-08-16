/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  The main interface of data structure test
 *
 *        Version:  1.0
 *        Created:  08/16/2013 04:47:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */

#include <stdio.h>
#include "SList.h"
#include "test.h"


int main()
{
	int choice = 0;
	
	print_choice();
	do{
		printf(">");
		scanf("%d", &choice);
		switch(choice) {
		case SLIST:
			SList_test();
			break;
		default:
			print_choice();
			break;
		}
	}while(choice != 0);
	return 0;
}
