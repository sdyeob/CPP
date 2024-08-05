
#include <iostream>
#include "Span.hpp"

#include <vector>
#include <deque>
#include <set>

int main()
{
    // std::vector<int> s;

    // 1
    // 389
    // s.push_back(5);
    // s.push_back(-1);
    // s.push_back(123);
    // s.push_back(4);
    // s.push_back(512);

    // s.push_back('a');
    // s.push_back('b');
    // s.push_back('c');
    // s.push_back('d');
    // s.push_back('e');

    try
    {
        Span sp = Span(5);
        sp.addNumber(5);
        sp.addNumber(-1);
        sp.addNumber(123);
        sp.addNumber(4);
        sp.addNumber(512);
        // sp.addNumber(3);

        std::cout << "=====FIRST TEST=====" << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        // Span sp = Span(s.begin(), s.end());
        // std::cout << sp.shortestSpan() << std::endl;
        // std::cout << sp.longestSpan() << std::endl;

        Span sp = Span(12000);

        // std::cout << "=====FIRST TEST=====" << std::endl;
        // std::cout << sp.shortestSpan() << std::endl;
        // std::cout << sp.longestSpan() << std::endl;
        std::cout << "=====SECOND TEST=====" << std::endl;
        sp.addNumbers(200);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        std::cout << "=====THIRD TEST=====" << std::endl;
        sp.addNumbers(10000);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}