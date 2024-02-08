/**
* @file avltree.cpp
* @description avl ağacı ile ilgili fonksiyonlar
* @course 2/A
* @assignment 2.ödev
* @date 24 ARALIK 2023
* @author Ayşe Verda Gülcemal ayseeverda@gmail.com
*/
#include "avltree.hpp"
#include <algorithm>

AVLNode::AVLNode(int val) : data(val), left(nullptr), right(nullptr), height(1) {}

AVLTree::AVLTree() : root(nullptr) {}

int AVLTree::height(AVLNode* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

int AVLTree::getBalance(AVLNode* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

AVLNode* AVLTree::rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode* AVLTree::leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLNode* AVLTree::insert(AVLNode* node, int key) {
    if (node == nullptr)
        return new AVLNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->data)
        return rightRotate(node);

    if (balance < -1 && key > node->right->data)
        return leftRotate(node);

    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int AVLTree::postorderSumOfNonLeafNodes(AVLNode* node) {
    if (node == nullptr)
        return 0;

    int leftSum = postorderSumOfNonLeafNodes(node->left);
    int rightSum = postorderSumOfNonLeafNodes(node->right);

    if (node->left || node->right) {
        return leftSum + rightSum + node->data; // Include non-leaf nodes
    }

    return leftSum + rightSum;
}
void AVLTree::postorderLeafNodesToStack(AVLNode* node) {
    if (node == nullptr)
        return;

    postorderLeafNodesToStack(node->left);
    postorderLeafNodesToStack(node->right);

    if (node->left == nullptr && node->right == nullptr) {
        leafStack.ekle(node->data);
    }
}

void AVLTree::processLeafStack() {
	cout <<"bu avl agacinin yapraklari postorder sekilde yigina yerlesti"<<endl;
    while (leafStack.tepe != nullptr) {
        int leafData = leafStack.getir();
        // Process the leaf data as needed
        // For example, print or perform some operation
        cout << "  "<< leafData <<endl;

        // Remove the leaf node from the stack
        leafStack.cikar();
    }
}