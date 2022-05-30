/*
 PIC 10B Lecture 1, Homework 5
 Purpose: HW5, Iterator class CPP file
 Author: Lance Anthony Aquino
 Date: 05/28/2022
*/

#include "Iterator.h"
#include "Node.h"
#include "List.h"

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
    position = (position->next);
}

void Iterator::operator--()
{
    position = (position->prev);

}

bool Iterator::operator==(Iterator second) const
{
    if (this->position == second.position)
    {
        return true;
    }
    else
    {
        return false;
    }
}
