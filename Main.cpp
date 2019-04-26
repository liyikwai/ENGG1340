#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Adding_Record.h"
#include "Offering_Basic_Information.h"
#include "Editing_And_Deleting.h"
#include "Searching_The_Records.h"
#include "Offering_Financial_Report.h"
#include "Setting_Budget.h"
#include "Setting_And_Estimate_the_Goal.h"
#include "Definition.h"
using namespace std;


bool operator<(const record &a, const record &b) { // define a less-than < for record
  if (a.Type < b.Type)
    return true;
  if (a.Type > b.Type)
    return false;
  if (a.Amount < b.Amount)
    return true;
  if (a.Amount > b.Amount)
    return false;
  return a.Info < b.Info;
}

bool operator<(const date &a, const date &b) { // define a less-than < for date
  if (a.Year < b.Year)
    return true;
  if (a.Year > b.Year)
    return false;
  if (a.Month < b.Month)
    return true;
  if (a.Month > b.Month)
    return false;
  if (a.Day < b.Day)
    return true;
  if (a.Day > b.Day)
    return false;
  return a.rec < b.rec;
}

void Sort(date *&Date, int count){
  int Actual_Count = count;
  for (int i = 0; i < count; i++){
    if (Date[i].rec.Type == 0){
      Actual_Count = i + 1;
      break;
    }
  } // see how many entries there are
  for (int i = 0; i < Actual_Count - 1; i++)
    for (int j = i + 1; j < Actual_Count; j++)
      if (Date[i] < Date[j]){
        date *Temp = new date; //dynamic memory
        *Temp = Date[i];
        Date[i] = Date[j];
        Date[j] = *Temp;
        delete Temp;  //release memory
      }
}

