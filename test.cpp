#include "BinaryTree.hpp"
#include "BinarySearchTree.hpp"

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
    std::cout<<tree<<std::endl;
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
    std::cout<<tree<<std::endl;
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
    TestBinarySearchTree();
}
