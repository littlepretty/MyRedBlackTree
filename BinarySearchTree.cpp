#include "BinarySearchTree.hpp"

BinarySearchTree::BinarySearchTree(int rootKey): BinaryTree::BinaryTree(rootKey)
{
}

BinarySearchTree::~BinarySearchTree()
{
}

BinaryTreeNode* BinarySearchTree::insert(int key)
{
    BinaryTreeNode* current = root;
    // std::cout<<"Check Root "<<root->key<<std::endl;
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
                BinaryTreeNode* result = insertAsLeftChild(current, key);
                return result;
            } else {
                current = current->left;
                // continue;
            }
        }
        else if (current->key < key){
            if(current->right == NULL) {
                std::cout<<"Node("<<key<<") Inserted As Right Child of Node("<<current->key<<")"<<std::endl;
                BinaryTreeNode* result = insertAsRightChild(current, key);
                return result;
            } else {
                current = current->right;
                // continue;
            }
        } else {
            std::cout<<"Node("<<key<<") Already Exsists"<<std::endl;
            return current;
        }
    }
    return NULL;
}

BinaryTreeNode* BinarySearchTree::search(int key)
{
    BinaryTreeNode* current = root;
    while(current != NULL)
    {
        if(current->key < key) {
            current = current->right;
        } else if(current->key > key) {
            current = current->left;
        } else {
            std::cout<<"Find Node("<<current->key<<") in Tree"<<std::endl;
            return current;
        }
    }
    std::cout<<"Cannot Find Node("<<key<<") in Tree"<<std::endl;
    return NULL;
}
