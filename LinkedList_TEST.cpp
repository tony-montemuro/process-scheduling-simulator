//Programmer: 	Tony Montemuro
//Section: 		3
//Lab:			Project
//Date:			November 29th, 2020
//Description:	This program tests the methods declared in "LinkedList.hpp" and defined in "LinkedList.tpp".

#include <iostream>
#include <string>

#include "LinkedList.hpp"

using namespace std;

template <class item_t>
void empty(LinkedList<item_t>&);

int main()
{
	LinkedList<int> a;
	LinkedList<char> b;
	LinkedList<string> c;
	
	cout << "Test A: Testing isEmpty() & getSize() methods on empty linked-list a, then," << endl;
	cout << "after pushing back some nodes, testing it again." << endl;
	empty(a);
	cout << "Pushing back 5 integer nodes..." << endl;
	for (int i = 0; i < 5; i++)
	{
		a.pushBack(i);
	}
	empty(a);
	cout << endl;
	
	cout << "Test B: Testing popBack() method. popBack all elements of list a." << endl;
	for (int i = 0; i < 5; i++)
	{
		a.popBack();
		cout << "Popped back one element! New size: " << a.getSize() << "\t";	
	}
	cout << endl << endl;
	
	cout << "Test C: Testing pushFront(), getFront(), getBack(), and popFront() methods on list b. Use pushFront() to fill" << endl;
	cout << "b with all 26 letters. Then, getFront() should return 'a', while getBack() should return 'z'." << endl;
	cout << "Finally, popFront() all 26 elements, and see if the list is empty afterwards." << endl;
	for (char i = 'z'; i >= 'a'; i--)
	{
		b.pushFront(i);
	}
	cout << "Front of list b using getFront() method: " << b.getFront() << endl;
	cout << "Back of list b using getBack() method: " << b.getBack() << endl;
	cout << "Popping front all 26 elements..." << endl;
	for (int i = 0; i < 26; i++)
	{
		b.popFront();
	}
	empty(b);
	cout << endl;
	
	cout << "Test D: Testing getItem(), setItem(), insert(), and remove() methods on list c. First, use pushBack() to fill" << endl;
	cout << "c with 6 elements. This will be printed to screen using getItem(). Then, use setItem() to replace all 6 elements with new elements" << endl;
	cout << "and they will be once again printed to screen using getItem(). Finally, both insert() and remove() will be tested on the first, last, and" << endl;
	cout << "a middle element of list c." << endl;
	
	//fill and print c using pushBack and getItem respectively
	string t = "a";
	for (int i = 0; i <= 5; i++)
	{
		c.pushBack(t);
		cout << c.getItem(i) << "\t";
		t += "a";
	}
	cout << endl;
	
	//replace all 6 elements using setItem(), and print result to console
	c.setItem(0, "this");
	c.setItem(1, "sentence");
	c.setItem(2, "is");
	c.setItem(3, "pretty");
	c.setItem(4, "much");
	c.setItem(5, "incomplete");
	cout << "List c after replacing each element using setItem() method:" << endl;
	for (int i = 0; i < c.getSize(); i++)
	{
		cout << c.getItem(i) << "\t";
	}
	cout << endl;
	
	//insert new elements to list c using insert() method and print result to screen
	c.insert(0, "No");
	c.insert(4, "not");
	c.insert(7, "silly");
	cout << "List c after inserting new elements using insert() method:" << endl;
	for (int i = 0; i < c.getSize(); i++)
	{
		cout << c.getItem(i) << "\t";
	}
	cout << endl;
	
	//remove the new elements from list c using remove() method and print results to screen
	c.remove(0);
	c.remove(3);
	c.remove(6);
	cout << "List c after removing new elements using remove() method:" << endl;
	for(int i = 0; i < c.getSize(); i++)
	{
		cout << c.getItem(i) << "\t";
	}
	cout << endl;
	
	return 0;
	
	
}

template <class item_t>
void empty(LinkedList<item_t>& a)
{
	if (a.isEmpty())
	{
		cout << "a is empty, a has a size of " << a.getSize() << "." << endl;
	}
	else
	{
		cout << "a is not empty, a has a size of " << a.getSize() << "." << endl;
	}
}
