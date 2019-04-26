#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Setting_Budget.h"
using namespace std;

void Setting_budget ( int Monthly_Income, double Budget){
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
}