#include "../include/Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts;			// static 변수 사용 시 선언.
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

Account::Account() {
	_displayTimestamp();
	_accountIndex = _nbAccounts++;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}

Account::Account( int initial_deposit ) : _amount(initial_deposit) {
	_displayTimestamp();
	_accountIndex = _nbAccounts++;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "created\n";
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "closed\n";
}

void	Account::_displayTimestamp( void ) {
	time_t now = time(0);
	char* date_time = ctime(&now); // 현재 시간 (년/월/일/시간/분/초)를 계산하는 방식.
	std::string str = date_time; // date_time은 맨 뒤에 개행이 존재해서 다음과 같이 작성해줘야 한다.
	str.pop_back();
	std::cout << '[' << str << "] ";
}

//static 함수를 정의할 경우 키워드는 안붙임.
void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ';';
	std::cout << "total:" << _totalAmount << ';';
	std::cout << "deposits:" << _totalNbDeposits << ';';
	std::cout << "withdrawals:" << _totalNbWithdrawals << '\n';
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "desposit:" << _nbDeposits << ';';
	std::cout << "withdrawals:" << _nbWithdrawals << '\n';
}

void	Account::makeDeposit( int deposit ) {
	int	prev_amount;
	int	curr_amount;

	prev_amount = checkAmount();
	_amount += deposit;
	_nbDeposits++;
	curr_amount = checkAmount();
	_displayTimestamp();
	_totalNbDeposits++;
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "p_amount:" << prev_amount << ';';
	std::cout << "desposit:" << deposit << ';';
	std::cout << "amount:" << curr_amount << ';';
	std::cout << "nb_deposits:" << _nbDeposits << '\n';
}

bool	Account::makeWithdrawal( int withdrawal ) {
	int	prev_amount;
	int	curr_amount;

	_displayTimestamp();
	prev_amount = checkAmount();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "p_amount:" << prev_amount << ';';
	if ( prev_amount < withdrawal ) {
		std::cout << "withdrawal:refused\n";
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	curr_amount = checkAmount();
	std::cout << "withdrawal:" << withdrawal << ';';
	std::cout << "amount:" << curr_amount << ';';
	std::cout << "nb_withdrawals:" << _nbWithdrawals << '\n';
	return (true);
}


int	Account::checkAmount( void ) const {
	return (_amount);
}

int	Account::getNbAccounts( void ) {
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}
