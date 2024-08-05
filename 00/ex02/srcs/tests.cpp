// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>		//
#include <algorithm>	//
#include <functional>	//
#include "../include/Account.hpp"	// Account.hpp에 대한 내용.


int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t;
	/*
		t는 Account.hpp안에서 typedef Account t;로 되어있으므로,
		위의 코드는 typedef std::vector<Accout> accounts_t와 동일하다.
		해당 코드가 의미하는 바는, accounts_t라는 타입은은 Account라는 원소를 가지는 동적 배열이라는 의미이다.
	*/
	typedef std::vector<int>								  ints_t; // 동적 배열.
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t; // 2개의 동적 배열의 iterator을 가지는 변수.

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 }; // 총액
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) ); // 생성자와 똑같이 ()안의 값으로 초기화 됨. => amount 배열의 한칸 크기를 저장.
	accounts_t				accounts( amounts, amounts + amounts_size ); // account라는 벡터 배열에, amounts라는 배열의 값을 모두 저정해두기.
	accounts_t::iterator	acc_begin	= accounts.begin(); // account배열 첫번째 원소의 이터레이터.
	accounts_t::iterator	acc_end		= accounts.end(); // account배열 마지막 원소의 이터레이터.

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 }; // 보증금을 의미.
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size ); // d라는 배열의 모든 값을 여기에 담아둔다.
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 }; // 인출금을 의미.
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size ); // w라는 배열의 모든 값을 해당 vector에 담는다.
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	Account::displayAccountsInfos(); // Account 클래스의 static member 함수 호출.
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
