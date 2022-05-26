#ifndef __LL_H__
#define __LL_H__

#include "LinkedListNode.h"
#include <string>
#include <vector>
using namespace std;

class LinkedList {
    public:
        LinkedList();
        LinkedList(int firstData);
        string toString();
        string toStringBackwards();
        int get(int index);
        void printAddresses();
        void addAtTail(int d);
        void addAtHead(int d);
        void addInOrder(int d);
        void clear();
    private:
        LinkedListNode* head;
        LinkedListNode* tail;
        int size;
};

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

LinkedList::LinkedList(int firstData) {
    LinkedListNode* lln = new LinkedListNode(firstData);
    head = lln;
    tail = lln;
    size = 1;
}

string LinkedList::toString() {
    string result = "";
    LinkedListNode* current = head;
    for (int i = 0; i < size; i++) {
        result = result + to_string(current->data) + " ";
        current = current->next;
    }
    result += "(size: " + to_string(size) + ")";
    return result;
}

string LinkedList::toStringBackwards() {
    string result = "";
    LinkedListNode* current = tail;
    for (int i = 0; i < size; i++) {
        result = result + to_string(current->data) + " ";
        current = current->prev;
    }
    result += "(size: " + to_string(size) + ")";
    return result;
}

int LinkedList::get(int index) {
    LinkedListNode* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

void LinkedList::printAddresses() {
    LinkedListNode* current = head;
    for (int i = 0; i < size; i++) {
        cout << current << " ";
        current = current->next;
    }
    cout << endl;
}

void LinkedList::addAtTail(int d) {
    if (size == 0) {
        LinkedListNode* newNode = new LinkedListNode(d);
        head = newNode;
        tail = newNode;
        
        size++;
    } else {
        LinkedListNode* finalNode = tail;
        LinkedListNode* newNode = new LinkedListNode(d);
        finalNode->next = newNode;
        newNode->prev = finalNode;
        tail = newNode;
        size++;
    }
}

void LinkedList::addAtHead(int d) {
    if (size == 0) {
        LinkedListNode* newNode = new LinkedListNode(d);
        head = newNode;
        tail = newNode;
        size++;
    } else {
        LinkedListNode* firstNode = head;
        LinkedListNode* newNode = new LinkedListNode(d);
        firstNode->prev = newNode;
        newNode->next = firstNode;
        head = newNode;
        size++;
    }
}

// adds in order, assuming list is already in order originally
void LinkedList::addInOrder(int d) {
    if (size == 0) {
        LinkedListNode* newNode = new LinkedListNode(d);
        head = newNode;
        tail = newNode;
        size++;
    } else {
        if (d <= head->data) {
            addAtHead(d);
        } else if (d >= tail->data) {
            addAtTail(d);
        } else { // in this case, we know that size must be >= 2
            LinkedListNode* current = head;
            LinkedListNode* nextcurrent = current->next;
            for (int i = 0; i < size-1; i++) {
                if (current->data <= d && d <= nextcurrent->data) {
                    LinkedListNode* newNode = new LinkedListNode(d);
                    newNode->prev = current;
                    newNode->next = nextcurrent;
                    current->next = newNode;
                    nextcurrent->prev = newNode;
                    size++;
                    break;
                }
                current = nextcurrent;
                nextcurrent = current->next;
            }
        }
    }
}

// must free memory! Lec 24 tells us that not doing so is a fatal mistake!
void LinkedList::clear() {
    LinkedListNode* current = head;
    LinkedListNode* nextcurrent = current->next;
    for (int i = 0; i < size; i++) {
        nextcurrent = current->next;
        delete current;
        current = nextcurrent;
        // nextcurrent = current->next; // this line used to be here, but it caused a nullptr->next which is bad. So I moved it before.
    }
    size = 0;
    head = nullptr;
    tail = nullptr;
}

#endif //__LL_H__ 