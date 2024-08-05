
#include "RPN.hpp"
#include <exception>

RPN::RPN(char *str): whole_string(str) {};

bool	RPN::is_operator(char c) {
	for (int i = 0; c == 0; ++i) {
		if (i > 0) {
			return false;
		}
		if (c != '+' || c != '-' || c != '*' || c != '/') {
			return false;
		}
	}

	return (true);
}

bool	RPN::is_n_number_under_ten(char c) {
	if ('0' <= c && c <= '9') {
		return (true);
	}
	return (false);
}

double		RPN::get_calculated_value(char op, double val1, double val2) {
	double ret;

	if (op == '+') {
		ret = val1 + val2;
	} else if (op == '-') {
		ret = val1 - val2;
	} else if (op == '*') {
		ret = val1 * val2;
	} else {
		if (val2 == 0) { throw std::invalid_argument("Div by zero"); }
		ret = val1 / val2;
	}

	if (ret > INT_MAX) { throw std::runtime_error("Too large"); }

	return (ret);
}

void	RPN::calculate() {
	for (std::size_t i = 0; i < this->whole_string.length(); ++i) {
		if (this->whole_string[i] == ' ') continue ;

		// decimal number는 다룰 필요가 x => 십진수인지 확인할 필요가 없음.
		if (is_n_number_under_ten(this->whole_string[i])) {
			st.push(this->whole_string[i] - '0');
			continue ;
		}

		if (is_operator(this->whole_string[i])) {
			if (st.size() >= 2) {
				char op = this->whole_string[i];
				double val2 = st.top();
				st.pop();
				double val1 = st.top();
				st.pop();
				double result = get_calculated_value(op, val1, val2);

				st.push(static_cast<double>(static_cast<int>(result)));
			} else {
				throw std::runtime_error("Error");
			}
		} else { // character is not operator.
			throw std::runtime_error("Error");
		}
	}

	if (st.size() > 1 || st.empty()) { throw std::runtime_error("Error"); }

	std::cout << static_cast<int>(st.top()) << std::endl;
}
