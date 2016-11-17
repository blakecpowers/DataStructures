#include <iostream>
#include "list.h"

//
// main.cc serves as a driver for the program.  In this case, there is
// a sequence of List operations that exercise various test cases.  Your
// implementation should execute all these test cases successfully.
//

int
main(int argc, char **argv)
{
	class List l;
	NodePtr n;
	int i;

	std::cout << "Insert 10 nodes\n";
	for (i = 10; i > 0; i--) {
		n = new Node();
		n->val = i;
		l.Insert(n);
	}
	l.Print();
	std::cout << "\n";

	std::cout << "Remove value 5\n";
	n = l.Find(5);
	if (n == NULL) {
		std::cout << "Value 5 not found\n";
		return (-1);
	}
	l.Remove(n);

	l.Print();
	std::cout << "\n";

	std::cout << "Remove value 10\n";
	n = l.Find(10);
	if (n == NULL) {
		std::cout << "Value 10 not found\n";
		return (-1);
	}
	l.Remove(n);

	l.Print();
	std::cout << "\n";

	std::cout << "Remove value 1\n";
	n = l.Find(1);
	if (n == NULL) {
		std::cout << "Value 1 not found\n";
		return (-1);
	}
	l.Remove(n);

	l.Print();
	std::cout << "\n";

	std::cout << "Remove value 9\n";
	n = l.Find(9);
	if (n == NULL) {
		std::cout << "Value 9 not found\n";
		return (-1);
	}
	l.Remove(n);

	l.Print();
	std::cout << "\n";

	return 0;
}
