#pragma once
#include <iostream>

struct Node
{
    int key = 0;
    Node* parent = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;
};

class BinaryTree
{
private:
    Node* root = nullptr;
    unsigned int size = 0;

public:
    BinaryTree();
    bool Add(int value);
    bool Remove(int value);
    void Print(Node *root, int spacing);
    Node *Check(int value);
    Node* getRoot() const;
    unsigned int getSize() const;
};

