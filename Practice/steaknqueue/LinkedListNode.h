#ifndef __NODE_H__
#define __NODE_H__

class LinkedListNode {
    public:
        LinkedListNode();
        LinkedListNode(int d);
        int data;
        LinkedListNode* prev;
        LinkedListNode* next;
};

LinkedListNode::LinkedListNode() {
    data = -1;
    prev = nullptr;
    next = nullptr;
}

LinkedListNode::LinkedListNode(int d) {
    data = d;
    prev = nullptr;
    next = nullptr;
}

#endif //__NODE_H__ 