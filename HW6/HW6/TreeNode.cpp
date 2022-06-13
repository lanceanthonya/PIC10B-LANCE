/*
 PIC 10B Lecture 1, Homework 6
 Purpose: HW6, TreeNode cpp file
 Author: Lance Anthony Aquino
 Date: 06/07/2022
*/

#include "TreeNode.h"
#include <iostream>

TreeNode::TreeNode():
    val (0),
    right(nullptr),
    left(nullptr),
    parent(nullptr)
{}
    
TreeNode::TreeNode(int _val):
    val (_val),
    right(nullptr),
    left(nullptr),
    parent(nullptr)
{}

int TreeNode::get_val() const
{
    return val;
}

void TreeNode::prnt_incr_helper() const
{
    if (left!=nullptr) // if the next left node exists, this goes to that node to call the helper on it
    {
        left -> prnt_incr_helper();
    }
    
    std::cout<< val <<"\n"; // prints the value in the node, after all nodes to the left of it have been printed
    
    if (right!=nullptr) // if the next right node exists, this goes to that node to call the helper on it
    {
        right -> prnt_incr_helper();
    }
}

void TreeNode::prnt_decr_helper() const
{
    if (right!=nullptr) // if the next right node exists, this goes to that node to call the helper on it
    {
        right -> prnt_decr_helper();
    }
    
    std::cout<< val <<"\n";  // prints the value in the node, after all nodes to the left of it have been printed
    
    if (left!=nullptr) // if the next left node exists, this goes to that node to call the helper on it
    {
        left -> prnt_decr_helper();
    }
    
}


bool TreeNode::insert_helper(int new_num)
{
    // First, evaluate if the new_number is greater or less than the value stored in the current node
    
    bool successful_insert = false;
    // If less than the current node's value, go to left side and either insert the new value or go to the node on that side to make the insert_helper evaluation again
    if (new_num < val)
    {
        if (left == nullptr)
        {
            left = new TreeNode(new_num);
            left -> parent = this;
            successful_insert = true;
        }
        else
        {
            left -> insert_helper(new_num);
        }
    }
    
    // If greater than the current node's value, go to right side
    else if (new_num > val)
    {
        if (right == nullptr)
        {
            right = new TreeNode(new_num);
            successful_insert = true;
        }
        else
        {
            right -> insert_helper(new_num);
        }
    }
    return successful_insert;
}

bool TreeNode::erase_helper (int removed_num)
{
    bool val_found = false;
    if (removed_num == val) // case where the value is found in the tree
    {
        // case 1: node has no children
        if (left == nullptr && right == nullptr)
        {
            parent -> change_child(this, nullptr); // changes the pointer to a given node to 
            delete this;
            val_found = true;
        }
        
        // case 2: node has only one child
        if (left == nullptr && right != nullptr) // case 2.1: the right node is the child
        {
            
            TreeNode* original_parent = this -> parent; // right node is promoted to the position that the current node currently occupies
            
            TreeNode* promoted_node = this -> right;
            
            //original_parent;
            delete this;
        }
        
        if (left != nullptr && right == nullptr) // case 2.2: the left node is the child
        {
            left->parent = this -> parent;
        }
        
        // case 3: node has two children
        
        if (left != nullptr && right != nullptr)
        {
            
        }
        
    }
    else // alternate case: node value is not found in the tree
    {
        val_found= false;
    }
    return val_found;
}

void TreeNode::change_child (TreeNode* child_node, TreeNode* replacement_node)
{
    if (left == child_node)
    {
        left = replacement_node;
    }
    else if (right == child_node)
    {
        right = replacement_node;
    }
}

TreeNode* TreeNode::find_helper(int searched_value)
{

    if (left != nullptr)
    {
        TreeNode* left_traverse = left -> find_helper(searched_value);
        if (left_traverse!= nullptr)
        {
            return left_traverse;
        }
    }
    if (val == searched_value)
    {
        return this;
    }
    if (right != nullptr)
    {
        TreeNode* right_traverse = right -> find_helper(searched_value);
        if (right_traverse!= nullptr)
        {
            return right_traverse;
        }
    }
    return nullptr; // returns a nullptr in the case where the value is never found
}
