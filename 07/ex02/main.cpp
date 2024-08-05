
#include <vector>
#include <iostream>
# include "Array.hpp"

int main(void)
{
    Array<int> arr(5);

    std::cout << "Array size : " << arr.size() << std::endl;
    
    std::cout << "=====Before=====" << std::endl;
    for (int i = 0; i < arr.size(); ++i)
        std::cout << "Array [" << i << "] : " << arr[i] << std::endl;

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    arr[4] = 4;

    std::cout << "=====After=====" << std::endl;
    for (int i = 0; i < arr.size(); ++i)
        std::cout << "Array [" << i << "] : " << arr[i] << std::endl;
    try
    {
        arr[5];
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    Array<int> arr2 = arr;
    std::cout << "=====Array2=====" << std::endl;
    for (int i = 0; i < arr.size(); ++i)
        std::cout << "Array [" << i << "] : " << arr[i] << std::endl;

    Array<int> arr3;

    arr3 = arr2;
    std::cout << "=====Array3=====" << std::endl;
    for (int i = 0; i < arr.size(); ++i)
        std::cout << "Array [" << i << "] : " << arr[i] << std::endl;
    return (0);
}
