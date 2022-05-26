/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList ll(78);
    cout << ll.toString() << endl;
    ll.addAtTail(89);
    ll.addAtHead(43);
    cout << ll.toString() << endl;
    cout << ll.toStringBackwards() << endl;
    ll.printAddresses();
    ll.clear();
    
    ll.addAtTail(3);
    ll.addAtTail(1);
    ll.addAtTail(4);
    ll.addAtTail(1);
    ll.addAtTail(5);
    ll.addAtTail(9);
    ll.addAtTail(2);
    ll.addAtTail(6);
    cout << ll.toString() << endl;
    ll.clear();
    
    
    ll.addInOrder(3);
    ll.addInOrder(1);
    ll.addInOrder(4);
    ll.addInOrder(1);
    ll.addInOrder(5);
    ll.addInOrder(9);
    ll.addInOrder(2);
    ll.addInOrder(6);
    cout << ll.toString() << endl;
    ll.printAddresses();
    ll.clear();
    

    return 0;
}

// to demonstrate that vectors allocate memory sequentially
int main1()
{
    vector<int> v = {1,2,3,4};
    cout << &v[0] << endl;
    cout << &v[1] << endl;
    cout << &v[2] << endl;
    cout << &v[3] << endl;
    cout << endl;
    
    // notice below two addresses of v[0] are the same (so vector is not resized between the two loops)
    for (int i = 1; i <= 5; i++) {
        v.push_back(i);
    }
    cout << &v[0] << endl;
    cout << &v[1] << endl;
    cout << &v[2] << endl;
    cout << &v[3] << endl;
    cout << endl;
    
    for (int i = 1; i <= 5; i++) {
        v.push_back(i);
    }
    cout << &v[0] << endl;
    cout << endl;
    
    // notice below two addresses are the same (so vector is not resized between the two loops)
    for (int i = 1; i <= 25; i++) {
        v.push_back(i);
    }
    cout << &v[0] << endl;
    cout << endl;
    
    for (int i = 1; i <= 25; i++) {
        v.push_back(i);
    }
    cout << &v[0] << endl;
    cout << endl;
    
    // and the address changes again after this loop (meaning the vector was resized, and all elements copied)
    for (int i = 1; i <= 125; i++) {
        v.push_back(i);
    }
    cout << &v[0] << endl;

    return 0;
}
