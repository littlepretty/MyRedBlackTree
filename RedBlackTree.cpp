#include "RedBlackTree.hpp"

RedBlackTree::RedBlackTree(int rootKey): BinarySearchTree::BinarySearchTree(rootKey)
{
    root->color = BLACK;
}

RedBlackTree::~RedBlackTree()
{
}

BinaryTreeNode* RedBlackTree::insert(int key)
{
    BinaryTreeNode* x = BinarySearchTree::insert(key);
    BinaryTreeNode* result = x;
    while(x != root && x->parent->color == RED && x->parent->parent != NULL)
    {
        std::cout<<"---------Balancing Red Black Tree When Insert Node("<<x->key<<")---------"<<std::endl;
        if(x->parent == x->parent->parent->left) {
            BinaryTreeNode* y = x->parent->parent->right;
            if(y != NULL && y->color == RED) {
                // case 1
                std::cout<<"---------Case 1: Lift Up "<<*x<<"---------"<<std::endl;
                x->parent->color = BLACK;
                y->color = BLACK;
                x = x->parent->parent;
                x->color = RED;
            } else {
                if(x == x->parent->right) {
                    // case 2
                    BinaryTreeNode* A = x->parent;
                    std::cout<<"---------Case 2: Left Rotate "<<*A<<"---------"<<std::endl;
                    leftRotate(A);
                    x = x->left;
                }
                // case 3
                BinaryTreeNode* B = x->parent;
                BinaryTreeNode* C = x->parent->parent;
                std::cout<<"---------Case 3: Right Rotate "<<*C<<"---------"<<std::endl;
                B->color = BLACK;
                C->color = RED;
                rightRotate(C);
            }
        } else {
            BinaryTreeNode* y = x->parent->parent->left;
            if(y != NULL && y->color == RED) {
                // case 1
                std::cout<<"---------Case 1: Lift Up "<<*x<<"---------"<<std::endl;
                x->parent->color = BLACK;
                y->color = BLACK;
                x = x->parent->parent;
                x->color = RED;
            } else {
                if(x == x->parent->left) {
                    // case 2
                    BinaryTreeNode* A = x->parent;
                    std::cout<<"---------Case 2: Right Rotate "<<*A<<"---------"<<std::endl;
                    rightRotate(A); // change rotate direction
                    x = x->right;
                }
                // case 3
                BinaryTreeNode* B = x->parent;
                BinaryTreeNode* C = x->parent->parent;
                std::cout<<"---------Case 3: Left Rotate "<<*C<<"---------"<<std::endl;
                B->color = BLACK;
                C->color = RED;
                leftRotate(C); // change rotate direction
            }
        }
    }
    root->color = BLACK;

    return result;
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
        if(B->left) {
            B->left->parent = A;
        }
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
        if(B->right != NULL) {
            B->right->parent = A;
        }
        // B->left = NULL;
        
        A->parent = B;
        B->right = A;
    }
}
