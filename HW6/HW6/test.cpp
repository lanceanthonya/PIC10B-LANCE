//
//  test.cpp
//  HW6
//
//  Created by Lance Aquino on 6/7/22.
//

#include "TreeNode.h"
#include "BinarySearchTree.h"
#include <iostream>

using namespace std;
int main()
{
  
    BinarySearchTree bst;
    bst.insert(3); bst.insert(2); bst.insert(11);
    bst.insert(13); bst.insert(5); bst.insert(17); bst.insert(17);
    std::cout << "Your tree consists of : \n";
    bst.print_increasing();
    //TreeNode* seventeen = bst.find(1);
    
    if (bst.find(17)!= nullptr)
    {
        cout<< "There is a 17\n";
    }
    else {cout<< "There is no 17";}
    if (bst.find(2)!= nullptr)
    {
        cout<<"There is a 2\n";
    }
    else {cout<< "There is no 2";}
    if(bst.find(290)!=nullptr)
    {
        cout<< "There is a 290";
    }
    else {cout<< "There is no 290";}
    
    return 0;
}
