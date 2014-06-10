#include "BinarySearchTree.hpp"

BinarySearchTree::BinarySearchTree(int k): BinaryTree::BinaryTree(k)
{
}

BinarySearchTree::~BinarySearchTree()
{
}

void BinarySearchTree::insert(int key)
{
    BinaryTreeNode* current = root;
    std::cout<<"Check Root "<<root->key<<std::endl;
    while(current != NULL)
    {
        // std::cout<<"At Node("<<current->key<<")"<<std::endl;

        // std::cout<<"At Node("<<current->key<<")"<<std::endl;
        // std::cout<<"Compare "<<(current->key<key)<<std::endl;
        // std::cout<<"Check Left "<<current->left<<std::endl;
        // std::cout<<"Check Right "<<current->right<<std::endl;
    
        if(current->key > key) {
            if(current->left == NULL) {
                std::cout<<"Node("<<key<<") Inserted As Left Child of Node("<<current->key<<")"<<std::endl;
                insertAsLeftChild(current, key);
                return;
            } else {
                current = current->left;
                // continue;
            }
        }
        else if (current->key < key){
            if(current->right == NULL) {
                std::cout<<"Node("<<key<<") Inserted As Right Child of Node("<<current->key<<")"<<std::endl;
                insertAsRightChild(current, key);
                return;
            } else {
                current = current->right;
                // continue;
            }
        } else {
            std::cout<<"Node("<<key<<") Already Exsists"<<std::endl;
            return;
        }
    }
}
