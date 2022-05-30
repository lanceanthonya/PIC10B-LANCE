/*
 PIC 10B Lecture 1, Homework 5
 Purpose: HW5, List class header file
 Author: Lance Anthony Aquino
 Date: 05/28/2022
*/

#ifndef __LIST__
#define __LIST__

#include <iostream>
#include "Node.h"

class List
{
public:
    
    /**
     Default constructor for a list
     */
    List();
    
    /**
     Destructor for a list
     */
    ~List();
    
    void List_des_helper(Node* current_node);

    /**
     Reverses the order of a list
     */
    void reverse();
    
    //void push_front(int new_val);
    
    /**
     Addss a new value to the front of the list, such that it becomes the new Head
     
     @param new_node a new node to add to the list
     */
    void push_front(Node* new_node);
    
    /**
     Sorts the list in place
     */
    void sort();
    
    /**
     Prints the values of the list starting from the head and ending at the tail
     */
    void print() const;
    
    void print_helper(const Node* current_node) const;
    
    size_t get_size() const;

private:
    
    Node* First;
    Node* Last;
    
    size_t size;
    
    friend class Iterator;
    
};



#endif /* __LIST__ */
