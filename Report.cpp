#include <iostream>
#include <iomanip>
#include <string>
#include "Report.h"
#include "Definition.h"
using namespace std;
void Report(date *&Date, int count)
{ // produce an annual report
  double Annual_Income = 0, Annual_Expense = 0;
  double Income_E = 0, Income_F = 0, Income_P = 0;
  double Expense_T = 0, Expense_F = 0, Expense_L = 0;
  int Year = Date[0].Year;
  cout << left;
  cout << "Year : "
       << "Statistical Data"
       << "         Amount "
       << "Percentage " << endl;
  for (int i = 0; i < count; i++)
  {
    if (Date[i].Year == Year)
    {
      if (Date[i].rec.Type == 2)
      {
        Annual_Income += Date[i].rec.Amount;
        if (Date[i].rec.Info == "E")
          Income_E += Date[i].rec.Amount;
        else if (Date[i].rec.Info == "F")
          Income_F += Date[i].rec.Amount;
        else //P
          Income_P += Date[i].rec.Amount;
      }
      if (Date[i].rec.Type == 1)
      {
        Annual_Expense += Date[i].rec.Amount;
        if (Date[i].rec.Info == "T")
          Expense_T += Date[i].rec.Amount;
        else if (Date[i].rec.Info == "F")
          Expense_F += Date[i].rec.Amount;
        else //L
          Expense_L += Date[i].rec.Amount;
      }
    }
        double P_Earned = Income_E * 100 / Annual_Income, P_Porfolio = Income_F * 100 / Annual_Income, P_Passive = Income_P * 100 / Annual_Income, P_Transportation = Expense_T * 100 / Annual_Expense, P_Food = Expense_F * 100/Annual_Expense, P_living = Expense_L * 100 / Annual_Expense;
          if (Annual_Income == 0){
            P_Earned = 0; P_Porfolio = 0; P_Passive = 0;
          }
          if (Annual_Expense == 0){
            P_Transportation = 0; P_Food = 0; P_living = 0;
          }

    if (Date[i].Year != Year || i == count - 1)
    { // if year changes or reaches the last one
      cout << endl;
      cout << left;
      cout << Year << setw(28) << " : Average Monthly Income " << setw(5) << Annual_Income << "  \\ " << endl;
      cout << Year << setw(28) << " : Average Monthly Expense " << setw(5) << Annual_Expense << "  \\ " << endl;
      cout << Year << setw(28) << " : Net Income " << setw(5) << Annual_Income - Annual_Expense << "  \\ " << endl;
      cout << Year << setw(28) << " : Earned Income " << setw(5) << Income_E << "  " << P_Earned << "%" << endl;
      cout << Year << setw(28) << " : Porfolio Income " << setw(5) << Income_F << "  " << P_Porfolio  << "%" << endl;
      cout << Year << setw(28) << " : Passive Income " << setw(5) << Income_P << "  " << P_Passive << "%" << endl;
      cout << Year << setw(28) << " : Transportation Expense " << setw(5) << Expense_T << "  " << P_Transportation << "%" << endl;
      cout << Year << setw(28) << " : Food & Drinks " << setw(5) << Expense_F << "  " << P_Food << "%" << endl;
      cout << Year << setw(28) << " : Living & Others " << setw(5) << Expense_L << "  " <<  P_living << "%" << endl;
      Year = Date[i].Year; // year changes
      Annual_Income = Annual_Expense = 0;
      Income_E = Income_F = Income_P = 0;
      Expense_T = Expense_F = Expense_L = 0;
      if (Date[i].rec.Type == 2)
      {
        Annual_Income += Date[i].rec.Amount;
      }
      if (Date[i].rec.Type == 1)
      {
        Annual_Expense += Date[i].rec.Amount;
      }
    }
  }
}
