
#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain's default constructor called!\n";
	idea_cnt = 0;
}

Brain::Brain(const Brain& param)
{
	std::cout << "Brain's copy constructor called!\n";
	for (std::size_t i = 0; i < param.idea_cnt; ++i)
	{
		ideas[i] = param.ideas[i];
	}
	idea_cnt = param.idea_cnt;
}

Brain& Brain::operator=(const Brain& param)
{
	for (std::size_t i = 0; i < param.idea_cnt; ++i)
	{
		ideas[i] = param.ideas[i];
	}
	idea_cnt = param.idea_cnt;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain's destructor called!\n";
}

void Brain::addIdea(const std::string& idea)
{
	if (idea_cnt == 100)
	{
		std::cout << "ideas are full" << std::endl;
		return ;
	}
	ideas[idea_cnt] = idea;
	++idea_cnt;
}

const std::string& Brain::getIdea(std::size_t idx) const
{
	if (idx >= idea_cnt || idx >= 100)
	{
		std::cout << "invalid index value!" << std::endl;
		exit(1); // 어쩔 수 없는 선택
	}
	else
	{
		return (ideas[idx]);
	}
}
