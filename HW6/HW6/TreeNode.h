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
    
    /**
     Helper function for removing a node from the tree.
     */
    bool erase_helper (int removed_num);
    
    /**
     Helper function for changing either the parent's left or right node, based on the child passed, with the second node that gets promoted up the tree as a result. This method sould only be used on a given parent node
     
     @param child_node  a child node to be replaced, based on the second arg
     @param replacement_node a node that replaces the child node
     */
    void change_child (TreeNode* child_node, TreeNode* replacement_node);
    
    TreeNode* find_helper(int searched_value);
    
private:
    
    friend class BinarySearchTree;
    friend class TreeIterator;
    
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode* parent; // pointer to the parent node of a given node. Should be nullptr for the root
    
};

#endif /* __TREENODE__ */
