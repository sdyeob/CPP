
#include <iostream>
#include <exception>
#include <sstream>
#include "utils.hpp"

bool    is_digit(char *char_str) {
    std::string str = char_str;

    for (std::size_t i = 0; i < str.size(); ++i) {
        if (!isdigit(str[i])) {
            return (false);
        }
    }

    return (true);
}

int change_str_to_int32(char *str) {
    static std::stringstream ss;
    int ret_val;

    ss.clear();
    ss << str;
    ss >> ret_val;

    if (!ss) { // ss에 error/fail bit on
        throw std::invalid_argument("Input Error");
    }

    return (ret_val);
}

std::vector<s_element> parse_argv(int argc, char **argv) {    
    std::vector<s_element> ret;
    ret.reserve(argc - 1);

    for (int i = 1; i < argc; i++) {
        if (!is_digit(argv[i])) {
            throw std::invalid_argument("Input Error");
        }
        s_element a_elem;
        a_elem.value = change_str_to_int32(argv[i]);
        a_elem.idx = i - 1;
        ret.push_back(a_elem);
    }

    return (ret);
}

std::size_t get_jacobsthal_number(int n) {
    static std::size_t arr[50];

    if (arr[n] != 0) return (arr[n]);

    if (n == 0) { return (0); }
    if (n == 1 || n == 2) { 
        arr[1] = arr[2] = 1;
        return (1); }
    return (arr[n] = get_jacobsthal_number(n - 1) + 2 * get_jacobsthal_number(n - 2));
}