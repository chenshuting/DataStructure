DataStructure
=============
Implement the major data structures

#SList.h/Slist.c
  
  <p>Implement singly linked list, which is including following functions:</p>
  
  <ul>
  <li>SList_t *SL_add_tail(SList_t **, int);
  <li>SList_t *SL_add(SList_t **, int);
  <li>int SL_delete(SList_t **, int);
  <li>void SL_print(SList_t *); 
  <li>int SL_size(SList_t *); 
  <li>void SL_destroy(SList_t **);
  <li>int SL_find(SList_t *, int);
  </ul>
  
  ##test case
  <ol>
    <li>find element in list</li>
    <li>insert new element to end</li>
    <li>insert new element to head</li>
    <li>delete element from list</li>
    <li>destroy list</li>
    <li>create list</li>
  <ol>
  
#CStack.h/CStack.c

  <p>Implement an integer stack strucures, which is including following functions:</p>
  
  <ul>
  <li>CStack_t *CS_push(CStack_t **stack, int value);</li>
  <li>CStack_t *CS_pop(CStack_t **stack);</li>
  <li>CStack_t *CS_top(CStack_t *stack);</li>
  <li>int CS_destroy(CStack_t **stack);</li>
  <li>int CS_size(CStack_t *stack);</li>
  <li>void CS_print(CStack_t *stack);</li>
  </ul>
  
   ##test case
    <ol>
    <li>Create by size</li>
    <li>push element into stack</li>
    <li>pop element from stack</li>
    <li>get the top element of stack</li>
    <li>destroy stack</li>
    <li>print stack</li>
    </ol>
    
#VStack.h/VStack.c

 <p>Implement a void * pointer stack strucure, which is including following functions:</p>
  
  <ul>
  <li>void VS_push(VStack_t **stack, void *data);</li>
  <li>void *VS_pop(VStack_t **stack);</li>
  <li>void *VS_top(VStack_t *stack);</li>
  <li>int VS_destroy(VStack_t **stack);</li>
  <li>int VS_size(VStack_t *stack);</li>
  <li>int is_empty(VStack_t *stack);</li>
  </ul>
  
#BTree.h/BTree.c

  <p>Implement a binary tree structure, which is including following functions:</p>
  
  <ul>
  <li>BinaryNode_t *BN_insert(BinaryNode_t **root, int value);</li>
  <li>int BN_delete(BinaryNode_t **root, int value);</li>
  <li>BinaryNode_t *BN_search(BinaryNode_t *root, int value);</li>
  <li>void BN_destroy(BinaryNode_t **root);</li>
  <li>/* use stack as supplementary tools to ergodic binary tree */</li>
  <li>void BN_prev_print(BinaryNode_t *root);</li>
  <li>void BN_post_print(BinaryNode_t *root);</li>
  <li>void BN_mid_print(BinaryNode_t *root);</li>
  <li>/* recursively call functions to ergodic binary tree */</li>
  <li>void BN_prev_print_r(BinaryNode_t *root, char flag, int step);</li>
  <li>void BN_post_print_r(BinaryNode_t *root, char flag, int step);</li>
  <li>void BN_post_print_r(BinaryNode_t *root, char flag, int step);</li>
  </ul>
  
  ##test case
  <ol>
    <li>Create Binary tree by size</li>
    <li>Insert element into binary tree</li>
    <li>Delete element from binary tree</li>
    <li>print binary tree in prev order recursively</li>
    <li>print binary tree in mid order recursively</li>
    <li>print binary tree in post order recursively</li>
    <li>print binary tree in prev order by stack</li>
    <li>print binary tree in mid order by stack</li>
    <li>print binary tree in post order by stack</li>
    <li>Destroy binary tree
  </ol>
