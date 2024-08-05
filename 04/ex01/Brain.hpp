# ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private :
		std::string ideas[100]; // 단순히 char *ideas = malloc(sizeof(char) * 100)의 포인터로 생각해도 됨.
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
