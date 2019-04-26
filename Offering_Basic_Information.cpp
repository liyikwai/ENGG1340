#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Offering_Basic_Information.h"
using namespace std;

void Reading_record(){
  ifstream in("Financial_Record.txt");
  for(string str; getline(in, str);) // line by line
    cout << str << endl;
  cout << ""; // prevent weird characters at EOF
  cout << "(Financial_Record.txt has been created successfully) " << endl;
}