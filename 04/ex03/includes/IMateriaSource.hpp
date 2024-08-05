
# ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource
{
	public :
		IMateriaSource();
		virtual ~IMateriaSource();

		virtual void learnMateria(AMateria *param) = 0;
		virtual AMateria* createMateria(const std::string& type) = 0;
};

# endif
