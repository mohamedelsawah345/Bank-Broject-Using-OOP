#pragma once
#include"clsHeaderScrean.h"
#include"clsTransactionScreen.h"
#include"clsDepositScreen.h"
#include"clsWithDrawScreen.h"

class clsTransaction 
{
	

	static void _PerformanceOfTransactin()
	{
		short Num1 = 0;
		cout << "enter Number you Want It\n";
		cin >> Num1;
		switch (Num1)
		{
		case 1:
		{
			system("cls");
			clsDepositeScrean::showDepositeScrean();

			cout << "Enter 1 to go to TransactionMenue\n";
			short Answer;
			cin >> Answer;
			if (Answer == 1)
			{
				system("cls");
				ShowTransactionMenue();
			}
		


			break;
		}

		case 2:
		{
			system("cls");

			clsWithDrawScreen::showDepositeScrean();

			cout << "Enter 1 to go to TransactionMenue\n";
			short Answer;
			cin >> Answer;
			if (Answer == 1)
			{
				system("cls");
				ShowTransactionMenue();
			}
			

			break;
		}

		case 3:
		{
			system("cls");
			cout << "This Is Total Balance Screen\n";

			cout << "Enter 1 to go to TransactionMenue\n";
			short Answer;
			cin >> Answer;
			if (Answer == 1)
			{
				system("cls");
				ShowTransactionMenue();
			}
			

			break;
		}
		case 4:
		{

			system("cls");
			//cout << "This Is  Main Menue Screen\n";
			
			
			
			break;


		}
		}
	}

 public:

	static void ShowTransactionMenue()
	{
		clsHeaderScrean::PrintHeader("TransactionScreen");
		cout << "[1] Deposite\n";
		cout << "[2] withDraw\n";
		cout << "[3] Total Balance\n";
		cout << "[4] Main Menue\n";
		_PerformanceOfTransactin();

	}
};

