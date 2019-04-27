#include <iostream>
#include <string>
#include "DeleteChange.h"
#include "Definition.h"
using namespace std;

void Delete(date *&Date, int &size, int &count, int DD, int MM, int YYYY, int Del_Type, int Number, string Info)
{
  date *Temp = new date [size-1];
  int k = 0;
  count--;
  for (int i = 0; i < size - 1; i++)
  {
    if(Date[i].Day == DD && Date[i].Month == MM && Date[i].Year == YYYY)
      if (Date[i].rec.Type == Del_Type && Date[i].rec.Amount == Number && Date[i].rec.Info == Info)
        k++;  // Jump over the aim
    Temp[i] = Date[k];
    k++;
  }
  delete[] Date;  //release memory
  Date = Temp;
}

void Change(date *&Date, int size, int DD, int MM, int YYYY, int Change_Type, int Number, string Info)
{ //change from A to B
  int New_DD, New_MM, New_YYYY, New_Type, New_Amount;
  string New_Info, New_Type_String; // B's Info
  cout << "Please enter the date of the record" << endl;
  cout << "DD MM YYYY: " << endl;
  cin >> New_DD >> New_MM >> New_YYYY;
  cout << "Change the record to Income or Expense (input I or E): " << endl;
  cin >> New_Type_String;
  if (New_Type_String == "I")
  {
    New_Type = 2;
    cout << "Please enter the amount" << endl;
    cout << "Income: " << endl;
    cin >> New_Amount;
    cout << "Please enter the information of the income" << endl;
    cout << "Info: E: Earned Income\tF: Portfolio Income\tP: Passive Income" << endl;
    cin >> New_Info;
  }
  else if (New_Type_String == "E")
  {
    New_Type = 1;
    cout << "Please enter the amount" << endl;
    cout << "Expense: " << endl;
    cin >> New_Amount;
    cout << "Please enter the information of the expense" << endl;
    cout << "Info: T: Transportation\tF: Food & Drinks\tL: Living & Others" << endl;
    cin >> New_Info;
  }
  int Flag = 0; // to see if there is a match
  for (int i = 0; i < size; i++)
    if (Date[i].Day == DD && Date[i].Month == MM && Date[i].Year == YYYY)
      if (Date[i].rec.Type == Change_Type && Date[i].rec.Amount == Number && Date[i].rec.Info == Info)
      {
        Date[i].Day = New_DD;
        Date[i].Month = New_MM;
        Date[i].Year = New_YYYY;
        Date[i].rec.Type = New_Type;
        Date[i].rec.Amount = New_Amount;
        Date[i].rec.Info = New_Info;
        Flag = 1;
        break;
      }
  if (Flag == 0) //there is no match
    cout << "No such records found" << endl;
}
