#include <iostream>
#include <string>
#include "Definition.h"
using namespace std;

bool operator<(const record &a, const record &b)
{
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
bool operator<(const date &a, const date &b)
{
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
