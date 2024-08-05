
# ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private :
		AMateria* slot[4];
		std::string name;
	public :
		Character();
		Character(const std::string& name);
		Character(const Character& param);
		Character& operator=(const Character& param);
		virtual ~Character();

		virtual const std::string& getName() const;
		virtual void equip(AMateria* param);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
		static void unequipOnTheFloor(AMateria* param);

		static AMateria** floor;
		static std::size_t floor_size;
		static std::size_t floor_data_cnt;
};

# endif
