/*
 PIC 10B Lecture 1, Homework 5
 Purpose: HW5, main routine file
 Author: Lance Anthony Aquino
 Date: 05/28/2022
*/

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
    cout << "Your list is\n";
    list_of_ints.print();
    cout << "\n\n";

    size_t index = 0;
    int new_value;
    do
    {
        cout<< "Select an index for insertion (enter -1 when finished): ";
        cin>> index;
        if (index != end_condition)
        {
            cout<< "Select a value for insertion: ";
            cin>>new_value;
            list_of_ints.insert(list_of_ints[index], new_value);
        }
    }
    while (index != end_condition);
    cout<<"\n\n\n";
    
    cout<< "The augmented List is\n";
    list_of_ints.print();
    cout<<"\n\n";
    
    cout<< "When we sort the previous list we obtain\n";
    list_of_ints.sort();
    list_of_ints.print();
    cout<<"\n";
    
    cout<< "And this sorted list in reverse order is\n";
    list_of_ints.reverse();
    list_of_ints.print();
    cout<<"\n";
    
    List merge_partner;
    vector<int> new_vector = {2,3,5,7,11};
    for (int n : new_vector)
    {
        merge_partner.push_back(new Node(n));
    }
    
    cout<<"If we merge this list with the list (2,3,5,7,11) we obtain\n";
    (list_of_ints.merge(merge_partner)).print();
    cout<<"\n";
    

}
