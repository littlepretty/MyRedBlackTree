#include "BinaryTree.hpp"
#include "BinarySearchTree.hpp"
#include "RedBlackTree.hpp"
#include <fstream>
#include <iostream>

void TestBinaryTree()
{
    BinaryTree tree(5);
    tree.insert(3);
    tree.insert(6);
    tree.insert(9);
    tree.insert(1);
    tree.insert(2);
    tree.insert(4);
    tree.insert(7);
    tree.insert(8);
    
    tree.preOrderPrint(); 
}

void TestBinarySearchTree()
{
    BinarySearchTree tree(5);
    tree.insert(3);
    tree.insert(6);
    tree.insert(9);
    tree.insert(1);
    tree.insert(2);
    tree.insert(4);
    tree.insert(7);
    tree.insert(8);
    tree.preOrderPrint(); 
    

    tree.search(4);
    tree.search(8);
    tree.search(10);
    
}

void TestRedBlackTreeRotate()
{
    RedBlackTree tree(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(6);
    tree.insert(8); 

    BinaryTreeNode* node = tree.search(5);
    tree.inOrderPrint();

    tree.leftRotate(node);
    tree.inOrderPrint();

    node = tree.search(7);
    tree.rightRotate(node);
    tree.inOrderPrint();

}

void TestRedBlackTree()
{
    RedBlackTree tree(5);
    tree.insert(3);
    tree.insert(6);
    tree.insert(9);
    tree.insert(1);
    tree.insert(2);
    tree.insert(4);
    tree.insert(7);
    tree.insert(8);
    tree.preOrderPrint();
}

void TestFlipCoin()
{
    std::cout<<"---------Flip Coin Test---------"<<std::endl;
    FlipCoin* coin = new FlipCoin(0.5);
    for(int i = 0; i < 10; i++)
    {
        coin->flipCoinOnce();
    }
    delete coin;
}

int main()
{
    // TestFlipCoin();
    // TestBinaryTree();
    //TestBinarySearchTree();
    TestRedBlackTreeRotate();
    // TestRedBlackTree();
}
