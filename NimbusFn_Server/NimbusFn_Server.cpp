// NimbusFn_Server.cpp : Defines the entry point for the application.
//

#include "NimbusFn_Server.h"

void sayhello() {
	std::cout << "Hello from a function" << '\n';
}

int main()
{
	sayhello();
	std::cout << "Hello CMake." << std::endl;
	return 0;
}