int main() {
  string Command;
  int count = 0, size = 100;
  double total_income=0, total_expense=0, net_asset=0;
  date *Date = new date[100]; //initialization
  double Budget = -1;
  double Monthly_Balance = 0, Monthly_Income = 0, Monthly_Expense = 0;
  while(true) {      
    cout<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"|ENGG1340 Accounting System|"<<endl;
    cout<<"|          Group73         |"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<endl;
    cout << "Please enter the following commands:" << endl;
    cout << "I: Adding Income" << endl; // Done
    cout << "E: Adding Expense" << endl; // Done
    cout << "P: Present Information and Save it to a file" << endl; // Done
    cout << "C: Change Records" << endl; //Done
    cout << "D: Delete Records" << endl; //Done
    cout << "S: Search Records" << endl; //Done
    cout << "R: Report" << endl; // Done
    cout << "B: Budget Setting" << endl; // Done
    cout << "G: Goal Setting" << endl;   // Done
    cout << "Q: Quit" << endl;  //Done
    cin >> Command;
    if (Command == "Q") // Quit
      break;
	  
    if (Command == "I") { // Adding income
      if (count == size)
        Increase_Size(Date, size);
      Append_Income(Date, count);
      count++;
      continue;
    }
	  
    else if (Command == "E"){ // Adding Expense
      if (count == size)
        Increase_Size(Date, size);
      Append_Expense(Date, count);
      count++;
      continue;
    }

    if (Command != "I" && Command != "E") // All functions below need actual records
      if (count == 0){
        cout << "Warning: No Records!" << endl;
        continue;
      }

    if (Command == "D"){ // Delete Records
      int DD0, MM0, YYYY0;
      double Number0;
      string Del_Type, Info0;
      cout << "Deleting Income or Expense? I: Income E: Expense " << endl; // Search before delete
      cin >> Del_Type;
      cout << "DD MM YYYY: " << endl;
      cin >> DD0 >> MM0 >> YYYY0;
      if (Del_Type == "I"){
        cout << "Income: " << endl;
        cin >> Number0;
        cout << "Info: E: Earned Income\tF: Portfolio Income\tP: Passive Income" << endl;
        cin >> Info0;
        Delete(Date, size, DD0, MM0, YYYY0, 2, Number0, Info0);
      }
      else if (Del_Type == "E"){
        cout << "Expense: " << endl;
        cin >> Number0;
        cout << "Info: T: Transportation\tF: Food & Drinks\tL: Living & Others" << endl;
        cin >> Info0;
        Delete(Date, size, DD0, MM0, YYYY0, 1, Number0, Info0);
      }
      continue;
    }
	  
    if (Command == "C"){
      int DD1, MM1, YYYY1;
      double Number1;
      string Change_Type, Info1;
      cout << "Change Income or Expense? I: Income E: Expense " << endl; // Search before Change
      cin >> Change_Type;
      cout << "DD MM YYYY: " << endl;
      cin >> DD1 >> MM1 >> YYYY1;
      if (Change_Type == "I"){
        cout << "Income: " << endl;
        cin >> Number1;
        cout << "Info: E: Earned Income\tF: Portfolio Income\tP: Passive Income" << endl;
        cin >> Info1;
        Change(Date, size, DD1, MM1, YYYY1, 2, Number1, Info1);
      }
      else if (Change_Type == "E"){
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
    cout<<endl;
    ofstream fout;
    fout.open("Financial_Record.txt");
    if (fout.fail())
      exit(1);
    fout << "          Financial Record           " << endl;
    fout <<  "Day " << setw(6) << "Month "  << "Year " <<  " I/E    " << " Type " << "Amount" << endl; 
    fout<<left;
    for (int i = 0; i < count; i++){
      if (Date[i].rec.Type == 0)
        break;
      fout << setw(4)  << Date[i].Day << setw(6) << Date[i].Month << setw(5) << Date[i].Year << " ";
      if (Date[i].rec.Type == 2){
        fout << "Income  ";
	fout << setw(5)  << Date[i].rec.Info << setw(5) << Date[i].rec.Amount << endl;
	total_income += Date[i].rec.Amount;
      }
      else{
        fout << "Expense ";
        fout << setw(5)  << Date[i].rec.Info << setw(5) << Date[i].rec.Amount << endl;
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
    Calculate_Monthly(Date, count, Monthly_Balance, Monthly_Income, Monthly_Expense);
	  
    // Functions below will not change records
    if (Command == "P"){ // Present Information
      Reading_record();
      continue;
    }
	  
    if (Command == "B"){ // Budget Setting, representing your planned monthly expense
      Setting_budget ( Monthly_Income, Budget);
      continue;
    }
	
    if (Command == "G"){ // Goal Setting, representing your planned expense outside of budget
      if (Monthly_Balance < 0) {
        cout << "You are bleeding money. Please change your spending habit first!" << endl;
        continue;
      }
            Setting_goal( Monthly_Balance );
      continue;
    }

    if (Command == "S"){ // Search Records
      int DD2_1, DD2_2, MM2_1, MM2_2, YYYY2_1, YYYY2_2, Search_Type; // ranges
      double Amount1, Amount2;
      string Search_Type_String, Info;
      cout << "Please enter the range of searching dates (Results between these dates): " << endl << "(DD1 MM1 YYYY1 DD2 MM2 YYYY2): " << endl;
      cin >> DD2_1 >> MM2_1 >> YYYY2_1 >> DD2_2 >> MM2_2 >> YYYY2_2;
      cout << "Please enter the Type " << endl << "(I for Income, E for Expense): " << endl;
      cin >> Search_Type_String;
      if (Search_Type_String == "I")
        Search_Type = 2;
      else if (Search_Type_String == "E")
        Search_Type = 1;
      cout << "Please enter range of searching amount "<< endl << "(Amount1 Amount2): " << endl;
      cin >> Amount1 >> Amount2;
      if (Search_Type == 2){
        cout << "Please enter the searching info " << endl << "(E: Earned Income\tF: Portfolio Income\tP: Passive Income): " << endl;
        cin >> Info;
      }
      else if (Search_Type == 1){
        cout << "Please enter the searching info " << endl << "(T: Transportation\tF: Food & Drinks\tL: Living & Others): " << endl;
        cin >> Info;
      }
	    Search(Date, count, DD2_1, MM2_1, YYYY2_1, DD2_2, MM2_2, YYYY2_2, Search_Type, Amount1, Amount2, Info);
      continue;
    }
	  
    if (Command == "R"){
      cout << "          Financial Report          " << endl;
      cout << "Total income: " << total_income << endl;
      cout << "Total expense " << total_expense << endl;
      cout << "Net asset " << net_asset << endl; 
      Report(Date, count);
    }
    else{ // No such command
      cout << "Command not found" << endl;
      continue;
    }
  }
	
  delete[] Date; //release memory
  return 0;
}}