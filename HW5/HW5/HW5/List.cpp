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
    std::cout<<"(";
    print_helper(Head); // starts from the Head of the List
    std::cout<<")";

}

void List::print_helper(const Node* current_node) const
{
    if (current_node != nullptr) // ends if the current_node is a nullptr, meaning that it's the tail
    {
        std::cout << current_node->get_val() << ","; // prints the value stored at the current node
        print_helper(current_node->right); // recursively calls the value on the right, starting from the Head
    }
}

List::~List()
{
    List_des_helper(Head); // starts destruction from the head of the List
}

void List::List_des_helper(Node* current_node)
{
    if (current_node != nullptr) // only destructs if the current_node is an actual node, not nullptr
    {
        List_des_helper(current_node->right); // recursively calls this helper on the next Node*
        delete current_node; // deletes the node after the node to the right of it has been deleted
        
    }
    // otherwise, if the current_node is nullptr, it has reached the tail and therefore the recursion loop ends
    
}
