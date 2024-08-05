
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
    public :
        typedef typename std::stack<T>::container_type::iterator iterator; // ok
        // typename std::stack<T>::iterator iterator; //not ok 
        // just declaration. 

        MutantStack() {}
        MutantStack(const MutantStack& param)
        {
            this->c = param.c;
        }
        MutantStack& operator=(const MutantStack& param)
        {
            this->c = param.c;
            return (*this);
        }
        ~MutantStack() {}

        iterator begin()
        { return (this->c.begin()); }
        iterator end()
        { return (this->c.end()); }

        T& top()
        {
            if (this->size() == 0)
            {
                throw std::runtime_error("Error detected: [STACK IS EMPTY]");
            }
            else
            {
                return (this->c.back());
            }
        }

        void pop()
        {
            if (this->size() == 0)
            {
                throw std::runtime_error("Error detected: [STACK IS EMPTY]");
            }
            else
            {
                this->c.pop_back();
            }
        }
};