#pragma once
#include <iostream>

class BinaryTree
{
private:
    struct Node
    {
        int key = 0;
        Node* parent = nullptr;
        Node* left = nullptr;
        Node* right = nullptr;
        Node() {}
        Node(int value)
        {
            key = value;
        }
    };

    Node* root = nullptr;
    unsigned int size = 0;
public:
    BinaryTree();
    bool Add(int value);
    bool Remove(int value);
    bool Empty();
    void Print(Node *root, int spacing);
    Node *Check(int value);
    Node* getRoot() const;
    unsigned int getSize() const;
private:
    Node* minimumKey(Node* n);
};

