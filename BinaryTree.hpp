#include <iostream>
#include "FlipCoin.hpp"

struct BinaryTreeNode
{
    int key;
    BinaryTreeNode* parent;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    explicit BinaryTreeNode(int k);

    virtual ~BinaryTreeNode();
};

class BinaryTree
{
    private:
        BinaryTreeNode* root;
        int numNodes;
        FlipCoin* coin;

        void insertAsLeftChild(BinaryTreeNode*& parent, int key);
        void insertAsRightChild(BinaryTreeNode*& parent, int key);

    public:
        explicit BinaryTree(int rootKey);
        virtual ~BinaryTree();
        
        virtual void insert(int key); 

        friend std::ostream& operator<<(std::ostream& os, const BinaryTree& tree);
};
