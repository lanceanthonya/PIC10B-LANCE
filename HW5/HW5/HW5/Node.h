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
    
    
    Node* prev; // prev refers to the value facing the "head"/start of the linked list
    Node* next; // next refers to the value facing the "tail"/end of the linked list
    
    // Grants friendship to the List and Iterator objects, so that they can alter/read the left and right values
    friend class List;
    friend class Iterator;
};


#endif /* __NODE__ */
