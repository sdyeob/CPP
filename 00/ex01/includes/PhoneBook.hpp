#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	int			cnt;
	int			n_idx;
	Contact 	contacts[8];
public:
	PhoneBook();
	bool	Input(std::string out, std::string &in);
	bool	AddContact();
	void	PrintContact();
};

#endif