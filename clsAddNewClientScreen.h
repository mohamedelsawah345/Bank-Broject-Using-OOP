#pragma once
#include"clsClientBank.h"
#include"clsHeaderScrean.h"
#include<iostream>
#include<iomanip>

class clsAddNewClientScreen :protected clsHeaderScrean
{
	 static void _Print(clsClientBank Client1)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client1. FirstName;
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
	static void AddNewClientScrean()
	{

		clsHeaderScrean::PrintHeader("AddNewClientScrean");
		string AccountNumber;


		cout << "Please enter your Account Number\n";
		cin >> AccountNumber;

		while (clsClientBank::IsClientExist(AccountNumber))
		{
			cout << "Please enter Another Account Number,This Account Exist Already\n";
			cin >> AccountNumber;
		}

		clsClientBank Client1 = clsClientBank::AddNewObject(AccountNumber);

		clsClientBank:: ReadInfo(Client1);
		clsClientBank::enSavedResult SaveResult;

		SaveResult = Client1.Save();
		switch (SaveResult)
		{
		case clsClientBank::enSavedResult::FaildEmptyClient:
			cout << "\nEror,this Client isEmpty\n";

			break;
		case clsClientBank::enSavedResult::SavedSuccessfuly:
			cout << "\nThis Client Add Successfuly\n";

			break;
		case clsClientBank::enSavedResult::FaildExistClient:
			cout << "\nError,Client already Exist\n";

			break;

		}
		_Print(Client1);
	}
	
};

