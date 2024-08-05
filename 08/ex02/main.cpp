
#include "MutantStack.hpp"
#include <iostream>

int main()
{
    MutantStack<int> mstack;

    // mstack.push(1);
    // mstack.push(2);
    try
    {
        std::cout << "TOP CALL IN STACK" << std::endl;
        // top function call with no element is segmentation fault;
        std::cout << mstack.top() << std::endl;
        std::cout << "POP CALL IN STACK" << std::endl;
        // pop function call with no element is segmentation fault;
        mstack.pop();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "SIZE CALL IN STACK" << std::endl;
    std::cout << mstack.size() << std::endl;

    std::cout << "PUSH DATA IN STACK" << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "CREATE NEW STACK" << std::endl;
    // std::stack<int> mstack2(mstack); // possible expression
    MutantStack<int> mstack2(mstack);
    MutantStack<int>::iterator it_mstack2 = mstack.begin();
    MutantStack<int>::iterator ite_mstack2 = mstack.end();

    ++it_mstack2;
    --it_mstack2;
    while (it_mstack2 != ite_mstack2)
    {
        std::cout << *it_mstack2 << std::endl;
        ++it_mstack2;
    }
    return 0;
}