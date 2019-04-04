#include "Dictionary.h"		// Dictionary header
using namespace Containers; // Namespace for dictionary

struct Dictionary::Node
{
	Key key;				// Key variable
	Item item;				// Item variable
	Node* child = nullptr;	// Child node variable
	Node(Key, Item);		// Node constructor
};

Dictionary::Node::Node(Key K, Item I)
{
	key = K;	// Initialise variable
	item = I;	// Initialise variable
}

void Dictionary::insert(Key K, Item I)
{
	insertWorker(K, I, this->root); // Call insertWorker function with this dictionary's root
}

void Dictionary::insertWorker(Key K, Item I, Node*& N)
{
	if (N == nullptr)	// Current node is nullptr
	{
		N = new Node(K, I);	// Construct node
	}
	else if (K == N->key)	// Key matches with current node's key
	{
		N->item = I;	// Overwrite current node item with new item
	}
	else	// Current node not nullptr
	{
		insertWorker(K, I, N->child);	// Call insertWorker function with child pointer
	}
}

Dictionary::Item* Dictionary::lookup(Key K)
{
	return lookupWorker(K, root);	// Call lookupWorker function
}

Dictionary::Item* Dictionary::lookupWorker(Key K, Node* N)
{
	if (N == nullptr)	// Current node is nullptr
	{
		return nullptr;	// Return nullptr
	}
	else if (K == N->key)	// Key matches with current node's key
	{
		return &N->item;	// Return item
	}
	else	// Current node not nullptr and does not match key
	{
		return lookupWorker(K, N->child);	// Call lookupWorker function with child pointer and return the item
	}
}

void Dictionary::remove(Key K)
{
	removeWorker(K, root);	// Call removeWorker function
}

void Dictionary::removeWorker(Key K, Node*& N)
{
	if (N == nullptr) // Current node is nullptr
	{
		// Do nothing
	}
	else if (K == N->key)	// Key matches with current node's key
	{
		if (N->child == nullptr)	// Current node child is nullptr
		{
			delete N;		// Delete node
			N = nullptr;	// Set node to nullptr
		}
		else	// Current node child not nullptr
		{
			Node* temp;		// Create temporary node
			temp = N;		// Temporary node equal to current node
			N = N->child;	// Current node pointer becomes child pointer
			delete temp;	// Temporary node deleted
		}
	}
	else	// Current node not nullptr and does not match key
	{
		removeWorker(K, N->child);	// Call removeWorker function with child pointer
	}
}

Dictionary::Dictionary(const Dictionary& original)
{
	this->root = deepCopyWorker(original.root);	// Set this dictionary's root node equal to the node's root returned from deepCopyWorker
}

Dictionary::Node* Dictionary::deepCopyWorker(Node* original)
{
	Node* copy = new Node(original->key, original->item);	// Use node constructor to make a copy of the original node

	if (original->child == nullptr)	// Original node's child is a nullptr
	{
		copy->child = nullptr;	// Copied node's child set to nullptr
	}
	else	// Original node's child is not a nullptr
	{
		copy->child = deepCopyWorker(original->child); // Set copied node's child to the returned value of deepCopyWorker function
	}
	return copy;	// Return copied node
}

Dictionary::Dictionary(Dictionary&& original)
{
	Dictionary temp = original;	// Create temporary dictionary
	this->root = temp.root;		// Set this dictionary's root equal equal to temporary dictionary's root
	delete original.root;		// Delete original dictionary's root
	original.root = nullptr;	// Set original dictionary's root to nullptr
}

Dictionary& Dictionary::operator = (Dictionary&& original)
{
	Dictionary temp = original;	// Create temporary dictionary
	this->root = temp.root;		// Set this dictionary's root equal to temporary dictionary's root
	delete original.root;		// Delete original dictinary's root
	original.root = nullptr;	// Set original dictionary's root to nullptr
	return *this;				// Return this dictionary
}