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

/**
 @class TreeNode one node in a binary search tree. Conains an in value at two pointers to two otther nodes on the "left" and "right" of a given node. Also stores the parent node, or the node poiting to a given node
 */
class TreeNode
{
public:
    
    /**
     Default Constructor for TreeNode that initializes left and right as nullptr, and the val as 0
     */
    TreeNode();
    
    /**
      Constructor for TreeNode that initializes left and right as nullptr, and the val as _val
     
     @param _val some into to explicitly set the value of the TreeNode
     */
    TreeNode(int _val);
    
    /**
     Getter functtion for the value stored in the node
     
     @return the value
     */
    int get_val() const;
    
    /**
     Helper function for BinarySearchTree::print_increasing(), that prints nodes in increasing order
     */
    void prnt_incr_helper() const;
    
    /**
     Helper function for BinarySearchTree::print_decreasing(), that prints nodes in decreasing order
     */
    void prnt_decr_helper() const;
    
    /**
     Helper function for adding a new node to the tree
     
     @param new_num an int represeing the val of the new Node to add
    */
    bool insert_helper(int new_num);
    
private:
    
    friend class BinarySearchTree;
    friend class TreeIterator;
    
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode* daddy; // pointer to the parent node of a given node. Should be nullptr for the root
    
};

#endif /* __TREENODE__ */
