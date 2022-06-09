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
    left(nullptr)
{}
    
TreeNode::TreeNode(int _val):
    val (_val),
    right(nullptr),
    left(nullptr)
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


void TreeNode::insert_helper(int new_num)
{
    // First, evaluate if the new_number is greater or less than the value stored in the current node
    
    // If less than the current node's value, go to left side and either insert the new value or go to the node on that side to make the insert_helper evaluation again
    if (new_num < val)
    {
        if (left == nullptr)
        {
            left = new TreeNode(new_num);
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
        }
        else
        {
            right -> insert_helper(new_num);
        }
    }
    
}
