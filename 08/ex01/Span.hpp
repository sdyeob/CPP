
# ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
    private :
        std::vector<int>    cont_vec;
        unsigned int        span_capacity;
        static bool         seeded;

    public :
        Span();
        Span(unsigned int n);
        Span(const Span& param);
        Span& operator=(const Span& param);
        ~Span();

        void addNumber(int value);
        void addNumbers(unsigned int n);
        int shortestSpan();
        int longestSpan();

        template<typename T>
        Span(T First, T Last);
};

#include "Span.tpp"

# endif