//
//  BSTree.cpp
//  bstree_practice
//
//  Created by Lance Aquino on 5/17/22.
//

#include <stdio.h>
#include "BSTree.h"
#include "TreeNode.h"
#include <vector>

BSTree::BSTree(const std::vector<int>& unsorted):
    root(nullptr), size(0)
{
    for (int current_num : unsorted)
    {
        this -> add(current_num);
    }
}

void BSTree::add(int d) {
    root = addHelper(d, root);
}

TreeNode* addHelper(int d, TreeNode* rt) {
    if (rt == nullptr) {
        TreeNode* newNode = new TreeNode(d);
        return newNode;
    } else {
        if (d < rt->data) {
            rt->left = addHelper(d, rt->left);
        } else {
            rt->right = addHelper(d, rt->right);
        }
        return rt; // return of addHelper is either newNode (base case), or itself
    }
}

void BSTree::print() {
    printHelper(root);
}

void printHelper(TreeNode* rt) {
    if (rt != nullptr) {
        printHelper(rt->left);
        cout << rt->data<<"\n";
        printHelper(rt->right);
    }
}


int BSTree::sum()
{
    return sumHelper(root);
}

int sumHelper(TreeNode* rt)
{
    if (rt==nullptr)
    {
        return 0;
    }
    else
    {
        return sumHelper(rt -> left)+ rt-> data + sumHelper(rt -> right);
    }
}

bool BSTree::find(int num)
{
    return findhelper(root, num);
}

bool findhelper (TreeNode* rt, int num)
{
    if (rt == nullptr)
    {
        return false;
    }
    else
    {
        if (rt -> data == num)
        {
            return true;
        }
        else if (findhelper(rt->left,num)||findhelper(rt->right, num))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
