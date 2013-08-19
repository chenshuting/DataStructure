/*
 * =====================================================================================
 *
 *       Filename:  BTree.c
 *
 *    Description: Implement the functions 
 *
 *        Version:  1.0
 *        Created:  08/19/2013 04:25:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */

#include "BTree.h"
#include "VStack.h"

#include <stdio.h>
#include <malloc.h>

/* *
 * Insert node to binary tree
 * */
BinaryNode_t *BN_insert(BinaryNode_t **root, int value)
{
	//Create and Initialize binary node
	BinaryNode_t *node = (BinaryNode_t *)malloc(sizeof(BinaryNode_t));
	node->value = value;
	node->left = NULL;
	node->right = NULL;

	if (root == NULL || *root == NULL) {
		//The tree is NULL
		*root = node;
	} else {
		BinaryNode_t *pos = *root;
		while (1){
			if (pos->value < value) {
				//Insert to the right
				if (pos->right != NULL) {
					pos = pos->right;
				} else {
					pos->right = node;
					break;
				}
			} else {
				//Insert to the left 
				if (pos->left != NULL) {
					pos = pos->left;
				} else {
					pos->left = node;
					break;
				}
			}
		}
	}

	return node;
}

/* *
 * Delete node from binary tree
 * */
int BN_delete(BinaryNode_t **root, int value)
{
	BinaryNode_t *parent = NULL, *pos = *root;
	BinaryNode_t *left = NULL, *right = NULL;
	int ret = 0;

	if (root == NULL || *root == NULL)
		return ret;

	while (pos != NULL) {
		if (pos->value < value) {
			parent = pos;
			pos = pos->right;
		} else if (pos->value > value) {
			parent = pos;
			pos = pos->left;
		} else {
			//Find node
			ret = 1;
			left = pos->left;
			right = pos->right;
			if (parent == NULL) {
				//delete root node
				if (left != NULL) {
					*root = left;
					while (left->right!= NULL)
						left = left->right;
					left->right = right;
				} else if (right != NULL){
					*root = right;
					while (right->left!= NULL)
						right = right->left;
					right->left = left;
				} else {
					//Only has one node in binary tree
					*root = NULL;
				}
			} else if (parent->left == pos) {
				if(right != NULL) {
					parent->left = right;
					while(right->left != NULL)
						right = right->left;
					right->left = left;
				} else {
					parent->left = left;
				}
			} else if (parent->right == pos) {
				if (left != NULL) {
					parent->right = left;
					while (left->right != NULL) 
						left = left->right;
					left->right = right;
				} else {
					parent->right = right;
				}
			}
			break;
		}
	}

	if (ret) {
		printf("Binary nodei[%d] is find!\n", value);	
		free(pos);
	} else {
		printf("Binary nodei[%d] is not find!\n", value);	
	}
	return ret;
}

/* *
 * Search node from Binary Tree
 * */
BinaryNode_t *BN_search(BinaryNode_t *root, int value)
{
	if (root == NULL) {
		printf("The binary tree is NULL\n");
		return NULL;
	}
	
	BinaryNode_t *node = root;
	int flag = 0;

	while (node->left != NULL || node->right != NULL) {
		if (node->value == value) {
			flag = 1;
			break;
		} else if (node->value < value) {
			node = node->right;
		} else {
			node = node->left;
		}
	}
	
	if (flag)
		node = NULL;

	return node;
}

/* *
 * Destroy binary tree
 * */
void BN_destroy(BinaryNode_t **root)
{
	if (root == NULL || *root == NULL)
		return;

	BN_destroy(&(*root)->left);	
	BN_destroy(&(*root)->right);	

	//Delete when is leaf node
	BinaryNode_t *node = *root;
	if ((*root)->left == NULL && (*root)->right == NULL) {
		free(node);
		*root = NULL;
	}
}

/* *
 * print binary tree in prev order
 * */
void BN_prev_print_r(BinaryNode_t *root, char flag, int parent)
{
	if (root == NULL)
		return;
	
	int cnt = 0;
	while(cnt < parent) {
		printf("\t");
		cnt++;
	}

	printf("%d %c:%d\n", parent, flag, root->value);
	BN_post_print_r(root->left, 'L', parent + 1);
	BN_post_print_r(root->right,'R', parent + 1);
}

/* *
 * print binary tree in post order
 * */
void BN_post_print_r(BinaryNode_t *root, char flag, int parent)
{
	if (root == NULL)
		return;
	
	int cnt = 0;

	BN_post_print_r(root->left, 'L', parent + 1);
	BN_post_print_r(root->right, 'R', parent + 1);

	while(cnt < parent) {
		printf("\t");
		cnt++;
	}

	printf("%d %c:%d\n", parent, flag, root->value);

}

/* *
 * print binary tree in middle order
 * */
void BN_mid_print_r(BinaryNode_t *root, char flag, int parent)
{
	if (root == NULL)
		return;
	
	int cnt = 0;

	BN_post_print_r(root->left, 'L', parent + 1);

	while(cnt < parent) {
		printf("\t");
		cnt++;
	}
	printf("%d %c:%d\n", parent, flag, root->value);

	BN_post_print_r(root->right, 'R', parent + 1);

}

/* *
 * Previous order print tree
 * */
void BN_prev_print(BinaryNode_t *root)
{
	VStack_t *stack = NULL;	
	BinaryNode_t *pos = root;
	
	printf("++++++++++ Previous order ++++++++++++\n");

	if (root == NULL) {
		printf("The binary tree is NULL!\n");
		return;
	}

	VS_push(&stack, pos);

	while(!is_empty(stack)){
		pos = (BinaryNode_t *)VS_pop(&stack);

		printf("%d ", pos->value);

		if (pos->right != NULL)
			VS_push(&stack, pos->right);

		if (pos->left != NULL)
			VS_push(&stack, pos->left);
	}

	printf("\n");

}

/* *
 * Post order print tree
 * Note:
 * 	prev: the previous node which is printed.
 * */
void BN_post_print(BinaryNode_t *root)
{
	
	VStack_t *stack = NULL;	
	BinaryNode_t *pos = root, *prev = NULL;

	printf("++++++++++ Post order ++++++++++++\n");

	if (root == NULL) {
		printf("The binary tree is NULL!\n");
		return;
	}
	
	VS_push(&stack, pos);
	while (!is_empty(stack) || pos) {
		while (pos != NULL) {
			VS_push(&stack, pos);
			pos = pos->left;
		}

		pos = (BinaryNode_t *)VS_top(stack);
		if (pos->right == NULL || pos->right == prev){
			printf("%d ", pos->value);
			VS_pop(&stack);
			prev = pos;
			pos = NULL;
		} else {
			pos = pos->right;
		}
	}
	printf("\n");
}

/* *
 * Middle order print tree
 * */
void BN_mid_print(BinaryNode_t *root)
{
	
	VStack_t *stack = NULL;	
	BinaryNode_t *pos = root;

	printf("++++++++++ Middle order ++++++++++++\n");

	if (root == NULL) {
		printf("The binary tree is NULL!\n");
		return;
	}

	while (pos || !is_empty(stack)) {
		while (pos) {
			VS_push(&stack, pos);
			pos = pos->left;
		}

		pos = (BinaryNode_t *)VS_pop(&stack);
		printf("%d ", pos->value);

		pos = pos->right;
	}
	printf("\n");
}
