//Programmer: 	Tony Montemuro
//Section: 		3
//Lab:			Project
//Date:			November 29th, 2020
//Description:	Definitions of the methods declared in "LinkedList.hpp".

#include <iostream>

using namespace std;

template <class item_t>
LinkedList<item_t>::LinkedList()
{
	/*
		Precond: An object of class LinkedList is declared.
		Postcond: The attributes of ArrayList are initialized to default values, creating an empty list; head = 0, tail = 0, and size = 0.
	*/
	head = 0;
	tail = 0;
	size = 0;
}

template <class item_t>
void LinkedList<item_t>::addToEmpty(const item_t& item)
{
	/*
		Precond: Either pushBack() or pushFront() has been run on an empty LinkedList.
		Postcond: The head node is set equal to a new LinkedListNode which is constructed using the item parameter. Then, tail is set equal to head, since size has increased to 1.
	*/
	head = new LinkedListNode<item_t>(0, item);
	tail = head;
}

template <class item_t>
void LinkedList<item_t>::removeSizeOne()
{
	/*
		Precond: Either popBack() or popFront() has been run on a LinkedList with a size of 1.
		Postcond: Tail is set equal to 0. Then, delete and deallocate the node head is pointing to. Then, set head equal to 0.
	*/
	tail = 0;
	delete head;
	head = tail;
}

template <class item_t>
LinkedListNode<item_t>* LinkedList<item_t>::getNode(int index) const
{
	/*
		Precond: An object of class LinkedList is declared and constructed; size > 0 and index < size.
		Postcond: The index-th node is returned.
	*/
	LinkedListNode<item_t>* t = head;
	for (int i = 0; i < index; i++)
	{
		t = t->getNext();
	}
	return t;
}


template <class item_t>
void LinkedList<item_t>::pushBack(const item_t& item)
{
	/*
		Precond: An object of class LinkedList is declared.
		Postcond: If the list is empty, addToEmpty() method is run. Otherwise, the tail pointer is set equal to a new LinkedListNode, which is constructed using the item parameter.
	*/
	if (isEmpty())
	{
		addToEmpty(item);
	}
	else
	{
		tail->setNext(new LinkedListNode<item_t>(0, item));
		tail = tail->getNext();
	}
	size++;
}

template <class item_t>
void LinkedList<item_t>::popBack()
{
	/*
		Precond: An object of class LinkedList is declared and constructed, and size > 0.
		Postcond: The last node of the list is deleted and deallocated from memory.
	*/
	if(size == 1)
	{
		removeSizeOne();
	}
	//otherwise, set tail to the node before the last node, and delete and deallocate last node
	else
	{
		LinkedListNode<item_t>* r = head;
		while (r->getNext() != tail)
		{
			r = r->getNext();
		}
		tail = r;
		r = r->getNext();
		delete r;
		tail->setNext(0);
	}
	size--;
}

template <class item_t>
const item_t& LinkedList<item_t>::getBack() const
{
	/*
		Precond: An object of class LinkedList is declared and constructed, and size > 0.
		Postcond: The item in the last node is returned.
	*/
	return tail->getItem();
}

template <class item_t>
void LinkedList<item_t>::pushFront(const item_t& item)
{
	/*
		Precond: An object of class LinkedList is declared.
		Postcond: If the list is empty, addToEmpty() method is run. Otherwise, LinkedListNode t pointer is used to construct a new LinkedListNode using the item parameter and head as the next pointer. Then, head is set equal to t,
				  and size is increased.
	*/
	if (isEmpty())
	{
		addToEmpty(item);
	}
	else
	{
		LinkedListNode<item_t>* t = new LinkedListNode<item_t>(head, item);
		head = t;
	}
	size++;
}

template <class item_t>
void LinkedList<item_t>::popFront()
{
	/*
		Precond: An object of class LinkedList is declared and constructed, and size > 0.
		Postcond: The first node of the list is deleted and deallocated from memory.
	*/
	if (size == 1)
	{
		removeSizeOne();
	}
	else
	{
		LinkedListNode<item_t>* t = head;
		head = head->getNext();
		delete t;
	}
	size--;
}

template <class item_t>
const item_t& LinkedList<item_t>::getFront() const
{
	/*
		Precond: An object of class LinkedList is declared and constructed, and size > 0.
		Postcond: The item in the first node is returned.
	*/
	return head->getItem();
}

template <class item_t>
const item_t& LinkedList<item_t>::getItem(int index) const
{
	/*
		Precond: An object of class LinkedList is declared and constructed; size > 0 and index < size.
		Postcond: The item at index-th node is returned.
	*/
	return getNode(index)->getItem();
}

template <class item_t>
void LinkedList<item_t>::setItem(int index, const item_t& item)
{
	/*
		Precond: An object of class LinkedList is declared and constructed; size > 0 and index < size.
		Postcind: The item at index-th node is set to item parameter.
	*/
	getNode(index)->setItem(item);
}

template <class item_t>
void LinkedList<item_t>::insert(int index, const item_t& item)
{
	/*
		Precond: An object of class LinkedList is declared and constructed; size > 0 and index < size.
		Postcond: Node is constructed using item parameter and inserted into the list at the index-th position of the list.
	*/
	if (index == 0)
	{
		pushFront(item);
	}
	else if (index == size-1)
	{
		pushBack(item);
	}
	else
	{
		LinkedListNode<item_t>* t = getNode(index-1);
		LinkedListNode<item_t>* t_next = t->getNext();
		t->setNext(new LinkedListNode<item_t>(t_next, item));
		size++;
	}
}

template <class item_t>
void LinkedList<item_t>::remove(int index)
{
	/*
		Precond: An object of class LinkedList is declared and constructed; size > 0 and index < size.
		Postcond: The node at index-th position is deleted from the list and deallocated.
	*/
	if (index == 0)
	{
		popFront();
	}
	else if (index == size-1)
	{
		popBack();
	}
	else
	{
		LinkedListNode<item_t>* t = getNode(index-1);
		LinkedListNode<item_t>* nodeToDel = t->getNext();
		t->setNext(nodeToDel->getNext());
		delete nodeToDel;
		size--;
	}
}

template <class item_t>
int LinkedList<item_t>::getSize() const
{
	/*
		Precond: A LinkedList object has been declared and constructed.
		Postcond: The size of LinkedList is returned.
	*/
	return size;
}

template <class item_t>
bool LinkedList<item_t>::isEmpty() const
{
	/*
		Precond: A LinkedList object has been declared and constructed.
		Postcond: If the size of the LinkedList is 0, true is returned. Otherwise, false is returned.
	*/
	return size == 0;
}

template <class item_t>
LinkedList<item_t>::~LinkedList()
{
	/*
		Precond: Destructor is manually called on object using delete, or program has terminated.
		Postcond: All nodes are deleted and deallocated from the LinkedList.
	*/
	LinkedListNode<item_t>* t;
	while (head != tail)
	{
		t = head;
		head = head->getNext();
		delete t;
	}
	delete head;
}
