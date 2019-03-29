# __ENGG1340 Project__
*Group 73: Huang Sheng 3035534103, Li Yik Wai 3035566015*

### **1.Problem Statement**
  In recent years, as information technology rapidly develops, digital tools are widely available in various areas, including the financial sector. Multinational corporations, as well as individual citizens, are in desperate need of digital accounting systems to better facilitate their wealth management. 

  The problem is, even though there have been products managing users' wealth by various means, the available tools are unsatisfactory in personalization to meet some needs that users may have in the daily financial management, such as budget setting according to the users' income status, spending patterns or help users to set their financial goal. 

  This programme acts as an accounting system to help users manage their financial state. By processing the records of income and expense as well as other financial information through this programme, users can have a better understanding and management of their wealth. 
  
### **2.Problem Setting**
  We assume that the maximum number that the user input is less than 100000000 to avoid overflow. Besides, Income and expense received should be rounded to two decimals. In addition, the user is expected not to input negative numbers. Furthermore, the information provided by user should be meaningful and valid. For example, the user cannot input invalid dates like 32/2/2019 (32th February 2019). 
 
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
     - _Output_: Confirmation with the user on his/her input.A file named "Financial_Record.txt". 2 dynamic array income[] and expense[].
     
  2. Offering_Basic_Information
     - _Input_: Command 'INFO'. Opening file "Financial_Records.txt"
     - _Output_: A detailed list of information containing the amount, date, types of income or expense and etc.
     
  3. Editing_And_Deleting
     - _Input_: Open the file "Financial_Records.txt". After that, input the letter 'e' or 'd', representing edit or delete correspondingly. For 'e', input multiple combinations of 3 integer numbers indicating the day, month, year and 2 double denoting the user's income or expenses. For 'd', input 2 integers representing time and income/expense whose records need deleting
     - _Output_: Confirmation informing the user the success or failure of his command
     
  4. Searching_The_Records
     - _Input_: Command 'Search', and command 'D', 'T' or 'A', representing date, time or account code, income source or expense purposes, and then input the corresponding keywords.
     - _Output_: Search information
     
  5. Offering_Financial_Report
     - _Input_: Multiple integers income and expense in that month as well as their basic information will be received.
     - _Output_: A file named "Financial_Report.txt" containing integers denoting monthly income, expense, net income and percentage of different types of expenses.
     
  6. Setting_Budget
     - _Input_: At the beginning of each month, this function receives an integer representing the estimated expense of this month. 
     - _Output_: If the expense is less than the budget, it will give a signal of safety. Otherwise, it will give a warning. 
     
  7. Setting_And_Estimating_Goals
     - _Input_: Command 'SET' represent budget setting, a string representing the user's goal and an double denoting the money they need
     - _Output_: A double denoting the money and a integer representing the days the user still needed. 
