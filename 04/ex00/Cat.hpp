# ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public :
		Cat();
		Cat(const Cat& param);
		Cat& operator=(const Cat& param);
		~Cat();

		void makeSound() const ;
};

# endif
