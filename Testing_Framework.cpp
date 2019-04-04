#include "Dictionary.h"		// Dictionary class
using namespace Containers;	// Namespace used by dictionary class

void main()
{
	Dictionary A;	// Create a dictionary

	A.insert("63", "Alan");				// Testing insert function
	A.insert("22", "Ben");				// Testing insert function
	A.insert("21", "Catherine");		// Testing insert function
	A.insert("34", "Charlotte");		// Testing insert function
	A.insert("60", "Christine");		// Testing insert function
	A.insert("37", "David");			// Testing insert function
	A.insert("22", "Name Overwritten");	// Testing insert function for overwriting existing node

	A.lookup("37");		// Testing lookup function
	A.lookup("34");		// Testing lookup function
	A.lookup("21");		// Testing lookup function
	A.lookup("22");		// Testing lookup function
	A.lookup("63");		// Testing lookup function
	A.lookup("60");		// Testing lookup function
	A.lookup("1000");	// Testing lookup function on non-existing entry

	Dictionary B = A;	// Testing copy constructor

	A.remove("21");		// Testing remove function
	A.remove("22");		// Testing remove function
	A.remove("34");		// Testing remove function
	A.remove("37");		// Testing remove function
	A.remove("60");		// Testing remove function
	A.remove("63");		// Testing remove function
	A.remove("99");		// Testing remove function on non-existing entry

	Dictionary C = Dictionary(std::move(B));	// Testing move function with move constructor
	Dictionary D;								// Testing move function with overloaded operator
	D = std::move(C);							// Testing move function with overloaded operator

	system("pause");	// System call to pause program (Windows only)
}