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

    size_t number_of_vals = val_vector.size();
    for (size_t current = number_of_vals-1; 0<=current; --current)
    {
        
        list_of_ints.push_front( new Node(val_vector[current]) );
        if (current == 0)
        {
            break;
        }
    }
    
    list_of_ints.print();
    
    return 0;
}
