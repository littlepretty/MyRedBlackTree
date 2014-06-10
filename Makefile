CC = g++
CFLAGS = -c -Wall -std=c++11
LDFLAGS = 

RBTree: test.o FlipCoin.o BinaryTree.o BinarySearchTree.o
	$(CC) test.o BinaryTree.o FlipCoin.o BinarySearchTree.o -o RBTree

test.o: test.cpp
	$(CC) $(CFLAGS) test.cpp

FlipCoin.o: FlipCoin.cpp
	$(CC) $(CFLAGS) FlipCoin.cpp

BinaryTree.o: BinaryTree.cpp
	$(CC) $(CFLAGS) BinaryTree.cpp

BinarySearchTree.o: BinarySearchTree.cpp
	$(CC) $(CFLAGS) BinarySearchTree.cpp

#SkipList.o: SkipList.cpp
#	$(CC) $(CFLAGS) SkipList.cpp

clean:
	rm -rf *.o RBTree
