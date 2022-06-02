/*
 PIC 10B Lecture 1, Homework 5
 Purpose: HW5, List class header file
 Author: Lance Anthony Aquino
 Date: 05/28/2022
*/

#ifndef __LIST__
#define __LIST__

#include <iostream>
#include "Iterator.h"
#include "Node.h"

class Iterator;

class List
{
public:
    
    /**
     Default constructor for a list
     */
    List();
    
    /**
     Destructor for a list
     */
    ~List();
    
    /**
     Helper function for the destructor
     
     @param current_node the current LL node to be deleted
     */
    void List_des_helper(Node* current_node);

    /**
     Reverses the order of a list
     */
    void reverse();
        
    /**
     Addss a new value to the front of the list, such that it becomes the new Head
     
     @param new_node a new node to add to the list
     */
    void push_front(Node* new_node);
    
    /**
     Addss a new value to the end of the list, such that it becomes the new Tail
     
     @param new_node a new node to add to the list
     */
    void push_back(Node* new_node);
    
    /**
     Sorts the list in place from ascending order using a selection sort algorithhm
     */
    void sort();
    
    /**
     Prints the values of the list starting from the head and ending at the tail recursively
     */
    void print() const;
    
    /**
     Helper function for the print function recursively printing the values starting from the head and ending at the tail
     
     @param current_node the current node being printed to the console
     */
    void print_helper(const Node* current_node) const;
    
    /**
     Creates a node at the position/index corressponding to pos, by shhifting the existing node  after it towards the Tail/Last node
     
     @param pos iterator refering to the index of the value to be shifted forward
     @param i the  value of the node to be created on the Heap
     */
    void insert(Iterator pos, const int i);

    /**
     Deletes the node corresponding to pos
     
     @param pos an iterator refering to the index of the value being deleted
     
     @return an iterator referring to the node immediately after the node that was just deleted
     */
    Iterator erase(Iterator pos);
    
    /**
     Creates an iterator based on the head
     
     @return an iterator whose position value is that of the First node
     */
    Iterator begin();
    
    /**
     Creates an iterator based on the Tail/Last node
     
     @return an iterator whose position value is that of the Last node
     */
    Iterator end();
    
    /**
     Returns the number of nodes in the List
     
     @return the number of nodes in the List
     */
    size_t get_size() const;

    /**
     Swaps the int vals of two nodes
     
     @param pos_a the first node to have itss value swapped
     @param pos_b the node that switches its val with pos_a
     */
    void swap(Iterator& pos_a, Iterator& pos_b);
    
    /**
    Operator overload for indexing operator

    @param index the index of a node in the list, starting from 0

    @return an Iterator object at the position in the List corresponding with index. Note that List[0] would be an Iterator object referring the First value
    */
    Iterator operator[](const size_t index) const;
    
    /**
    Merges two lists
     */
    void merge(const List& list_a, const List& list_b);
    
    void clear();
    
private:
    
    
    Node* First; // refers to the "head" of the List
    Node* Last; // refers to the "tail" of the List
    
    size_t size;
    
    friend class Iterator;
    
};



#endif /* __LIST__ */
