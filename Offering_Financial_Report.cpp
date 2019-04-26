#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Offering_Financial_Report.h"
using namespace std;

void Calculate_Monthly(date * &Date, int count, double &Monthly_Balance, double &Monthly_Income, double &Monthly_Expense){
  double Months = (Date[count - 1].Year - Date[0].Year) * 12 + (Date[count - 1].Month - Date[0].Month) + 1; // how many months there are
  Monthly_Income = Monthly_Expense = 0;
  for (int i = 0; i < count; i++){
    if (Date[i].rec.Type == 2)
      Monthly_Income += Date[i].rec.Amount;
    else 
      Monthly_Expense += Date[i].rec.Amount;
  }
  Monthly_Income /= Months;
  Monthly_Expense /= Months;
  Monthly_Balance = Monthly_Income - Monthly_Expense;
}

void Report(date *&Date, int count){ // produce an annual report
  double Annual_Income = 0, Annual_Expense = 0;
  double Income_E = 0, Income_F = 0, Income_P = 0;
  double Expense_T = 0, Expense_F = 0, Expense_L = 0;
  int Year = Date[0].Year;
    cout<<left;
  cout << "Year : " << "Statistical Data" << "         Amount " << "Percentage " << endl; 
  for (int i = 0; i < count; i++){
    if (Date[i].Year == Year){
      if (Date[i].rec.Type == 2){
        Annual_Income += Date[i].rec.Amount;
        if (Date[i].rec.Info == "E")
          Income_E += Date[i].rec.Amount;
        else if (Date[i].rec.Info == "F")
          Income_F += Date[i].rec.Amount;
        else //P
          Income_P += Date[i].rec.Amount;
      }
      if (Date[i].rec.Type == 1){
        Annual_Expense += Date[i].rec.Amount;
        if (Date[i].rec.Info == "T")
          Expense_T += Date[i].rec.Amount;
        else if (Date[i].rec.Info == "F")
          Expense_F += Date[i].rec.Amount;
        else //L
          Expense_L += Date[i].rec.Amount;
      }
    }
    if (Date[i].Year != Year || i == count - 1) { // if year changes or reaches the last one
      cout<<endl;
      cout<<left; 
      cout << Year << setw(28) << " : Average Monthly Income " << setw(5) << Annual_Income << "  \\ " << endl;
      cout << Year << setw(28) << " : Average Monthly Expense " << setw(5) << Annual_Expense << "  \\ " << endl;
      cout << Year << setw(28) << " : Net Income " << setw(5) << Annual_Income - Annual_Expense << "  \\ " << endl;
      cout << Year << setw(28) << " : Earned Income " << setw(5) << Income_E << "  " << Income_E * 100 / Annual_Income << "%" << endl;
      cout << Year << setw(28) << " : Porfolio Income " << setw(5) << Income_F << "  " << Income_F * 100 / Annual_Income << "%" << endl;
      cout << Year << setw(28) << " : Passive Income " << setw(5) << Income_P << "  " << Income_P * 100 / Annual_Income << "%" << endl;
      cout << Year << setw(28) << " : Transportation Expense " << setw(5) << Expense_T << "  " << Expense_T * 100 / Annual_Expense << "%" << endl;
      cout << Year << setw(28) << " : Food & Drinks " << setw(5) << Expense_F << "  " << Expense_F * 100 / Annual_Expense << "%" << endl;
      cout << Year << setw(28) << " : Living & Others " << setw(5) << Expense_L << "  " << Expense_L * 100 / Annual_Expense << "%" << endl;
      Year = Date[i].Year; // year changes
      Annual_Income = Annual_Expense = 0;
      Income_E = Income_F = Income_P = 0;
      Expense_T = Expense_F = Expense_L = 0;
      if (Date[i].rec.Type == 2){
        Annual_Income += Date[i].rec.Amount;
      }
      if (Date[i].rec.Type == 1){
        Annual_Expense += Date[i].rec.Amount;
      }
    }
  }
}

