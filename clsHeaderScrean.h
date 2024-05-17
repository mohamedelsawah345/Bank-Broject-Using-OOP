#pragma once
#include<iostream>
#include "clsDate.h"
#include"Global.h"

using namespace std;


class clsHeaderScrean
{
private:
	

public:

 static void PrintHeader(string Header, string SubTitle="")
	{

		cout << "\n___________________________________________________________________________\n";
		cout << "\t\t\t\t" << Header << "\t\t\t\t";
		if (SubTitle!="")
		{
			cout << "\n\t\t\t\t" << SubTitle;
		}
		cout << "\n___________________________________________________________________________\n";

		cout << "\t\t\t\t" <<" this Is User :"<<CurrentUser.UserName << "\t\t\t\t\n";
		cout << "\t\t\t\t" << " Time Now Is :"<<clsDate::DateToString(clsDate()) ;
		cout << endl;
	}

 static void PrintDisAllowedToEnter()
 {

	 cout << "\n____________________________________________________\n";
		 cout << "DisAllowed To Enter To This File ,Don't Have Permisin\n";
		 cout << "____________________________________________________\n";


 }

};

