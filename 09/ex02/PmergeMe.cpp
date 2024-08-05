
#include "PmergeMe.hpp"
#include "utils.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& origin) {
    *this = origin;
}

// PmergeMe& PmergeMe::operator=(const PmergeMe& origin) {
//     if ()
//     // *this origin;

//     return (*this);
// }

PmergeMe::~PmergeMe() {}

// the indexes of src elements are guaranteed this formula : idx(An) = idx(An - 1) + 1;
void    PmergeMe::make_pair_chain(t_pair_chain &dst, const std::vector<s_element> &src) {
    std::size_t src_size = src.size();
    dst.reserve(src_size / 2);

    for (std::size_t i = 0; i < src_size; i += 2) {
        if (src[i].value >= src[i + 1].value) {
            dst.push_back(std::make_pair(src[i], src[i + 1]));
            
        } else {
            dst.push_back(std::make_pair(src[i + 1], src[i]));
        }
    }
}

/*
    this function returns the index at vec.
*/
int PmergeMe::binary_search(const std::vector<s_element> &vec, const int value, std::size_t end) {
    int left = 0;
    int right = end - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (vec[mid].value == value)
            return (mid);
        if (vec[mid].value < value)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return (left);
}

std::vector<s_element> *PmergeMe::alloc_and_set(const t_pair_chain &main_chain) {
    std::vector<s_element> *ret_vec = new std::vector<s_element>;
    std::size_t   main_chain_size = main_chain.size();

    (*ret_vec).reserve(main_chain_size * 2);

    for (std::size_t i = 0; i < main_chain_size; ++i) {
        (*ret_vec).push_back(main_chain[i].first);
    }

    return (ret_vec);
}

std::vector<s_element> *PmergeMe::do_insertion(const t_pair_chain &main_chain) {
    std::vector<s_element> *ret_vec = alloc_and_set(main_chain);
    std::size_t   main_chain_size = main_chain.size();
    std::size_t cur_jacob_num = 0;
    std::size_t prev_jacob_num;
    int k = 1;
    int insertion_cnt = 0;

    while (1) {
        prev_jacob_num = cur_jacob_num;
        if (prev_jacob_num >= main_chain_size) { break ; }
        cur_jacob_num = (get_jacobsthal_number(k) < main_chain_size) ? get_jacobsthal_number(k) : main_chain_size;

        std::size_t sub = cur_jacob_num - prev_jacob_num;
        for (std::size_t i = 0; i < sub; ++i) {
            std::size_t search_range = cur_jacob_num + insertion_cnt + 1; // to find a location of insertion of child node
            std::size_t indexing_number = cur_jacob_num - i - 1; // reverse order

            std::size_t insert_idx = binary_search(*ret_vec, main_chain[indexing_number].second.value, search_range);
            (*ret_vec).insert((*ret_vec).begin() + insert_idx, main_chain[indexing_number].second);
            insertion_cnt++;
        }
        k++;
    }
    return (ret_vec);
}

std::vector<s_element> PmergeMe::make_new_vector_with_parent(const t_pair_chain &main_chain) {
    std::vector<s_element> ret_vec;
    std::size_t main_chain_size = main_chain.size();
    ret_vec.reserve(main_chain_size);

    for (std::size_t i = 0; i < main_chain_size; ++i) {
        ret_vec.push_back(main_chain[i].first);
        ret_vec[i].idx = i;
    }

    return (ret_vec);
}

t_pair_chain PmergeMe::index_recovery(const t_pair_chain &main_chain, const std::vector<s_element> &temp_chain) {
    t_pair_chain new_main_chain = main_chain;
    std::size_t temp_chain_size = temp_chain.size();

    for (std::size_t i = 0; i < temp_chain_size; ++i) {
        new_main_chain[i] = main_chain[temp_chain[i].idx];
    }

    return (new_main_chain);
}

std::vector<s_element> *PmergeMe::mergeinsertion(std::vector<s_element> &src) {
    t_pair_chain            main_chain;
    std::vector<s_element>  *temp_chain;
    std::vector<s_element>  *ret_chain;

    s_element odd_elem;
    bool      is_odd = false;

    if (src.size() == 1) {
        return (NULL); // base case(leaf node)
    }

    if (src.size() % 2 == 1) {
        is_odd = true;
        odd_elem = src.back();
        src.pop_back();
    }

    make_pair_chain(main_chain, src); // split src to parent and child chain.
    std::vector<s_element> new_src = make_new_vector_with_parent(main_chain);
    temp_chain = mergeinsertion(new_src);
    if (temp_chain != NULL) {
        main_chain = index_recovery(main_chain, *temp_chain);
        delete temp_chain;
    }
    ret_chain = do_insertion(main_chain);

    if (is_odd) {
        std::size_t idx = binary_search(*ret_chain, odd_elem.value, (*ret_chain).size());
        (*ret_chain).insert((*ret_chain).begin() + idx, odd_elem);
    }

    return (ret_chain);
}

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@ seperate line @@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

