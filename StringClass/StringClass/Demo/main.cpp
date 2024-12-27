#include <iostream>

#include "String.h"

int main()
{
	String string("Ronnie");
	std::cout << string << '\n';

	string = "Test String\n";
	std::cout << string << '\n';
	std::cout << string.Length() << '\n';

	std::cout << ((string == "Ronnie") ? "True" : "False") << '\n';
}