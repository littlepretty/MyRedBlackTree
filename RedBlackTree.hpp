#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <iostream>
#include "BinarySearchTree.hpp"

class RedBlackTree: public BinarySearchTree 
{
    public:
        explicit RedBlackTree(int rootKey);
        virtual ~RedBlackTree();

        virtual void insert(int key);

    private:
        void leftRotate(BinaryTreeNode*& node);
        void rightRotate(BinaryTreeNode*& node);

};

#endif
