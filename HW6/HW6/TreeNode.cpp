/*
 PIC 10B Lecture 1, Homework 6
 Purpose: HW6, TreeNode cpp file
 Author: Lance Anthony Aquino
 Date: 06/07/2022
*/

#include "TreeNode.h"

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
