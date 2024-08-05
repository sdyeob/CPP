# ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private :
		std::string ideas[100];
		std::size_t idea_cnt;
	public :
		Brain();
		Brain(const Brain& param);
		Brain& operator=(const Brain& param);
		~Brain();

		void addIdea(const std::string& idea);
		const std::string& getIdea(std::size_t idx) const ;
};

# endif
