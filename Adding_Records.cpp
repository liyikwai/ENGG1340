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
  for (int i = 0; i < size - 1; i++){
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

void Search(date *&Date, int count, int DD1, int MM1, int YYYY1, int DD2, int MM2, int YYYY2, int Type, int Amount1, int Amount2, string Info){
  int Flag = 0;
  for (int i = 0; i < count; i++)
    if (Date[i].Year <= YYYY2 && Date[i].Year >= YYYY1 && Date[i].Month <= MM2 && Date[i].Month >= MM1 && Date[i].Day <= DD2 && Date[i].Day >= DD1){
      if (Date[i].rec.Type == Type)
        if (Date[i].rec.Amount <= Amount2 && Date[i].rec.Amount >= Amount2)
          if (Date[i].rec.Info == Info){
            cout << Date[i].Day << " " << Date[i].Month << " " << Date[i].Year << " ";
            if (Date[i].rec.Type == 2)
              cout << "Income" << " ";
            else 
              cout << "Expense" << " ";
            cout << Date[i].rec.Info << endl;
            Flag = 1;
          }
    }
    if (Flag == 0)
      cout << "Not Found!" << endl;
}

void Report(date *&Date, int count){
  double Annual_Income = 0, Annual_Expense = 0;
  double Income_E = 0, Income_F = 0, Income_P = 0;
  double Expense_T = 0, Expense_F = 0, Expense_L = 0;
  int Year = Date[0].Year;
  for (int i = 0; i < count; i++){
    if (Date[i].Year == Year){
      if (Date[i].rec.Type == 2){
        Annual_Income += Date[i].rec.Amount;
        if (Date[i].rec.Info == "E")
          Income_E += Date[i].rec.Amount;
        else if (Date[i].rec.Info == "F")
          Income_F += Date[i].rec.Amount;
        else
          Income_P += Date[i].rec.Amount;
      }
      if (Date[i].rec.Type == 1){
        Annual_Expense += Date[i].rec.Amount;
        if (Date[i].rec.Info == "T")
          Expense_T += Date[i].rec.Amount;
        else if (Date[i].rec.Info == "F")
          Expense_F += Date[i].rec.Amount;
        else
          Expense_L += Date[i].rec.Amount;
      }
    }
    else{
      cout << Year << " : Annual Income " << Annual_Income << endl;
      cout << Year << " : Annual Expense " << Annual_Expense <<endl;
      cout << Year << " : Annual Balance " << Annual_Income - Annual_Expense <<endl;
      cout << Year << " : Earned Income " << Income_E << Income_E / Annual_Income << endl;
      cout << Year << " : Porfolio Income " << Income_F << Income_F / Annual_Income << endl;
      cout << Year << " : Passive Income " << Income_P << Income_P / Annual_Income << endl;
      cout << Year << " : Transportation Expense " << Expense_T << Expense_T / Annual_Expense << endl;
      cout << Year << " : Food & Drinks " << Expense_F << Expense_F / Annual_Expense << endl;
      cout << Year << " : Living & Others " << Expense_L << Expense_L / Annual_Expense << endl;
      Year = Date[i].Year;
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

void Calculate_Monthly(date * &Date, int count, double &Monthly_Balance, double &Monthly_Income, double &Monthly_Expense){
  int Months = (Date[count - 1].Year - Date[0].Year) * 12 + (Date[count - 1].Month - Date[0].Year) + 1;
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

int main() {
  string Command;
  int count = 0, size = 100;
  date *Date = new date[100];
  double Budget = -1;
  double Monthly_Balance = 0, Monthly_Income = 0, Monthly_Expense = 0;
  while(true) {
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
    if (Command == "D"){ // Delete Records
      if(count == 0){
        cout<<"Warning: No record "<<endl;
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
    //Record_to_File 
    ofstream fout;
    fout.open("Financial_Record.txt");
    if (fout.fail())
      exit(1);
    for (int i = 0; i < count; i++){
      if (Date[i].rec.Type == 0)
        break;
      fout << Date[i].Day << " " << Date[i].Month << " " << Date[i].Year << " ";
      fout << Date[i].rec.Type << " " << Date[i].rec.Amount << " " << Date[i].rec.Info << endl;
    }
    fout.close();
    
    Calculate_Monthly(Date, count, Monthly_Balance, Monthly_Income, Monthly_Expense);
    
    // Functions below will not change records
    if (Command == "P"){ // Present Information
      if(count == 0){
        cout<<"Warning: No record "<<endl;
        continue;
      }
      ifstream in("Financial_Record.txt");
      while(in)
        cout << (char)in.get();
      continue;
    }
    if (Command == "B"){ // Budget Setting
      if(count == 0){
        cout<<"Warning: No record "<<endl;
        continue;
      }
      while(true){
        cout << "Set your monthly budget: " << endl;
        cin >> Budget;
        if (Budget <= Monthly_Income){
          cout << "You can afford it." << endl;
          break;
        }
        else
          cout << "Beyond Your financial capability! Reset your budget!" << endl;
      }
      continue;
    }
    if (Command == "G"){ // Goal Setting
      if(count == 0){
        cout<<"Warning: No record "<<endl;
        continue;
      }
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
        else{
          cout << "That will take you " << Goal / Monthly_Goal << " months to achieve!" << endl;
          break;
        }
      }
      continue;
    }
    if (Command == "S"){ // Search Records
      if(count == 0){
        cout<<"Warning: No record "<<endl;
        continue;
      }
      int DD2_1, DD2_2, MM2_1, MM2_2, YYYY2_1, YYYY2_2, Amount1, Amount2, Search_Type;
      string Search_Type_String, Info;
      cout << "Please enter the dates: DD1 MM1 YYYY1 DD2 MM2 YYYY2: \n(Results between these dates)" << endl;
      cin >> DD2_1 >> MM2_1 >> YYYY2_1 >> DD2_2;
      cout << "Please enter the Type (I for Income, E for Expense): " << endl;
      cin >> Search_Type_String;
      if (Search_Type_String == "I")
        Search_Type = 2;
      else if (Search_Type_String == "E")
        Search_Type = 1;
      cout << "Please enter Amount range (Amount1 Amount2): " << endl;
      cin >> Amount1 >> Amount2;
      if (Search_Type == 2){
        cout << "Please enter the Info (E: Earned Income\tF: Portfolio Income\tP: Passive Income): " << endl;
        cin >> Info;
      }
      else if (Search_Type == 1){
        cout << "Please enter the Info (T: Transportation\tF: Food & Drinks\tL: Living & Others): " << endl;
        cin >> Info;
      }
	    Search(Date, count, DD2_1, MM2_1, YYYY2_1, DD2_2, MM2_2, YYYY2_2, Search_Type, Amount1, Amount2, Info);
      continue;
    }
    if (Command == "R"){
      if(count == 0){
        cout<<"Warning: No record "<<endl;
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
// Split .cpp and create makefile
// Need Mistake-proof
