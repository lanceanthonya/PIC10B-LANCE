//
//  TESTLA.cpp
//  HW5
//  Purpose: Testing the functionality of hww5-related files
//  Created by Lance Aquino on 5/28/22.
//

#include "List.h"
#include "Node.h"
#include <vector>

using namespace std;
int main()
{
//    cout<< "(For List 1) ";
//    cout<< "Please input a set of nonnegative numbers for a List\n";
//    cout<< "(Enter -1 when you are finished);\n\n";
//
//    vector<int> val_vector;
//    int end_condition = -1;
//    int num = 0 ;
//    while (cin >> num)
//    {
//        if (num == end_condition)
//        {
//            break;
//        }
//        else
//        {
//            val_vector.push_back(num);
//        }
//    }
//
//    List list_of_ints;
//
//    size_t final_index = (val_vector.size())-1;
//    for (size_t current = 0; current<=final_index; ++current)
//    {
//
//        list_of_ints.push_back( new Node(val_vector[current]) );
//
//    }
//    cout << "The inputted list: ";
//
//    list_of_ints.print();
//    cout << "\n";

    // testing iterator for: adding a number to a certain position

//    size_t index;
//    int value;
//
//    cout << "What index to add the new value?: ";
//    cin >> index;
//
//    cout << "What value to insert at that index? ";
//    cin >> value;
//
//
//
//    list_of_ints.insert(list_of_ints[index], value); // creates a new node that shifts the current node at that position to becoming the next value, relative to the new node.
//    list_of_ints.print();
//
//    cout << "\nWhat index to remove a value?: ";
//    cin >> index;
//
//    cout << "\nErased value: "<< *(list_of_ints[index])<<"\n";
//    list_of_ints.erase(list_of_ints[index]); // erases the value at the position indicated by the index
//
//    list_of_ints.print();

    //size_t index_1, index_2;

    //cout << "Write two indeces to swap, separated by a space: ";
//    //cin >> index_1>>index_2;
//    cout<< "\nReversed list: \n";
//
//    list_of_ints.reverse();
//
//    list_of_ints.print();
//
//
//    cout << "\n";
//
//    list_of_ints.sort();
//    list_of_ints.print();
//
    
    //Testing merge()
    
    List list_a;
    List list_b;
    vector<int> vec_a = {1,7,12};
    vector<int> vec_b = {8,3,11,2,2,1};
    
    for (int n : vec_a)
    {
        list_a.push_back(new Node(n));
    }
    for (int n : vec_b)
    {
        list_b.push_back(new Node(n));
    }
    
    List new_list = (list_a.merge(list_b));
    new_list.print();
    
    return 0;
}
