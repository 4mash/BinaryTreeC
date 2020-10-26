#pragma once
#include <iostream>

template<typename T>
class BinaryTree
{
private:
    struct Node
    {
        T key = 0;
        Node* parent = nullptr;
        Node* left = nullptr;
        Node* right = nullptr;
        Node() {}
        Node(T value)
        {
            key = value;
        }
        ~Node()
        {
            key = 0;
            parent = nullptr;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root = nullptr;
    unsigned int size = 0;
public:
    BinaryTree();
    bool Add(T value);
    bool Remove(T value);
    bool Empty();
    unsigned int Count(T value);
    void Print(Node *root, int spacing);
    Node *Check(T value);
    Node* getRoot() const;
    unsigned int getSize() const;
private:
    Node* minimumKey(Node* n);
    Node* leafNode(bool left = true);
    void Delete(Node*& p);
};

