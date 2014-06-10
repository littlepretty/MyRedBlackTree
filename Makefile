CC = g++
CFLAGS = -c -Wall -std=c++11
LDFLAGS = 

RBTree: test.o FlipCoin.o BinaryTree.o BinarySearchTree.o RedBlackTree.o
	$(CC) test.o BinaryTree.o FlipCoin.o BinarySearchTree.o RedBlackTree.o -o RBTree

test.o: test.cpp
	$(CC) $(CFLAGS) test.cpp

FlipCoin.o: FlipCoin.cpp
	$(CC) $(CFLAGS) FlipCoin.cpp

BinaryTree.o: BinaryTree.cpp
	$(CC) $(CFLAGS) BinaryTree.cpp

BinarySearchTree.o: BinarySearchTree.cpp
	$(CC) $(CFLAGS) BinarySearchTree.cpp

RedBlackTree.o: RedBlackTree.cpp
	$(CC) $(CFLAGS) RedBlackTree.cpp

clean:
	rm -rf *.o RBTree
