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
      
  2. Offering_Basic_Information
 
  3. Editing_And_Deleting
    
  4. Searching_The_Records
 
  5. Offering_Financial_Report
  6. Setting_Budget
 
  7. Setting_And_Estimating_Goals
### **4. Compliation**
To compile
```
$ make Main
```
To run
```
$ ./Main
```
To clean
```
$ make clean
```
### **5. Execution Instruction**
List of Navigation
```
Please enter the following commands:
I: Adding Income
E: Adding Expense
P: Present Information and Save it to a file
C: Change Records
D: Delete Records
S: Search Records
R: Report
B: Budget Setting
G: Goal Setting
Q: Quit
```
#### 1. Adding Income 
```
I: Adding Income
```
  _Input_: _Input_: Command 'I' represents adding income
```
Please enter the date
DD MM YYYY: 
Please enter the amount
Income: 
Please enter the information of the income
Info: 
E: Earned Income	F: Portfolio Income	P: Passive Income
```
  _Input_: 3 integer numbers indicating the day, month, year, a double numbers denoting the user's income or expenses,  a string denoting income source or expense purposes.
  _Output_: A sturct dynamic array of the records. The record will be saved to a file named "Records.txt".
  
#### 2. Adding Expense
```
E: Adding Expense
```
 _Input_: _Input_: Command 'E' represents adding expenses. 
 
 ```
DD MM YYYY: 
Please enter the amount
Expense: 
Please enter the information of the expense
Info: 
T: Transportation	F: Food & Drinks	L: Living & Others
```
   _Input_: 3 integer numbers indicating the day, month, year, a double numbers denoting the user's income or expenses,  a string denoting income source or expense purposes.
  _Output_: A sturct dynamic array of the records. The record will be saved to a file named "Records.txt".
  
  
#### 3. Present Information and Save it to a file
```
P: Present Information and Save it to a file
```
   _Input_: Command 'P' represents show the information of the records
  
```
          Financial Record           
Day Month Year  I/E     Type Amount
25  12    2018  Expense L    10000
15  12    2018  Expense L    1000 
10  12    2018  Expense T    500  
2   12    2018  Income  E    7000 
(Income  E: Earned Income;  F: Portfolio Income; P: Passive Income 
 Expense T: Transportation; F: Food & Drinks     L: Living & Others)
Total income: 7000
Total expense: 11500
Net asset: -4500
(Financial_Record.txt has been created successfully) 
``` 
   _Output_: The detail of the records
   
#### 4. Change Records
```
C: Change Records
```
 _Input_: Command 'C' represents changing records
```
 Please enter the information of the record to be changed 
Change Income or Expense? I: Income E: Expense 
DD MM YYYY: 
Amount: 
Info: E: Earned Income	F: Portfolio Income	P: Passive Income
Please enter the date of the record
DD MM YYYY: 
Change the record to Income or Expense (input I or E): 
Please enter the amount
Income: 
Please enter the information of the income
Info: E: Earned Income	F: Portfolio Income	P: Passive Income
```
  _Input_: For changing the data, input 3 integers representing day, month, year and amount. A string representing the type of the correspond income of expense. After that, input the new date, amount and type of this record.
  _Output_: A changed sturct dynamic array of the records.
  
#### 5. Delete Records
```
D: Delete Records
```
 _Input_: For deleting the datas,enter command 'D'. Then, input the day, month, year, amount and type of the income of expense to locate the position of the record to be deleted. 
 _Output_: A new struct dynamic array of the record after deleting.
 
#### 6. Search Records
```
S: Search Records
```
 _Input_: Command 'S' represents search the records
 
```
Please enter the range of searching dates (Results between these dates): 
(DD1 MM1 YYYY1 DD2 MM2 YYYY2): 
Please enter the Type 
(I for Income, E for Expense): 
Please enter range of searching amount 
(Amount1 Amount2): 
Please enter the searching info 
(T: Transportation	F: Food & Drinks	L: Living & Others): 

```
 
 ```
          Searching Result          
Day Month Year  I/E     Type Amount
25  12    2018  Expense  L
15  12    2018  Expense  L
```
 _Input_: 2 combinations of 3 integers representing day, month and year to specify the range of searching date. A string representing the type of the income or expense. 2 double number representing the range of the searching amount.
 _Output_: Searching information according to the range set from user's inputs
 
 
#### 7. Report Records
```
R: Report
```
 _Input_: Command 'R' represents reporting records
 
  ```
Year : Statistical Data         Amount Percentage 
2018 : Average Monthly Income   7000   \ 
2018 : Average Monthly Expense  11500  \ 
2018 : Net Income               -4500  \ 
2018 : Earned Income            7000   100%
2018 : Porfolio Income          0      0%
2018 : Passive Income           0      0%
2018 : Transportation Expense   500    4.34783%
2018 : Food & Drinks            0      0%
2018 : Living & Others          11000  95.6522%
```
  _Input_: A struct dynamic array containing information of a series of the reords .
  _Output_: Multiple lines containg different statistical parameter. Each line have 1integer denoting the year. 1 string representing the type of the record. 1 double number denoting the correspond data. 1 integer representing the percentage of the type of records.
 
 
#### 8. Budget Setting
```
B: Budget Setting
```
 _Input_: Command 'B' represents setting the budget.
 
```
Please enter your monthly budget: 
```
```
Beyond Your financial capability! Please reset your budget! 
```
```
You can afford it. 
```
 _Output_: Set a monthly budget, and see if your current average monthly income can support this budget. If yes, you are told so. If not, you are advised to change your budget.
 
 
#### 9. Goal Setting
```
G: Goal Setting
```
 _Input_: Command 'G' represents setting the goal
 
 ```
You are bleeding money. Please change your spending habit first!
```
 
_Input_: An double number denoting the money they need
_Output_: If the user cannot reach the goal, a warning signal will be given. Otherwise, a double number denoting integer representing the days the user still needed. 

#### 10. Quit
```
Q: Quit
```
 _Input_: Command 'Q' represents terminate the programmme.

### **6.Problems and possible further improvements**
Throughout our testing, we have found the program easily dive into unexpected error and unwanted loop. We have not included enough checks on our user input, and just asssumed they will keep their input right.

However, that is not true given our testing experience. Using a program without a UI is extremely easy to make mistakes. Our program still needs an efficient mechanisms to deal with them.
In addition, the program is not smart enough. We still need all infomation the user could provide to locate a record, which could be avoided by better managing and monitering our data.
Furthermore, lacking professional knowledge in the financial field has led us develop a tool that might not cater to the needs of a more professional user. We still need more understanding of finance and gain knowledge to develop a more powerful tool.
