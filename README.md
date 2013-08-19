DataStructure
=============

Implement the major data structures

[SList.h/Slist.c]
  
  Implement singly linked list, which is including following functions:

  SList_t *SL_add_tail(SList_t **, int);
  SList_t *SL_add(SList_t **, int);
  int SL_delete(SList_t **, int);
  void SL_print(SList_t *); 
  int SL_size(SList_t *); 
  void SL_destroy(SList_t **);
  int SL_find(SList_t *, int);
  
  <test case>
    1. find element in list
    2. insert new element to end
    3. insert new element to head
    4. delete element from list
    5. destroy list
    6. create list

[CStack.h/CStack.c]

  Implement an integer stack strucures, which is including following functions:
  
  CStack_t *CS_push(CStack_t **stack, int value);
  CStack_t *CS_pop(CStack_t **stack);
  CStack_t *CS_top(CStack_t *stack);
  int CS_destroy(CStack_t **stack);
  int CS_size(CStack_t *stack);
  void CS_print(CStack_t *stack);
  
   <test case>
    1. Create by size
    2. push element into stack
    3. pop element from stack
    4. get the top element of stack
    5. destroy stack
    6. print stack
    
[VStack.h/VStack.c]

  Implement a void * pointer stack strucure, which is including following functions:
  
  void VS_push(VStack_t **stack, void *data);
  void *VS_pop(VStack_t **stack);
  void *VS_top(VStack_t *stack);
  int VS_destroy(VStack_t **stack);
  int VS_size(VStack_t *stack);
  int is_empty(VStack_t *stack);
  
[BTree.h/BTree.c]

  Implement a binary tree structure, which is including following functions:
  
  BinaryNode_t *BN_insert(BinaryNode_t **root, int value);
  int BN_delete(BinaryNode_t **root, int value);
  BinaryNode_t *BN_search(BinaryNode_t *root, int value);
  void BN_destroy(BinaryNode_t **root);
  /* use stack as supplementary tools to ergodic binary tree */
  void BN_prev_print(BinaryNode_t *root);
  void BN_post_print(BinaryNode_t *root);
  void BN_mid_print(BinaryNode_t *root);
  /* recursively call functions to ergodic binary tree */
  void BN_prev_print_r(BinaryNode_t *root, char flag, int step);
  void BN_post_print_r(BinaryNode_t *root, char flag, int step);
  void BN_post_print_r(BinaryNode_t *root, char flag, int step);
  
  <test case>
    1. Create Binary tree by size
    2. Insert element into binary tree
    3. Delete element from binary tree
    4. print binary tree in prev order recursively
    5. print binary tree in mid order recursively
    6. print binary tree in post order recursively
    7. print binary tree in prev order by stack
    8. print binary tree in mid order by stack
    9. print binary tree in post order by stack
    10.Destroy binary tree\n");
