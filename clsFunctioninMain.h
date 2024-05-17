#pragma once

#include <iostream>
#include <string>
#include"clsClientBank.h"
#include<iomanip>

using namespace std;
class clsFunctioninMain
{



	void ReadInfo(clsClientBank& Client)
	{
		string FristName, LastName, phone, Email, PinCode;
		double Balance;

		cout << "Enter Frist Name\n";
		getline(cin >> ws, FristName);
		Client.FirstName = FristName;

		cout << "Enter Last Name\n";
		getline(cin, LastName);
		Client.LastName = LastName;

		cout << "Enter Phone\n";
		getline(cin, phone);
		Client.Phone = phone;

		cout << "Enter Email\n";
		getline(cin, Email);
		Client.Email = Email;

		cout << "Enter PinCode\n";
		getline(cin, PinCode);
		Client.PinCode = PinCode;


		cout << "Enter Balance\n";
		cin >> Balance;
		Client.Balance = Balance;



	}

	void UpdateInfo()
	{

		string AccountNumber;

		cout << "This is Update Client Info\n";

		cout << "Enter Account Number \n";
		getline(cin, AccountNumber);

		while (!clsClientBank::IsClientExist(AccountNumber))
		{

			cout << " Error,Enter  Another Account Number \n";
			getline(cin, AccountNumber);
		}
		clsClientBank Client1 = clsClientBank::Find(AccountNumber);
		Client1.Print();

		ReadInfo(Client1);

		Client1.UpdateClient();


	}

	void AddNewClient()
	{
		string AccountNumber;


		cout << "Please enter your Account Number\n";
		cin >> AccountNumber;

		while (clsClientBank::IsClientExist(AccountNumber))
		{
			cout << "Please enter Another Account Number,This Account Exist Already\n";
			cin >> AccountNumber;
		}

		clsClientBank Client1 = clsClientBank::AddNewObject(AccountNumber);

		ReadInfo(Client1);
		clsClientBank::enSavedResult SaveResult;

		SaveResult = Client1.Save();
		switch (SaveResult)
		{
		case clsClientBank::enSavedResult::FaildEmptyClient:
			cout << "Eror,this Client isEmpty";

			break;
		case clsClientBank::enSavedResult::SavedSuccessfuly:
			cout << "This Client Add Successfuly";

			break;
		case clsClientBank::enSavedResult::FaildExistClient:
			cout << "Error,Client already Exist";

			break;

		}



	}

	void DeletClient()
	{
		string AccountNumber;
		cout << "Hey This is a DeletFunction\n";
		cout << "Enter AccountNumber's u Want Delet it\n";
		cin >> AccountNumber;
		while (!clsClientBank::IsClientExist(AccountNumber))
		{
			cout << "Enter AccountNumber is not found\n";
			cin >> AccountNumber;
		}
		bool Answer = 0;
		cout << "Do u Want Delelt?\n";
		cin >> Answer;
		if (Answer)
		{
			clsClientBank::DeletClientWithAccountNumber(AccountNumber);
			cout << "Deleted Successfuly";
		}



	}

	void ClientList()
	{
		vector<clsClientBank> ThisClientList = clsClientBank::GetClientList();

		cout << "\t\t\t\t\tNumber Of Client Is (" << ThisClientList.size() << ")\n";
		cout << "____________________________________________________________________________";
		cout << "___________________________________________\n";
		cout << left << setw(20) << "AccountNumber";
		cout << left << setw(20) << " ClientName";
		cout << left << setw(15) << " Phone";
		cout << left << setw(20) << " Email";
		cout << left << setw(10) << " PinCode";
		cout << left << setw(15) << " AccountBalance";
		cout << "\n____________________________________________________________________________";
		cout << "___________________________________________\n";

		if (ThisClientList.size() == 0)
		{
			cout << "No client Exist In The System";
		}
		else
		{
			for (int i = 0; i < ThisClientList.size(); i++)
			{
				cout << left << setw(20) << ThisClientList[i].AccountNumber();
				cout << left << setw(20) << ThisClientList[i].FullName();
				cout << setw(15) << ThisClientList[i].Phone;
				cout << setw(20) << ThisClientList[i].Email;
				cout << setw(10) << ThisClientList[i].PinCode;
				cout << setw(15) << ThisClientList[i].Balance;
				cout << endl;
			}

			cout << "TotalBalance Is  " << clsClientBank::GetTotalBalances() << endl;
			cout << "\n____________________________________________________________________________";
			cout << "___________________________________________\n";


		}

	}


	int main()
	{

	}
};

