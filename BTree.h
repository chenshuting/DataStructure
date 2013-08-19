/*
 * =====================================================================================
 *
 *       Filename:  BTree.h
 *
 *    Description:  Define the binary tree operations
 *
 *        Version:  1.0
 *        Created:  08/19/2013 04:19:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */

typedef struct BinaryNode {
	int value;
	struct BinaryNode *left;
	struct BinaryNode *right;
}BinaryNode_t;

BinaryNode_t *BN_insert(BinaryNode_t **root, int value);

int BN_delete(BinaryNode_t **root, int value);

BinaryNode_t *BN_search(BinaryNode_t *root, int value);

void BN_destroy(BinaryNode_t **root);

void BN_prev_print_r(BinaryNode_t *root, char flag, int step);

void BN_prev_print(BinaryNode_t *root);

void BN_post_print(BinaryNode_t *root);

void BN_post_print_r(BinaryNode_t *root, char flag, int step);

void BN_mid_print(BinaryNode_t *root);

void BN_post_print_r(BinaryNode_t *root, char flag, int step);

