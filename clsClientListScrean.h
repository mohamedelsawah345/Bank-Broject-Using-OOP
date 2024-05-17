#pragma once
#include"clsClientBank.h"
#include"clsHeaderScrean.h"
#include<iostream>
#include<iomanip>



class clsClientListScrean :protected clsHeaderScrean//لازم علشان تورث كلاس لابد الاول انك تعملها انكلد
{
public:
	static void ShowClientScrean()
	{

		vector<clsClientBank> ClientList = clsClientBank::GetClientList();
		short NumberOfClients = ClientList.size();

		string SubTitle = "Number Of Client Is" + to_string(NumberOfClients);
		PrintHeader("ClientScrean", SubTitle);

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

		if (NumberOfClients == 0)
		{
			cout << "No client Exist In The System";
		}
		else
		{
			for (int i = 0; i < NumberOfClients; i++)
			{
				cout << left << setw(20) << ClientList[i].AccountNumber();
				cout << left << setw(20) << ClientList[i].FullName();
				cout << setw(15) << ClientList[i].Phone;
				cout << setw(20) << ClientList[i].Email;
				cout << setw(10) << ClientList[i].PinCode;
				cout << setw(15) << ClientList[i].Balance;
				cout << endl;
			}

			cout << "TotalBalance Is  " << clsClientBank::GetTotalBalances() << endl;
			cout << "\n____________________________________________________________________________";
			cout << "___________________________________________\n";



		}
	}
	

};

