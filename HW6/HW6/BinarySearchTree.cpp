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

bool BinarySearchTree:: insert(int new_val)
{
    bool successful_insrt = false;
    if (root == nullptr)
    {
        root = new TreeNode(new_val);
        ++size;
        successful_insrt = true;
    }
    else
    {
        successful_insrt = (root -> insert_helper(new_val));
    }
    
    return successful_insrt;
    
}

bool BinarySearchTree::erase(int value_to_erase)
{
    TreeNode* node_with_value = this->find(value_to_erase);
    if (node_with_value != nullptr) // case where the value is found in the tree
    {
        // case 1: node has no children
        TreeNode* og_left = node_with_value->left;
        TreeNode* og_right = node_with_value -> right;
        TreeNode* og_parent = node_with_value -> parent;
        
        if (og_left == nullptr && og_right == nullptr)
        {
            og_parent -> change_child(node_with_value, nullptr); // changes the pointer to the erased node to nullptr
            delete node_with_value;
            return true;
        }
        
        // case 2: node has only one child
        if (og_left == nullptr && og_right != nullptr) // case 2.1: the right node is the child
        {
            og_parent -> change_child(node_with_value, og_right); // the original parent's pointer to the node that gets deleted is switched for the right node of the node that gets deleted
            delete node_with_value;
            return true;
        }
        
        if (og_left != nullptr && og_right == nullptr) // case 2.2: the left node is the child
        {
            og_parent -> change_child(node_with_value, og_left); // the original parent's pointer to the node that gets deleted is switched for the left node of the node that gets deleted
            delete node_with_value;
            return true;
        }
        
        // case 3: node has two children
        
        if (og_left != nullptr && og_right != nullptr)
        {
            TreeNode* lowest_in_right_branch = findmin(og_right);
        }
        
    }
     // alternate case: node value is not found in the tree
    return false;
    
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

    if (l_node!=nullptr) // recursively deletes all nodes to the left of a node first, stopping when the next left node is nullptr
    {
        tree_des_helper(l_node);
    }
    
    if (r_node!=nullptr) // then recursively deletes all nodes to the right of a node, stopping when the next right node is nullptr
    {
        tree_des_helper(r_node);
    }
    
    size = 0;
    delete current_node; // then deletes the node
    //Note: structured so that overall, thee left side of a tree will be deleted, then the right side, and lastly the root
    
}

TreeIterator BinarySearchTree::begin()
{
    TreeIterator iter;
    TreeNode* min_node = findmin(root);

    iter.container = this;
    iter.position = min_node;

    return iter;
}

TreeIterator BinarySearchTree::end()
{
    TreeIterator iter;
    TreeNode* max_node = findmax(root);

    iter.container = this;
    iter.position = max_node;

    return iter;
}

TreeNode* BinarySearchTree::findmax(TreeNode* current_node) const
{
    TreeNode* left_node = current_node -> left; // the node with the smallest value should be the left-most node
    
    if (left_node != nullptr) // if the next left node exists, continues recursively going down the left side of the tree
    {
        return findmax(left_node);
    }
    else // if there is no next left node, returns a pointer to the current node
    {
        return current_node;
    }
}

TreeNode* BinarySearchTree::findmin(TreeNode* current_node) const
{
    TreeNode* right_node = current_node -> right; // the node with the greatest value should be the right-most node
    if (right_node != nullptr)  // if the next right node exists, continues recursively going down the right side of the tree
    {
        return findmin(right_node);
    }
    else // if there is no next right node, returns a pointer to the current node
    {
        return current_node;
    }
}
TreeNode* BinarySearchTree::find(int searched_value)
{
    return (root ->find_helper(searched_value));
}

