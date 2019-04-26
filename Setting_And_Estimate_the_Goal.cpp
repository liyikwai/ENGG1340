#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Setting_And_Estimate_the_Goal.h"
using namespace std;
      
void Setting_goal( int Monthly_Balance ){
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