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
    std::string get() const;  // Use operator* instead
    
    std::string operator*();
    
    void operator++();
    
    void operator--();
    
    bool operator==(Iterator second) const;


    
private:
    
    friend class List;
    Node* position;
    const List* container;
};



#endif /* __ITERATOR__ */
