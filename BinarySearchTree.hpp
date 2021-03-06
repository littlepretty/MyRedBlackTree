#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <iostream>
#include "BinaryTree.hpp"

class BinarySearchTree: public BinaryTree
{
    public:
        explicit BinarySearchTree(int rootKey);
        virtual ~BinarySearchTree();

        virtual BinaryTreeNode* insert(int key);

        virtual BinaryTreeNode* search(int key);
};

#endif
