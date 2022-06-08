/*
 PIC 10B Lecture 1, Homework 6
 Purpose: HW6, TreeIterator header file
 Author: Lance Anthony Aquino
 Date: 06/07/2022
*/

#ifndef __T_ITERATOR__
#define __T_ITERATOR__

#include "TreeNode.h"
#include "BinarySearchTree.h"

class TreeNode;
class BinarySearchTree;
class TreeIterator{
    
public:
    
    TreeIterator();
    
private:
    
    friend class BinarySearchTree;
    TreeNode* position;
    const BinarySearchTree* container;
    
};

#endif /* __T_ITERATOR__ */
