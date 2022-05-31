/*
 PIC 10B Lecture 1, Homework 5
 Purpose: HW5, List class header file
 Author: Lance Anthony Aquino
 Date: 05/28/2022
*/

#ifndef __LIST__
#define __LIST__

#include <iostream>
#include "Iterator.h"
#include "Node.h"

class Iterator;

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
     Addss a new value to the end of the list, such that it becomes the new Tail
     
     @param new_node a new node to add to the list
     */
    void push_back(Node* new_node);
    
    /**
     Sorts the list in place
     */
    void sort();
    
    /**
     Prints the values of the list starting from the head and ending at the tail recursively
     */
    void print() const;
    
    void print_helper(const Node* current_node) const;
    
    void insert(Iterator pos, int i);

    
    Iterator erase(Iterator pos);
    
    Iterator begin();
    
    Iterator end();
    
    size_t get_size() const;
    

private:
    
    Node* First; // refers to the "head" of the List
    Node* Last; // refers to the "tail" of the List
    
    size_t size;
    
    friend class Iterator;
    
};



#endif /* __LIST__ */
