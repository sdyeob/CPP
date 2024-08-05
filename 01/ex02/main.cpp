
#include <iostream>

int main(void)
{
	//std::string &ref = new std::string("hello");
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr_str = &str;
	std::string &ref_str = str;

	std::cout << "The string address : " << &str << '\n';
	std::cout << "The string pointer address : " << ptr_str << '\n';
	std::cout << "The string reference address : " << &ref_str << '\n';

	std::cout << "The string value : " << str << '\n';
	std::cout << "The string value pointed to pointer : " << *ptr_str << '\n';
	std::cout << "The string value pointed to reference : " << ref_str << '\n';

	return (0);
}
