
# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <cctype>
# include <climits>
# include <cfloat>

#define ERROR -1
#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3

class ScalarConverter // static class in C#
{
    private :
        ScalarConverter();
        ScalarConverter(const ScalarConverter& param);
        ScalarConverter& operator=(const ScalarConverter& param);
        ~ScalarConverter();

    public :
        static void convert(std::string& string);
};

# endif
