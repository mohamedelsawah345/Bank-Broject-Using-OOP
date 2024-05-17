#pragma once
#include "Global.h"
#include<iostream>
#include "clsMainScrean.h"
#include"clsHeaderScrean.h"
class clsLogin :protected clsHeaderScrean
{

 public:
	 static void ShowLoginScreen()
	 {
		 system("cls");
		 clsHeaderScrean::PrintHeader("Welcome To You In Login Screen");
		 bool Login = false;
		 string UserName, Password;
		 short Counter = 0;
		 do
		 {
			 cout << "Enter UserName And Passowrd\n";
			 cout << "Enter UsserName";
			 cin >> UserName;
			 cout << "Enter Password";
			 cin >> Password;

			 CurrentUser = clsUser::Find(UserName, Password);


			 if (CurrentUser.IsEmpty())
			 {
				 cout << "This Is Invalid UserName Or Passowrd";
				 Login = false;
				 CounterBlock ++;
			 }
			 else
			 {
				 Login = true;

				 clsMainScrean::PrintMainScrean();


			 }


		 } while (Login|| CounterBlock <=3);
		 if (CounterBlock > 3)
		 {
		 cout << "You Are Blocked Becaudse U Enter Password Three Time Wrong";
		 cout << "enter Enty thing to end";
		 system("pause");
		 }
		
		
	 }








};

