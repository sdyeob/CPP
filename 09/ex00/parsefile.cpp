
#include <iostream>
#include <sstream>

void	pipe_validate(const std::string& input_fstring) {
	std::size_t f1 = input_fstring.find('|');
	std::size_t f2 = input_fstring.rfind('|');

	// There is no '|' delimiter or there are a number of '|' delimiter.
	if (f1 == std::string::npos || f1 != f2) {
		std::string error_str = "Error: bad input => " + input_fstring;
		throw std::invalid_argument(error_str);
	}
}

bool	is_leap_year(int year) {
	if (year % 4 != 0) return false;
	if (year % 100 != 0) return true;
	if (year % 400 == 0) return true;
	return false;
}

int		get_date_inf(std::stringstream &whole_sstream, char delim, const std::string& err_str) {
	int	ret_val;
	std::string a_string;
	std::stringstream a_datum_sstream;

	std::getline(whole_sstream, a_string, delim);
	a_datum_sstream.str(a_string);
	a_datum_sstream >> ret_val;

	// entered year is not a number.
	if (!a_datum_sstream) {
		throw std::invalid_argument(err_str);
	}

	return (ret_val);
}

void	date_validate(const std::string& date) {
	const std::string err_str = "Error: bad input => " + date;
	std::stringstream whole_sstream(date);
	std::size_t f1 = date.find('-');
	std::size_t f2 = date.rfind('-');

	// The wrong position of '-' character or Not a complete format
	if (f1 != 4 || f2 != 7 || date.length() != 10) {
		throw std::invalid_argument(err_str);
	}

	int year = get_date_inf(whole_sstream, '-', err_str);
	int month = get_date_inf(whole_sstream, '-', err_str);

	if (month < 1 || 12 < month) {
		throw std::invalid_argument(err_str);
	}

	int day = get_date_inf(whole_sstream, '\n', err_str);

	int dates_of_months[12] = {31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30};
	if (is_leap_year(year) == true) {
		dates_of_months[1] = 29;
	}
	if (day < 1 || dates_of_months[month - 1] < day) {
		throw std::invalid_argument(err_str);
	}
}

void	value_validate(const float& value) {
	// value error
	if (value < 0) {
		throw std::invalid_argument("Error: not a positive number.");
	} else if (1000 < value) {
		throw std::invalid_argument("Error: too large a number.");
	}
}

std::pair<std::string, float>	check_line_validate(const std::string& input_fstring)
{
	std::stringstream whole_sstream(input_fstring);
	std::stringstream a_datum_sstream;
	std::string a_string;
	std::string date;
	float value;

	pipe_validate(input_fstring);

	std::getline(whole_sstream, a_string, '|');
	a_datum_sstream.clear();
	a_datum_sstream << a_string;
	a_datum_sstream >> date;

	date_validate(date);

	std::getline(whole_sstream, a_string);
	a_datum_sstream.clear();
	a_datum_sstream << a_string;
	a_datum_sstream >> value;

	// if value is not a number.
	if (!a_datum_sstream) {
		const std::string error_str = "Error: bad input => " + input_fstring;
		throw std::invalid_argument(error_str);
	}

	value_validate(value);
	return (std::make_pair(date, value));
};
