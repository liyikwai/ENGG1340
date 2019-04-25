Target = account
Object = add.o offer.o edit.o search.o report.o budget.o goal.o

$(Target): $(Object)
  g++ $(Object) -o $(Target)

add.o: Adding_Record.cpp
  g++ -c Adding_Record.cpp

offer.o: Offering_Basic_Information.cpp
  g++ -c Offering_Basic_Information.cpp

edit.o: Editing_And_Deleting.cpp
  g++ -c Editing_And_Deleting.cpp

search.o: Searching_The_Records.cpp
  g++ -c Searching_The_Records.cpp

report.o: Offering_Financial_Report.cpp
  g++ -c Offering_Financial_Report.cpp

budget.o: Setting_Budget.cpp
  g++ -c Setting_Budget.cpp

goal.o: Setting_And_Estimation.cpp
  g++ -c Setting_And_Estimation.cpp


