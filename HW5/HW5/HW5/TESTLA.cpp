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
    
    list_of_ints.print();
    
    return 0;
}
