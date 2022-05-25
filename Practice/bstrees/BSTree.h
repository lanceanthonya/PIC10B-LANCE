#ifndef __BSTREE__
#define __BSTREE__


#include <iostream>
#include "TreeNode.h"
#include <vector>

using namespace std;

class BSTree {
    public:
        BSTree() : root(nullptr), size(0) {};
        BSTree(const std::vector<int> &unsorted);
        void print();
        void add(int d);
        // void addBad(int d);
        int sum();
        void printPreOrderTraverse();
        void printPostOrderTraverse();
        int height();
        bool find(int num);

    private:
        TreeNode* root;
        int size;
};

//void addBadHelper(int d, TreeNode* rt);

TreeNode* addHelper(int d, TreeNode* rt);


void printHelper(TreeNode* rt);

int sumHelper(TreeNode* rt);


bool findhelper (TreeNode* rt, int num);

#endif //__BSTREE__
