# ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private :
		Brain* cat_brain;
	public :
		Cat();
		Cat(const Cat& param);
		Cat& operator=(const Cat& param);
		~Cat();

		void makeSound() const ;
		void addIdea(const std::string& idea);
		const std::string& getIdea(const std::size_t& idx) const ;
};

# endif
