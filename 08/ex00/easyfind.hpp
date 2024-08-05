
# ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <stdexcept>
#include <iostream>
#include <algorithm>

template<typename T>
void easyfind(T& cont, int data_for_find)
{
    if (std::find(cont.begin(), cont.end(), data_for_find) != cont.end())
        std::cout << "FIND DATA!" << std::endl;
    else
        throw std::runtime_error("Data Not Found");
}

# endif
