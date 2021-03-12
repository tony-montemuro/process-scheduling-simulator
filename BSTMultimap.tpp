//Programmer: 	Tony Montemuro
//Section: 		3
//Lab:			Project
//Date:			November 29th, 2020
//Description:	Definitions of the methods declared in "BSTMultimap.hpp".

template <class key_t, class val_t>
BSTMultimap<key_t, val_t>::BSTMultimap()
{
	/*
		Precond:  An object of type BSTMultimap has been declared.
		Postcond: The sentinel pointer is initialized to 0, root is initialized to sentinel, and numItems is initialized to 0.
	*/
	sentinel = 0;
	root = sentinel;
	numItems = 0;
}

template <class key_t, class val_t>
BSTNode<key_t, val_t>* BSTMultimap<key_t, val_t>::insertNode(BSTNode<key_t, val_t>* node, BSTNode<key_t, val_t>* r)
{
	/*
		Precond: An object of class BSTMultimap is declared and constructed; node is of type BSTNode<key_t, val_t>*.
		Postcond: Node is added to the BST based on the value of the node's key. If the node's key is less than the root's key, then the key is inserted on the left side of the tree.
				  If the node's key is greater than the root's key, then the key is inserted on the right side of the tree. Also, if the key already exists in the BST,
				  the node is inserted into a linked-list associated with that key within the tree.
	*/
	//Base Case
	if (r == sentinel)
	{
		r = node;
	}
	
	//Recursive Cases
	else if (node->getKey() < r->getKey())
	{
		r->setLeftChild(insertNode(node, r->getLeftChild()));
		r->getLeftChild()->setParent(r);
	}
	else
	{
		r->setRightChild(insertNode(node, r->getRightChild()));
		r->getRightChild()->setParent(r);	
	}
	return r;
}

template <class key_t, class val_t>
bool BSTMultimap<key_t, val_t>::containsKey(BSTNode<key_t, val_t>* r, const key_t& key) const
{
	/*
		Precond: An object of class BSTMultimap is declared and constructed; node is of type BSTNode<key_t, val_t>*, and key is of type const key_t&.
		Postcond: This method searches through the tree in search of key. It does this by checking whether the key parameter is greater than, less than, or equal to the key
		 		  in node.
	*/
	//Base Cases
	if (r == sentinel)
	{
		return false;
	}
	if (r->getKey() == key)
	{
		return true;	
	}

	//Recursive Cases
	if (key < r->getKey())
	{
		return containsKey(r->getLeftChild(), key);
	}
	else
	{
		return containsKey(r->getRightChild(), key);
	}
}

