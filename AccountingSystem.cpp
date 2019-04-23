#include <iostream>
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
  cin >> Info;
  Date[count].rec.Amount = Expense;
  Date[count].rec.Type = 1;
  Date[count].rec.Info = Info;
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

int main() {
  string Command;
  int count = 0, size = 100;
  date *Date = new date[100];
  while(true) {
    cout << "Please enter the following commands:" << endl;
    cout << "I: Adding income" << endl; // Done
    cout << "E: Adding Expense" << endl; // Done
    cout << "S: Showing Information" << endl; // Done
    cout << "C: Change Records" << endl;
    cout << "D: Delete Records" << endl;
    cout << "S: Search Records" << endl;
    cout << "R: Report" << endl;
    cout << "B: Budget Setting" << endl;
    cout << "G: Goal Setting" << endl;
    cout << "Q: Quit" << endl;
    cin >> Command;
    if (Command == "Q")
      break;
    if (Command == "I") {
      if (count == size)
        Increase_Size(Date, size);
      Append_Income(Date, count);
      count++;
      continue;
    }
    else if (Command == "E"){
      if (count == size)
        Increase_Size(Date, size);
      Append_Expense(Date, count);
      count++;
      continue;
    }
    //C, D
    Sort(Date, count);
    if (Command == "S"){
      for (int i = 0; i < count; i++){
        if (Date[i].rec.Type == 0)
          break;
        cout << Date[i].Day << " " << Date[i].Month << " " << Date[i].Year << " ";
        if (Date[i].rec.Type == 2)
          cout << "Income" << " ";
        if (Date[i].rec.Type == 1)
          cout << "Expense" << " ";
        cout << Date[i].rec.Amount << " " << Date[i].rec.Info << endl;
      }
      continue;
    }
    // S, R, B, G
    
  }
  delete[] Date;
  return 0;
}
