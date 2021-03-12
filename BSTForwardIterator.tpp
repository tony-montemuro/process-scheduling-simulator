//Programmer: 	Tony Montemuro
//Section: 		3
//Lab:			Project
//Date:			November 21st, 2020
//Description:	Definitions of the methods declared in "BSTForwardIterator.hpp".

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t>::BSTForwardIterator(BSTNode<key_t, val_t>* node, BSTNode<key_t, val_t>* sentinel)
{
	/*
		Precond: An object of type BSTForwardIterator has been declared.
		Postcond: current is initialized to the value of node, and sentinel is initialized to the value of the sentinel parameter.
	*/
	current = node;
	this->sentinel = sentinel;
}

template <class key_t, class val_t>
void BSTForwardIterator<key_t, val_t>::next()
{
	/*
		Precond: An object of type BSTForwardIterator has been declared and constructed.
		Postcond: current is set to the next node in an in-order traversal of the tree. If current is sentinel, however, the method does nothing.
	*/
	//Case 1: Current is equal to sentinel pointer (terminates method)
	if (current == sentinel)
	{
		return;
	}
	//Case 2: Right Child Exists (meaning next node must be a child node)
	if (current->getRightChild() != sentinel)
	{
		current = current->getRightChild();
		while (current->getLeftChild() != sentinel)
		{
			current = current->getLeftChild();
		}
	}
	//Case 3: Right Child Does Not Exist (meaning next node must be a parent node)
	else
	{
		while (current->getParent() != sentinel && current == current->getParent()->getRightChild())
		{
			current = current->getParent();
		}
		current = current->getParent();
	}
}

template <class key_t, class val_t>
bool BSTForwardIterator<key_t, val_t>::isPastEnd() const
{
	/*
		Precond: An object of type BSTForwardIterator has been declared and constructed.
		Postcond: If current is equal to sentinel, true is return. Otherwise, false is returned.
	*/
	return current == sentinel;
}

template <class key_t, class val_t>
const key_t& BSTForwardIterator<key_t, val_t>::getKey() const
{
	/*
		Precond: An object of type BSTForwardIterator has been declared and constructed; current is not sentinel.
		Postcond: The key at current is returned.
	*/
	return current->getKey();
}

template <class key_t, class val_t>
const val_t& BSTForwardIterator<key_t, val_t>::getValue() const
{
	/*
		Precond: An object of type BSTForwardIterator has been declared and constructed; current is not sentinel.
		Postcond: The value at current is returned.
	*/
	return current->getValue();
}

template <class key_t, class val_t>
void BSTForwardIterator<key_t, val_t>::setValue(const val_t& newVal)
{
	/*
		Precond: An object of type BSTForwardIterator has been declared and constructed; newVal is of type const val_t&, and current is not sentinel.
		Postcond: The value at current is set equal to newVal.
	*/
	current->setValue(newVal);
}
