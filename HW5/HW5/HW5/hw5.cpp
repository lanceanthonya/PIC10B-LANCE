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
    cout<< "(Enter -1 when you are finished):\n\n";

    // Creates a vector of ints to temporarily hold values that will be used to creete the Listt
    vector<int> vec_1;
    int end_condition = -1; // when the inputted number is -1, this stops acceping vals
    int num = 0 ;
    while (cin >> num)
    {
        if (num == end_condition) // stops looping when reaching -1 is inputted
        {
            break;
        }
        else
        {
            vec_1.push_back(num);
        }
    }

    List list_1;

    size_t final_index = (vec_1.size())-1;
    for (size_t current = 0; current<=final_index; ++current)
    {

        list_1.push_back( new Node(vec_1[current]) );

    }
    cout << "Your list is\n";
    list_1.print();
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
            list_1.insert(list_1[index], new_value);
        }
    }
    while (index != end_condition);
    cout<<"\n\n\n";
    
    cout<< "The augmented List is\n";
    list_1.print();
    cout<<"\n\n";
    
    cout<< "When we sort the previous list we obtain\n";
    list_1.sort();
    list_1.print();
    cout<<"\n";
    
    cout<< "And this sorted list in reverse order is\n";
    list_1.reverse();
    list_1.print();
    cout<<"\n";
    
    List list_2;
    vector<int> vec_2 = {2,3,5,7,11}; // used for creating the hard coded list that gets merged with list_1
    for (int n : vec_2)
    {
        list_2.push_back(new Node(n));
    }
    
    List list_3;
    cout<<"If we merge this list with the list (2,3,5,7,11) we obtain\n";
    list_3.merge(list_1, list_2);
    list_3.print();
    
    cout<<"\n";
    

}
