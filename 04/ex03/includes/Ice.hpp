
# ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	public :
		Ice();
		// Ice(const Ice& param);
		// Ice& operator=(const Ice& param);
		virtual ~Ice();

		virtual AMateria* clone() const ;
		virtual void use(ICharacter& target);
};

# endif
