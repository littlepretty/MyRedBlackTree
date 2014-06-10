#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <iostream>
#include "BinarySearchTree.hpp"

class RedBlackTree: public BinarySearchTree 
{
    public:
        explicit RedBlackTree(int rootKey);
        virtual ~RedBlackTree();

        virtual BinaryTreeNode* insert(int key);

    //private:
        void leftRotate(BinaryTreeNode*& A);
        void rightRotate(BinaryTreeNode*& A);

};

#endif
