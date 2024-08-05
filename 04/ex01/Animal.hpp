
# ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected :
		std::string type;
	public :
		Animal();
		Animal(const std::string& type);
		Animal(const Animal& param);
		Animal& operator=(const Animal& param);
		virtual ~Animal();

		virtual void makeSound() const ;
		const std::string& getType() const;
};

# endif
