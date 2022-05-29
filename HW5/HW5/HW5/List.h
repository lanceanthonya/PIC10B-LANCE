/*
 PIC 10B Lecture 1, Homework 5
 Purpose: HW5, List class header file
 Author: Lance Anthony Aquino
 Date: 05/28/2022
*/

#ifndef __LIST__
#define __LIST__

#include "Node.h"

class LinkedList
{
public:
    
    Node* get_head();
    Node* get_tail();
    
    void reverse();
    
    void push_front();
    
    void sort();
    
private:
    
    Node* Head;
    Node* Tail;
};


#endif /* __LIST__ */
