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
    if (left!=nullptr)
    {
        left -> prnt_incr_helper();
    }
    
    std::cout<< val;
    if (right!=nullptr)
    {
        right -> prnt_incr_helper();
    }
}

void TreeNode::prnt_decr_helper() const
{
    if (right!=nullptr)
    {
        right -> prnt_decr_helper();
    }
    
    std::cout<< val;
    
    if (left!=nullptr)
    {
        left -> prnt_decr_helper();
    }
    
}
