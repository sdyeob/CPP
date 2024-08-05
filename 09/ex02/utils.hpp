
# ifndef UTILS_HPP
# define UTILS_HPP

#include "typedef.hpp"

bool                    is_digit(char *char_str);
int                     change_str_to_int32(char *str);
std::vector<s_element>  parse_argv(int argc, char **argv);
std::size_t             get_jacobsthal_number(int n);
# endif