#pragma once
#include<iostream>
#include"clsPerson.h"
#include"clsString.h"
#include<vector>
#include<string>
#include<fstream>


using namespace std;


class clsClientBank :public clsPerson
{
private:
	enum enMode
	{
		Empty = 1,
		Update=2,
        AddNew=3
	};
   

	 enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	double _Balance;
    bool _MarkedForDelet = false;


   
    static clsClientBank _ConvertLineToObject(string Line,string Seperator ="#//#")
    {
        vector<string>vsClient;
        vsClient = clsString::Split(Line, Seperator);


        return clsClientBank(enMode::Update, vsClient[0], vsClient[1], vsClient[2],
            vsClient[3], vsClient[4], vsClient[5], stod(vsClient[6]));
        //????? ????????? ?? ????????????? ???? ??????
    }
   static string _ConvertObjectToLine(clsClientBank Object1)
    {
        string Line;
        Line = Object1.FirstName+"#//#";
        Line += Object1.LastName + "#//#";
        Line += Object1.Email+ "#//#";
        Line += Object1.Phone + "#//#";
        Line += Object1.AccountNumber() + "#//#";
        Line += Object1.PinCode + "#//#";
        Line += to_string( Object1.Balance);
      

        return Line;

    }
   ///////////////////////////////////////////////////////////////////////////

    static clsClientBank _GetEmptyClientObjectt()
    {
        return clsClientBank(enMode::Empty, " ", " ", " ", " ", " "," ",0);
    }
    /////////////////////////////////////////////////////////////////
    static vector<clsClientBank> _LoadDateFromFile()
    {
        vector<clsClientBank> vFileDate;

        string Line;


        fstream MyFile;
        MyFile.open("Yarb.txt", ios::in);

        if (MyFile.is_open())
        {
            while (getline(MyFile, Line))
            {
                clsClientBank Client = _ConvertLineToObject(Line);
               
                vFileDate.push_back(Client);


            }


            MyFile.close();

        }
        return vFileDate;
    }
    static void _LoadDatetoFile(vector<clsClientBank> vFileDate)
    {
       
        
        string Line;
        fstream MyFile;
        MyFile.open("Yarb.txt", ios::out);

        if (MyFile.is_open())
        {
            for (clsClientBank Client : vFileDate)
            {
                if (!Client._MarkedForDelet)
                {
                    Line = _ConvertObjectToLine(Client);
                    MyFile << Line << endl;
                }
               

            }


            MyFile.close();

        }
      
    }

    ///////////////////////////////////////////////////////////////
    void _AddNewDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("yarb.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }
    void _AddNew()
    {

        _AddNewDataLineToFile(_ConvertObjectToLine(*this));
    }
    ////////////////////////////////////////////////
public:

	clsClientBank(enMode Mode,string FristName, string LastName, string Email,
		string Phone,string AccountNumber, string PinCode, float Balance )
		:clsPerson( FristName, LastName, Email, Phone) // ??? ???? ??? ???? ?? ?? ?? ???? ??? ???????????? ???? ???????? ??????? ?????
	{
		 _Mode=Mode;
	     _AccountNumber= AccountNumber;
		 _PinCode= PinCode;
		 _Balance=Balance;
	}

   
///////////////////////////////////////////////////////////////SetAndGet
    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }
    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetBalance(float Balance)
    {
        _Balance = Balance;
    }
    float GetBalance()
    {
        return _Balance;
    }
    __declspec(property(get = GetBalance, put = SetBalance)) float Balance;
    ///////////////////////////////////////////////
    
   

   static clsClientBank Find(string AccountNumber)
   {
       string Line;
       fstream MyFile;
       MyFile.open("yarb.txt", ios::in);

      // fstream::open("Client.txt", ios::in);//read only "in"
       if (MyFile.is_open())//open
       {
           while (getline(MyFile,Line))
           {
              clsClientBank Client =_ConvertLineToObject(Line,"#//#");
              
              if (Client.AccountNumber() == AccountNumber)
              {
                  MyFile.close();
                  return Client;
              }

           }



           MyFile.close();

           return _GetEmptyClientObjectt();
       }



      return _GetEmptyClientObjectt();
   }
   static clsClientBank Find(string AccountNumber, string PinCode)
   {
       fstream MyFile;
       MyFile.open("yarb.txt", ios::in);

           if(MyFile.is_open())
           {
               string Line;
               while (getline(MyFile,Line))
               {

                  clsClientBank Client= _ConvertLineToObject(Line, "#//#");

                  if (Client.AccountNumber() == AccountNumber&&Client.PinCode==PinCode)
                  {
                      MyFile.close();

                      return Client;
                  }
               }


               MyFile.close();

               return _GetEmptyClientObjectt();
           }


   }


   bool IsEmpty()
   {

       return(_Mode == enMode::Empty);
   }
   static bool IsClientExist(string Accountnumbers)
   {
      
       clsClientBank  Client1 = clsClientBank::Find(Accountnumbers);
      

       return (!Client1.IsEmpty());
   }

   
   static  void SaveUpdatedDateToFile(clsClientBank Client1)
    {
      
       vector<clsClientBank>vsClient;
       vsClient = _LoadDateFromFile();

         for ( clsClientBank &Client : vsClient)
         {
            if (Client.AccountNumber() ==Client1.AccountNumber() )
            {
                Client = Client1;
                break;
            }
           

         }
         _LoadDatetoFile(vsClient);


    }
    void UpdateClient()
   {
    
      SaveUpdatedDateToFile(*this);
   }

    static clsClientBank AddNewObject(string AcccountNumber)
    {
        return clsClientBank(enMode::AddNew, "", "", "", "", AcccountNumber, "", 0);

    }
    void AddClient()
    {

        _AddNew();
    }

   static enum enSavedResult {
        FaildExistClient=1,
        SavedSuccessfuly = 2,
        FaildEmptyClient = 3


    };
    enSavedResult Save()
   {
       switch (_Mode)
       {
       case enMode::Empty:
           if (IsEmpty())
           {
               return enSavedResult::FaildEmptyClient;
           }
         
         
       case  enMode::Update:
       {
           UpdateClient();
          return enSavedResult::SavedSuccessfuly;
       }
          
          
       case  enMode::AddNew:
       {
         
           if (IsClientExist(_AccountNumber))
           {
               return enSavedResult::FaildExistClient;
           }
           else
           {
               AddClient();
               _Mode = enMode::Update;
               return enSavedResult::SavedSuccessfuly;
           }

       }
      
       }


   }


    static void DeletClientWithAccountNumber(string AccountNumber)
    {

        clsClientBank Client1 = Find(AccountNumber);
        Client1._MarkedForDelet = true;
       
        SaveUpdatedDateToFile(Client1);

       

       

    }
  
    static  vector<clsClientBank>  GetClientList()
    {

        return _LoadDateFromFile();

    }

    static double  GetTotalBalances()
    {
        double TotalBalance=0;
        vector< clsClientBank> Date= _LoadDateFromFile();
        for (clsClientBank Client1:Date)
        {
            TotalBalance += Client1.Balance;
        }
      
        return TotalBalance;
    }

    static void ReadInfo(clsClientBank& Client)
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

};

