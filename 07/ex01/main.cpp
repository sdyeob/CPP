
#include "iter.hpp"
#include <iostream>

int main(void)
{

    int arr[4] = {1, 2, 3, 4};
    std::cout << "=====INT ARRAY=====" << std::endl;
    ::iter(arr, 4, functor());

    char arr2[2] = {'a', 'b'};
    std::cout << "=====CHAR ARRAY=====" << std::endl;
    ::iter(arr2, 2, functor());

    float arr3[4] = {4.2, 7.5, 1.2, 9.1};
    std::cout << "=====FLOAT ARRAY=====" << std::endl;
    ::iter(arr3, 4, functor());

    return (0);
}
