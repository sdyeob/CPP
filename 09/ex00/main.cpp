
#include <iostream>
#include <fstream>
#include <exception>
#include "BitcoinExchange.hpp"

std::pair<std::string, float>	check_line_validate(const std::string& input_fstring);

int main (int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Error: could not open file." << std::endl;
		exit(1);
	}

	std::ifstream in(argv[1]);
	std::string file_string;

	if (in.is_open()) {
		std::getline (in, file_string);
		BitcoinExchange exchager;
		while(std::getline (in, file_string)) {
			try {
				std::pair<std::string, float> p_data = check_line_validate(file_string);
				exchager.Exchange(p_data);
			} catch(const std::exception& e) {
				std::cerr << e.what() << '\n';
			}
		}
	} else {
		std::cout << "Error: could not open file." << std::endl;
	}

	return 0;
}

