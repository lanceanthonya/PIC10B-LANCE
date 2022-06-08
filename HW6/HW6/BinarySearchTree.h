/*
 PIC 10B Lecture 1, Homework 6
 Purpose: HW6, BinarySearchTree header file
 Author: Lance Anthony Aquino
 Date: 06/07/2022
*/

#ifndef __BSEARCHTREE__
#define __BSEARCHTREE__

#include "TreeNode.h"
#include "TreeIterator.h"

class TreeNode; // forward declaration of TreeNode to eliminate circular dependency
class BinarySearchTree
{
public:
    BinarySearchTree();
    
    BinarySearchTree(int value);
    
    ~BinarySearchTree();
    
    void tree_des_helper(TreeNode* current_node);
    
    TreeNode* get_root() const;
    
    void insert(int new_val);
    
    void erase(int value_to_erase);
    
    void print_increasing() const;
    
    void print_decreasing() const; 
    
        
private:
    
    TreeNode* root;
    int size;

};

#endif /* __BSEARCHTREE__ */
