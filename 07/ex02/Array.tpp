
# ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"
# include <stdexcept>

template<typename T>
Array<T>::Array()
: data(NULL), capacity(0) { }

template<typename T>
Array<T>::Array(unsigned int n)
: data(new T[n]), capacity(n) {
    if (n == 0)
        std::cout << "Allocated array size is zero" << std::endl;
}

template<typename T>
Array<T>::Array(const Array<T>& param)
: data(new T[param.capacity]), capacity(param.capacity)
{
    if (param.capacity == 0)
        std::cout << "Allocated array size is zero" << std::endl;
    for (unsigned int i = 0; i < param.capacity; ++i) data[i] = param.data[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& param)
{
    if (this != &param)
    {
        if (data != NULL) delete [] data;
        data = new T[param.capacity];
        if (param.capacity == 0)
            std::cout << "Allocated array size is zero" << std::endl;
        for (unsigned int i = 0; i < param.capacity; ++i) data[i] = param.data[i];
    }
    return (*this);
}

template<typename T>
Array<T>::~Array()
{
    if (data != NULL) delete [] data;
}

template<typename T>
T& Array<T>::operator[](unsigned int idx)
{
    if (idx >= capacity)
        throw std::out_of_range("out of range");
    else
        return (data[idx]);
}

template<typename T>
int Array<T>::size() const 
{
    return (capacity);
}

# endif
