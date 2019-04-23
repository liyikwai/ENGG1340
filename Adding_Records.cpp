#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct account{
	int day;
	int month;
	int year;
	double inc;
	string inc_info;
	double exp;
	string exp_info;
	account();
};

account::account(){
	inc_info="NULL";
	exp_info="NULL";
}

void increase_size(account *&user, int &account_size, int n){
	account *temp = new account[account_size+1];
	for (int i=0; i<account_size; i++){
		temp[i] = user[i];
	}
	delete []user;
	user = temp;
	account_size += n;
}

void Append_Records(char add, account *user, int tail){
	int amount, d, m, y;
	string remark;
	cout<<"Please enter the date: Day Motnth Year "<<endl;
	cin>>d>>m>>y;
	cout<<"Please enter the amount "<<endl;
	cin>>amount;
	cout<<"Please enter the remark of this record "<<endl;
	cin>>remark;
	user[tail].day=d;
	user[tail].month=m;
	user[tail].year=y;
	if (add=='I'){
		user[tail].inc=amount;
		user[tail].inc_info=remark;
	}
	if (add=='E'){
		user[tail].exp=amount;
		user[tail].exp_info=remark;
	}
}

void Create_record(account *user, int tail){
	ofstream fout;
	fout.open("Financial_Record.txt");
	if (fout.fail()){
		exit(1);
	}
	for(int i=0; i<tail; i++){
		fout<<"Date: "<<user[i].day<<"/"<<user[i].month<<"/"<<user[i].year<<endl;
		fout<<"    Income: "<<user[i].inc<<endl;
		fout<<"    Income remark: "<<user[i].inc_info<<endl;
		fout<<"    Expense "<<user[i].exp<<endl;
		fout<<"    Expense remark: "<<user[i].exp_info<<endl;
	}
	fout.close();
}

int main(){
	char add;
	double record;
	int tail = 0;
	int account_size = 10;
	account *user = new account[account_size];
	cout<<"----------------------------"<<endl;
	cout<<"|ENGG1340 Accounting System|"<<endl;
	cout<<"|          Group73         |"<<endl;
	cout<<"----------------------------"<<endl;
	cout<<endl;
	while(1){
		cout<<"Please enter: "<<endl;
		cout<<"I: Adding Income "<<endl;
		cout<<"E: Adding Expense "<<endl;
		cout<<"Q: Quit "<<endl;
		cin>>add;
		if (add == 'Q'){
			break;
		}
		else{
			Append_Records(add,user,tail);
			tail++;
			if (tail==account_size){
				increase_size(user, account_size, 10);
			}
		}
	}
	Create_record(user,tail);
	delete []user;
}
