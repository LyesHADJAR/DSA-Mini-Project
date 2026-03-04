#ifndef BST_H
#define BST_H

#include <iostream>
#include <sstream>

template<class Comparable>
class BSTNode {
public:
    Comparable data;
    BSTNode *left;
    BSTNode *right;

    explicit BSTNode(Comparable value) : data(value), left(nullptr), right(nullptr) {}
};

template<class Comparable>
class BST {
private:
    BSTNode<Comparable> *root;

    void insertNode(BSTNode<Comparable> *&currentNode, const Comparable &value) {
        if (currentNode == nullptr) {
            currentNode = new BSTNode<Comparable>(value);
        } else if (value < currentNode->data) {
            insertNode(currentNode->left, value);
        } else if (value > currentNode->data) {
            insertNode(currentNode->right, value);
        }
    }

    Comparable *searchNode(BSTNode<Comparable> *currentNode, long long value) const {
        if (currentNode == nullptr) {
            return nullptr;
        } else if (value == stringToLongLong(currentNode->data.getIDNumber())) {
            return &(currentNode->data);
        } else if (value < stringToLongLong(currentNode->data.getIDNumber())) {
            return searchNode(currentNode->left, value);
        } else {
            return searchNode(currentNode->right, value);
        }
    }

    void removeNode(BSTNode<Comparable> *&currentNode, double value) {
        if (currentNode == nullptr) {
            return;
        } else if (value < stoi(currentNode->data.getIDNumber())) {
            removeNode(currentNode->left, value);
        } else if (value > stoi(currentNode->data.getIDNumber())) {
            removeNode(currentNode->right, value);
        } else {
            if (currentNode->left == nullptr && currentNode->right == nullptr) {
                delete currentNode;
                currentNode = nullptr;
            } else if (currentNode->left == nullptr) {
                BSTNode<Comparable> *temp = currentNode;
                currentNode = currentNode->right;
                delete temp;
            } else if (currentNode->right == nullptr) {
                BSTNode<Comparable> *temp = currentNode;
                currentNode = currentNode->left;
                delete temp;
            } else {
                // Node with two children: Get the inorder successor
                BSTNode<Comparable> *successor = findMin(currentNode->right);
                // Copy the inorder successor's data to this node
                currentNode->data = successor->data;
                // Delete the inorder successor
                removeNode(currentNode->right, stoi(successor->data.getIDNumber()));
            }
        }
    }

    BSTNode<Comparable> *findMin(BSTNode<Comparable> *node) const {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void updateNode(BSTNode<Comparable> *&currentNode, const Comparable &newValue, double value) {
        if (currentNode == nullptr) {
            return;
        } else if (value == stoi(currentNode->data.getIDNumber())) {
            currentNode->data = newValue;

        } else if (value < stoi(currentNode->data.getIDNumber())) {
            updateNode(currentNode->left, newValue, value);
        } else {
            updateNode(currentNode->right, newValue, value);
        }
    }


    void destroyTree(BSTNode<Comparable> *&currentNode) {
        if (currentNode != nullptr) {
            destroyTree(currentNode->left);
            destroyTree(currentNode->right);
            delete currentNode;
            currentNode = nullptr;
        }
    }

    static long long stringToLongLong(const std::string &str) {
        std::stringstream ss(str);
        long long result = 0;
        ss >> result;
        return result;
    }

    void inOrderTraversal(BSTNode<Comparable> *node, std::vector<Comparable> &result) const {
        if (node != nullptr) {
            inOrderTraversal(node->left, result);
            result.push_back(node->data);
            inOrderTraversal(node->right, result);
        }
    }

public:
    BST() : root(nullptr) {}

    ~BST() {
        destroyTree(root);
    }

    void insert(const Comparable &value) {
        insertNode(root, value);
    }

    void remove(double value) {
        removeNode(root, value);
    }

    void destroyTree() {
        destroyTree(root);
    }

    void update(const Comparable &newValue, double value) {
        updateNode(root, newValue, value);
    }

    Comparable *search(string id) const {
        BSTNode<Comparable> *temp = root;
        long long val = stringToLongLong(id);
        return searchNode(temp, val);
    }

    BSTNode<Comparable> *getRoot() const {
        if (root == NULL) return NULL;
        else return root;
    }

    std::vector<Comparable> inOrderTraversal() const {
        std::vector<Comparable> result;
        inOrderTraversal(root, result);
        return result;
    }

};

#endif
