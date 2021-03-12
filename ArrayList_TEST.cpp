//Programmer: 	Tony Montemuro
//Section: 		3
//Lab:			Project
//Date:			October 11th, 2020
//Description:	This program tests the methods declared in "ArrayList.hpp" and defined in "ArrayList.tpp".

#include <iostream>
#include <string>

#include "ArrayList.hpp"

using namespace std;

int main() {
	//General Testing
	ArrayList<char> a;
	ArrayList<int> b(50);
	ArrayList<string> c;
	ArrayList<int> d(2);
	ArrayList<int> e(1);
	
	cout << "Capacity of arraylist a after construction: " << a.getCapacity() << endl;
	cout << "Capacity of arraylist b after construction (capacity initialized with parameter): " << b.getCapacity() << endl << endl;
	
	for (int i = 'a'; i <= 'z'; i++)
	{
		a.pushBack(i);
	}
	for (int i = 0; i < 75; i++)
	{
		b.pushFront(i);
	}
	cout << "Capacity of arraylist A after pushing back 26 elements: " << a.getCapacity() << endl;
	cout << "Capacity of arraylist B after pushing front 75 elements: " << a.getCapacity() << endl << endl;
	
	cout << "First element of arraylist A: " << a.getFront() << endl;
	cout << "Last element of arraylist A: " << a.getBack() << endl << endl;
	
	cout << "First element of arraylist B: " << b.getFront() << endl;
	cout << "Last element of arraylist B: " << b.getBack() << endl << endl;
	
	a.pushFront('X');
	cout << "First element of arraylist A after pushing 1 character to the front: " << a.getFront() << endl << endl;
	
	a.popFront();
	cout << "First element of arraylist A after removing character at the front of the list using popFront(): " << a.getFront() << endl << endl;
	
	cout << "5th element of arraylist B: " << b.getItem(5) << endl;
	cout << "Size of arraylist B: " << b.getSize() << endl;
	b.remove(5);
	cout << "5th element of arraylist B after removing 5th element: " << b.getItem(5) << endl;
	cout << "Size of arraylist B after removing 5th element: " << b.getSize() << endl << endl;
	
	cout << "Last element of arraylist B: " << b.getBack() << endl;
	b.setItem(73, 100);
	cout << "Last element of arraylist after setting to new value using setItem(int, item_t): " << b.getBack() << endl << endl;
	
	cout << "14th element of arraylist a: " << a.getItem(14) << endl;
	cout << "Size of arraylist a: " << a.getSize() << endl;
	a.insert(14, '!');
	cout << "14th element of arraylist a after inserting new value at index 14 using insert(int, item_t): " << a.getItem(14) << endl;
	cout << "Size of arraylist a after inserting new value at index 14 using insert(int, item_t): " << a.getSize() << endl << endl;
	
	if(c.isEmpty())
	{
		cout << "Arraylist c is empty." << endl;
	}
	else
	{
		cout << "Arraylist c is not empty." << endl;
	}
	
	if(b.isEmpty())
	{
		cout << "Arraylist b is empty." << endl << endl;
	}
	else
	{
		cout << "Arraylist b is not empty." << endl << endl;
	}
	
	//Testing exceptional cases
	string temp = "a";
	for (int i = 0; i < 10; i++)
	{
		temp += "a";
		c.pushBack(temp);
	}
	cout << "Capacity of arraylist c: " << c.getCapacity() << endl;
	c.pushFront("a");
	cout << "Capacity of arraylist c after pushing a new element to the front using pushFront(): " << c.getCapacity() << endl << endl;
	
	for (int i = 0; i < 2; i++)
	{
		d.insert(i, i);
	}
	cout << "Capacity of arraylist d: " << d.getCapacity() << endl;
	d.pushBack(2);
	cout << "Capacity of arraylist d after pushing a new element to the back using pushBack(): " << d.getCapacity() << endl << endl;

	e.pushBack(2);
	cout << "Capacity of arraylist e: " << e.getCapacity() << endl;
	e.insert(0, 1);
	cout << "Capacity of arraylist e after inserting a new element at index 0 using insert(int, item_t): " << e.getCapacity() << endl;
	return 0;
}
