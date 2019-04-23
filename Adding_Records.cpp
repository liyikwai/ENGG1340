#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct date{
  int Day;
  int Month;
  int Year;
};

struct account{
  date Date;
  double Income;
  string Income_Info;
  double Expense;
  string Expense_Info;
  account();
};

account::account(){
  Income_Info = "NULL";
  Expense_Info = "NULL";
}

void increase_size(account *&user, int &account_size, int n){
  account *temp = new account[account_size+1];
  for (int i = 0; i < account_size; i++){
    temp[i] = user[i];
  }
  delete []user;
  user = temp;
  account_size += n;
}

void Append_Records(char add, account *user, int tail){
  int amount, d, m, y;
  string remark;
  cout << "Please enter the date: Day Motnth Year " << endl;
  cin >> d >> m >> y;
  cout << "Please enter the amount " << endl;
  cin >> amount;
  cout << "Please enter the remark of this record " << endl;
  cin >> remark;
  user[tail].Date.Day = d;
  user[tail].Date.Month = m;
  user[tail].Date.Year = y;
  if (add == 'I'){
    user[tail].Income = amount;
    user[tail].Income_Info = remark;
  }
  if (add == 'E'){
    user[tail].Expense = amount;
    user[tail].Expense_Info = remark;
  }
}

void Create_record(account *user, int tail){
  ofstream fout;
  fout.open("Financial_Record.txt");
  if (fout.fail()){
    exit(1);
  }
  for(int i = 0; i < tail; i++){
    fout << "Date: " << user[i].Date.Day << "/" << user[i].Date.Month << "/" << user[i].Date.Year << endl;
    fout << "    Income: " << user[i].Income << endl;
    fout << "    Income remark: " << user[i].Income_Info << endl;
    fout << "    Expenseense " << user[i].Expense << endl;
    fout << "    Expenseense remark: "<< user[i].Expense_Info << endl;
  }
  fout.close();
}

int main(){
  char add;
  double record;
  int tail = 0;
  int account_size = 10;
  account *user = new account[account_size];
  cout << "----------------------------" << endl;
  cout << "|ENGG1340 Accounting System|" << endl;
  cout << "|          Group73         |" << endl;
  cout << "----------------------------" << endl;
  cout << endl;
  while(1){
    cout << "Please enter: " << endl;
    cout << "I: Adding Income " << endl;
    cout << "E: Adding Expenseense " << endl;
    cout << "Q: Quit " << endl;
    cin >> add;
    if (add == 'Q'){
      break;
    }
    else{
      Append_Records(add, user, tail);
      tail++;
      if (tail == account_size){
        increase_size(user, account_size, 10);
      }
    }
  }
  Create_record(user, tail);
  delete []user;
  return 0;
}
