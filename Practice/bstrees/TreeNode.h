#ifndef __TREENODE__
#define __TREENODE__

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : data(0), left(nullptr), right(nullptr) {};
        TreeNode(int d) : data(d), left(nullptr), right(nullptr) {};
};

#endif //__TREENODE__