# __ENGG1340 Project__
*Group 73: Huang Sheng 3035534103, Li Yik Wai 3035566015*

### **1. Problem Statement**
  In recent years, as information technology rapidly develops, digital tools are widely available in various areas, including the financial sector. Multinational corporations, as well as individual citizens, are in desperate need of digital accounting systems to better facilitate their wealth management. 

  The problem is, even though there have been products managing users' wealth by various means, the available tools are unsatisfactory in personalization to meet some needs that users may have in the daily financial management, such as budget setting according to the users' income status, spending patterns or help users to set their financial goal. 

  This programme acts as an accounting system to help users manage their financial state. By processing the records of income and expense as well as other financial information through this programme, users can have a better understanding and management of their wealth. 
  
### **2. Problem Setting**
  We assume that the maximum number of the user input is less than 100,000,000 to avoid overflow. Besides, Income and expense received should be rounded to two decimals. In addition, the user is expected not to input negative numbers. Furthermore, the information provided by user should be meaningful and valid. For example, the user cannot input invalid dates like 32/02/2019 (32nd February 2019). 
 
  We divide this problem into 7 functionalities. 
  1. _Adding Record_: This function is to record the user's monthly income and expenses. The data will be stored in two dynamic arrays income[] and expense[]. A file named "Financial_Records.txt" containing the information that the user input will be created.
 
  2. _Offering Basic Information_: This function is to show detailed information of the records. This will be done by opening and reading the data from "Financial_Records.txt".
  
  3. _Editing and Deleting_: This function is to let the user edit or delete the records. This action will be done by applying the method of array insertion and deletion. After editing, the array will be sorted by the method of bubble sort.The data in "Financial_Records.txt" will also be updated.
  
  4. _Searching the Records_: This function to let user easily search for and review the records which he or she has input into the programme. This searching purpose will be achieved by applying linear search to the dynamic struct array.
  
  5. _Offering Financial Report_: This function is to calculate different parameter that could report the user's financial situation. 
  
  6. _Setting Budget_: This function is to allow the user to create their own budget setting. Whenever the user adding his or her expense, it will calculate the cumulative expense and check whether the expense exceeeds the budget or not.
  
  7. _Setting and Estimating the Goal_: This function allows the user to set up his or her goals such as buying a property or other products. After that, it will estimate whether the user are capable to achieve the goal. If they are able to do so, it will calculate the time they needed.

### **3. Program Feature**
  Input and output specification
  
  Users are strongly advised to see the information below and follow the instructions on input during use.
  1. Adding_Records
     - _Input_: Command 'I' or 'E' represents adding income or expenses, 3 integer numbers indicating the day, month, year, a double numbers denoting the user's income or expenses,  a string denoting income source or expense purposes. 
     - _Output_: A sturct dynamic array of the records. The record will be saved to a file named "Records.txt".
      
  2. Offering_Basic_Information
     - _Input_: Command 'P'. Opening file "Records.txt"
     - _Output_: Print the information include the date, types of income or expense and amount to the screen.
     
  3. Editing_And_Deleting
     - _Input_: For editing the datas, enter command 'C'. Input 3 integers representing day, month, year and amount. A string representing the type of the correspond income of expense. After that, input the new date, amount and type of this record. For deleting the datas,enter command 'D'. Then, input the day, month, year, amount and type of the income of expense to locate the position of the record to be deleted. 
     - _Output_: A new struct dynamic array of the record after editing or deleting.
     
  4. Searching_The_Records
     - _Input_: Command 'S'. 2 combinations of 3 integers representing day, month and year to specify the range of searching date. A string representing the type of the income or expense. 2 double number representing the range of the searching amount.
     - _Output_: Searching information according to the range set from user's inputs
     
  5. Offering_Financial_Report
     - _Input_: A struct dynamic array containing information of a series of the reords .
     - _Output_: Multiple lines containg different statistical parameter. Each line have 1integer denoting the year. 1 string representing the type of the record. 1 double number denoting the correspond data. 1 integer representing the percentage of the type of records.
     
  6. Setting_Budget
     - _Input_: Command 'B'. A interger representing the monthly budget. 
     - _Output_: Set a monthly budget, and see if your current average monthly income can support this budget. If yes, you are told so. If not, you are advised to change your budget.
     
  7. Setting_And_Estimating_Goals
     - _Input_: Command 'G' represent budget setting, a string representing the user's goal and an double number denoting the money they need
     - _Output_: If the user cannot reach the goal, a warning signal will be given. Otherwise, a double number denoting integer representing the days the user still needed. 

### **4. Compliation**

To compile

__$ make__

To run

__$ ./Main__

To clean

__$ make clean__
