#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() {
	n_idx = 0;
	cnt = 0;
}

bool PhoneBook::Input(std::string out, std::string &in) {
	while (std::cin.good()) {
		std::cout << out;
		getline(std::cin, in);
		if(in.length() != 0) return (true);
	}
	std::cout << "Error!" << '\n';
	return (false);
}

bool	PhoneBook::AddContact() {
	std::string input;
	Contact		contact;

	if (!(Input("Input First name : ", input))) return (false);
	contact.SetFName(input);
	if (!(Input("Input Last name : ", input))) return (false);
	contact.SetLName(input);
	if (!(Input("Input Nick name : ", input))) return (false);
	contact.SetNName(input);
	if (!(Input("Input Phone number : ", input))) return (false);
	contact.SetPhone(input);
	if (!(Input("Input secret : ", input))) return (false);
	contact.SetSecret(input);

	contacts[n_idx] = contact;
	n_idx = (n_idx + 1) % 8;
	cnt++;
	return (true);
}

void	StrManufacture(std::string str) {
	std::string output;

	if (str.length() > 10) {
			output = str.substr(0, 9);
			output.push_back('.');
	}
	else output = str;
	std::cout.width(10);
	std::cout << output << '|';
}

void	PhoneBook::PrintContact() {
	int end;
	std::string	choose;

	if (cnt == 0) {
		std::cout << "There is no Information\n";
		return ;
	}
	if (cnt >= 8) end = 8;
	else end = cnt;
	for (int i = 0; i < end; i++) {
		std::cout.width(10);
		std::cout << i + 1 << '|';
		StrManufacture(contacts[i].GetFName());
		StrManufacture(contacts[i].GetLName());
		StrManufacture(contacts[i].GetNName());
		std::cout << '\n';
	}
	while (1) {
		Input("Choose Index : ", choose);
		if (choose.length() == 1 && '1' <= choose[0] && choose[0] <= '0' + end) break ;
	}
	std::cout << contacts[choose[0] - '0' - 1].GetFName() << '\n';
	std::cout << contacts[choose[0] - '0' - 1].GetLName() << '\n';
	std::cout << contacts[choose[0] - '0' - 1].GetNName() << '\n';
	std::cout << contacts[choose[0] - '0' - 1].GetPhone() << '\n';
	std::cout << contacts[choose[0] - '0' - 1].GetSecret() << '\n';
}
