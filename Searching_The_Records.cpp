#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Searching_The_Records.h"
using namespace std;

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
