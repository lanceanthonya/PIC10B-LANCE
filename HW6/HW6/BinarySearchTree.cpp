/*
 PIC 10B Lecture 1, Homework 6
 Purpose: HW6, BinarySearchTree cpp file
 Author: Lance Anthony Aquino
 Date: 06/07/2022
*/

#include "BinarySearchTree.h"
#include "TreeNode.h"


BinarySearchTree::BinarySearchTree():
    root(nullptr),
    size(0)
{}

BinarySearchTree::BinarySearchTree(int value):
    root(new TreeNode(value)),
    size(1)
{}

TreeNode* BinarySearchTree::get_root() const
{
    return root;
}

void BinarySearchTree:: insert(int new_val)
{
    if (root == nullptr)
    {
        root = new TreeNode(new_val);
    }
    else
    {
        root -> insert_helper(new_val);
    }
}

void BinarySearchTree::erase(int value_to_erase)
{
    
}

void BinarySearchTree::print_increasing() const
{
    root->prnt_incr_helper();
}

void BinarySearchTree::print_decreasing() const
{
    root->prnt_decr_helper();
}

BinarySearchTree::~BinarySearchTree()
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        tree_des_helper(root);
    }
    
}
void BinarySearchTree::tree_des_helper(TreeNode* current_node)
{
    TreeNode* l_node = current_node->left;
    TreeNode* r_node = current_node->right;

    if (l_node!=nullptr)
    {
        tree_des_helper(l_node);
    }
    
    if (r_node!=nullptr)
    {
        tree_des_helper(r_node);
    }
    delete current_node;
    
}


