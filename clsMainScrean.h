#pragma once
#include"clsHeaderScrean.h"
#include"clsInputValidate.h"
#include"clsClientListScrean.h"
#include"clsAddNewClientScreen.h"
#include"clsDeletClientScrean.h"
#include"clsUpdatedClientScrean.h"
#include"clsFindClientScrean.h"
#include"clsTransactionScreen.h"
#include"clsMangeUsers.h"
#include "Global.h"
#include"clsUser.h"
#include<fstream>
#include"clsDate.h"


class clsMainScrean :public clsHeaderScrean
{
private:

	 static void _Performancess(short Number)
	{
		
		switch (Number)
		{
		case 1:
		{
			system("cls");

			if (!CurrentUser. CheckUsserHavePermessionOrNot(clsUser::enPermissions::pListClients))
			{
				clsHeaderScrean::PrintDisAllowedToEnter();
				cout << "\nEnter 1 to return to Main Menue\n";
				short Answer;
				cin >> Answer;
				if (Answer == 1)
				{
					system("cls");
					PrintMainScrean();
				}

				return;
			}


			clsClientListScrean::ShowClientScrean();
			cout << "\nEnter 1 to return to Main Menue\n";
			short Answer;
			cin >> Answer;
			if (Answer==1)
			{
				system("cls");
				PrintMainScrean();
			}

			break;
		}
		case 2:
		
		{	system("cls");
				//cout << "This Is Add New Client Screan";

		if (!CurrentUser.CheckUsserHavePermessionOrNot(clsUser::enPermissions::pAddNewClient))
		{
			clsHeaderScrean::PrintDisAllowedToEnter();
			cout << "\nEnter 1 to return to Main Menue\n";
			short Answer;
			cin >> Answer;
			if (Answer == 1)
			{
				system("cls");
				PrintMainScrean();
			}
			return;
		}

				clsAddNewClientScreen::AddNewClientScrean();
		cout << "\nEnter 1 to go to Main Menue\n";
		short Answer;
		cin >> Answer;
		if (Answer == 1)
		{
			system("cls");
			PrintMainScrean();
		}
			break;
		}
		case 3:
		{
			system("cls"); 
			//cout << "This Is Update Client Info Screan";


			if (!CurrentUser.CheckUsserHavePermessionOrNot(clsUser::enPermissions::pDeleteClient))
			{
				clsHeaderScrean::PrintDisAllowedToEnter();
				cout << "\nEnter 1 to return to Main Menue\n";
				short Answer;
				cin >> Answer;
				if (Answer == 1)
				{
					system("cls");
					PrintMainScrean();
				}
				return;
			}
			clsDeletClientScrean::DeletClientScrean();
		cout << "Enter 1 to go to Main Menue\n";
		short Answer;
		cin >> Answer;
		if (Answer == 1)
		{
			system("cls");
			PrintMainScrean();
		}
			break;
		}
		case 4:
		{
			system("cls");

			if (!CurrentUser.CheckUsserHavePermessionOrNot(clsUser::enPermissions::pUpdateClients))
			{
				clsHeaderScrean::PrintDisAllowedToEnter();
				cout << "\nEnter 1 to return to Main Menue\n";
				short Answer;
				cin >> Answer;
				if (Answer == 1)
				{
					system("cls");
					PrintMainScrean();
				}
				return;
			}
			clsAbdatedClientScrean::updatedClientScrean();
			cout << "Enter 1 to go to Main Menue\n";
			short Answer;
			cin >> Answer;
			if (Answer == 1)
			{
				system("cls");
				PrintMainScrean();
			}
			break;
		}
		case 5:
		{
			system("cls");
			//cout << "This Is  Find Client Screan";

			if (!CurrentUser.CheckUsserHavePermessionOrNot(clsUser::enPermissions::pFindClient))
			{
				clsHeaderScrean::PrintDisAllowedToEnter();
				cout << "\nEnter 1 to return to Main Menue\n";
				short Answer;
				cin >> Answer;
				if (Answer == 1)
				{
					system("cls");
					PrintMainScrean();
				}
				return;
			}
			clsFindClientScrean::FindClientScrean();
			cout << "Enter 1 to go to Main Menue\n";
			short Answer;
			cin >> Answer;
			if (Answer == 1)
			{
				system("cls");
				PrintMainScrean();
			}
			break;
		}
		case 6:
		{
			system("cls");

			if (!CurrentUser.CheckUsserHavePermessionOrNot(clsUser::enPermissions::pTranactions))
			{
				clsHeaderScrean::PrintDisAllowedToEnter();
				cout << "\nEnter 1 to return to Main Menue\n";
				short Answer;
				cin >> Answer;
				if (Answer == 1)
				{
					system("cls");
					PrintMainScrean();
				}
				return;
			}
			//cout << "This Is Trancaction  Screan";
			clsTransaction::ShowTransactionMenue();
			PrintMainScrean();
			break;
		}
		case 7:
		{
			system("cls");

			if (!CurrentUser.CheckUsserHavePermessionOrNot(clsUser::enPermissions::pManageUsers))
			{
				clsHeaderScrean::PrintDisAllowedToEnter();
				cout << "\nEnter 1 to return to Main Menue\n";
				short Answer;
				cin >> Answer;
				if (Answer == 1)
				{
					system("cls");
					PrintMainScrean();
				}
				return;
			}
			clsManageUsers::ShowManageUsersMenue();
				PrintMainScrean();
			
			break;
		}
		case 8:
		{
			system("cls");

			CurrentUser = clsUser::Find("", "");
			
			break;
		}
		

		}
		
	}

	 static void _RejesterRecord()
	{
		fstream MyFile;
		MyFile.open("RejesterFile.txt", ios::out| ios::app );
		if (MyFile.is_open())
		{
			MyFile<< clsDate::GetSystemTimeTostring()<< CurrentUser.UserName << "#//#" << CurrentUser.Password << "#//#" << CurrentUser.Permissions << endl;

			MyFile.close();
		}

	}

public:
	
	static void PrintMainScrean()
	{

		clsHeaderScrean::PrintHeader("Main Screan");
		cout << "\t\t\t\t[1] Show Client List\n";
		cout << "\t\t\t\t[2] Add New Client \n";
		cout << "\t\t\t\t[3] Delet Client\n";
		cout << "\t\t\t\t[4] Update Client Info\n";
		cout << "\t\t\t\t[5] Find Client\n";
		cout << "\t\t\t\t[6] Trancaction\n";
		cout << "\t\t\t\t[7] Manage Users\n";
		cout << "\t\t\t\t[8] LogOut\n";

		_RejesterRecord();


		cout << "Choise What you Need\n";
		short Number = 1;
		 Number = clsInputValidate::ReadShortNumberBetween(1, 8);
		 _Performancess(Number);
	}
	
};

