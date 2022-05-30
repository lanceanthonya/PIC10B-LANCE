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
    void next();         // Use ++ instead
    void previous(); // Use -- instead
    bool equals(Iterator b) const; //Use == instead
    
private:
    
    friend class List;
    Node* position;
    const List* bug;
  
    
};


#endif /* __ITERATOR__ */
