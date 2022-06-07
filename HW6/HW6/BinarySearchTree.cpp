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

