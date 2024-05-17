#pragma once
#include"clsHeaderScrean.h"
#include"clsUsersList.h"
#include "clsAddNewClientScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"



class clsManageUsers
{


	static void _PerformanceOfManageUsers()
	{
		short Num1 = 0;
		cout << "enter Number you Want It\n";
		cin >> Num1;
		switch (Num1)
		{
		case 1:
		{
			system("cls");
			clsListUsersScreen::ShowUsersList();

			cout << "Enter 1 to go to ManageUsers Screen\n";
			short Answer;
			cin >> Answer;
			if (Answer == 1)
			{
				system("cls");
				ShowManageUsersMenue();
			}



			break;
		}

		case 2:
		{

			system("cls");
			/*cout << "This Is Manade Users 2\n";*/
			clsAddNewClientScreen::AddNewClientScrean();

			cout << "Enter 1 to go to ManageUsers Screen\n";
			short Answer;
			cin >> Answer;
			if (Answer == 1)
			{
				system("cls");
				ShowManageUsersMenue();
			}



			break;
		}

		case 3:
		{
			system("cls");
			//cout << "This Is Manade Users 3\n";
			 clsDeleteUserScreen:: ShowDeleteUserScreen();

			cout << "Enter 1 to go to ManageUsers Screen\n";
			short Answer;
			cin >> Answer;
			if (Answer == 1)
			{
				system("cls");
				ShowManageUsersMenue();
			}



			break;
		}
		case 4:
		{

			system("cls");
			//cout << "This Is Manade Users 4\n";
			clsUpdateUserScreen::ShowUpdateUserScreen();

			cout << "Enter 1 to go to ManageUsers Screen\n";
			short Answer;
			cin >> Answer;
			if (Answer == 1)
			{
				system("cls");
				ShowManageUsersMenue();
			}



			break;

		}
		case 5:
		{
			system("cls");
			//cout << "This Is Manade Users 5\n";
			clsFindUserScreen::ShowFindUserScreen();

			cout << "Enter 1 to go to ManageUsers Screen\n";
			short Answer;
			cin >> Answer;
			if (Answer == 1)
			{
				system("cls");
				ShowManageUsersMenue();
			}


			break;
		}

		case 6:
		{
				system("cls");
			break;

		}

		}
	}

public:

	static void ShowManageUsersMenue()
	{
		clsHeaderScrean::PrintHeader("ManageUsers Screen");
		cout << "[1] List Users\n";
		cout << "[2] Add New Yousers\n";
		cout << "[3] DeletUsers\n";
		cout << "[4] Update Users\n";
		cout << "[5] Find User\n";
		cout << "[6] Main Menue\n";
		_PerformanceOfManageUsers();

	}
};

