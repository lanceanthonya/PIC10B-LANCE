/*
 PIC 10B Lecture 1, Homework 5
 Purpose: HW5, List class CPP file
 Author: Lance Anthony Aquino
 Date: 05/28/2022
*/

#include <iostream>
#include "List.h"
#include "Node.h"

List::List():
    Head(nullptr),
    Tail(nullptr)
{}

void List::reverse()
{
    
}

void List::push_front(Node* new_node)
{
    if (Head==nullptr)
    {
        Head = new_node;
        Tail = new_node;
    }
    else
    {
        Head->left = new_node;
        new_node-> right = Head;
        Head = new_node;
    }
}

void List::sort()
{
    
}

void List::print() const
{
    print_helper(Head);
}

void List::print_helper(const Node* current_node) const
{
    if (current_node != nullptr)
    {
        std::cout << current_node->get_val();
        print_helper(current_node->right);
    }
}

