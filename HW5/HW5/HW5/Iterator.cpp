/*
 PIC 10B Lecture 1, Homework 5
 Purpose: HW5, Iterator class CPP file
 Author: Lance Anthony Aquino
 Date: 05/28/2022
*/

#include "List.h"
#include "Node.h"
#include <string>



class Iterator
{
private:
    Node* position;
    const List* container;
    friend class List;
    
public:
    Iterator();
    std::string get() const;  // Use operator* instead
    void next();         // Use ++ instead
    void previous(); // Use -- instead
    bool equals(Iterator b) const; //Use == instead
};
