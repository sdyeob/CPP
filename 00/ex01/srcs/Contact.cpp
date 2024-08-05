#include "../includes/Contact.hpp"

std::string Contact::GetFName() { return (f_name); }
std::string Contact::GetLName() { return (l_name); }
std::string Contact::GetNName() { return (n_name); }
std::string Contact::GetPhone() { return (phone); }
std::string Contact::GetSecret() { return (secret); }

void	Contact::SetFName(std::string input) { f_name = input; }
void	Contact::SetLName(std::string input) { l_name = input; }
void	Contact::SetNName(std::string input) { n_name = input; }
void	Contact::SetPhone(std::string input) { phone = input; }
void	Contact::SetSecret(std::string input) { secret = input; }
