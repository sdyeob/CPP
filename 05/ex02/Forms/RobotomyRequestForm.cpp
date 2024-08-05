
#include "RobotomyRequestForm.hpp"
#include <random>

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45)
{
	// std::cout << "RobotomyRequestForm's default constructor called.\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
 : AForm("RobotomyRequestForm", 72, 45), target(target)
{
	// std::cout << "RobotomyRequestForm's constructor called with a target parameter.\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& param)
: AForm("RobotomyRequestForm", 72, 45), target(param.target)
{
	// std::cout << "RobotomyRequestForm's copy constructor called.\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& param)
{
	// std::cout << "RobotomyRequestForm's assignment operator called.\n";
	target = param.target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "RobotomyRequestForm's destructor called.\n";
}

void RobotomyRequestForm::concreteExecute() const
{
	std::random_device rd; // on linux system, this parameter is interpreted as a filesystem path.
	// and has a default value of /def/urandom.
	std::mt19937 gen(rd());
	// rd() -> make ne wrandom number. return value : unsigned int.
	std::uniform_int_distribution<int> dis(0, 1); // 0 부터 1까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.

	if (dis(gen))
	{
		std::cout << target << " has been robotomized!\n";
	}
	else
	{
		std::cout << target << " is robotomy failed!\n";
	}
}
