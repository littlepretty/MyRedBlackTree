#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <iostream>
#include <string>
#include "FlipCoin.hpp"

enum Color { BLACK, RED};

struct BinaryTreeNode
{
    int key;
    Color color;

    BinaryTreeNode* parent;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    explicit BinaryTreeNode(int k);

    virtual ~BinaryTreeNode();

    private:
        std::string getColorDescription();
};

class BinaryTree
{
    private:
        FlipCoin* coin;

    protected:
        BinaryTreeNode* root;
        int numNodes;
        void insertAsLeftChild(BinaryTreeNode*& parent, int key);
        void insertAsRightChild(BinaryTreeNode*& parent, int key);

    public:
        explicit BinaryTree(int rootKey);
        virtual ~BinaryTree();
        
        virtual void insert(int key); 

        friend std::ostream& operator<<(std::ostream& os, const BinaryTree& tree);
};

#endif


