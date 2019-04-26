#include <iostream>
#include <string>
#include "Sort.h"
#include "Definition.h"
using namespace std;
void Sort(date *&Date, int count)
{
  int Actual_Count = count;
  for (int i = 0; i < count; i++)
  {
    if (Date[i].rec.Type == 0)
    {
      Actual_Count = i + 1;
      break;
    }
  } // see how many entries there are
  for (int i = 0; i < Actual_Count - 1; i++)
    for (int j = i + 1; j < Actual_Count; j++)
      if (Date[i] < Date[j])
      {
        date *Temp = new date; //dynamic memory
        *Temp = Date[i];
        Date[i] = Date[j];
        Date[j] = *Temp;
        delete Temp; //release memory
      }
}
