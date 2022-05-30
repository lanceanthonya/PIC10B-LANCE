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
    First(nullptr),
    Last(nullptr),
    size(0)
{}

size_t List::get_size() const
{
    return size;
}

void List::reverse()
{
    
}

void List::push_front(Node* new_node)
{
    if (First==nullptr) // if the list is empty
    {
        First = new_node;
        Last = new_node;
    }
    else // otherwise, if the List has existing items, meaning the First object exists
    {
        First->left = new_node;
        new_node-> right = First;
        First = new_node;
    }
    ++size;
}

void List::sort()
{
    
}

void List::print() const
{
    std::cout<<"(";
    print_helper(First); // starts from the First item of the List
    std::cout<<")";

}

void List::print_helper(const Node* current_node) const
{
    if (current_node->right != nullptr) // calls the function again if the next node exists
    {
        std::cout << current_node->get_val() << ","; // prints the value stored at the current node
        print_helper(current_node->right); // recursively calls the value on the right, starting from the First node
    }
    else if (current_node-> right == nullptr) // does not call the function again if there is no next node, meaning that the current node is the tail
    {
        std::cout << current_node->get_val();
    }
}

List::~List()
{
    List_des_helper(First); // starts destruction from the beginning of the List
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
