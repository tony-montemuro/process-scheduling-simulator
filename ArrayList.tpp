//Programmer: 	Tony Montemuro
//Section: 		3
//Lab:			Project
//Date:			October 11th, 2020
//Description:	Definitions of the methods declared in "ArrayList.hpp".

#include "ArrayList.hpp"

template <class item_t>
ArrayList<item_t>::ArrayList()
{
	/*
		Precond: An object of class ArrayList is declared with no parameters.
		Postcond: The attributes of ArrayList are initialized to default values; size = 0, capacity = 10, and memory is allocated for items array of capacity 10
	*/
	size = 0;
	capacity = 10;
	items = new item_t[capacity];
}

template <class item_t>
ArrayList<item_t>::ArrayList(int capacity)
{
	/*
		Precond: An object of class ArrayList is declared with capacity parameter.
		Postcond: The attributes of ArrayList are initialized using capacity parameter; size = 0, capacity = capacity, and memory is allocated for items array of capacity 'capacity'
	*/
	size = 0;
	this->capacity = capacity;
	items = new item_t[capacity];
}

template <class item_t>
void ArrayList<item_t>::capIncrease()
{
	/*
		Precond: An object of class ArrayList is declared and initlaized.
		Postcond: The capacity of items is doubled.
	*/
	item_t* temp = new item_t[capacity*2];
	for (int i = 0; i < capacity; i++)
	{
		temp[i] = items[i];		
	}
	delete[] items;
	items = temp;
	capacity *= 2;	
}

template <class item_t>
void ArrayList<item_t>::pushBack(const item_t& item)
{
	/*
		Precond: An ArrayList object has been declared and constructed, item is a constant reference of type item_t.
		Postcond: Item has been pushed to the end of the list. If the array was full before this method, capacity is doubled by copying old array into a new array, and item pushed to end of new array. Size is incremented.
	*/
	if (size == capacity)
	{
		capIncrease();
		items[size] = item;
		size++;
	}
	else
	{
		items[size] = item;
		size++;
	}
	return;
}

template <class item_t>
void ArrayList<item_t>::popBack()
{
	/*
		Precond: An ArrayList object has been declared and constructed, and the list has a size greater than 0.
		Postcond: The size of the array has been decreased by one (assuming the list has any items).
	*/
	if (size > 0)
	{
		size--;	
	}
}

template <class item_t>
const item_t& ArrayList<item_t>::getBack() const
{
	/*
		Precond: An ArrayList object has been declared and constructed, and has a size greater than 0.
		Postcond: The last element of the array is returned.
	*/
	return items[size-1];
}

template <class item_t>
void ArrayList<item_t>::pushFront(const item_t& item)
{
	/*
		Precond: An ArrayList object has been declared and constructed, item is type item_t.
		Postcond: All items in the array have shifted one position to the right, and item has been pushed to the front of the list. Capacity of the list is doubled if needed.
	*/
	if (size == capacity)
	{
		capIncrease();
	}
	for (int i = size; i > 0; i--)
	{
		items[i] = items[i-1];	
	}	
	items[0] = item;
	size++;
}

template <class item_t>
void ArrayList<item_t>::popFront()
{
	/*
		Precond: An ArrayList object has been declared and constructed, and has a size greater than 0.
		Postcond: The first element of the list is "popped" out of the list.
	*/
	for (int i = 0; i < size-1; i++)
	{
		items[i] = items[i+1];
	}
	size--;
}

template<class item_t>
const item_t& ArrayList<item_t>::getFront() const
{
	/*
		Precond: An ArrayList Object has been declared and constructed, and has a size greater than 0.
		Postcond: The last element of the list is returned.
	*/
	return items[0];
}

template <class item_t>
const item_t& ArrayList<item_t>::getItem(int index) const
{
	/*
		Precond: An ArrayList Object has been declared and constructed, and has a size greater than 0.
		Postcond: The element at index in the list is returned.
	*/
	return items[index];
}

template <class item_t>
void ArrayList<item_t>::setItem(int index, const item_t& item)
{
	/*
		Precond: An ArrayList object has been declared and constructed, and has a size greater than 0. Index is >=0. Item is of type item_t.
		Postcond: Item at index has been set equal to item.
	*/
	items[index] = item;
}

template <class item_t>
void ArrayList<item_t>::insert(int index, const item_t& item)
{
	/*
		Precond: An ArrayList object has been declared and constructed, and has a size greater than 0. Index is >= 0. Item is of type item_t.
		Postcond: Item has been placed at index, and all elements at and to the right of index have shifted over to the right once.
	*/
	if (size == capacity)
	{
		capIncrease();
	}
	for (int i = size; i > index; i--)
	{
		items[i] = items[i-1];
	}
	items[index] = item;
	size++;
}

template <class item_t>
void ArrayList<item_t>::remove(int index)
{
	/*
		Precond: An ArrayList object has been declared and constructed, and has a size greater than 0. Index is >= 0.
		Postcond: Element at index has been removed from list, and all elements to the right of index have been shifted over one position to the left.
	*/
	for (int i = index; i < size-1; i++)
	{
		items[i] = items[i+1];
	}
	size--;
}

template <class item_t>
int ArrayList<item_t>::getSize() const
{
	/*
		Precond: An ArrayList object has been declared and constructed.
		Postcond: The size of ArrayList is returned.
	*/
	return size;
}

template <class item_t>
bool ArrayList<item_t>::isEmpty() const
{
	/*
		Precond: An ArrayList object has been declared and constructed.
		Postcond: If the size of the array is 0, true is returned. Otherwise, false is returned.
	*/
	if (size == 0)
	{
		return true;
	}
	return false;
}

template <class item_t>
int ArrayList<item_t>::getCapacity() const
{
	/*
		Precond: An ArrayList object has been declared and constructed.
		Postcond: The capacity of ArrayList is returned.
	*/
	return capacity;
}

template <class item_t>
ArrayList<item_t>::~ArrayList()
{
	/*
		Precond: Destructor is manually called on object using delete, or program has terminated.
		Postcond: The item array is deleted from memory, and capacity is set to -1 to signify the deconstructor has been called.
	*/
	delete[] items;
	capacity = -1;
}
