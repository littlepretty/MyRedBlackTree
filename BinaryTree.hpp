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
    void inOrderPrint() const;
    void preOrderPrint() const;

    friend std::ostream& operator<<(std::ostream& os, const BinaryTreeNode& node);

    private:
        std::string getColorDescription() const;
};

class BinaryTree
{
    private:
        FlipCoin* coin;

    protected:
        BinaryTreeNode* root;
        int numNodes;
        BinaryTreeNode* insertAsLeftChild(BinaryTreeNode*& parent, int key);
        BinaryTreeNode* insertAsRightChild(BinaryTreeNode*& parent, int key);

    public:
        explicit BinaryTree(int rootKey);
        virtual ~BinaryTree();
        
        virtual BinaryTreeNode* insert(int key);

        void inOrderPrint() const;
        void preOrderPrint() const;

        // friend std::ostream& operator<<(std::ostream& os, const BinaryTree& tree);
};

#endif


