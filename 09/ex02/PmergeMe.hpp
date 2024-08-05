
# ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include "typedef.hpp"

class PmergeMe
{
    private :   

    private :
        void    make_pair_chain(t_pair_chain &dst, const std::vector<s_element> &src);
        int     binary_search(const std::vector<s_element> &vec, const int value, std::size_t end);
        std::vector<s_element> *alloc_and_set(const t_pair_chain &main_chain);
        std::vector<s_element> *do_insertion(const t_pair_chain &main_chain);
        std::vector<s_element> make_new_vector_with_parent(const t_pair_chain &main_chain);
        t_pair_chain index_recovery(const t_pair_chain &main_chain, const std::vector<s_element> &temp_chain);

        void    make_pair_chain(t_deque_chain &dst, const std::deque<s_element> &src);
        int     binary_search(const std::deque<s_element> &vec, const int value, std::size_t end);
        std::deque<s_element> *alloc_and_set(const t_deque_chain &main_chain);
        std::deque<s_element> *do_insertion(const t_deque_chain &main_chain);
        std::deque<s_element> make_new_vector_with_parent(const t_deque_chain &main_chain);
        t_deque_chain index_recovery(const t_deque_chain &main_chain, const std::deque<s_element> &temp_chain);

    public :
        PmergeMe();
        PmergeMe(const PmergeMe& origin);
        // PmergeMe& operator=(const PmergeMe& origin);
        ~PmergeMe();

    public :
        std::vector<s_element> *mergeinsertion(std::vector<s_element> &src);
        std::deque<s_element> *mergeinsertion(std::deque<s_element> &src);
};

# endif