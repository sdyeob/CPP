
# ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
//#include "ICharacter.hpp"
class ICharacter;

class AMateria
{
	protected :
		std::string type;
	public:
		AMateria();
		AMateria(const std::string& type); // mandatory
		// AMateria(const AMateria& param);
		// AMateria& operator=(const AMateria& param);
		virtual ~AMateria();

		const std::string& getType() const ; //Returns the materia type // mandatory
		virtual AMateria* clone() const = 0; // mandatory
		virtual void use(ICharacter& target); // mandatory
};

# endif
