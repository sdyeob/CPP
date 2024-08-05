
# ifndef TYPEDEF_HPP
# define TYPEDEF_HPP

#include <vector>
#include <deque>
#include <utility>

typedef struct element s_element;

struct element
{
    std::size_t idx;
    int value;
};

typedef std::vector< std::pair<s_element, s_element> > t_pair_chain;
typedef std::deque< std::pair<s_element, s_element> > t_deque_chain;

# endif