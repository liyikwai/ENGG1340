#include <string>
#ifndef DEFINITION_H
#define DEFINITION_H
struct record
{
  int Type; // Income or Expense, 2 for Income, 1 for Expense
  int Amount;
  std::string Info;
};
struct date
{
  int Day;
  int Month;
  int Year;
  record rec;
};
bool operator<(const record &a, const record &b);
bool operator<(const date &a, const date &b);
#endif
