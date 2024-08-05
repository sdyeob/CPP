
# ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	/*
	Implement a Weapon class that has:
		• A private attribute type, which is a string.
		• A getType() member function that returns a const reference to type.
		• A setType() member function that sets type using the new one passed as parameter.
	*/
	private :
		std::string type;
	public :
		Weapon(const std::string &type);
		const std::string &getType(void) const ;
		void setType(const std::string &newtype);
};

# endif
