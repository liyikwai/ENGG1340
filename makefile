add.o:
  g++ -c Adding_Record.cpp

offer.o:
  g++ -c Offering_Basic_Information.cpp

edit.o:
  g++ -c Editing_And_Deleting.cpp

search.o:
  g++ -c Searching_The_Records.cpp

report.o:
  g++ -c Offering_Financial_Report.cpp

budget.o:
  g++ -c Setting_Budget.cpp

goal.o:
  g++ -c Setting_And_Estimation.cpp

Target = account
Object = add.o offer.o edit.o search.o report.o budget.o goal.o

$(Target): $(Object)
  g++ $(Object) -o $(Target)
