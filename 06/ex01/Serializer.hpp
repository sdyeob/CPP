
# ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <iostream>

class Serializer
{
    private :
        Serializer();
        Serializer(const Serializer& param);
        Serializer& operator=(const Serializer& param);
        ~Serializer();

    public :
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

# endif
