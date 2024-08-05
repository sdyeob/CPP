
#include <iostream>
#include "utils.hpp"
#include "PmergeMe.hpp"
#include <algorithm>
#include <ctime>

void    time_interval(const clock_t &st, const clock_t &en) {
    clock_t t = en - st;;
    double time = ((double)t / CLOCKS_PER_SEC);

    std::cout << time << std::endl;
}

bool    comp(const s_element &a1, const s_element &a2) {
    if (a1.value == a2.value) {
        return (true);
    }
    return (false);
}

struct Cmp
{
    bool operator() (const s_element &a1, const s_element &a2) const {
        return (a1.value < a2.value);
    }
};

void    validate(const std::vector<s_element> &ret_chain, std::vector<s_element> &temp) {
    std::sort(temp.begin(), temp.end(), Cmp());

    for (std::size_t i = 0; i < temp.size(); ++i) {
        if (!comp(ret_chain[i], temp[i])) {
            std::cout << "Error" << std::endl;
        }
    }
    // std::cout << "temp : ";
    // for (std::size_t i = 0; i < temp.size(); ++i) {
    //     std::cout << temp[i].value << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "ret_chain : ";
    // for (std::size_t i = 0; i < ret_chain.size(); ++i) {
    //     std::cout << ret_chain[i].value << " ";
    // }
    // std::cout << std::endl;
}

void    validate(const std::deque<s_element> &ret_chain, std::vector<s_element> &temp) {
    std::sort(temp.begin(), temp.end(), Cmp());

    for (std::size_t i = 0; i < temp.size(); ++i) {
        if (!comp(ret_chain[i], temp[i])) {
            std::cout << "Error" << std::endl;
        }
    }
    // std::cout << "temp : ";
    // for (std::size_t i = 0; i < temp.size(); ++i) {
    //     std::cout << temp[i].value << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "ret_chain : ";
    // for (std::size_t i = 0; i < ret_chain.size(); ++i) {
    //     std::cout << ret_chain[i].value << " ";
    // }
    // std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "Error" << std::endl;
        return (-1);
    }

    try
    {
        std::vector<s_element> src = parse_argv(argc, argv);
        std::vector<s_element> for_test = src;
        std::deque<s_element> src2;
        src2.resize(src.size());
        
        for (std::size_t i = 0; i < src.size(); ++i) {
            src2[i] = src[i];
        }

        PmergeMe merge;

        clock_t st = std::clock();
        std::vector<s_element> *ret_chain = merge.mergeinsertion(src);
        clock_t en = std::clock();

        time_interval(st, en);
        validate(*ret_chain, for_test);

        st = std::clock();
        std::deque<s_element> *ret_chain2 = merge.mergeinsertion(src2);
        en = std::clock();

        time_interval(st, en);
        validate(*ret_chain2, for_test);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (-1);
    }
    return (0);
}