/*
 PIC 10B Lecture 1, Homework 6
 Purpose: HW6, BinarySearchTree header file
 Author: Lance Anthony Aquino
 Date: 06/07/2022
*/

#ifndef __BSEARCHTREE__
#define __BSEARCHTREE__

#include "TreeNode.h"

class TreeNode; // forward declaration of TreeNode to eliminate circular dependency
class BinarySearchTree
{
public:
    BinarySearchTree();
    
    BinarySearchTree(int value);
        
private:
    
    TreeNode* root;
    int size;

};

#endif /* __BSEARCHTREE__ */