/*
    this function returns the index at vec.
*/
int PmergeMe::binary_search(const std::deque<s_element> &vec, const int value, std::size_t end) {
    int left = 0;
    int right = end - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (vec[mid].value == value)
            return (mid);
        if (vec[mid].value < value)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return (left);
}

// the indexes of src elements are guaranteed this formula : idx(An) = idx(An - 1) + 1;
void    PmergeMe::make_pair_chain(t_deque_chain &dst, const std::deque<s_element> &src) {
    std::size_t src_size = src.size();

    for (std::size_t i = 0; i < src_size; i += 2) {
        if (src[i].value >= src[i + 1].value) {
            dst.push_back(std::make_pair(src[i], src[i + 1]));
            
        } else {
            dst.push_back(std::make_pair(src[i + 1], src[i]));
        }
    }
}

std::deque<s_element> *PmergeMe::alloc_and_set(const t_deque_chain &main_chain) {
    std::deque<s_element> *ret_vec = new std::deque<s_element>;
    std::size_t   main_chain_size = main_chain.size();

    for (std::size_t i = 0; i < main_chain_size; ++i) {
        (*ret_vec).push_back(main_chain[i].first);
    }

    return (ret_vec);
}

std::deque<s_element> *PmergeMe::do_insertion(const t_deque_chain &main_chain) {
    std::deque<s_element> *ret_vec = alloc_and_set(main_chain);
    std::size_t   main_chain_size = main_chain.size();
    std::size_t cur_jacob_num = 0;
    std::size_t prev_jacob_num;
    int k = 1;
    int insertion_cnt = 0;

    while (1) {
        prev_jacob_num = cur_jacob_num;
        if (prev_jacob_num >= main_chain_size) { break ; }
        cur_jacob_num = (get_jacobsthal_number(k) < main_chain_size) ? get_jacobsthal_number(k) : main_chain_size;

        std::size_t sub = cur_jacob_num - prev_jacob_num;
        for (std::size_t i = 0; i < sub; ++i) {
            std::size_t search_range = cur_jacob_num + insertion_cnt + 1; // to find a location of insertion of child node
            std::size_t indexing_number = cur_jacob_num - i - 1; // reverse order

            std::size_t insert_idx = binary_search(*ret_vec, main_chain[indexing_number].second.value, search_range);
            (*ret_vec).insert((*ret_vec).begin() + insert_idx, main_chain[indexing_number].second);
            insertion_cnt++;
        }
        k++;
    }
    return (ret_vec);
}

std::deque<s_element> PmergeMe::make_new_vector_with_parent(const t_deque_chain &main_chain) {
    std::deque<s_element> ret_vec;
    std::size_t main_chain_size = main_chain.size();

    for (std::size_t i = 0; i < main_chain_size; ++i) {
        ret_vec.push_back(main_chain[i].first);
        ret_vec[i].idx = i;
    }

    return (ret_vec);
}

t_deque_chain PmergeMe::index_recovery(const t_deque_chain &main_chain, const std::deque<s_element> &temp_chain) {
    t_deque_chain new_main_chain = main_chain;
    std::size_t temp_chain_size = temp_chain.size();

    for (std::size_t i = 0; i < temp_chain_size; ++i) {
        new_main_chain[i] = main_chain[temp_chain[i].idx];
    }

    return (new_main_chain);
}

std::deque<s_element> *PmergeMe::mergeinsertion(std::deque<s_element> &src) {
    t_deque_chain            main_chain;
    std::deque<s_element>  *temp_chain;
    std::deque<s_element>  *ret_chain;

    if (src.size() == 1) {
        return (NULL); // base case(leaf node)
    }

    s_element odd_elem = {0, -1};
    if (src.size() % 2 == 1) {
        odd_elem = src.back();
        src.pop_back();
    }

    make_pair_chain(main_chain, src); // split src to parent and child chain.
    std::deque<s_element> new_src = make_new_vector_with_parent(main_chain);
    temp_chain = mergeinsertion(new_src);
    if (temp_chain != NULL) {
        main_chain = index_recovery(main_chain, *temp_chain);
        delete temp_chain;
    }
    ret_chain = do_insertion(main_chain);

    if (odd_elem.value != -1) {
        std::size_t idx = binary_search(*ret_chain, odd_elem.value, (*ret_chain).size());
        (*ret_chain).insert((*ret_chain).begin() + idx, odd_elem);
    }

    return (ret_chain);
}
