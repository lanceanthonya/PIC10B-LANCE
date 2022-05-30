/*
 PIC 10B Lecture 1, Homework 5
 Purpose: HW5, Node class CPP file
 Author: Lance Anthony Aquino
 Date: 05/28/2022
*/

#include "Node.h"

Node::Node (int _val):
    val (_val),
    prev(nullptr),
    next (nullptr)
{}

Node::Node():
    val (0),
    prev(nullptr),
    next (nullptr)
{}

int Node::get_val() const
{
    return val;
}
