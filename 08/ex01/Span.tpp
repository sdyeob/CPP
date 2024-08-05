
#include "Span.hpp"
#include <iterator> // for std::iterator_traits
#include <typeinfo>

template<typename InputIt>
Span::Span(InputIt First, InputIt Last)
{
    // Check if InputIt value_type is int
    // static_assert(std::is_same<typename std::iterator_traits<InputIt>::value_type, int>::value,
    //                 "InputIt must be an iterator of a container with int value_type");

    typename std::iterator_traits<InputIt>::value_type tmp;

    if (typeid(tmp) != typeid(int))
    {
        throw std::runtime_error("Detected Error: [Iterator Type Error]");
    }

    cont_vec.insert(cont_vec.begin(), First, Last);
    span_capacity = cont_vec.capacity();
}
