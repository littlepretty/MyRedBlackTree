CC = g++
CFLAGS = -c -Wall -std=c++11
LDFLAGS = 

RBTree: test.o FlipCoin.o BinaryTree.o
	$(CC) test.o BinaryTree.o FlipCoin.o -o RBTree

test.o: test.cpp
	$(CC) $(CFLAGS) test.cpp

FlipCoin.o: FlipCoin.cpp
	$(CC) $(CFLAGS) FlipCoin.cpp

BinaryTree.o: BinaryTree.cpp
	$(CC) $(CFLAGS) BinaryTree.cpp

#SkipListNode.o: SkipListNode.cpp
#	$(CC) $(CFLAGS) SkipListNode.cpp

#SkipList.o: SkipList.cpp
#	$(CC) $(CFLAGS) SkipList.cpp

clean:
	rm -rf *.o RBTree
