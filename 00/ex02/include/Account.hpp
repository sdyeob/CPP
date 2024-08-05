// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {

public	: // Member method

	typedef Account		t;

	static int	getNbAccounts( void );			
	static int	getTotalAmount( void );			
	static int	getNbDeposits( void );			
	static int	getNbWithdrawals( void );		
	static void	displayAccountsInfos( void );	

	Account( int initial_deposit );				
	~Account( void );							

	void	makeDeposit( int deposit );			
	bool	makeWithdrawal( int withdrawal );	
	int		checkAmount( void ) const;			
	void	displayStatus( void ) const;		


private :

	static int	_nbAccounts; // 계좌 갯수
	static int	_totalAmount; // 계좌들 잔액의 총액
	static int	_totalNbDeposits; // 입금 횟수
	static int	_totalNbWithdrawals; // 인출 횟수

	static void	_displayTimestamp( void );		

	int				_accountIndex;	// 계좌 index
	int				_amount;		// 해당 index계좌의 잔액
	int				_nbDeposits;	// 해당 index계좌의 입금 횟수
	int				_nbWithdrawals;	// 해당 index계좌의 인출 횟수

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
