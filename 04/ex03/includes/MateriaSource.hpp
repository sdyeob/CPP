
# ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private :
		AMateria* slot[4];
		int slot_cnt;
	public :
		MateriaSource();
		MateriaSource(const MateriaSource& param);
		MateriaSource& operator=(const MateriaSource& param);
		virtual ~MateriaSource();

		virtual void learnMateria(AMateria *param);
		virtual AMateria* createMateria(const std::string& type);
};

# endif
