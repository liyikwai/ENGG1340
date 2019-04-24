#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct record {
  int Type; // Income or Expense, 2 for Income, 1 for Expense
  int Amount;
  string Info;
};
struct date {
  int Day;
  int Month;
  int Year;
  record rec;
};
bool operator<(const record &a, const record &b) {
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
bool operator<(const date &a, const date &b) {
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
void Increase_Size(date *&Date, int &size) {
  date *temp = new date [size + 10];
  for (int i = 0; i < size; i++)
    temp[i] = Date[i];
  delete[] Date;
  Date = temp;
  size += 10;
}

void Append_Income(date *&Date, int count) {
  int DD, MM, YYYY;
  double Income;
  string Info;
  cout << "DD MM YYYY: " << endl;
  cin >> DD >> MM >> YYYY;
  Date[count].Day = DD;
  Date[count].Month = MM;
  Date[count].Year = YYYY;
  cout << "Income: " << endl;
  cin >> Income;
  cout << "Info: " << endl;
  cout << "E: Earned Income\tF: Portfolio Income\tP: Passive Income" << endl;
  cin >> Info;
  Date[count].rec.Amount = Income;
  Date[count].rec.Type = 2;
  Date[count].rec.Info = Info;
}

void Append_Expense(date *&Date, int count){
  int DD, MM, YYYY;
  double Expense;
  string Info;
  cout << "DD MM YYYY: " << endl;
  cin >> DD >> MM >> YYYY;
  Date[count].Day = DD;
  Date[count].Month = MM;
  Date[count].Year = YYYY;
  cout << "Expense: " << endl;
  cin >> Expense;
  cout << "Info: " << endl;
  cout << "T: Transportation\tF: Food & Drinks\tL: Living & Others" << endl;
  cin >> Info;
  Date[count].rec.Amount = Expense;
  Date[count].rec.Type = 1;
  Date[count].rec.Info = Info;
}

void Delete(date *&Date, int &size, int DD, int MM, int YYYY, int Del_Type, int Number, string Info){
  date *Temp = new date [size-1];
  int k = 0;
  size--;
  for (int i = 0; i < size; i++){
    if(Date[i].Day == DD && Date[i].Month == MM && Date[i].Year == YYYY)
      if (Date[i].rec.Type == Del_Type && Date[i].rec.Amount == Number && Date[i].rec.Info == Info)
        k++;
    Temp[i] = Date[k];
    k++;
  }
  delete[] Date;
  Date = Temp;
}

void Change(date *&Date, int size, int DD, int MM, int YYYY, int Change_Type, int Number, string Info){
  int New_DD, New_MM, New_YYYY, New_Type, New_Amount;
  string New_Info, New_Type_String;
  cout << "DD MM YYYY: " << endl;
  cin >> New_DD >> New_MM >> New_YYYY;
  cout << "Change to Income or Expense (input I or E): " << endl;
  cin >> New_Type_String;
  if (New_Type_String == "I"){
    New_Type = 2;
    cout << "Income: " << endl;
    cin >> New_Amount;
    cout << "Info: E: Earned Income\tF: Portfolio Income\tP: Passive Income" << endl;
    cin >> New_Info;
  }
  else if (New_Type_String == "E"){
    New_Type = 1;
    cout << "Expense: " << endl;
    cin >> New_Amount;
    cout << "Info: T: Transportation\tF: Food & Drinks\tL: Living & Others" << endl;
    cin >> New_Info;
  }
  for (int i = 0; i < size; i++){
    if(Date[i].Day == DD && Date[i].Month == MM && Date[i].Year == YYYY)
      if (Date[i].rec.Type == Change_Type && Date[i].rec.Amount == Number && Date[i].rec.Info == Info){
        Date[i].Day = New_DD;
        Date[i].Month = New_MM;
        Date[i].Year = New_YYYY;
        Date[i].rec.Type = New_Type;
        Date[i].rec.Amount = New_Amount;
        Date[i].rec.Info = New_Info;
        break;
      }
  }
}

void Sort(date *&Date, int count){
  int Actual_Count = count;
  for (int i = 0; i < count; i++){
    if (Date[i].rec.Type == 0){
      Actual_Count = i + 1;
      break;
    }
  }
  for (int i = 0; i < Actual_Count - 1; i++)
    for (int j = i + 1; j < Actual_Count; j++)
      if (Date[i] < Date[j]){
        date *Temp = new date;
        *Temp = Date[i];
        Date[i] = Date[j];
        Date[j] = *Temp;
        delete Temp;
      }
}

void Search(date *&Date, int count, int DD, int MM, int YYYY){
  for (int i = 0; i < count; i++)
    if (Date[i].Day == DD && Date[i].Month == MM && Date[i].Year == YYYY){
      if (Date[i].rec.Type == 2)
        cout << "Income: " << " ";
      if (Date[i].rec.Type == 1)
        cout << "Expense: " << " ";
      cout << Date[i].rec.Amount << " Info: " << Date[i].rec.Info << endl;
    }
}

void Report(date *&Date, int count){
  int Annual_Income, Annual_Expense, Net_Annual_Income, Year = Date[0].Year;
  for (int i = 0; i < count; i++){
    if (Date[i].Year == Year){
      if (Date[i].rec.Type == 2){
        Annual_Income += Date[i].rec.Amount;
      }
      if (Date[i].rec.Type == 1){
        Annual_Expense += Date[i].rec.Amount;
      }
    }
    else{
      cout << Year << ": Annual income " << Annual_Income << endl;
      cout << Year << " : Annual expense " << Annual_Expense<<endl;
      Year=Date[i].Year;
      Annual_Income = 0;
      Annual_Expense = 0;
       if (Date[i].rec.Type == 2){
        Annual_Income += Date[i].rec.Amount;
      }
      if (Date[i].rec.Type == 1){
        Annual_Expense += Date[i].rec.Amount;
      }
    }
  }
}
int main() {
  string Command;
  int count = 0, size = 100;
  date *Date = new date[100];
  double Budget = -1;
  double Monthly_Balance = 0, Monthly_Income = 0, Monthly_Expense = 0;
  while(true) {
    cout << "Please enter the following commands:" << endl;
    cout << "I: Adding income" << endl; // Done
    cout << "E: Adding Expense" << endl; // Done
    cout << "P: Present Information and Save it to a file" << endl; // Done
    cout << "C: Change Records" << endl; //Done
    cout << "D: Delete Records" << endl; //Done
    cout << "S: Search Records" << endl; //Done, to be Modified
    cout << "R: Report" << endl; // Need to be Modified
    cout << "B: Budget Setting" << endl; // Need Monthly_Income
    cout << "G: Goal Setting" << endl;   // Need Monthly_Balance
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
    if (Command == "D"){ // Delete Records
      if(count == 0){
        cout << "No record to be deleted" << endl;
        continue;
      }
      int DD0, MM0, YYYY0;
      double Number0;
      string Del_Type, Info0;
      cout << "Deleting Income or Expense? I: Income E: Expense " << endl;
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
      if(count==0){
        cout<<"No record to be changed"<<endl;
        continue;
      }
      int DD1, MM1, YYYY1;
      double Number1;
      string Change_Type, Info1;
      cout << "Change Income or Expense? I: Income E: Expense " << endl;
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
      Sort(Date, count);
      // Calculate_Monthly();
      // monthly income, monthly expense, monthly balance, monthly spending compared to budget
    
      if (Command == "P"){ // Present Information
        ofstream fout;
        fout.open("Financial_Record.txt");
        if (fout.fail())
          exit(1);
        for (int i = 0; i < count; i++){
          if (Date[i].rec.Type == 0)
            break;
          cout << Date[i].Day << " " << Date[i].Month << " " << Date[i].Year << " ";
                  fout << Date[i].Day << " " << Date[i].Month << " " << Date[i].Year << " ";
          if (Date[i].rec.Type == 2){
            cout << "Income" << " ";
                      fout << "Income" << " ";
        }
          if (Date[i].rec.Type == 1){
            cout << "Expense" << " ";
                      fout << "Expense" << " ";
          }
          cout << Date[i].rec.Amount << " " << Date[i].rec.Info << endl;
                  fout << Date[i].rec.Amount << " " << Date[i].rec.Info << endl;
        }
        fout.close();
        continue;
      }
    if (Command == "B"){ // Budget Setting
      while(true){
        cout << "Set your budget: " << endl;
        cin >> Budget;
        if (Budget <= Monthly_Income){
          cout << "OK." << endl;
          break;
        }
        else
          cout << "Beyond Your financial capability! Reset your budget!" << endl;
      }
      continue;
    }
    if (Command == "G"){ // Goal Setting
      double Goal, Monthly_Goal;
      cout << "What's your goal?" << endl;
      cin >> Goal;
      cout << "That will take you at least " << Goal / Monthly_Balance << "months." << endl;
      cout << "How much per month do you want to save for it?" << endl;
      while(true){
        if (Monthly_Balance < 0) {
          cout << "You are bleeding money, change your spending habit first!" << endl;
          break;
        }
        cin >> Monthly_Goal;
        if(Monthly_Goal > Monthly_Balance)
          cout << "That's beyond your financial capability!";
        else
          cout << "That will take you " << Goal / Monthly_Goal << " months to achieve!" << endl;
      }
      continue;
    }
    if (Command == "S"){ // Search Records
      int DD2, MM2, YYYY2;
      cout << "Please enter the date for searching: DD MM YYYY: " << endl;
      cin >> DD2 >> MM2 >> YYYY2;
	    Search(Date, count, DD2, MM2, YYYY2);
      continue;
    }
    if (Command == "R"){
      if(count == 0){
        cout << "No record to be reported" << endl;
        continue;
      }
      Report(Date, count);
    }
    else{
        cout<<"Command not found"<<endl;
        continue;
    }
  }
  delete[] Date;
  return 0;
}
// Also need to do file I/O
// Split .cpp and create makefile
// Need Mistake-proof