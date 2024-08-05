
#include <iostream>
#include <exception>
#include <random>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
    std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 2);

	if (dis(gen) == 0)
		return (new A());
	else if (dis(gen) == 1)
		return (new B());
    else
		return (new C());
}

void identify(Base* p)
{
    if(dynamic_cast<A* >(p))
        std::cout << "Pointer to A" << std::endl;
    else if(dynamic_cast<B* >(p))
        std::cout << "Pointer to B" << std::endl;
    else if(dynamic_cast<C* >(p))
        std::cout << "Pointer to C" << std::endl;
    else
        std::cout << "No matched result" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& ref_a = dynamic_cast<A&>(p);
        std::cout << "Reference to A" << std::endl;
    }
    catch(const std::exception& e)
    {
        try
        {
            B& ref_a = dynamic_cast<B&>(p);
            std::cout << "Reference to B" << std::endl;
        }
        catch(const std::exception& e)
        {
            try
            {
                C& ref_a = dynamic_cast<C&>(p);
                std::cout << "Reference to C" << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }
}

int main(void)
{
    Base* ptr = generate();
    Base& ref = *ptr;

    identify(ptr);
    identify(ref);
    
    return (0);
}
