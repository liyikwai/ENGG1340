#include <iostream>
#include <string>
#include "Append.h"
#include "Definition.h"
using namespace std;

void Increase_Size(date *&Date, int &size)
{ // increase the size of dynamic array
  date *temp = new date[size + 10];
  for (int i = 0; i < size; i++)
    temp[i] = Date[i];
  delete[] Date; // release memory
  Date = temp;
  size += 10;
}

void Append_Income(date *&Date, int count)
{ // Add a record of income
  int DD, MM, YYYY;
  double Income;
  string Info;
  cout << "Please enter the date" << endl;
  cout << "DD MM YYYY: " << endl;
  cin >> DD >> MM >> YYYY;
  Date[count].Day = DD;
  Date[count].Month = MM;
  Date[count].Year = YYYY;
  cout << "Please enter the amount" << endl;
  cout << "Income: " << endl;
  cin >> Income;
  cout << "Please enter the information of the income" << endl;
  cout << "Info: " << endl;
  cout << "E: Earned Income\tF: Portfolio Income\tP: Passive Income" << endl; // Types of Income
  cin >> Info;
  Date[count].rec.Amount = Income;
  Date[count].rec.Type = 2;
  Date[count].rec.Info = Info;
}

void Append_Expense(date *&Date, int count)
{ // Add a record of expense
  int DD, MM, YYYY;
  double Expense;
  string Info;
  cout << "Please enter the date" << endl;
  cout << "DD MM YYYY: " << endl;
  cin >> DD >> MM >> YYYY;
  Date[count].Day = DD;
  Date[count].Month = MM;
  Date[count].Year = YYYY;
  cout << "Please enter the amount" << endl;
  cout << "Expense: " << endl;
  cin >> Expense;
  cout << "Please enter the information of the expense" << endl;
  cout << "Info: " << endl;
  cout << "T: Transportation\tF: Food & Drinks\tL: Living & Others" << endl; // Types of Expense
  cin >> Info;
  Date[count].rec.Amount = Expense;
  Date[count].rec.Type = 1;
  Date[count].rec.Info = Info;
}
