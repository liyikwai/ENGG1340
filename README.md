# __ENGG1340__
*Huang Sheng 3035534103, Li Yik Wai 3035566015*

### **1.Problem Statement**
  In recent years, as information technology rapidly develops, digital tools are widely available in various areas, including the financial sector. Multinational corporations, as well as individual citizens, are in desperate need of digital accounting systems to better facilitate their wealth management. 

  The problem is, even though there have been products managing users' wealth by various means, the available tools are unsatisfactory in personalization to meet some needs that users may have in the daily financial management, such as budget setting according to the users' income status, spending patterns or help users to set their financial goal. 

  This programme acts as an accounting system to help users manage their financial state. By processing the records of income and expense as well as other financial information through this programme, users can have a better understanding and management of their wealth. 
  
### **2.Problem Setting**
  We assume that the maximum number that the user input is less than 100000000 to avoid overflow. Besides, Income and expense received should be rounded to two decimals. In addition, the user is expected not to input negative number. Furthermore, the information provided by user should be meaningful and valid. For example, the user cannot input invalid dates like 32/2/2019 (32th Feburary 2019). 
 
  We divide this problem into 7 functionalities. 
  1. _Adding records of income and expense_: This function to record the user's monthly income and expenses.
  2. _Offering basic information of the records_: This function to provide detailed information of the records.
  3. _Editing and deleting the records_: This function to let user edit or delete the records. 
  4. _Searching the records_: This function to let user easily search for and review the records which s/he has input into the programme.
  5. _Offering report of users’ financial state_: This function is to calculate different data that could report the user's financial situation.
  6. _Setting budget_: This function is to allow user to create their own budget setting.
  7. _Setting and estimating user's goal_: This function allows user to set up his or her goals such as buying a property or other products. After that, it will estimate the time and money they needed to achieve the goals.

### **3.Program Feature**
  Input and output specification
  1. Adding_Records
     - _Input_: command 'I' or 'E' representing income or expenses, multiple combinations of 3 integer numbers indicating the day, month, year and 2 double denoting the user's income or expenses, a string for account code, a string denoting income source or expense purposes. The above information will be stored in two dynamic arrays income[] and expense[].
     - _Output_: Confirmation with the user on his/her input.A file named "Financial_Record.txt" containing the information that the user input.
     
  2. Offering_basic_information
     - _Input_: command 'INFO'
     - _Output_: a detailed list of information containing the amount, date, types of income or expense and etc.
     
  3. Editing_and_deleting
     - _Input_: First input the letter 'e' or 'd', representing edit or delete correspondingly. For 'e', input multiple combinations of 3 integer numbers indicating the day, month, year and 2 double denoting the user's income or expenses. For 'd', input 2 integers representing time and income/expense whose records need deleting
     - _Output_: confirmation informing the user the success or failure of his command
     
  4. Searching_the_records
     - _Input_: command 'Search', and command 'D', 'T' or 'A', representing date, time or account code, income source or expense purposes, and then input the corresponding keywords.
     - _Output_: search information
     
  5. Offering_financial_report
     - _Input_: Multiple integers income and expense of a month as well as their basic information will be received.
     - _Output_: A file named "Financial_Report.txt" containing integers denoting monthly income, expense, net income and percentage of different types of expenses.  
     
  6. Setting_budget
     - _Input_: At the beginning of each month, this function receives a integer that represent the estimated expense of this month. Afterward, whenever the user adding his or her expense, it will calculate the cumulative expense and check whether the expense exceeeds the budget or not.
     - _Output_: If the expense is less than the budget, it will give a signal of safety. Otherwise, it will give a warning. 
     
  7. Setting_and_estimating_goals
     - _Input_: command 'SET' represent budget setting, a string representing the user's goal and a integer denoting the money they need
     - _Output_: This function will calculate and output two integers denoting the money and time the user still needed respectively. 
