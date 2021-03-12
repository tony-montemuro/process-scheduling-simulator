//Programmer: 	Tony Montemuro
//Section: 		3
//Lab:			Project
//Date:			November 29th, 2020
//Description:	Definitions of the methods declared in "BSTNode.hpp".

template <class key_t, class val_t>
BSTNode<key_t, val_t>::BSTNode(const key_t& key, const val_t& value)
{
	/*
		Precond: An object of class ArrayList is declared with two parameters: val value of type val_t, and key value of type key_t.
		Postcond: The attributes of ArrayList are initialized using parameters, and the pointer parameters are set equal to 0.
	*/
	this->key = key;
	this->value = value;
	leftChild = 0;
	rightChild = 0;
	parent = 0;
}

template <class key_t, class val_t>
const key_t& BSTNode<key_t, val_t>::getKey() const
{
	/*
		Precond: An object of class BSTNode is declared and constructed.
		Postcond: A constant reference to the node's key is returned.
	*/
	return key;	
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setKey(const key_t& newKey)
{
	/*
		Precond: An object of class BSTNode is declared and constructed; newKey is of type const key_t&.
		Postcond: Key is set equal to the parameter newKey.
	*/
	key = newKey;
}

template <class key_t, class val_t>
const val_t& BSTNode<key_t, val_t>::getValue() const
{
	/*
		Precond: An object of class BSTNode is declared and constructed.
		Postcond: A constant reference to the node's value is returned.
	*/
	return value;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setValue(const val_t& newValue)
{
	/*
		Precond: An object of class BSTNode is declared and constructed; newValue is of type const val_t&.
		Postcond: Value is set equal to the parameter newValue.
	*/
	value = newValue;
}

template <class key_t, class val_t>
BSTNode<key_t, val_t>* BSTNode<key_t, val_t>::getLeftChild() const
{
	/*
		Precond: An object of class BSTNode is declared and constructed.
		Postcond: The address of the node's left child is returned.
	*/
	return leftChild;
}

template <class key_t, class val_t>
BSTNode<key_t, val_t>* BSTNode<key_t, val_t>::getRightChild() const
{
	/*
		Precond: An object of class BSTNode is declared and constructed. 
		Postcond: The address of the node's right child is returned.
	*/
	return rightChild;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setLeftChild(BSTNode<key_t, val_t>* child)
{
	/*
		Precond: An object of class BSTNode is declared and constructed; child is of type BSTNode<key_t, val_t>*.
		Postcond: leftChild is set equal to the parameter child.
	*/
	leftChild = child;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setRightChild(BSTNode<key_t, val_t>* child)
{
	/*
		Precond: An object of class BSTNode is declared and constructed; child is of type BSTNode<key_t, val_t>*. 
		Postcond: rightChild is set equal to the parameter child.
	*/
	rightChild = child;
}

template <class key_t, class val_t>
BSTNode<key_t, val_t>* BSTNode<key_t, val_t>::getParent() const
{
	/*
		Precond: An object of class BSTNode is declared and constructed. 
		Postcond: The address of the node's parent is returned.
	*/
	return parent;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setParent(BSTNode<key_t, val_t>* newParent)
{
	/*
		Precond: An object of class BSTNode is declared and constructed; newParent is of type BSTNode<key_t, val_t>*.
		Postcond: parent is set equal to the parameter newParent.
	*/
	parent = newParent;
}
