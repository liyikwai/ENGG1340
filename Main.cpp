#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "Append.h"
#include "Definition.h"
#include "DeleteChange.h"
#include "Monthly.h"
#include "Report.h"
#include "Search.h"
#include "Sort.h"
using namespace std;
int main()
{
  string Command;
  int count = 0, size = 100;
  double total_income = 0, total_expense = 0, net_asset = 0;
  date *Date = new date[100]; //initialization
  double Budget = -1;
  double Monthly_Balance = 0, Monthly_Income = 0, Monthly_Expense = 0;  
    cout << endl;
  cout << "----------------------------" << endl;
  cout << "|ENGG1340 Accounting System|" << endl;
  cout << "|          Group73         |" << endl;
  cout << "----------------------------" << endl;
  while (true)
  {
    cout << endl;
    cout << "Please enter the following commands:" << endl;
    cout << "I: Adding Income" << endl;                             // Done
    cout << "E: Adding Expense" << endl;                            // Done
    cout << "P: Present Information and Save it to a file" << endl; // Done
    cout << "C: Change Records" << endl;                            //Done
    cout << "D: Delete Records" << endl;                            //Done
    cout << "S: Search Records" << endl;                            //Done
    cout << "R: Report" << endl;                                    // Done
    cout << "B: Budget Setting" << endl;                            // Done
    cout << "G: Goal Setting" << endl;                              // Done
    cout << "Q: Quit" << endl;                                      //Done
    cin >> Command;
    if (Command == "Q") // Quit
      break;
    if (Command == "I")
    { // Adding income
      if (count == size)
        Increase_Size(Date, size);
      Append_Income(Date, count);
      count++;
      continue;
    }
    else if (Command == "E")
    { // Adding Expense
      if (count == size)
        Increase_Size(Date, size);
      Append_Expense(Date, count);
      count++;
      continue;
    }

    if (Command != "I" && Command != "E") // All functions below need actual records
      if (count == 0)
      {
        cout << "Warning: No Records!" << endl;
        continue;
      }

    if (Command == "D")
    { // Delete Records
      int DD0, MM0, YYYY0;
      double Number0;
      string Del_Type, Info0;
      cout << "Deleting Income or Expense? I: Income E: Expense " << endl; // Search before delete
      cin >> Del_Type;
            cout << "Please enter the information of the record to be deleted." << endl;
      cout << "DD MM YYYY: " << endl;
      cin >> DD0 >> MM0 >> YYYY0;
      if (Del_Type == "I")
      {
        cout << "Income: " << endl;
        cin >> Number0;
        cout << "Info: E: Earned Income\tF: Portfolio Income\tP: Passive Income" << endl;
        cin >> Info0;
        Delete(Date, size, DD0, MM0, YYYY0, 2, Number0, Info0);
      }
      else if (Del_Type == "E")
      {
        cout << "Expense: " << endl;
        cin >> Number0;
        cout << "Info: T: Transportation\tF: Food & Drinks\tL: Living & Others" << endl;
        cin >> Info0;
        Delete(Date, size, DD0, MM0, YYYY0, 1, Number0, Info0);
      }
      continue;
    }
    if (Command == "C")
    {
      int DD1, MM1, YYYY1;
      double Number1;
      string Change_Type, Info1;
      cout << "Change Income or Expense? I: Income E: Expense " << endl; // Search before Change
      cin >> Change_Type;
            cout << "Please enter the information of the record to be changed." << endl;
      cout << "DD MM YYYY: " << endl;
      cin >> DD1 >> MM1 >> YYYY1;
      if (Change_Type == "I")
      {
        cout << "Income: " << endl;
        cin >> Number1;
        cout << "Info: E: Earned Income\tF: Portfolio Income\tP: Passive Income" << endl;
        cin >> Info1;
        Change(Date, size, DD1, MM1, YYYY1, 2, Number1, Info1);
      }
      else if (Change_Type == "E")
      {
        cout << "Expense: " << endl;
        cin >> Number1;
        cout << "Info: T: Transportation\tF: Food & Drinks\tL: Living & Others" << endl;
        cin >> Info1;
        Change(Date, size, DD1, MM1, YYYY1, 1, Number1, Info1);
      }
      continue;
    }
    Sort(Date, count); //Sort after all functions that could change records
    //Record_to_File
    cout << endl;
    ofstream fout;
    fout.open("Financial_Record.txt");
    if (fout.fail())
      exit(1);
    fout << "          Financial Record           " << endl;
    fout << "Day " << setw(6) << "Month "
         << "Year "
         << " I/E    "
         << " Type "
         << "Amount" << endl;
    fout << left;
        total_income = 0;
          total_expense = 0;
    for (int i = 0; i < count; i++)
    {
      if (Date[i].rec.Type == 0)
        break;
      fout << setw(4) << Date[i].Day << setw(6) << Date[i].Month << setw(5) << Date[i].Year << " ";
      if (Date[i].rec.Type == 2)
      {
        fout << "Income  ";
        fout << setw(5) << Date[i].rec.Info << setw(5) << Date[i].rec.Amount << endl;
        total_income += Date[i].rec.Amount;
      }
      else
      {
        fout << "Expense ";
        fout << setw(5) << Date[i].rec.Info << setw(5) << Date[i].rec.Amount << endl;
        total_expense += Date[i].rec.Amount;
      }
    }
    net_asset = total_income - total_expense;
    fout << "(Income  E: Earned Income;  F: Portfolio Income; P: Passive Income " << endl;
    fout << " Expense T: Transportation; F: Food & Drinks     L: Living & Others)" << endl;
    fout << "Total income: " << total_income << endl;
    fout << "Total expense: " << total_expense << endl;
    fout << "Net asset: " << net_asset << endl;
    fout.close();
    // Calculate all monthlies after all functions that could change records
    // Functions below will not change records
    if (Command == "P")
    { // Present Information
      Reading_record();
      continue;
    }
    if (Command == "B")
    { // Budget Setting, representing your planned monthly expense
      while (true)
      {
        cout << "Please enter your monthly budget: " << endl;
        cin >> Budget;
        if (Budget <= Monthly_Income)
        {
          cout << "You can afford it." << endl;
          break;
        }
        else
        {
          cout << "Beyond Your financial capability! Please reset your budget!" << endl;
          break;
        }
      }
      continue;
    }
    if (Command == "G")
    { // Goal Setting, representing your planned expense outside of budget
      if (Monthly_Balance < 0)
      {
        cout << "You are bleeding money. Please change your spending habit first!" << endl;
        continue;
      }
      setting_goal(Monthly_Balance);
      continue;
    }

    if (Command == "S")
    {                                                                // Search Records
      int DD2_1, DD2_2, MM2_1, MM2_2, YYYY2_1, YYYY2_2, Search_Type; // ranges
      double Amount1, Amount2;
      string Search_Type_String, Info;
      cout << "Please enter the range of searching dates (Results between these dates): " << endl
           << "(DD1 MM1 YYYY1 DD2 MM2 YYYY2): " << endl;
      cin >> DD2_1 >> MM2_1 >> YYYY2_1 >> DD2_2 >> MM2_2 >> YYYY2_2;
      cout << "Please enter the Type " << endl
           << "(I for Income, E for Expense): " << endl;
      cin >> Search_Type_String;
      if (Search_Type_String == "I")
        Search_Type = 2;
      else if (Search_Type_String == "E")
        Search_Type = 1;
      cout << "Please enter range of searching amount " << endl
           << "(Amount1 Amount2): " << endl;
      cin >> Amount1 >> Amount2;
      if (Search_Type == 2)
      {
        cout << "Please enter the searching info " << endl
             << "(E: Earned Income\tF: Portfolio Income\tP: Passive Income): " << endl;
        cin >> Info;
      }
      else if (Search_Type == 1)
      {
        cout << "Please enter the searching info " << endl
             << "(T: Transportation\tF: Food & Drinks\tL: Living & Others): " << endl;
        cin >> Info;
      }
      Search(Date, count, DD2_1, MM2_1, YYYY2_1, DD2_2, MM2_2, YYYY2_2, Search_Type, Amount1, Amount2, Info);
      continue;
    }
    if (Command == "R")
    {
      cout << "          Financial Report          " << endl;
      cout << "Total income: " << total_income << endl;
      cout << "Total expense " << total_expense << endl;
      cout << "Net asset " << net_asset << endl;
      Report(Date, count);
    }
    else
    { // No such command
      cout << "Command not found" << endl;
      continue;
    }
  }
  delete[] Date; //release memory
  return 0;
}
// Split .cpp and create makefile
