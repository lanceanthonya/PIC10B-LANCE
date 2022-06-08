/*
 PIC 10B Lecture 1, Homework 6
 Purpose: HW6, TreeNode header file
 Author: Lance Anthony Aquino
 Date: 06/07/2022
*/

#ifndef __TREENODE__
#define __TREENODE__

#include "BinarySearchTree.h"
#include "TreeIterator.h"

class TreeNode
{
public:
    
    TreeNode();
    
    TreeNode(int _val);
    
    int get_val() const;
    
    void prnt_incr_helper() const;
    
    void prnt_decr_helper() const;
    
private:
    
    friend class BinarySearchTree;
    friend class TreeIterator;
    
    int val;
    TreeNode* right;
    TreeNode* left;
    
    
};

#endif /* __TREENODE__ */
