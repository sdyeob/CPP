
#include <iostream>
#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cout << "Error" << std::endl;
		return (-1);
	}

	RPN rpn(argv[1]);
	try
	{
		rpn.calculate();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
