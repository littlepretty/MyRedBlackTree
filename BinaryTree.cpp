#include "BinaryTree.hpp"


BinaryTreeNode::BinaryTreeNode(int k): key(k), color(RED), parent(NULL), left(NULL), right(NULL)
{
}

BinaryTreeNode::~BinaryTreeNode()
{
    if(left != NULL) {
        delete left;
        // left = NULL;
    }
    
    std::cout<<"---------Dispose "<<getColorDescription()<<" Node ("<<key<<")---------"<<std::endl;
    
    if(right != NULL) {
        delete right;
        // right = NULL;
    }
    // parent = NULL;
}

std::string BinaryTreeNode::getColorDescription()
{
    if(color == RED) {
        return "Red";
    } else {
        return "Black";
    }
}

std::ostream& operator<<(std::ostream& os, const BinaryTreeNode& node)
{
    // Pre-Order Traverse for BST
    if(node.left != NULL) {
        os<<*(node.left)<<"\t";
    }

    os<<"Node("<<node.key<<")\t";
    
    if(node.right != NULL) {
        os<<*(node.right)<<"\t";
    }
    return os;
}



BinaryTree::BinaryTree(int rootKey): root(new BinaryTreeNode(rootKey)), numNodes(1)
{
    coin = new FlipCoin(0.5);
}

BinaryTree::~BinaryTree()
{
    std::cout<<"---------Dispose Tree----------"<<std::endl;
    numNodes = 0;
    if(root != NULL)
    {
        std::cout<<"---------Dispose Node----------"<<std::endl;
        delete root;
    }
    std::cout<<"---------Nodes Disposed---------"<<std::endl;
    if(coin != NULL)
    {
        std::cout<<"---------Dispose FlipCoin---------"<<std::endl;
        delete coin;
    }
}

void BinaryTree::insert(int key)
{
    BinaryTreeNode* current = root;
    while(true) {
        if(current->left == NULL) {
            std::cout<<"Insert "<<key<<" As Left of Node("<<current->key<<")"<<std::endl;
            insertAsLeftChild(current, key);
            break;
        } else if(current->right == NULL) {
            std::cout<<"Insert "<<key<<" As Right of Node("<<current->key<<")"<<std::endl;
            insertAsRightChild(current, key);
            break;
        } else {
            if(coin->flipCoinOnce()) {
                current = current->left;
                // std::cout<<"turn left"<<std::endl;
            } else {
                current = current->right;
                // std::cout<<"turn right"<<std::endl;
            }
        }
    }
}

void BinaryTree::insertAsLeftChild(BinaryTreeNode*& parent, int key)
{
    BinaryTreeNode* left = new BinaryTreeNode(key);
    parent->left = left;
    left->parent = parent;
}

void BinaryTree::insertAsRightChild(BinaryTreeNode*& parent, int key)
{
    BinaryTreeNode* right = new BinaryTreeNode(key);
    parent->right = right;
    right->parent = parent;
}

std::ostream& operator<<(std::ostream& os, const BinaryTree& tree)
{
    os<<"---------Pred-Order Traverse Tree---------"<<std::endl;
    os<<*(tree.root)<<std::endl;
    return os<<std::endl;
}

