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
    cout<< "Please input a set of nonnegative numbers for a List\n";
    cout<< "(Enter -1 when you are finished);\n\n";
    
    vector<int> val_vector;
    int end_condition = -1;
    int num = 0 ;
    while (cin >> num)
    {
        if (num == end_condition)
        {
            break;
        }
        else
        {
            val_vector.push_back(num);
        }
    }
    
    List list_of_ints;

    size_t final_index = (val_vector.size())-1;
    for (size_t current = 0; current<=final_index; ++current)
    {
        
        list_of_ints.push_back( new Node(val_vector[current]) );

    }
    cout << "The inputted list: ";

    list_of_ints.print();
    cout << "\n";

    // testing iterator for: adding a number to a certain position

    size_t index;
    int value;

    cout << "What index to add the new value?: ";
    cin >> index;

    cout << "What value to insert at that index? ";
    cin >> value; 

    Iterator pos_to_add_new_val = list_of_ints.begin();

    for (size_t cur_index = 0; cur_index < index; ++cur_index) // increments the Iterator until the index the iterator corresponds to matches the user-inputted index
    {
        ++pos_to_add_new_val; // moves the iterator to the Next value
    }

    list_of_ints.insert(pos_to_add_new_val, value); // creates a new node that shifts the current node at that position to becoming the next value, relative to the new node.
    list_of_ints.print();

    cout << "What index to remove a value?: ";
    cin >> index;

    Iterator pos_to_rm_val = list_of_ints.begin();
    for (size_t cur_index = 0; cur_index < index; ++cur_index) // increments the Iterator until the index the iterator corresponds to matches the user-inputted index
    {
        ++pos_to_rm_val; // moves the iterator to the Next value
    }
    list_of_ints.erase(pos_to_rm_val); // erases the value at the position indicated by the index
    list_of_ints.print();


    return 0;
}
