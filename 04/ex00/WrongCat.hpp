# ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public :
		WrongCat();
		WrongCat(const WrongCat& param);
		WrongCat& operator=(const WrongCat& param);
		~WrongCat();

		void makeSound() const ;
};

# endif
