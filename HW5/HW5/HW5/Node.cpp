/*
 PIC 10B Lecture 1, Homework 5
 Purpose: HW5, Node class CPP file
 Author: Lance Anthony Aquino
 Date: 05/28/2022
*/

#include "Node.h"

Node::Node (int _val):
    val (_val),
    left(nullptr),
    right (nullptr)
{}

Node::Node():
    val (0),
    left(nullptr),
    right (nullptr)
{}
