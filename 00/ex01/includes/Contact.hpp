#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
	std::string f_name;
	std::string l_name;
	std::string n_name;
	std::string	phone;
	std::string	secret;
public:
	std::string GetFName();
	std::string GetLName();
	std::string GetNName();
	std::string GetPhone();
	std::string GetSecret();
	void SetFName(std::string input);
	void SetLName(std::string input);
	void SetNName(std::string input);
	void SetPhone(std::string input);
	void SetSecret(std::string input);
};

#endif