template<class key_t, class val_t>
BSTNode<key_t, val_t>* BSTMultimap<key_t, val_t>::firstNodeOfKey(BSTNode<key_t, val_t>* node, const key_t& key) const
{
	/*
		Precond: An object of class BSTMultimap is declared and constructed; node is of type BSTNode<key_t, val_t>*, and key is of type const key_t&. key also exists somewhere in the BST.
		Postcond: This method returns the first instance of a node of a particular key. Returns the sentinel node if node with particular key is not found.
	*/
	BSTNode<key_t, val_t>* r = node;
	while (r != sentinel && r->getKey() != key)
	{
		if (key < r->getKey())
		{
			r = r->getLeftChild();
		}
		else
		{
			r = r->getRightChild();
		}
	}
	return r;
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::removeNode(const BSTForwardIterator<key_t, val_t>& pos)
{
	/*
		Precond: An object of class BSTMultimap is declared and constructed; pos is of type BSTForwardIterator<key_t, val_t>.
		Postcond: The node that pos points to is removed from the tree, the tree is fixed, and an iterator to this nodes successor is returned. Recusion is used in the case of a node with two non-sentinel children.
	*/
	//Node to be deleted is temp
	BSTNode<key_t, val_t>* temp = pos.current;
	BSTForwardIterator<key_t, val_t> n(pos.current, pos.sentinel);
	n.next();
	//Case 2: The BSTNode stored in pos has no children.
	if (temp->getLeftChild() == sentinel && temp->getRightChild() == sentinel)
	{
		//This is only possible if current points to the head node
		if (temp->getParent() == sentinel)
		{
			delete temp;
			root = sentinel;
			return n;
		}
		//Set either the parent's left or right child equal to the sentinel node
		setParentChild(temp, sentinel);
		//Deleted node is deallocated from memory, and the successor node is returned in an iterator
		delete temp;
		return n;
	}
	//Case 3: The BSTNode stored in pos has one child.
	else if (temp->getLeftChild() != sentinel && temp->getRightChild() == sentinel)
	{
		//This is only possible if current points to the head node
		if (temp->getParent() == sentinel)
		{
			root = temp->getLeftChild();
			root->setParent(sentinel);
		}
		else
		{
			//The parent node of the node to be removed has one of it's children set equal to the node to be deleted's left child
			temp->getLeftChild()->setParent(temp->getParent());
			setParentChild(temp, temp->getLeftChild());
		}
		//Deleted node is deallocated from memory, and the successor node is returned in an iterator
		delete temp;
		return n;
	}
	else if (temp->getLeftChild() == sentinel && temp->getRightChild() != sentinel)
	{
		//This is only possible if current points to the head node
		if (temp->getParent() == sentinel)
		{
			root = temp->getRightChild();
			root->setParent(sentinel);
		}
		else
		{
			//The parent node of the node to be removed has it's right children set equal to the node to be deleted's right child
			temp->getRightChild()->setParent(temp->getParent());
			setParentChild(temp, temp->getRightChild());
		}
		//Deleted node is deallocated from memory, and the successor node is returned in an iterator
		delete temp;
		return n;
	}
	//Case 4: The BSTNode stored in pos has two children.
	else
	{
		//Key and values are copied from the next node in in-order order
		temp->setKey(n.current->getKey());
		temp->setValue(n.current->getValue());
		//Now, it is important to remove this next node from the tree, so remove is called again on the iterator that holds the next node. Storing the result in a dummy iterator, as it is unimportant.
		BSTForwardIterator<key_t, val_t> dummy = removeNode(n);
		return n;
	}
}

template <class key_t, class val_t>
void BSTMultimap<key_t, val_t>::setParentChild(BSTNode<key_t, val_t>* node, BSTNode<key_t, val_t>* child)
{
	/*
		Precond: node is of type BSTNode<key_t, val_t>*, child is of type BSTNode<key_t, val_t>*. This method is only run during removeNode() method.
		Postcond: If the node's paren't left child is equal to node, then the parent node's left child is set equal to child. Otherwise, the parent's node's right child is set equal to child.
	*/
	if (node->getParent()->getLeftChild() == node)
	{
		node->getParent()->setLeftChild(child);
	}
	else
	{
		node->getParent()->setRightChild(child);
	}
}

template <class key_t, class val_t>
void BSTMultimap<key_t, val_t>::insert(const key_t& key, const val_t& value)
{
	/*
		Precond: An object of class BSTMultimap is declared and constructed; key is of type const key_t&, and value is of type const val_t&.
		Postcond: A new node is constructed using the parameters, and is inserted into it's correct position into the BST. numItems is incremented as well.
	*/
	BSTNode<key_t, val_t>* temp = new BSTNode<key_t, val_t>(key, value);
	root = insertNode(temp, root);
	numItems++;
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::remove(const BSTForwardIterator<key_t, val_t>& pos)
{
	/*
		Precond: An object of class BSTMultimap is declared and constructed; pos is of type const BSTForwardIterator<key_t, val_t>&.
		Postcond: The node that pos points to is removed from the tree, and an iterator to this nodes successor is returned. numItems decreases by 1.
	*/
	//Case 1: The BSTNode stored in pos is the sentinel node.
	if (pos.current == sentinel)
	{
		return pos;
	}
	//Assuming the iterator is not pointing to the sentinel, numItems must be decreased, since it is certain that a node will be removed.
	numItems--;
	//Other 3 cases described in method below
	return removeNode(pos);
}

template <class key_t, class val_t>
void BSTMultimap<key_t, val_t>::clear()
{
	/*
		Precond: An object of class BSTMultimap is declared and constructed.
		Postcond: The entire tree is deleted from memory, meaning all nodes of the tree are deallocated from memory.
	*/
	queue<BSTNode<key_t, val_t>*> q;
	if (isEmpty())
	{
		return;
	}
	else
	{
		q.push(root);
		while(!q.empty())
		{
			BSTNode<key_t, val_t>* t = q.front();
			q.pop();
			if (t->getLeftChild() != sentinel)
			{
				q.push(t->getLeftChild());
			}
			if (t->getRightChild() != sentinel)
			{
				q.push(t->getRightChild());
			}
			BSTNode<key_t, val_t>* r = t->getParent();
			delete t;
			numItems--;
		}
		root = sentinel;
	}
}

template <class key_t, class val_t>
bool BSTMultimap<key_t, val_t>::contains(const key_t& key) const
{
	/*
		Precond: An object of class BSTMultimap is declared and constructed; key is of type const key_t&.
		Postcond: If key is found within the BST, true is returned. Otherwise, false is returned.
	*/
	return containsKey(root, key);
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::findFirst(const key_t& key) const
{
	/*
		Precond: An object of class BSTMultimap is declared and constructed; key is of type const key_t&.
		Postcond: This method returns an iterator pointing to the first node (in an in-order traversal) that has the given key. If key is not present, iterator to the sentinel is returned.
	*/
	return BSTForwardIterator<key_t, val_t>(firstNodeOfKey(root, key), sentinel);
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::findLast(const key_t& key) const
{
	/*
		Precond: An object of class BSTMultimap is declared and constructed; key is of type const key_t&.
		Postcond: This method returns an iterator pointing to the last node (in an in-order traversal) that has the given key. If key is not present, iterator to the sentinel is returned.
	*/
	BSTForwardIterator<key_t, val_t> lastIt(firstNodeOfKey(root, key), sentinel);
	if (lastIt.current == sentinel)
	{
		return lastIt;
	}
	BSTForwardIterator<key_t, val_t> nextIt(lastIt.current, sentinel);
	nextIt.next();
	while (nextIt.current != sentinel && lastIt.getKey() == nextIt.getKey())
	{
		lastIt.next();
		nextIt.next();
	}
	return lastIt;
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::getMin() const
{
	/*
		Precond: An object of class BSTMultimap is declared and constructed.
		Postcond: Returns the node with the minimum key in the tree packaged in a BSTForwardIterator object. If the tree is empty, an iterator pointing to the sentinel is returned.
	*/
	if (isEmpty())
	{
		return BSTForwardIterator<key_t, val_t>(sentinel, sentinel);
	}
	BSTNode<key_t, val_t>* min = root;
	while (min->getLeftChild() != sentinel)
	{
		min = min->getLeftChild();
	}
	return BSTForwardIterator<key_t, val_t>(min, sentinel);
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::getMax() const
{
	/*
		Precond: An object of class BSTMultimap is declared and constructed.
		Postcond: Returns the node with the maximum key in the tree packaged in a BSTForwardIterator object. If the tree is empty, an iterator pointing to the sentinel is returned.
	*/
	if (isEmpty())
	{
		return BSTForwardIterator<key_t, val_t>(sentinel, sentinel);
	}
	BSTNode<key_t, val_t>* max = root;
	while (max->getRightChild() != sentinel)
	{
		max = max->getRightChild();
	}
	return BSTForwardIterator<key_t, val_t>(max, sentinel);
}

template <class key_t, class val_t>
int BSTMultimap<key_t, val_t>::getSize() const
{
	/*
		Precond: An object of class BSTMultimap is declared and constructed.
		Postcond: Returns the number of items in the BST.
	*/
	return numItems;
}

template <class key_t, class val_t>
bool BSTMultimap<key_t, val_t>::isEmpty() const
{
	/*
		Precond: An object of class BSTMultimap is declared and constructed.
		Postcond: Returns true if the BST is empty, which is true when the root pointer points to sentinel; otherwise returns false.
	*/
	return root == sentinel;
}

template <class key_t, class val_t>
void BSTMultimap<key_t, val_t>::toString()
{
	/*
		Precond: An object of class BSTMultimap is declared and constructed.
		Postcond: This debugging method is used to print the BST in level-order.
	*/
	cout << "Tree in Level-Order: ";
	if (isEmpty())
	{
		cout << endl;
		return;
	}
	else
	{
		queue<BSTNode<key_t, val_t>*> q;
		q.push(root);
		while (!q.empty())
		{
			BSTNode<key_t, val_t>* t = q.front();
			q.pop();
			cout << t->getKey() << " ";
			if (t->getLeftChild() != sentinel)
			{
				q.push(t->getLeftChild());
			}
			if (t->getRightChild() != sentinel)
			{
				q.push(t->getRightChild());
			}
		}
		cout << endl;
	}
	
}

template <class key_t, class val_t>
BSTMultimap<key_t, val_t>::~BSTMultimap()
{
	/*
		Precond: An object of class BSTMultimap is declared and constructed, and the program has been terminated or a destructor has been called manually on an object of type BSTMultimap.
		Postcond: The clear() method is run. See postcond of clear() for more details.
	*/
	clear();
}
