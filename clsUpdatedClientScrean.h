#pragma once
#include"clsClientBank.h"
#include"clsHeaderScrean.h"
#include<iostream>
#include<iomanip>

class clsAbdatedClientScrean :protected clsHeaderScrean
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
public:

	static void updatedClientScrean()
	{
		clsHeaderScrean::PrintHeader("updatedClientScrean");


		string AccountNumber;
		
		cout << "Enter AccountNumber's u Want Update it\n";
		cin >> AccountNumber;
		while (!clsClientBank::IsClientExist(AccountNumber))
		{
			cout << "Enter AccountNumber is not found\n";
			cin >> AccountNumber;
		}
		clsClientBank Client1 = clsClientBank::Find(AccountNumber);
		_Print(Client1);

	clsClientBank::	ReadInfo(Client1);

		Client1.UpdateClient();




	}
};

