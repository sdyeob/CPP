
#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main(void)
{
    MutantStack<int> mstack;
    std::list<int> mlist;

    mstack.push(5);
    mstack.push(17);

    mlist.push_back(5);
    mlist.push_back(17);

    std::cout << "mstack top : " << mstack.top() << std::endl;
    std::cout << "mlist top : " << mlist.back() << std::endl;

    mstack.pop();
    mlist.pop_back();

    std::cout << "mstack size : " << mstack.size() << std::endl;
    std::cout << "mlist size : " << mlist.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);

    MutantStack<int>::iterator it_for_stack = mstack.begin();
    MutantStack<int>::iterator ite_for_stack = mstack.end();

    std::cout << "STACK DATA : " << std::endl;
    ++it_for_stack;
    --it_for_stack;
    while (it_for_stack != ite_for_stack)
    {
        std::cout << *it_for_stack << std::endl;
        ++it_for_stack;
    }

    std::list<int>::iterator it_for_list = mlist.begin();
    std::list<int>::iterator ite_for_list = mlist.end();
    
    std::cout << "LIST DATA : " << std::endl;
    ++it_for_list;
    --it_for_list;
    while (it_for_list != ite_for_list)
    {
        std::cout << *it_for_list << std::endl;
        ++it_for_list;
    }
    return 0;
}