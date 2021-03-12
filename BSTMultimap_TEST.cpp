//Programmer: 	Tony Montemuro
//Section: 		3
//Lab:			Project
//Date:			November 28th, 2020
//Description:	This program tests the methods declared in "BSTMultimap.hpp" and defined in "BSTMultimap.tpp".

#include <iostream>
#include "BSTMultimap.hpp"

void emptyTest(bool, int);
string containsTest(bool);

int main() {
	//Test 1: Testing isEmpty(), getSize(), insert(), and toString()
	cout << "Test 1: Testing isEmpty(), getSize(), insert(), and toString() methods." << endl;
	BSTMultimap<int, int> tree1;
	cout << "tree1 is an empty BSTMultimap." << endl;
	emptyTest(tree1.isEmpty(), tree1.getSize());
	tree1.toString(); //should return "Tree in Level-Order: "
	tree1.insert(5, 5);	/*														5			*/
	tree1.insert(3, 3);	/*													   / \  		*/
	tree1.insert(7, 7);	/*													  3	  7 		*/
	cout << "tree1 now is a nonempty BSTMultimap with 3 elements." << endl;
	emptyTest(tree1.isEmpty(), tree1.getSize());
	tree1.toString(); //should return "Tree in Level-Order: 5 3 7"
	BSTMultimap<double, string> tree2;
	tree2.insert(5.0, "5.0");	/*													5.0 		*/
	tree2.insert(3.5, "3.5");	/*												   /   \  		*/
	tree2.insert(9.3, "9.3");	/*												 3.5	9.3  	*/
	tree2.insert(4.4, "4.4");	/*												/   \   / 		*/
	tree2.insert(0.1, "0.1");	/*											   0.1 4.4 8.7  	*/
	tree2.insert(8.7, "8.7");											
	cout << "tree2 is a non-empty BSTMultimap with 6 elements." << endl;
	emptyTest(tree2.isEmpty(), tree2.getSize());
	tree2.toString(); //should return "Tree in Level-Order: 5.0, 3.5, 9.3, 0.1, 4.4, 8.7
	BSTMultimap<int, char> tree3;
	tree3.insert(10, 'a');	/*																			10							*/
	tree3.insert(8, 'b');	/*																		   /							*/	
	tree3.insert(6, 'c');	/*																		  8								*/
	tree3.insert(4, 'd');	/*																		 /								*/
	tree3.insert(2, 'e');	/*																		6								*/
							/*																	   /								*/
							/*																	  4									*/
							/*																	 /									*/	
							/*																	2									*/
	cout << "tree3 is a non-empty BSTMultimap with 5 elements." << endl;
	emptyTest(tree3.isEmpty(), tree3.getSize());
	tree3.toString(); //should return "Tree in Level-Order: 10, 8, 6, 4, 2
	
	//Test 2: Testing contains() and clear()
	BSTMultimap<int, int> emptyTree;
	cout << endl << "Test 2: Testing contains() and clear() methods." << endl;
	cout << "TREE1: " << endl;
	tree1.toString();
	cout << "contains(3) returns: " << containsTest(tree1.contains(3)) << endl;
	cout << "contains(7) returns: " << containsTest(tree1.contains(7)) << endl;
	cout << "contains(6) reutnrs: " << containsTest(tree1.contains(6)) << endl;	
	cout << "TREE2: " << endl;
	tree2.toString();
	cout << "contains(4.4) returns: " << containsTest(tree2.contains(4.4)) << endl;
	cout << "contains(5.1) returns: " << containsTest(tree2.contains(5.1)) << endl;
	cout << "contains (100.0) returns: " << containsTest(tree2.contains(100.0)) << endl;
	cout << "TREE3: " << endl;
	tree3.toString();
	cout << "contains(10) returns: " << containsTest(tree3.contains(10)) << endl;
	cout << "contains(4) returns: "	<< containsTest(tree3.contains(4)) << endl;
	cout << "contains(3) returns: " << containsTest(tree3.contains(3)) << endl;
	cout << "EMPTY TREE: " << endl;
	emptyTree.toString();
	cout << "contains(1) returns: " << containsTest(emptyTree.contains(1)) << endl;
	cout << "contains(2) returns: "	<< containsTest(emptyTree.contains(2)) << endl;
	cout << "contains(3) returns: " << containsTest(emptyTree.contains(3)) << endl;
	cout << "Clearing tree1..." << endl;
	tree1.clear();
	cout << "Now, tree1 is an empty BSTMultimap." << endl;
	emptyTest(tree1.isEmpty(), tree1.getSize());
	cout << "Clearing tree2..." << endl;
	tree2.clear();
	cout << "Now, tree2 is an empty BSTMultimap." << endl;
	emptyTest(tree2.isEmpty(), tree2.getSize());
	cout << "Clearing tree3..." << endl;
	tree3.clear();
	cout << "Now, tree3 is an empty BSTMultimap." << endl;
	emptyTest(tree3.isEmpty(), tree3.getSize());
	cout << "Clearing emptyTree..." << endl;
	emptyTree.clear();
	cout << "emptyTree is still an empty BSTMultimap." << endl;
	emptyTest(emptyTree.isEmpty(), emptyTree.getSize());
	
	//Test 3: Testing methods from BSTForwardIterator class: next(), isPastEnd(), getKey(), getValue(), and setValue()
	//		  also testing getMin() method from BSTMultimap class
	cout << endl << "Test 3: Testing BSTForwardIterator class and getMin() method from BSTMultimap class." << endl;
	tree1.insert(10, 10);	/*												10																*/
	tree1.insert(5, 5);		/*											   /  \																*/
	tree1.insert(3, 9);		/*											  5	  15															*/
	tree1.insert(7, 7);		/*											 / \  /	\															*/
	tree1.insert(15, 15);	/*											3  7 11  18   														*/
	tree1.insert(18, 18);	/*												\																*/
	tree1.insert(11, 11);	/*												 9																*/
	tree1.insert(9, 9);
	cout << "TREE 1:" << endl;
	tree1.toString();
	tree2.insert(1.0, "0.0");		/*											1.0															*/
	tree2.insert(10.0, "10.0");		/*											   \														*/
	tree2.insert(2.0, "2.0");		/*												10.0													*/
	tree2.insert(100.0, "100.0");	/*												/														*/
	tree2.insert(3.0, "3.0");		/*											   2.0														*/
									/*												\														*/
									/*												 100.0													*/
									/*												  /														*/
									/*												3.0														*/
	cout << "TREE 2:" << endl;
	tree2.toString();
	tree3.insert(10, 'e');	/*												10																*/
	tree3.insert(5, 'b');	/*											   /  \																*/
	tree3.insert(2, 'z');	/*											  5   15															*/
	tree3.insert(7, 'c');	/*											 / \  / \ 															*/
	tree3.insert(5, 'd');	/*											2  7 12	 20															*/
	tree3.insert(15, 'h');	/*												\ \																*/
	tree3.insert(12, 'f');	/*												 5 12 															*/
	tree3.insert(20, 'i');	/*																												*/
	tree3.insert(12, 'g');
	cout << "TREE 3:" << endl;
	tree3.toString();
	BSTForwardIterator<int, int> tree1_it = tree1.getMin();
	cout << "Running getMin().getKey() on tree1 returns: " << tree1_it.getKey() << endl;
	cout << "and getMin().getValue() on tree1 returns: " << tree1_it.getValue() << endl;
	BSTForwardIterator<double, string> tree2_it = tree2.getMin();
	cout << "Running getMin().getKey() on tree2 returns: " << tree2_it.getKey() << endl;
	cout << "and getMin().getValue() on tree2 returns: " << tree2_it.getValue() << endl;
	BSTForwardIterator<int, char> tree3_it = tree3.getMin();
	cout << "Running getMin().getKey() on tree1 returns: " << tree3_it.getKey() << endl;
	cout << "and getMin().getValue() on tree3 returns: " << tree3_it.getValue() << endl;
	cout << "Running getMin().setValue() on each tree to correct values..." << endl;
	//Just testing to see if method runs at all
	BSTForwardIterator<int, int> emptyTree_it = emptyTree.getMin();
	tree1_it.setValue(3);
	tree2_it.setValue("1.0");
	tree3_it.setValue('e');
	cout << "Running getMin().getValue() on tree1 now returns: " << tree1_it.getValue() << endl;
	cout << "Running getMin().getValue() on tree2 now returns: " << tree2_it.getValue() << endl;
	cout << "Running getMin().getValue() on tree3 now returns: " << tree3_it.getValue() << endl;
	cout << "Using next() method to print all keys of tree1 in-order order: " << endl;
	//This also tests isPastEnd(), since it determines when this loop ends (same applies for other 2 trees).
	while (!tree1_it.isPastEnd())
	{
		cout << tree1_it.getKey() << " ";
		tree1_it.next();
	}
	cout << endl << "Using next() method to print all keys of tree2 in-order order: " << endl;
	while (!tree2_it.isPastEnd())
	{
		cout << tree2_it.getKey() << " ";
		tree2_it.next();
	}
	cout << endl << "Using next() method to print all keys of tree3 in-order order: " << endl;
	while (!tree3_it.isPastEnd())
	{
		cout << tree3_it.getKey() << " ";
		tree3_it.next();
	}
	
	//Test 4: Testing getMax(), findFirst(), and findLast() methods of BSTMultimap
	cout << endl << endl << "Test 4: Testing BSTMultimap methods getMax(), findFirst(), and findLast()." << endl;
	BSTForwardIterator<int, int> tree1_it2 = tree1.getMax();
	cout << "Running getMax().getKey() on tree1 returns: " << tree1_it2.getKey() << endl;
	cout << "and getMax().getValue() on tree1 returns: " << tree1_it2.getValue() << endl;
	BSTForwardIterator<double, string> tree2_it2 = tree2.getMax();
	cout << "Running getMax().getKey() on tree2 returns: " << tree2_it2.getKey() << endl;
	cout << "and getMax().getValue() on tree2 returns: " << tree2_it2.getValue() << endl;
	BSTForwardIterator<int, char> tree3_it2 = tree3.getMax();
	cout << "Running getMax().getKey() on tree3 returns: " << tree3_it2.getKey() << endl;
	cout << "and getMax().getValue() on tree3 returns: " << tree3_it2.getValue() << endl;
	//Just testing to see if method runs at all
	BSTForwardIterator<int, int> emptyTree_it2 = emptyTree.getMax();
	BSTMultimap<int, float> tree4;
	tree4.insert(5, 1.0);	/*										5																*/
	tree4.insert(3, 1.0);	/*									  /    \															*/
	tree4.insert(4, 1.0);	/*									3		7															*/
	tree4.insert(1, 1.0);	/*								  /	  \		  \															*/
	tree4.insert(3, 2.0);	/*								 1	   4	   9														*/
	tree4.insert(3, 3.0);	/*									  /	 	  /	  														*/
	tree4.insert(7, 1.0);	/*									 3		 8															*/
	tree4.insert(9, 1.0);	/*									  \		  \															*/
	tree4.insert(8, 1.0);	/*									   3	   7														*/
	tree4.insert(7, 2.0);
	cout << "TREE 4:" << endl;
	tree4.toString();
	BSTForwardIterator<int, float> tree4_it1 = tree4.findFirst(9);
	BSTForwardIterator<int, float> tree4_it2 = tree4.findLast(9);
	cout << "tree4.findFirst(9) returns key: " << tree4_it1.getKey() << " and value: " << tree4_it1.getValue() << endl;
	cout << "tree4.findLast(9) returns key: " << tree4_it2.getKey() << " and value: " << tree4_it2.getValue() << endl;
	tree4_it1 = tree4.findFirst(7);
	tree4_it2 = tree4.findLast(7);
	cout << "tree4.findFirst(7) returns key: " << tree4_it1.getKey() << " and value: " << tree4_it1.getValue() << endl;
	cout << "tree4.findLast(7) returns key: " << tree4_it2.getKey() << " and value: " << tree4_it2.getValue() << endl;
	tree4_it1 = tree4.findFirst(3);
	tree4_it2 = tree4.findLast(3);
	cout << "tree4.findFirst(3) returns key: " << tree4_it1.getKey() << " and value: " << tree4_it1.getValue() << endl;
	cout << "tree4.findLast(3) returns key: " << tree4_it2.getKey() << " and value: " << tree4_it2.getValue() << endl;
	tree4_it1 = tree4.findFirst(11);
	tree4_it2 = tree4.findLast(11);
	if (tree4_it1.isPastEnd() && tree4_it2.isPastEnd())
	{
		cout << "Both tree4.findFirst(11) and tree4.findLast(11) returned iterators whose current pointers are sentinel," << endl;
		cout << "since 11 is not a key found in tree4!" << endl;
	}
	else
	{
		cout << "Error! This result is unexpected." << endl;
	}
	
	//Test 5: Testing the remove() method of BSTMultimap
	cout << endl << "Test 5: Testing BSTMultimap method delete()." << endl;
	tree1_it = tree1.getMin();
	tree2_it = tree2.getMax();
	tree3_it = tree3.getMin();
	tree4_it1 = tree4.getMin();
	emptyTree_it = emptyTree.getMin();
	cout << "First, deleting all nodes of tree1 using only remove() method." << endl;
	while (!tree1_it.isPastEnd())
	{
		tree1_it = tree1.remove(tree1_it);
	}
	cout << "Success! Tree 1 cleared! ";
	emptyTest(tree1.isEmpty(), tree1.getSize());
	cout << "Now, attempting to remove root node of tree3. Should maintain tree structure afterwards." << endl;
	cout << "Tree 3 before removing root node: " << endl;
	tree3.toString();
	for (int i = 0; i < 4; i++)
	{
		tree3_it.next();
	}
	tree3_it = tree3.remove(tree3_it);
	cout << "Tree 3 after removing root node: " << endl;
	tree3.toString();
	cout << "Next, deleting the max node of tree 2." << endl;
	cout << "Tree 2 before removing max node: " << endl;
	tree2.toString();
	tree2_it = tree2.remove(tree2_it);
	cout << "Tree 2 after removing max node: " << endl;
	tree2.toString();
	if (tree2_it.isPastEnd())
	{
		cout << "tree2_it is past end of tree, meaning return was successful." << endl;
	}
	else
	{
		cout << "tree2_it is not past end of tree, meaning return was unsuccessful." << endl;
	}
	//Just testing to see if method runs at all
	emptyTree_it = emptyTree.remove(emptyTree_it);
	return 0;
}

void emptyTest(bool empty, int size)
{
	if (empty)
	{
		cout << "isEmpty() returns true, and getSize() returns " << size << endl;
	}
	else
	{
		cout << "isEmpty() returns false, and getSize() returns " << size << endl;
	}
}

string containsTest(bool contains)
{
	if (contains)
	{
		return "true";
	}
	else
	{
		return "false";
	}
}


