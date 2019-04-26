#include <iostream>
#include <fstream>
#include <iomanip>
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
void Increase_Size(date *&Date, int &size) { // increase the size of dynamic array
  date *temp = new date [size + 10];
  for (int i = 0; i < size; i++)
    temp[i] = Date[i];
  delete[] Date;  // release memory
  Date = temp;
  size += 10;
}

void Append_Income(date *&Date, int count) { // Add a record of income
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

void Append_Expense(date *&Date, int count){ // Add a record of expense
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

void Delete(date *&Date, int &size, int DD, int MM, int YYYY, int Del_Type, int Number, string Info){
  date *Temp = new date [size-1];
  int k = 0;
  size--;
  for (int i = 0; i < size - 1; i++){
    if(Date[i].Day == DD && Date[i].Month == MM && Date[i].Year == YYYY)
      if (Date[i].rec.Type == Del_Type && Date[i].rec.Amount == Number && Date[i].rec.Info == Info)
        k++;  // Jump over the aim
    Temp[i] = Date[k];
    k++;
  }
  delete[] Date;  //release memory
  Date = Temp;
}

void Change(date *&Date, int size, int DD, int MM, int YYYY, int Change_Type, int Number, string Info){ //change from A to B
  int New_DD, New_MM, New_YYYY, New_Type, New_Amount;
  string New_Info, New_Type_String; // B's Info
  cout << "Please enter the date of the record" << endl;
  cout << "DD MM YYYY: " << endl;
  cin >> New_DD >> New_MM >> New_YYYY;
  cout << "Change the record to Income or Expense (input I or E): " << endl;
  cin >> New_Type_String;
  if (New_Type_String == "I"){
    New_Type = 2;
    cout << "Please enter the amount" << endl;
    cout << "Income: " << endl;
    cin >> New_Amount;
    cout << "Please enter the information of the income" << endl;
    cout << "Info: E: Earned Income\tF: Portfolio Income\tP: Passive Income" << endl;
    cin >> New_Info;
  }
  else if (New_Type_String == "E"){
    New_Type = 1;
    cout << "Please enter the amount" << endl;
    cout << "Expense: " << endl;
    cin >> New_Amount;
    cout << "Please enter the information of the expense" << endl;
    cout << "Info: T: Transportation\tF: Food & Drinks\tL: Living & Others" << endl;
    cin >> New_Info;
  }
  int Flag = 0; // to see if there is a match
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
        Flag = 1;
      }
  }
  if (Flag == 0) //there is no match
    cout << "No such records found" << endl;
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

void Search(date *&Date, int count, int DD1, int MM1, int YYYY1, int DD2, int MM2, int YYYY2, int Type, double Amount1, double Amount2, string Info){
  int Flag = 0; //flag if there is a match
  cout << endl << "          Searching Result          " << endl;
  for (int i = 0; i < count; i++)
    if (Date[i].Year <= YYYY2 && Date[i].Year >= YYYY1 && Date[i].Month <= MM2 && Date[i].Month >= MM1 && Date[i].Day <= DD2 && Date[i].Day >= DD1){ //if in the range
      if (Date[i].rec.Type == Type)
        if (Date[i].rec.Amount <= Amount2 && Date[i].rec.Amount >= Amount1)
          if (Date[i].rec.Info == Info){
	          cout <<  "Day " << setw(6) << "Month "  << "Year " <<  " I/E    " << " Type " << "Amount" << endl;
            cout << Date[i].Day << "  " << Date[i].Month << "    " << Date[i].Year << "  ";
            if (Date[i].rec.Type == 2)
              cout << "Income" << "  ";
            else 
              cout << "Expense" << "  ";
            cout << Date[i].rec.Info << endl;
            Flag = 1;
          }
    }
    if (Flag == 0) // not match found
      cout << "Not Found!" << endl;
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
        double P_Earned=Income_E * 100 / Annual_Income , P_Porfolio = Income_F * 100 / Annual_Income, P_Passive = Income_P * 100 / Annual_Income;
          double P_Transportataion = Expense_T * 100 / Annual_Expense, P_Food = Expense_F * 100 / Annual_Expense, P_Living = Expense_L * 100 / Annual_Expense; 
          if (Annual_Income == 0){
            P_Earned = 0; 
            P_Passive = 0; 
            P_Passive = 0;
          }
          if (Annual_Expense == 0){
            P_Transportataion = 0; 
            P_Food = 0; 
            P_Living = 0;
          }
    if (Date[i].Year != Year || i == count - 1) { // if year changes or reaches the last one
      cout<<endl;
      cout<<left; 
      cout << Year << setw(28) << " : Average Monthly Income " << setw(5) << Annual_Income << "  \\ " << endl;
      cout << Year << setw(28) << " : Average Monthly Expense " << setw(5) << Annual_Expense << "  \\ " << endl;
      cout << Year << setw(28) << " : Net Income " << setw(5) << Annual_Income - Annual_Expense << "  \\ " << endl;
      cout << Year << setw(28) << " : Earned Income " << setw(5) << Income_E << "  " << P_Earned << "%" << endl;
      cout << Year << setw(28) << " : Porfolio Income " << setw(5) << Income_F << "  " <<  P_Passive << "%" << endl;
      cout << Year << setw(28) << " : Passive Income " << setw(5) << Income_P << "  " << P_Passive << "%" << endl;
      cout << Year << setw(28) << " : Transportation Expense " << setw(5) << Expense_T << "  " << P_Transportataion << "%" << endl;
      cout << Year << setw(28) << " : Food & Drinks " << setw(5) << Expense_F << "  " << P_Food << "%" << endl;
      cout << Year << setw(28) << " : Living & Others " << setw(5) << Expense_L << "  " << P_Living << "%" << endl;
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

void Reading_record(){
  ifstream in("Financial_Record.txt");
  for(string str; getline(in, str);) // line by line
    cout << str << endl;
  cout << ""; // prevent weird characters at EOF
  cout << "(Financial_Record.txt has been created successfully) " << endl;
}

void setting_goal( int Monthly_Balance ){
  double Goal, Monthly_Goal;
  cout << "What's your goal?" << endl;
  cin >> Goal;
  cout << "That will take you at least " << Goal / Monthly_Balance << " months." << endl; // spending all budget left
  cout << "How much per month do you want to save to achieve your goal?" << endl;
  while(true){
    cin >> Monthly_Goal;
    if(Monthly_Goal > Monthly_Balance){
      cout << "That's beyond your financial capability!" << endl;
      break;
    }
    else{
      cout << "That will take you " << Goal / Monthly_Goal << " months to achieve!" << endl;
      break;
    }
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
    cout << endl;
    cout << "----------------------------" << endl;
    cout << "|ENGG1340 Accounting System|" << endl;
    cout << "|          Group73         |" << endl;
    cout << "----------------------------" << endl;
    cout << endl;
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
    total_income = 0;
    total_expense = 0;
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
      while(true){
        cout << "Please enter your monthly budget: " << endl;
        cin >> Budget;
        if (Budget <= Monthly_Income){
          cout << "You can afford it." << endl;
          break;
        }
        else{
          cout << "Beyond Your financial capability! Please reset your budget!" << endl;
          break;
        }
      }
      continue;
    }
    if (Command == "G"){ // Goal Setting, representing your planned expense outside of budget
      if (Monthly_Balance < 0) {
        cout << "You are bleeding money. Please change your spending habit first!" << endl;
        continue;
      }
            setting_goal( Monthly_Balance );
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
}
// Split .cpp and create makefile
