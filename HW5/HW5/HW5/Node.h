/*
 PIC 10B Lecture 1, Homework 5
 Purpose: HW5, Node class header file
 Author: Lance Anthony Aquino
 Date: 05/28/2022
*/

#ifndef __NODE__
#define __NODE__

/**
 @class Node represents one value in a list. Storess information about the value, the address of the next value in the list, and the addresss of the next value in the list
 */
class Node
{
public:
    
    // Grants friendship to the List object, so that it can alter the left and right values
    friend class List;
    
    /**
     Constructor of a Node object that stores the value.
     
     @param _val some integer number to store as the "value" of the Node
     */
    Node (int _val);
    
    /**
     Constructor of a Node object that stores the value. By default, a Node's value is 0
     */
    Node ();
    
    /**
     Returns the value stored at a node
     
     @return the int stored at a node
     */
    int get_val() const;
    
    int val;

    
private:
    
    Node* left;
    Node* right;
    
    
};


#endif /* __NODE__ */
