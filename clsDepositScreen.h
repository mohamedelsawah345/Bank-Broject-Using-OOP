#pragma once
#include"clsClientBank.h"
#include"clsHeaderScrean.h"
#include<iostream>
#include<iomanip>
using namespace std;

class clsDepositeScrean :protected clsHeaderScrean
{
	static void _Print(clsClientBank Client1)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client1.FirstName;
		cout << "\nLastName    : " << Client1.LastName;
		cout << "\nFull Name   : " << Client1.FullName();
		cout << "\nEmail       : " << Client1.Email;
		cout << "\nPhone       : " << Client1.Phone;
		cout << "\nAcc. Number : " << Client1.AccountNumber();
		cout << "\nPassword    : " << Client1.PinCode;
		cout << "\nBalance     : " << Client1.Balance;
		cout << "\n___________________\n";
	}
	 static void _ReadClientDeposite(short &MoneyDeposited)
	{
		

		cout << "How much Do u want to Deposite it\n";
			cin >> MoneyDeposited;


	}
public:

	static void showDepositeScrean()
	{
		clsHeaderScrean::PrintHeader("DepositeClientScrean");


		string AccountNumber;

		cout << "Enter AccountNumber's u Want Deposite to it\n";
		cin >> AccountNumber;
		while (!clsClientBank::IsClientExist(AccountNumber))
		{
			cout << "Enter AccountNumber is not found\n";
			cin >> AccountNumber;
		}
		clsClientBank Client1 = clsClientBank::Find(AccountNumber);
		_Print(Client1);
		short ClientDeposited;

		_ReadClientDeposite(ClientDeposited);
		 Client1.Balance += ClientDeposited;
		cout << "yoir Total Balance Now Is: " << Client1.Balance;

		Client1.UpdateClient();




	}
};


