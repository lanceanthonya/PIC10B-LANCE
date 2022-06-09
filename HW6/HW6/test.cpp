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
    
    
    return 0;
}
