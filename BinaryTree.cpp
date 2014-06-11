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
    os<<"Node("<<node.key<<")  ";
    return os;
}

void BinaryTreeNode::inOrderPrint() const 
{
    // In-Order Traverse for BST
    std::cout<<"Node("<<key<<")  ";
    
    if(left != NULL) {
        // (*left).inOrderPrint(os);
        // std::cout<<*(left);
        (*left).inOrderPrint();
    }

    if(right != NULL) {        
        // std::cout<<*(right);
        (*right).inOrderPrint();
    }
    // return os;
}

void BinaryTreeNode::preOrderPrint() const 
{
    // Pre-Order Traverse for BST
    if(left != NULL) {
        (*left).preOrderPrint();
        // std::cout<<*(left);
    }

    std::cout<<"Node("<<key<<")  ";
    
    if(right != NULL) {
        (*right).preOrderPrint();
        // std::cout<<*(right);
    }
    // return os;
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

BinaryTreeNode* BinaryTree::insert(int key)
{
    BinaryTreeNode* current = root;
    while(true) {
        if(current->left == NULL) {
            std::cout<<"Insert "<<key<<" As Left of Node("<<current->key<<")"<<std::endl;
            BinaryTreeNode *result = insertAsLeftChild(current, key);
            return result;
        } else if(current->right == NULL) {
            std::cout<<"Insert "<<key<<" As Right of Node("<<current->key<<")"<<std::endl;
            BinaryTreeNode* result = insertAsRightChild(current, key);
            return result;
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

BinaryTreeNode* BinaryTree::insertAsLeftChild(BinaryTreeNode*& parent, int key)
{
    BinaryTreeNode* left = new BinaryTreeNode(key);
    parent->left = left;
    left->parent = parent;
    return left;
}

BinaryTreeNode* BinaryTree::insertAsRightChild(BinaryTreeNode*& parent, int key)
{
    BinaryTreeNode* right = new BinaryTreeNode(key);
    parent->right = right;
    right->parent = parent;
    return right;
}

void BinaryTree::inOrderPrint() const
{
    if(root != NULL) {
        (*root).inOrderPrint();
    }
    std::cout<<std::endl;
}
void BinaryTree::preOrderPrint() const
{
    if(root != NULL) {
        (*root).preOrderPrint();
    }
    std::cout<<std::endl;
}

/*
std::ostream& operator<<(std::ostream& os, const BinaryTree& tree)
{
    // os<<"---------Pred-Order Traverse Tree---------"<<std::endl;
    // os<<*(tree.root)<<std::endl;
    return tree.preOrderPrint(os);
    // return os<<std::endl;
}
*/


