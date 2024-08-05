
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137)
{
	// std::cout << "ShrubberyCreationForm's default constructor called.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
 : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	// std::cout << "ShrubberyCreationForm's constructor called with a target parameter.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& param)
: AForm("ShrubberyCreationForm", 145, 137), target(param.target)
{
	// std::cout << "ShrubberyCreationForm's copy constructor called.\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& param)
{
	// std::cout << "ShrubberyCreationForm's assignment operator called.\n";
	target = param.target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "ShrubberyCreationForm's destructor called.\n";
}

void ShrubberyCreationForm::concreteExecute() const
	
{
	std::ofstream out("tree.txt");
	if (out.is_open())
	{
		out << "                                                 \n";
		out << "                       O                         \n";
		out << "                      ***                        \n";
		out << "                     **O**                       \n";
		out << "                    *******                      \n";
		out << "                   *********                     \n";
		out << "                  ***********                    \n";
		out << "                   ******o**                     \n";
		out << "                  ***********                    \n";
		out << "                 ****o********                   \n";
		out << "                ***************                  \n";
		out << "               ****o***o********                 \n";
		out << "              *******************                \n";
		out << "            ***********************              \n";
		out << "               *****O***********                 \n";
		out << "              **********o********                \n";
		out << "             ****************o****               \n";
		out << "            **O********************              \n";
		out << "           ***********o********O****             \n";
		out << "         *****************************           \n";
		out << "             *********************               \n";
		out << "            ***o*******************              \n";
		out << "           ***********o*******o*****             \n";
		out << "          ***************************            \n";
		out << "         ***********************O*****           \n";
		out << "        ***O***************************          \n";
		out << "      ***********************************        \n";
		out << "           *************************             \n";
		out << "          *******o********o**********            \n";
		out << "         *****************************           \n";
		out << "        **************o****************          \n";
		out << "       *************************O*******         \n";
		out << "      *****O*****************************        \n";
		out << "    **************o************************      \n";
		out << "          ***************************            \n";
		out << "         *************o***************           \n";
		out << "        ***********o*******************          \n";
		out << "       **************************O******         \n";
		out << "      ***o******************O************        \n";
		out << "    ***o***********o****************o******      \n";
		out << "                      ###                        \n";
		out << "                      ###                        \n";
		out << "                      ###                        \n";
		out << "                  ###########                    \n";
		out << "                  ###########                    \n";
	}
}
