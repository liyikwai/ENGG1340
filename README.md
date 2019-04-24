# __ENGG1340 Project__
*Group 73: Huang Sheng 3035534103, Li Yik Wai 3035566015*

### **1.Problem Statement**
  In recent years, as information technology rapidly develops, digital tools are widely available in various areas, including the financial sector. Multinational corporations, as well as individual citizens, are in desperate need of digital accounting systems to better facilitate their wealth management. 

  The problem is, even though there have been products managing users' wealth by various means, the available tools are unsatisfactory in personalization to meet some needs that users may have in the daily financial management, such as budget setting according to the users' income status, spending patterns or help users to set their financial goal. 

  This programme acts as an accounting system to help users manage their financial state. By processing the records of income and expense as well as other financial information through this programme, users can have a better understanding and management of their wealth. 
  
### **2.Problem Setting**
  We assume that the maximum number of the user input is less than 100,000,000 to avoid overflow. Besides, Income and expense received should be rounded to two decimals. In addition, the user is expected not to input negative numbers. Furthermore, the information provided by user should be meaningful and valid. For example, the user cannot input invalid dates like 32/02/2019 (32nd February 2019). 
 
  We divide this problem into 7 functionalities. 
  1. _Adding records of income and expense_: This function is to record the user's monthly income and expenses. The data will be stored in two dynamic arrays income[] and expense[]. A file named "Financial_Records.txt" containing the information that the user input will be created.
  
  2. _Offering basic information of the records_: This function is to show detailed information of the records. This will be done by opening and reading the data from "Financial_Records.txt".
  
  3. _Editing and deleting the records_: This function is to let the user edit or delete the records. This action will be done by applying the method of array insertion and deletion. After editing, the array will be sorted by the method of bubble sort.The data in "Financial_Records.txt" will also be updated.
  
  4. _Searching the records_: This function to let user easily search for and review the records which he or she has input into the programme. This searching purpose will be achieved by applying binary search to the two dynamic arrays.
  
  5. _Offering report of users’ financial state_: This function is to calculate different data that could report the user's financial situation. A file named "Financial_Report.txt" with useful financial data.
  
  6. _Setting budget_: This function is to allow the user to create their own budget setting. Whenever the user adding his or her expense, it will calculate the cumulative expense and check whether the expense exceeeds the budget or not.
  
  7. _Setting and estimating user's goal_: This function allows the user to set up his or her goals such as buying a property or other products. After that, it will estimate the time and money they needed to achieve the goals.

### **3.Program Feature**
  Input and output specification
  1. Adding_Records
     - _Input_: Command 'I' or 'E' representing income or expenses, multiple combinations of 3 integer numbers indicating the day, month, year and 2 double denoting the user's income or expenses, a string for account code, a string denoting income source or expense purposes. 
     - _Output_: A sturct dynamic array of the records.
     
  2. Offering_Basic_Information
     - _Input_: Command 'P'. Opening file "Records.txt"
     - _Output_: Print the information and store it to a file containing the amount, date, types of income or expense.
     
  3. Editing_And_Deleting
     - _Input_: For editing the datas, using command 'C'. Input 3 integers representing day, month, year and amount. 1 string representing the type of the correspond income of expense. After that, input the new date, amount and type of this record. For deleting the datas,using command 'D'. Then, input the day, month, year, amount and type of the income of expense to locate the position of the record to be deleted. 
     - _Output_: A new struct dynamic array of the record after editing or deleting.
     
  4. Searching_The_Records
     - _Input_: Command 'S'. 3 integers representing day, month and year. 1 string representing the type of the income or expense. 1 double number representing the amount of the record.
     - _Output_: Search information
     
  5. Offering_Financial_Report
     - _Input_: The struct dynamic array containing information of a series of the reords .
     - _Output_: Multiple lines containg different statistical parameter. Each line have 1integer denoting the year. 1 string representing the type of the record. 1 double number denoting the correspond data. 1 integer representing the percentage of the type of records.
     
  6. Setting_Budget
     - _Input_: Command 'B'. 1 interger representing the monthly budget. 
     - _Output_: If the expense is less than the budget, it will give a signal of safety. Otherwise, it will give a warning. 
     
  7. Setting_And_Estimating_Goals
     - _Input_: Command 'G' represent budget setting, a string representing the user's goal and an double denoting the money they need
     - _Output_: A double denoting the money and a integer representing the days the user still needed. 
