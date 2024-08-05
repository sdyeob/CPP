# ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange
{
	private :
		std::map<std::string, float> db;

	public :
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& origin);
		BitcoinExchange& operator= (const BitcoinExchange& origin);
		~BitcoinExchange();

	public :
		void Exchange(const std::pair<std::string, float>& p_data);
};

# endif
