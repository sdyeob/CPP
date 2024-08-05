
#include "Span.hpp"
#include <algorithm>
#include <stdexcept>
#include <deque>
#include <numeric>
#include <climits>
#include <cstdlib> //rand(), srand()
#include <ctime> //time()

bool Span::seeded = false;

Span::Span()
: span_capacity(0)
{

}

Span::Span(unsigned int n)
: span_capacity(n)
{
    this->cont_vec.reserve(span_capacity);
}

Span::Span(const Span& param)
: cont_vec(param.cont_vec.begin(), param.cont_vec.end())
{
    span_capacity = param.span_capacity;
}

Span& Span::operator=(const Span& param)
{
    if (this->span_capacity < param.span_capacity)
    {
        this->cont_vec.reserve(param.span_capacity);
    }

    this->cont_vec.insert(this->cont_vec.begin(), param.cont_vec.begin(), param.cont_vec.end());
    this->span_capacity = param.span_capacity;

    return (*this);
}

Span::~Span() {}

void Span::addNumber(int value)
{
    if (this->cont_vec.size() < this->span_capacity) // 수용할 수 있는 상태
    {
        this->cont_vec.push_back(value);
    }
    else // this->cont_vec.size() >= this->span_capacity
    {
        throw std::runtime_error("Detected Error: [Too many Data]");
    }
}

void Span::addNumbers(unsigned int n)
{
    unsigned int _size = this->cont_vec.size();

    if (!(this->seeded))
    {
        std::srand(unsigned(std::time(NULL)));
        this->seeded = true;
    }

    if (static_cast<unsigned long long int>(_size) + n > this->span_capacity)
    {
        throw std::runtime_error("Detected Error: [Too many Data]");
    }
    else // this->cont_vec.size() + n <= this->span_capacity
    {
        this->cont_vec.resize(_size + n);
        std::generate(this->cont_vec.begin() + _size, this->cont_vec.end(), std::rand);
    }
}

int Span::shortestSpan()
{
    if (this->cont_vec.size() == 0 || this->cont_vec.size() == 1)
    {
        throw std::runtime_error("Detected Error: [Not enough data to get span]");
    }

    std::deque<int> _temp_deque(this->cont_vec.size());

    std::adjacent_difference(this->cont_vec.begin(), this->cont_vec.end(), _temp_deque.begin());

    _temp_deque.pop_front();

    for (std::deque<int>::iterator it = _temp_deque.begin(); it != _temp_deque.end(); ++it)
        *it < 0 ? *it *= -1 : 0;

    std::sort(_temp_deque.begin(), _temp_deque.end());

    return (_temp_deque.at(0));
}

int Span::longestSpan()
{
    if (this->cont_vec.size() == 0 || this->cont_vec.size() == 1)
        throw std::runtime_error("Detected Error: [Not enough data to get span]");

    std::deque<int> _temp_deque(this->cont_vec.begin(), this->cont_vec.end());

    std::adjacent_difference(this->cont_vec.begin(), this->cont_vec.end(), _temp_deque.begin());

    _temp_deque.pop_front();

    for (std::deque<int>::iterator it = _temp_deque.begin(); it != _temp_deque.end(); ++it)
        *it < 0 ? *it *= -1 : 0;

    std::sort(_temp_deque.begin(), _temp_deque.end());

    return (*(--_temp_deque.end()));
}
