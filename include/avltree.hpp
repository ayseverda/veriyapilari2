/**
* @file avltree.hpp
* @description avltree.cpp metotlarını topladık
* @course 2/A
* @assignment 2.ödev
* @date 24 ARALIK 2023
* @author Ayşe Verda Gülcemal ayseeverda@gmail.com
*/

#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP
#include "yigin.hpp"
struct AVLNode {
	
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int val);
};

class AVLTree {
	private:
    Yigin leafStack;
public:
    AVLNode* root;

    AVLTree();

    int height(AVLNode* node);
    int getBalance(AVLNode* node);
    AVLNode* rightRotate(AVLNode* y);
    AVLNode* leftRotate(AVLNode* x);
    AVLNode* insert(AVLNode* node, int key);
    int postorderSumOfNonLeafNodes(AVLNode* node);
	void postorderLeafNodesToStack(AVLNode* node);
    void processLeafStack();
};

#endif // AVL_TREE_HPP