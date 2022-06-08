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
    
    /**
     Default constructor for the iterator. Sets posittion and container as nullptr. These two can only be altered by members of List
     */
    Iterator();
    
    /**
     Operator overloading for dereferencing the node at the iterator in order to get the int val stored
     */
    int operator*() const;
    
    /**
     Increments the iterator, by changing its position to the next node
     */
    void operator++();
    
    /**
     Decrements the iterator, by changing its position to the previous node
     */
    void operator--();
    
    /**
     Checks if two iterators refer to the same node
     
     @param second another Iterator object to compare to the iterator on the left of the sign
     
     @return true if the iterators' positions are the same node. False ottherwise
     */
    bool operator==(const Iterator& second) const;

    /**
     Checks if two iterators DO NOT refer to the same node
     
     @param second another Iterator object to compare to the iterator on the left of the sign
     
     @return true if the iterators' positions are different nodes. False ottherwise
     */

    bool operator!=(const Iterator& second) const;

    
private:
    
    Node* position;
    const List* container;
    friend class List; // Since the Iterator class should only be editted by the List class

};



#endif /* __ITERATOR__ */
