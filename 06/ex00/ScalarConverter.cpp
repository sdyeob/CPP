
#include "ScalarConverter.hpp"

static int first_data(const char& c);
static int get_data_type(std::string& string);
static void* convert_actual_type(int data_type, std::istringstream& input);
static void convert_to_others(int data_type, void *data, bool istringstream_error_flag);
static void print_char_data(double data, char c);
static void print_int_data(double data, int i);
static void print_float_data(double data, float f);
static void print_types(char c, int i, float f, double d, int data_type, bool istringstream_error_flag);

static int first_data(const char& c)
{
    if (c == '+' || c == '-') return (1);
    else return (0);
}

static int get_data_type(std::string& string)
{
    if (string.length() == 1 && !isdigit(string.at(0))) return (CHAR);
    if (string == "nanf"  || string == "inff" || string == "+inff" || string == "-inff") return (FLOAT);
    if (string == "nan" || string == "inf" || string == "+inf" || string == "-inf") return (DOUBLE);

    int dot = 0;
    int is_float = (string.at(string.length() - 1)) == 'f' ? 1 : 0;

    for (int i = first_data(string.at(0)); i < (int)(string.length() - is_float); ++i)
    {
        if (string[i] == '.') ++dot;
        else if (!isdigit(string[i])) return (ERROR);
    }

    if (dot == 0) return (INT);
    else if (dot == 1)
    {
        if (is_float) return (FLOAT);
        else return (DOUBLE);
    }
    else return (ERROR);
}

static void* convert_actual_type(int data_type, std::istringstream& input)
{
    void* data = NULL;

    switch(data_type)
    {
        case CHAR :
            data = new char;
            input >> *(static_cast<char *>(data));
            break ;
        case INT :
            data = new int;
            input >> *(static_cast<int *>(data));
            break ;
        case FLOAT :
            data = new float;
            input >> *(static_cast<float *>(data));
            break ;
        case DOUBLE :
            data = new double;
            input >> *(static_cast<double *>(data));
            break ;
    }
    return (data);
}

static void convert_to_others(int data_type, void *data, bool istringstream_error_flag)
{
    char c;
    int i;
    float f;
    double d;

    switch(data_type)
    {
        case CHAR :
            c = *(static_cast<char *>(data));

            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);
            break ;
        case INT :
            i = *(static_cast<int *>(data));

            c = static_cast<char>(i);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
            break ;
        case FLOAT :
            f = *(static_cast<float *>(data));

            c = static_cast<char>(f);
            i = static_cast<int>(f);
            d = static_cast<double>(f);
            break ;
        case DOUBLE :
            d = *(static_cast<double *>(data));

            c = static_cast<char>(d);
            i = static_cast<int>(d);
            f = static_cast<float>(d);
            break ;
    }
    print_types(c, i, f, d, data_type, istringstream_error_flag);
}

static void print_char_data(double data, char c)
{
    if ((0 <= data && data <= 31) || data == 127)
            std::cout << "char : Non displayable" << std::endl;
    else if (data < 0 || 127 < data || isnan(data) || isinf(data))
        std::cout << "char : Impossible" << std::endl;
    else
        std::cout << "char : \'" << c << '\'' <<std::endl;
}

static void print_int_data(double data, int i)
{
    if (data < INT_MIN || data > INT_MAX || isnan(data) || isinf(data))
        std::cout << "int : Impossible" << std::endl;
    else
        std::cout << "int : " << i << std::endl;
}

static void print_float_data(double data, float f)
{
    if (isnan(data) || isinf(data))
        std::cout << "float : " << f << 'f' << std::endl;
    else if (data < -FLT_MAX || data > FLT_MAX)
        std::cout << "float : Impossible" << std::endl;
    else
        std::cout << "float : " << f << 'f' << std::endl;
}

static void print_types(char c, int i, float f, double d, int data_type, bool istringstream_error_flag)
{
    double for_checking_valid_data;

    if (istringstream_error_flag || data_type == ERROR)
    {
        std::cout << "char : Impossible" << std::endl;
        std::cout << "int : Impossible" << std::endl;
        std::cout << "float : Impossible" << std::endl;
        std::cout << "double : Impossible" << std::endl;
    }
    else
    {
        switch (data_type)
        {
            case CHAR :
                for_checking_valid_data = static_cast<double>(c);
                break;
            case INT :
                for_checking_valid_data = static_cast<double>(i);
                break;
            case FLOAT :
                for_checking_valid_data = static_cast<double>(f);
                break;
            case DOUBLE :
                for_checking_valid_data = d;
                break;
        }
        print_char_data(for_checking_valid_data, c);
        print_int_data(for_checking_valid_data, i);
        print_float_data(for_checking_valid_data, f);
        std::cout << "double : " << d << std::endl;
    }
}

void ScalarConverter::convert(std::string& string)
{
    int data_type = get_data_type(string);
    if (data_type == FLOAT) string.pop_back();

    std::istringstream input(string);

    void* data = convert_actual_type(data_type, input);
    // if (data == NULL) return ;

    convert_to_others(data_type, data, !((bool)(input)));
}
