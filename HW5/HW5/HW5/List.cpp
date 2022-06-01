/*
 PIC 10B Lecture 1, Homework 5
 Purpose: HW5, List class CPP file
 Author: Lance Anthony Aquino
 Date: 05/28/2022
*/

#include <iostream>
#include "List.h"
#include "Node.h"
#include <cassert>

List::List():
    First(nullptr),
    Last(nullptr),
    size(0)
{}

size_t List::get_size() const
{
    return size;
}


void List::push_front(Node* new_node)
{
    if (First==nullptr) // if the list is empty, sets the node as both the last and first node
    {
        First = new_node;
        Last = new_node;
    }
    else // otherwise, if the List has existing items, this means that the First object exists and therefore the new_node will replace it
    {
        First->prev = new_node; // sets a pointer to the new node for the current First
        new_node-> next = First; // sets a pointer to the current First for the new node
        First = new_node; // makes new_node the new value for First/ the "Head"
    }
    ++size; // increments the value of size
}

void List::push_back(Node* new_node)
{
    if (Last==nullptr) // if the list is empty, sets the node as both the last and first node
    {
        First = new_node;
        Last = new_node;
    }
    else // otherwise, if the List has existing items, this means that the Last object exists and therefore the new_node will replace it
    {
        Last->next = new_node; // sets a pointer to the new node for the current Last
        new_node->prev = Last; // sets a pointer to the current Last for the new node
        Last = new_node; // makes new_node the new value for Last/ the "Tail"
    }
    ++size; // increments the value of size
}


void List::print() const
{
    std::cout<<"(";
    print_helper(First); // starts from the First item of the List
    std::cout<<")";

}

void List::print_helper(const Node* current_node) const
{
    if (current_node->next != nullptr) // calls the function again if the next node exists
    {
        std::cout << current_node->get_val() << ","; // prints the value stored at the current node, along with a comma
        print_helper(current_node->next); // recursively calls the value on the right, starting from the First node
    }
    else if (current_node-> next == nullptr) // does not call the function again if there is no next node, meaning that the current node is the tail
    {
        std::cout << current_node->get_val(); // no comma, since this represents the tail/last value
    }
}

List::~List()
{
    List_des_helper(First); // starts destruction from the Start of the List
}

void List::List_des_helper(Node* current_node)
{
    if (current_node != nullptr) // only destructs if the current_node is an actual node, not nullptr
    {
        
        List_des_helper(current_node->next); // recursively calls this helper on the next Node*
        
        delete current_node; // deletes the node after the node to the next node has been deleted. At the final function call, nodes are deleted starting at the Last node, and ending at the First node
    }
    // otherwise, if the current_node is nullptr, the tail has been reached and therefore the recursion loop ends
    
}

void List::insert(Iterator pos, int i)
{
    // first create a new node

    if (pos == this->begin())
    {
        this->push_front( new Node (i));
    }
    else if (pos == this->end())
    {
        this->push_back( new Node(i) );
    }
    else
    {
        Node* new_node = new Node(i); // creates a new node with empty prev and next value

        Node* new_next = pos.position;
        --pos; // decrements the position to the previous item in the list so that a pointer to it can be created 
        Node* new_prev = pos.position;


        new_node->next = new_next;
        new_next->prev = new_node;

        new_node->prev = new_prev;
        new_prev->next = new_node;
    }
    ++size;
  
}

