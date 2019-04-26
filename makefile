Target = Account
Object1 = Main.cpp Adding_Record.o Offering_Basic_Information.o Editing_And_Deleting.o Searching_The_Records.o Offering_Financial_Report.o Setting_Budget.o Setting_And_Estimate_the_Goal.o
Object2 = Adding_Record.h Offering_Basic_Information.h Editing_And_Deleting.h Searching_The_Records.h Offering_Financial_Report.h Setting_Budget.h Setting_And_Estimate_the_Goal.h


$(Target): $(Object1)
	g++ $(Object1) -o $(Target)

Add_Record.o: Adding_Record.cpp
	g++ -c Adding_Record.cpp

Offer_Basic_Information.o:  Adding_Record.h Offering_Basic_Information.cpp
	g++ -c Offering_Basic_Information.cpp

Edit_And_Deleting.o: Adding_Record.h Editing_And_Deleting.cpp
	g++ -c Editing_And_Deleting.cpp

Search_The_Records.o:  Searching_The_Records.cpp
	g++ -c Searching_The_Records.cpp

Offering_Financial_Report.o:  Offering_Financial_Report.cpp
	g++ -c Offering_Financial_Report.cpp

Setting_Budget.o:  Setting_Budget.cpp
	g++ -c Setting_Budget.cpp

Setting_And_Estimate_the_Goal.o:  Setting_And_Estimate_the_Goal.cpp
	g++ -c Setting_And_Estimate_the_Goal.cpp

clean:
	rm *.o main
