/*
 PIC 10B Lecture 1, Homework 5
 Purpose: HW5, Iterator class header file
 Author: Lance Anthony Aquino
 Date: 05/28/2022
*/

#ifndef __ITERATOR__
#define __ITERATOR__

#include "Node.h"
#include <string>
#include "List.h"

class List; // forward declaration of List

class Iterator
{
public:
    
    Iterator();
    
    int operator*() const; // dereferencing the node at the iterator in order to get the value stored
    
    void operator++();
    
    void operator--();
    
    bool operator==(const Iterator& second) const;

    bool operator!=(const Iterator& second) const;

    
private:
    
    Node* position;
    const List* container;
    
    friend class List;

};



#endif /* __ITERATOR__ */
