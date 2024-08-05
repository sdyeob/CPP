#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream in("data.csv");
	std::string data_string;

	if (in.is_open()) {
		while(std::getline (in, data_string)) {
			std::pair<std::string, float> pair_for_map;

			std::stringstream ss(data_string);
			std::string a_string;

			std::getline(ss, a_string, ',');
			std::stringstream date_for_data(a_string);
			date_for_data >> pair_for_map.first;

			std::getline(ss, a_string);
			std::stringstream exchage_rate_for_data(a_string);
			exchage_rate_for_data >> pair_for_map.second;

			if (exchage_rate_for_data)
				db.insert(pair_for_map);
		}
	} else {
		std::cout << "Error: could not open file." << std::endl;
	}
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& origin)
{
	this->db = origin.db;
};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& origin)
{
	if (this != &origin) {
		this->db = origin.db;
	}
	return (*this);
};

BitcoinExchange::~BitcoinExchange()
{
};

void BitcoinExchange::Exchange(const std::pair<std::string, float>& p_data)
{
	const std::string err_str = "Error: bad input => " + p_data.first;
	std::map<std::string, float>::iterator it = this->db.find(p_data.first);

	if (it == this->db.end()) {
		it = db.upper_bound(p_data.first);
		if (it == this->db.begin()) {
			throw std::out_of_range(err_str);
		}
		it = --it;
	}

	const std::pair<std::string, float>& map_elem = *it;
	std::cout << map_elem.first << " => " << p_data.second << " = " << p_data.second * map_elem.second << std::endl;
}

