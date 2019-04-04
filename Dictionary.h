#include <string>	// String library

namespace Containers	// Namespace for class
{
	class Dictionary	// Class Dictionary
	{
	public:
		using Key = std::string;	// Alias
		using Item = std::string;	// Alias

		Dictionary() = default;			// Default constructor
		Dictionary(const Dictionary&);	// Copy constructor
		Dictionary(Dictionary &&);		// Move constructor

		void insert(Key, Item);	// Insert function
		Item* lookup(Key);		// Lookup function
		void remove(Key);		// Remove function

		Dictionary& operator = (Dictionary&&);	// Move operator
	private:
		struct Node;			// Node structure
		Node* root = nullptr;	// Starting node

		void insertWorker(Key, Item, Node*&);	// Insert worker function
		static Item* lookupWorker(Key, Node*);	// Lookup worker function
		void removeWorker(Key, Node*&);			// Remove worker function
		static Node* deepCopyWorker(Node*);		// Copy worker function
	};
}