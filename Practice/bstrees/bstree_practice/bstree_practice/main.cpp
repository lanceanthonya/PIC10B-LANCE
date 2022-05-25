//
//  main.cpp
//  bstree_practice
//
//  Created by Lance Aquino on 5/17/22.
//

#include <iostream>
#include "BSTree.h"
#include <vector>
#include "TreeNode.h"

using namespace std;

int main() {
    vector<int> ints = {1,4,8,10,9};
    BSTree bullshitree (ints);
//    bullshitree.add(1);
//    bullshitree.add(4);
//    bullshitree.add(8);
//    bullshitree.add(10);
//    bullshitree.add(9);
    
    bullshitree.print();
    
    cout<< "Sum of tree: "<< bullshitree.sum()<<"\n";
    
    cout<<"9 is in the tree: ";
    (bullshitree.find(9))?cout<<"true":cout<<"false";
    
    
    cout<<"\n";
    return 0;
}
