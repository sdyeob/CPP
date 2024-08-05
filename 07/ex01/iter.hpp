
# ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T, typename F>
void iter(T* arr, size_t length, F func)
{
    // if (arr == NULL)
    // {
    //     std::cout << "First Param is invalid" << std::endl;
    //     return ;
    // }
    for (size_t i = 0; i < length; ++i)
        func(arr[i]);
}

struct functor
{
    template<typename T>
    void operator()(T data)
    {
        std::cout << data << std::endl;
    }
};

# endif
