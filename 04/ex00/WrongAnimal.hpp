
# ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected :
		std::string type;
	public :
		WrongAnimal();
		WrongAnimal(const std::string& type);
		WrongAnimal(const WrongAnimal& param);
		WrongAnimal& operator=(const WrongAnimal& param);
		virtual ~WrongAnimal();

		void makeSound() const ;
		const std::string& getType() const;
};

# endif
