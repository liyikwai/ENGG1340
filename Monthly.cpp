#include <iostream>
#include <string>
#include <fstream>
#include "Monthly.h"
#include "Definition.h"
using namespace std;
void Calculate_Monthly(date *&Date, int count, double &Monthly_Balance, double &Monthly_Income, double &Monthly_Expense)
{
  double Months = (Date[count - 1].Year - Date[0].Year) * 12 + (Date[count - 1].Month - Date[0].Month) + 1; // how many months there are
  Monthly_Income = Monthly_Expense = 0;
  for (int i = 0; i < count; i++)
  {
    if (Date[i].rec.Type == 2)
      Monthly_Income += Date[i].rec.Amount;
    else
      Monthly_Expense += Date[i].rec.Amount;
  }
  Monthly_Income /= Months;
  Monthly_Expense /= Months;
  Monthly_Balance = Monthly_Income - Monthly_Expense;
}

void Reading_record()
{
  ifstream in("Financial_Record.txt");
  for (string str; getline(in, str);) // line by line
    cout << str << endl;
  cout << ""; // prevent weird characters at EOF
  cout << "(Financial_Record.txt has been created successfully) " << endl;
}

void setting_goal(int Monthly_Balance)
{
  double Goal, Monthly_Goal;
  cout << "What's your goal?" << endl;
  cin >> Goal;
  cout << "That will take you at least " << Goal / Monthly_Balance << " months." << endl; // spending all budget left
  cout << "How much per month do you want to save to achieve your goal?" << endl;
  while (true)
  {
    cin >> Monthly_Goal;
    if (Monthly_Goal > Monthly_Balance)
    {
      cout << "That's beyond your financial capability!" << endl;
      break;
    }
    else
    {
      cout << "That will take you " << Goal / Monthly_Goal << " months to achieve!" << endl;
      break;
    }
  }
}
