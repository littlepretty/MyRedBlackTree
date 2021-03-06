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
    tree.BinarySearchTree::insert(1);
    tree.BinarySearchTree::insert(9);
    tree.BinarySearchTree::insert(3);
    tree.BinarySearchTree::insert(7);
    tree.BinarySearchTree::insert(6);
    //tree.preOrderPrint();
    tree.BinarySearchTree::insert(8);
    tree.BinarySearchTree::insert(11);
    tree.BinarySearchTree::insert(4);
    tree.BinarySearchTree::insert(2);

    // Set rotate functions as public before uncomment and test
    /*
    tree.inOrderPrint();
    BinaryTreeNode* node = tree.search(1); // search(3), search(2)
    tree.leftRotate(node);
    tree.inOrderPrint();
    */
    
    /*
    tree.inOrderPrint(); 
    BinaryTreeNode* node = tree.search(9); // search(7), search(6)
    tree.rightRotate(node);
    tree.inOrderPrint();
    */
    
    tree.preOrderPrint();
}

void TestRedBlackTreeInsert()
{
    RedBlackTree tree(1);
    for(int i = 2; i < 32; i++)
    {
        tree.insert(i);
    }
    /*
    tree.insert(2);
    tree.insert(3);
    tree.inOrderPrint();

    tree.insert(4);
    tree.inOrderPrint();
    tree.insert(5);
    
    tree.inOrderPrint();
    tree.insert(6);
    
    tree.inOrderPrint();
    tree.insert(7);
    tree.inOrderPrint();
    
    tree.insert(8);
    tree.inOrderPrint();
    tree.insert(9);
    */

    tree.inOrderPrint();
    tree.preOrderPrint();
    tree.treeHeight();

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
    //TestFlipCoin();
    //TestBinaryTree();
    //TestBinarySearchTree();
    //TestRedBlackTreeRotate();
    TestRedBlackTreeInsert();
}
