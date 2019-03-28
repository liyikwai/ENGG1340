# __ENGG1340__
*Huang Sheng 3035534103, Li Yik Wai 3035566015*

### **1.Problem Statement**
  In recent years, as information technology rapidly develops, digital tools are widely available in various areas, including the financial sector. Multinational corporations, as well as individual citizens, are in desperate need of digital accounting systems to better facilitate their wealth management. 

  The problem is, even though there have been products managing users' wealth by various means, the available tools are unsatisfactory in personalization to meet some needs that users may have in the daily financial management, such as budget setting according to the users' income status, spending patterns or help users to set their financial goal. 

  This programme acts as an accounting system to help users manage their financial state. By processing the records of income and expense as well as other financial information through this programme, users can have a better understanding and management of their wealth. 
  
### **2.Problem Setting**
  We assume that the maximum number that the user input is less than 100000000 to avoid overflow. Besides, Income and expense received should be rounded to two decimals. In addition, the user is expected not to input negative number. Furthermore, the information provided by user should be meaningful and valid. For example, the user cannot input invalid dates like 32/2/2019 (32th Feburary 2019). 
  We divide this problem into 7 functionalities. 1)
  
  The following are some proposed function details.

### **3.Program Feature**
  Functionalities
  1. Adding records of income and expense
     - Feature: recording the user's monthly income and expenses
     - Input: command 'I' or 'E' representing income or expenses, multiple combinations of 3 integer numbers indicating the day, month, year and 2 double denoting the user's income or expenses, a string for account code, a string denoting income source or expense purposes. The above information will be stored in two dynamic arrays income[] and expense[].
     - Output: Confirmation with the user on his/her input.A file named "Financial_Record.txt" containing the information that the user input.
     
  2. Offering basic information of the records
     - Feature: providing detailed information of the records
     - Input: command 'Info'
     - Output: a detailed list of information containing the amount, date, types of income or expense and etc.
     
  3. Editing and deleting the records 
     - Feature: Letting user edit or delete the records.
     - Input: First input the letter 'e' or 'd', representing edit or delete correspondingly. For 'e', input multiple combinations of 3 integer numbers indicating the day, month, year and 2 double denoting the user's income or expenses. For 'd', input 2 integers representing time and income/expense whose records need deleting
     - Output: confirmation informing the user the success or failure of his command
     
  4. Searching the records
     - Feature: Letting the user easily search for and review the records which s/he has input into the programme
     - Input: command 'Search', and command 'D', 'T' or 'A', representing date, time or account code, income source or expense purposes, and then input the corresponding keywords.
     
     - Output: search information
  5. Offering report of users’ financial state
     - Feature: This function is to calculate different data that could report the user's financial situation.
     - Input: Multiple integers income and expense of a month as well as their basic information will be received.
     - Output: A file named "Financial_Report.txt" containing integers denoting monthly income, expense, net income and percentage of different types of expenses.  
     
  6. Setting budget
     - Feature: This function is to allow user to create their own budget setting.
     - Input: At the beginning of each month, this function receives a integer that represent the estimated expense of this month. Afterward, whenever the user adding his or her expense, it will calculate the cumulative expense and check whether the expense exceeeds the budget or not.
     - Output: If the expense is less than the budget, it will give a signal of safety. Otherwise, it will give a warning. 
     
  7. Setting and estimating user's goal
     - Feature: This function allows user to set up his or her goals such as buying a property or other products. After that, it will estimate the time and money they needed to achieve the goals.
     - Input: command 'Set' represent budget setting, a string representing the user's goal and a integer denoting the money they need
     - Output: This function will calculate and output two integers denoting the money and time the user still needed respectively. 
