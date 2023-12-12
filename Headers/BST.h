#ifndef BST_H
#define BST_H
#include "HouseHold.h"
#include <iostream>

class BSTNode {
public:
    HouseHold data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(HouseHold value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    BSTNode * root;

    void insertNode(BSTNode *& currentNode, const HouseHold & value) {
        if (currentNode == nullptr) {
            currentNode = new BSTNode(value);
        } else if (value < currentNode->data) {
            insertNode(currentNode->left, value);
        } else if (value > currentNode->data) {
            insertNode(currentNode->right, value);
        }
    }

    HouseHold* searchNode(BSTNode* currentNode, double value) const {
        if (currentNode == nullptr) {
            return nullptr;
        } else if (value == currentNode->data.getIDNumber()) {
            return &(currentNode->data);
        } else if (value < currentNode->data.getIDNumber()) {
            return searchNode(currentNode->left, value);
        } else {
            return searchNode(currentNode->right, value);
        }
    }

    void removeNode(BSTNode*& currentNode, double value) {
        if (currentNode == nullptr) {
            return;
        } else if (value < currentNode->data.getIDNumber()) {
            removeNode(currentNode->left, value);
        } else if (value > currentNode->data.getIDNumber()) {
            removeNode(currentNode->right, value);
        } else {
            if (currentNode->left == nullptr && currentNode->right == nullptr) {
                delete currentNode;
                currentNode = nullptr;
            } else if (currentNode->left == nullptr) {
                BSTNode* temp = currentNode;
                currentNode = currentNode->right;
                delete temp;
            } else if (currentNode->right == nullptr) {
                BSTNode* temp = currentNode;
                currentNode = currentNode->left;
                delete temp;
            } else {
                // Node with two children: Get the inorder successor
                BSTNode* successor = findMin(currentNode->right);
                // Copy the inorder successor's data to this node
                currentNode->data = successor->data;
                // Delete the inorder successor
                removeNode(currentNode->right, successor->data.getIDNumber());
            }
        }
    }

    BSTNode* findMin(BSTNode* node) const {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void updateNode(BSTNode*& currentNode, const HouseHold& newValue,double value) {
    if (currentNode == nullptr) {
        return;
    } else if (value == currentNode->data.getIDNumber()) {
        currentNode->data=newValue;
        
    } else if (value < currentNode->data.getIDNumber()) {
        updateNode(currentNode->left, newValue, value);
    } else {
        updateNode(currentNode->right, newValue, value);
    }
}


    void destroyTree(BSTNode*& currentNode) {
        if (currentNode != nullptr) {
            destroyTree(currentNode->left);
            destroyTree(currentNode->right);
            delete currentNode;
            currentNode = nullptr;
        }
    }

public:
    BST() : root(nullptr) {}

    ~BST() {
        destroyTree(root);
    }

    void insert(const HouseHold& value) {
        insertNode(root, value);
    }

    void remove(double value) {
        removeNode(root, value);
    }
    void destroyTree() {
        destroyTree(root);
    }
    void update(const HouseHold& newValue ,double value) {
    updateNode(root,newValue, value);
}

    HouseHold* search(unsigned value) const {
        BSTNode * temp = root;
        return searchNode(temp, value);
    }
    BSTNode* getRoot() const {
        return root;
    }
};

#endif
