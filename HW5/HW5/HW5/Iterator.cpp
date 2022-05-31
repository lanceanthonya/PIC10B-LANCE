/*
 PIC 10B Lecture 1, Homework 5
 Purpose: HW5, Iterator class CPP file
 Author: Lance Anthony Aquino
 Date: 05/28/2022
*/

#include "Iterator.h"
#include "Node.h"
#include "List.h"
#include <cassert>

Iterator::Iterator():
    position(nullptr),
    container(nullptr)
{}

int Iterator::operator*() const
{
    return (position->val);
}

void Iterator::operator++()
{
    assert(position!=nullptr);
    position = (position->next);
}

void Iterator::operator--()
{
    assert(position != container->First);
    if (position == nullptr) // if the position goes past the tail, sets the position as the tail value of the container
    {
        position = container->Last;
    }
    else // otherwise, sets position as the prev value of the Node
    {
        position = (position->prev);
    }

}

bool Iterator::operator==(const Iterator& second) const
{
    if (position == second.position) // checks if the iterator on the left matchews the iterator position on the right
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool Iterator::operator!=(const Iterator& second) const
{
    if(*this==second) // If the two iterators are equal, meaning they have the same position, this returns false (meaning that they are equal)
    {
        return false;
    }
    else // otherwwise, returns true, to show that they are equal
    {
        return true;
    }
    
}
