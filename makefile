Target = Account
Object = Main.cpp Add.o Offer.o Edit.o Search.o Report.o Budget.o Goal.o

$(Target): $(Object)
  g++ $(Object) -o $(Target)

Add_Record.o: Adding_Record.h Adding_Record.cpp
  g++ -c Adding_Record.cpp

Offer_Basic_Information.o: Offering_Basic_Information.h Offering_Basic_Information.cpp
  g++ -c Offering_Basic_Information.cpp

Edit_And_Deleting.o: Editing_And_Deleting.h Editing_And_Deleting.cpp
  g++ -c Editing_And_Deleting.cpp

Search_The_Records.o: Searching_The_Records.h Searching_The_Records.cpp
  g++ -c Searching_The_Records.cpp

Offering_Financial_Report.o: Offering_Financial_Report.h Offering_Financial_Report.cpp
  g++ -c Offering_Financial_Report.cpp

Setting_Budget.o: Setting_Budget.h Setting_Budget.cpp
  g++ -c Setting_Budget.cpp

Setting_And_Estimate_the_Goal.o: Setting_And_Estimate_the_Goal.h Setting_And_Estimate_the_Goal.cpp
  g++ -c Setting_And_Estimate_the_Goal.cpp

clean:
  rm *.o main
