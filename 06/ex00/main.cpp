
#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Input Error!" << std::endl;
        return (0);
    }
    std::string string(argv[1]);
    ScalarConverter::convert(string);
    return (0);
}
