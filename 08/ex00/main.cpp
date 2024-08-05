
#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <set>

int main(void)
{
    std::vector<int> vec(5);
    std::list<int> lst(5);
    std::deque<int> deq(5);
    // std::set<int> s;

    for (int i = 0; i < 5; ++i)
    {
        vec[i] = deq[i] = i;
        lst.push_back(i);
        // s.insert(i);
    }

    try
    {
        std::cout << "=====VECTOR=====" << std::endl;
        easyfind(vec, 3);
        std::cout << "=====LIST=====" << std::endl;
        easyfind(lst, 3);
        std::cout << "=====DEQUE=====" << std::endl;
        easyfind(deq, 3);
        // std::cout << "=====SET=====" << std::endl;
        // easyfind(s, 3);
        std::cout << "=====VECTOR=====" << std::endl;
        easyfind(vec, 8);
        
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    return (0);
}
       