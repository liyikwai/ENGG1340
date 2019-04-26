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


void Increase_Size(date *&Date, int &size);
void Append_Income(date *&Date, int count);
void Append_Expense(date *&Date, int count);