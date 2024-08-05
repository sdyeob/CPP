
# ifndef ARRAY_HPP
# define ARRAY_HPP

// template <typename T> class Array;
// template <typename T> using k = Array<T>;

template<typename T>
class Array
{
    private :
        T* data;
        unsigned int capacity;

    public :
        Array();
        Array(unsigned int n);
        Array(const Array<T>& param);
        // k<T>& operator=(const k<T>& param);
        Array<T>& operator=(const Array<T>& param);
        ~Array();

        T& operator[](unsigned int idx);
        int size() const ;
};


# include "Array.tpp"

# endif
