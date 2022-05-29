/*
 PIC 10B Lecture 1, Homework 5
 Purpose: HW5, Node class header file
 Author: Lance Anthony Aquino
 Date: 05/28/2022
*/

#ifndef __NODE__
#define __NODE__

class Node
{
public:

    Node (int _val);
    
    Node ();
    
    Node* left;
    Node* right;
    
private:
    int val;
};


#endif /* __NODE__ */
