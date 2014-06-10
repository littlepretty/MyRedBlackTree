#include "RedBlackTree.hpp"

RedBlackTree::RedBlackTree(int rootKey): BinarySearchTree::BinarySearchTree(rootKey)
{
}

RedBlackTree::~RedBlackTree()
{
}

BinaryTreeNode* RedBlackTree::insert(int key)
{
    BinaryTreeNode* x = BinarySearchTree::insert(key);
    while(x != root && x->parent->color == RED && x->parent->parent != NULL)
    {
        if(x->parent == x->parent->parent->left) {
            BinaryTreeNode* y = x->parent->parent->right;
            if(y->color == RED) {
                // case 1
                x->parent->color = BLACK;
                y->color = BLACK;
                x = x->parent->parent;
                x->color = RED;

            } else {
                if(x == x->parent->right) {
                    // case 2
                    BinaryTreeNode* A = x->parent;
                    leftRotate(A);
                }
                // case 3
                BinaryTreeNode* B = x->parent;
                BinaryTreeNode* C = x->parent->parent;
                B->color = BLACK;
                C->color = RED;
                rightRotate(C);
            }
        } else {
            
        }
    }
    return NULL;
}

void RedBlackTree::leftRotate(BinaryTreeNode*& A)
{
    BinaryTreeNode* B = A->right;
    if(B != NULL) {
        B->parent = A->parent;
        
        if(A->parent != NULL) {
            if(A == A->parent->left) {
                A->parent->left = B;
            } else {
                A->parent->right = B;
            }
        } else { // A was root, now B should be root
            root = B;
        }
        
        // A->parent = NULL;
        A->right = B->left;
        B->left->parent = A;
        // B->left = NULL;
        
        A->parent = B;
        B->left = A;
    }
}

void RedBlackTree::rightRotate(BinaryTreeNode*& A)
{
    BinaryTreeNode* B = A->left;
    if(B != NULL) {
        B->parent = A->parent;
        
        if(A->parent != NULL) {
            if(A == A->parent->left) {
                A->parent->left = B;
            } else {
                A->parent->right = B;
            }
        } else { // A was root, now B should be root
            root = B;
        }
        
        // A->parent = NULL;
        A->left = B->right;
        B->right->parent = A;
        // B->left = NULL;
        
        A->parent = B;
        B->right = A;
    }
}
