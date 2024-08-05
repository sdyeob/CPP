#include <iostream>
#include "PhoneBook.hpp"

int main(void) {
	PhoneBook phonebook;
	std::string cmd;

	while (1) {
		if (!(phonebook.Input("Command 1) ADD  2) SEARCH  3) EXIT : ", cmd))) return (1);
		if (!(cmd.compare("EXIT"))) break;
		else if (!(cmd.compare("ADD")))
			phonebook.AddContact();
		else if (!(cmd.compare("SEARCH")))
			phonebook.PrintContact();
	}
	return (0);
}