Iterator List::erase(Iterator pos)
{
    // Creates pointers to the node being removed as well as the nodes right next to it

    assert(pos.position != nullptr);
    Node* node_to_remove = pos.position;
    Node* before_ntr = node_to_remove->prev;
    Node* after_ntr = node_to_remove->next;

    // setting the nodes before and after the removed node to point at one another
    
    if (node_to_remove == First) // if the node being removed is the Head/First item, then the new First is set to the value after it
    { 
        First = after_ntr;
    }
    else // otherwise, just sets the next value of the node before the removed node to point at the node after the removed node
    { 
        before_ntr->next = after_ntr; 
    }    

    if (node_to_remove == Last) // if the node being removed is the Tail/Last item, then the new Last is set to the value before it
    {
        Last = before_ntr;
    }
    else // otherwise, just sets the previous value of the node after the removed node to point at the node before the removed node
    {
        after_ntr->prev = before_ntr;
    }

    delete node_to_remove; // deallocates the memory for the removed node

    Iterator r;
    r.position = after_ntr; // sets the new iterator's position to point at the node after the node that was just removed
    r.container = this;
    
    --size;
    return r;
}

Iterator List::begin()
{
    Iterator iter;
    iter.container = this;
    iter.position = this->First;
    return iter;
}

Iterator List::end()
{
    Iterator iter;
    iter.container = this;
    iter.position = nullptr;
    return iter;
}

Iterator List::operator[](size_t index) const
{
    Iterator iter; // idk why but begin() doesn't want to work here so I just rewrote the stuff from begin
    iter.container = this;
    iter.position = this->First;

    for (size_t cur_index = 0; cur_index < index; ++cur_index) // increments the Iterator until the index the iterator corresponds to matches the user-inputted index
    {
        ++iter; // moves the iterator to the Next value
    }
    return iter;
}

void List::reverse()
{
    // First, swaps the nodes for First and Last
    Node* temp = Last;
    Last = First;
    First = temp;

    // Iter starts at the new Tail, or the original Head
    Iterator iter = this-> end();
    
    while(iter != this->begin()) // keepss iterating until reaching the new Head, which was the original Tail
    {
        --iter; // for the current iterator, goes to the prev value. If iter == this->end(), then this brings iter to the new tail, or the current head.
        Node* current_node = iter.position;

        Node* new_next = current_node->prev; // a pointer to the original prev Node
        Node* new_prev = current_node->next; // a pointer to the original next Node

        // swaps the prev and next pointers for the current node
        current_node->prev = new_prev;
        current_node->next = new_next;
    }
}

void List::sort()
{
    Iterator first_pos = this -> begin();
    Iterator last_pos = this -> end();
    
    for (Iterator iter_1 = first_pos; iter_1 != last_pos; ++ iter_1)
    {
        Iterator new_lowest_pos = iter_1;
        
        for (Iterator iter_2 = iter_1; iter_2 != last_pos; ++ iter_2)
        {
            if (*iter_2<*new_lowest_pos )
            {
                new_lowest_pos = iter_2;
            }
        }
        if (iter_1 != new_lowest_pos)
        {
            swap (iter_1, new_lowest_pos);
        }
    }
}

void List::swap(Iterator pos_a, Iterator pos_b)
{
    int temp = *pos_a;
    pos_a.position->val = *pos_b; // the value of the second Iterator becomess the value of thhe first iterator
    pos_b.position->val = temp; // the value of the first Iterator becomess the value of thhe ssecond iterator
}

List List::merge(const List& list_b)
{
    List new_list;
    // the new List's head is always the first list's head, where the first list refers to *this
    
    size_t max_a_index = (this->size) -1 ;
    size_t max_b_index = list_b.size-1;
    
    new_list.size = (this->size) + (list_b.size);
    
    size_t max_index;
    
    if (max_a_index > max_b_index) // if list_a has more or as many nodes as list_b, then the max possible index is based on list_a
    {
        max_index = max_a_index;
    }
    else if (max_b_index>max_a_index)// if list_b has more valuess then the max possible index is based on list_b
    {
        max_index = max_b_index;
    }
    else
    {
        max_index = max_a_index;
    }
    
    for (size_t current_index = 0; current_index<=max_index; ++ current_index )
    {
        if (max_a_index>=current_index)
        {
            new_list.push_back(new Node(*(*this)[current_index]));
        }
        
        if (max_b_index>=current_index)
        {
            new_list.push_back(new Node(*list_b[current_index]));
        }
    }
    
    return new_list;
}
