# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private :
		std::string name;
	public :
		Zombie(void);
		Zombie(std::string name);
		void announce(void);
		void setname(const std::string& name);
		~Zombie(void);
};

# endif
