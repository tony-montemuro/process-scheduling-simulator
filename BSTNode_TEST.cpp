//Programmer: 	Tony Montemuro
//Section: 		3
//Lab:			Project
//Date:			November 29th, 2020
//Description:	This program tests the methods declared in "BSTNode.hpp" and defined in "BSTNode.tpp".

#include <iostream>
#include <string>
#include "BSTNode.hpp"

using namespace std;

int main() 
{
	//Test 1: Setters and Getters for Key and Value
	cout << "Test 1: Testing Setter and Getter Methods for Key and Value attributes." << endl;
	cout << "First, node1<int, char> is initialized with key of 2 and value of b." << endl;
	BSTNode<int, char> node1(2, 'b');
	cout << "getKey() returns: " << node1.getKey() << " and getValue() returns: " << node1.getValue() << endl;
	cout << "Using setKey() to set key to 1 and setValue to set value to a." << endl;
	node1.setKey(1);
	node1.setValue('a');
	cout << "getKey() returns: " << node1.getKey() << " and getValue() returns: " << node1.getValue() << endl << endl;
	
	//Test 2: Setters and Getters for Child and Parent Pointers
	cout << "Test 2: Testing Setter and Getter Methods for Child and Parent attributes." << endl;
	cout << "First node2<double, string> is initialized with key of 2.0 and value of 'val2'." << endl;
	BSTNode<double, string>* node2 = new BSTNode<double, string>(2.0, "val2");
	cout << "getKey() returns: " << node2->getKey() << " and getValue() returns: " << node2->getValue() << endl;
	cout << "Now, using setLeftChild() and setRightChild(), this node will have a left child with key of 1.0 and value of 'val1'," << endl;
	cout << "and a right child with key of 3.0 and a value of 'val3'." << endl;
	node2->setLeftChild(new BSTNode<double, string>(1.0, "val1"));
	node2->setRightChild(new BSTNode<double, string>(3.0, "val3"));
	cout << "getLeftChild()->getKey() returns: " << node2->getLeftChild()->getKey() << " and getRightChild()->getKey() returns: " << node2->getRightChild()->getKey() << endl;
	cout << "getLeftChild()->getValue() returns: " << node2->getLeftChild()->getValue() << " and getRightChild()->getValue() returns: " << node2->getRightChild()->getValue() << endl;
	cout << "Now, the parent pointer of each child pointer will be set to node2 pointer using setParent()." << endl;
	node2->getLeftChild()->setParent(node2);
	node2->getRightChild()->setParent(node2);
	cout << "getLeftChild()->getParent()->getKey() returns: " << node2->getLeftChild()->getParent()->getKey() << " and getRightChild->getParent()->getKey() returns: " << node2->getRightChild()->getParent()->getKey() << endl;
	cout << "getLeftChild()->getParent()->getValue() returns: " << node2->getLeftChild()->getParent()->getValue() << " and getRightChild->getParent()->getValue() returns: " << node2->getRightChild()->getParent()->getValue() << endl;
	
	//Deallocate Dynamic Memory
	delete node2->getLeftChild();
	node2->setLeftChild(0);
	delete node2->getRightChild();
	node2->setRightChild(0);
	delete node2;
	
	return 0;
}
