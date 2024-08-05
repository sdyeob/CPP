#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	std::string	str;
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else {
		for (int i = 1; i < argc; i++) { str += argv[i]; }
		for (size_t i = 0; i < str.length(); i++) { str[i] = toupper(str[i]); }
		std::cout << str;
	}
	std::cout << std::endl;
	return (0);
}
