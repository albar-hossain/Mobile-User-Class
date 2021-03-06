//TASK 2
#include <iostream>
using namespace std;

class Mobile
{
private:
	string MobileOwner{ "None" };
	string MobileNumber{ "Not set" };
	float Balance{ 50 };
	string OsName{ "Linux" };
	bool LockStatus{ false };
public:
	void setMobileOwner() {
		string name;
		cout << "Enter Owner Name :";
		cin >> name;
		MobileOwner = name;
		cout << "Mobile Owner is set to " << MobileOwner << " using setter method." << endl;
	}
	string getMobileNumber() {
		cout << "Enter Mobile Number :";
		cin >> MobileNumber;
		return MobileNumber;
		cout << "Mobile Number set to " << MobileNumber << " using getter method." << endl;
	}
	float getBalance() {
		cout << "Enter Amount To Add To Balance :";
		cin >> Balance;
		return Balance;
		cout << "Account Balance set to " << Balance << " using getter method." << endl;
	}
	string setOsName() {
		string type;
		cout << "Enter OS Type :";
		cin >> type;
		OsName = type;
		return OsName;
		cout << "OS is set to " << OsName << " using setter method." << endl;
	}
	bool GetLockStatus() {
		char lock{};
		cout << "Is your phone locked? Enter 'Y' or 'N' :";
		cin >> lock;
		if (lock == 'Y' || lock == 'y')
		{
			LockStatus = true;
			cout << "Phone is now locked." << endl;
			return LockStatus;
		}
		else if (lock == 'N' || lock == 'n')
		{
			LockStatus = false;
			cout << "Phone is now unlocked." << endl;
			return LockStatus;
		}
		else {
			cout << "Invalid selection lock status will be set to false." << endl;
		}
	}
	Mobile() {
		cout << "Empty Constructor" << endl;
	}

	Mobile(string o, string n, float b, string os, bool ls) {
		MobileOwner = o;
		MobileNumber = n;
		Balance = b;
		OsName = os;
		LockStatus = ls;
		cout << "Parameterized Constructor" << endl;
	}

	float Recharge(int amount) {
		cout << "Recharge successful. Your previous balance was " << Balance << " Taka." << endl;
		Balance += amount;
		cout << " Current balance is BDT " << Balance << "\n" << endl;
		return Balance;
	}

	float CallSomeone(int timeDuration) {
		if (LockStatus == false)
		{
			float cost{};
			cost = timeDuration * 0.5;
			Balance -= cost;
			cout << "\nYour call duration was " << timeDuration << " minutes. Your current balance is " << Balance << "\n" << endl;
			return Balance;
		}
		else
		{
			cout << "\nYou can't make calls. The phone is locked.\n" << endl;
		}
	}

	void ShowInfo() {
		cout << "Mobile Owner Name           : " << MobileOwner << endl;
		cout << "Mobile Number // SIM number : " << MobileNumber << endl;
		cout << "Mobile Balance              : " << Balance << endl;
		cout << "Mobile OS Name              : " << OsName << endl;
		cout << "Lock Status                 : " << boolalpha << LockStatus << endl;
	}

	~Mobile() {
		cout << "Destructor called for " << MobileOwner << endl;
	}
};

int main()
{
	Mobile b1;
	b1.ShowInfo();
	b1.CallSomeone(2);
	Mobile b2("SUS", "0112343345", 100, "Android", true);
	b2.ShowInfo();
	b2.CallSomeone(4);
	Mobile b3;
	b3.setMobileOwner();
	b3.getMobileNumber();
	b3.getBalance();
	b3.setOsName();
	b3.GetLockStatus();
	b3.CallSomeone(2);
	b3.ShowInfo();
	return 0;
}

//TASK 1

//#include <iostream>
//#include<string>
//using namespace std;
//
//class Account
//{
//private:
//	string AccountName{ "Not Set" };
//	string AccountNo{ "Not Set" };
//	int Balance{ 0 };
//	string AccountType{ "Not Set" };
//
//public:
//
//	//Setter Methods (Sets values from main)
//	void setAccountName(string name) {
//		AccountName = name;
//		cout << "Account name set to " << AccountName << endl;
//	}
//
//	void setAccountNo(string no) {
//		AccountNo = no;
//		cout << "Account number set to " << AccountNo << endl;
//	}
//
//	void setBalance(int amount) {
//		Balance += amount;
//		cout << "Account balance added BDT " << Balance << endl;
//	}
//
//	void setAccountType(string type) {
//		AccountType = type;
//		cout << "Account type is set to " << AccountType << endl;
//	}
//
//	//Getter Methods (Gets user inputs from console)
//	void getAccountName() {
//		string name{};
//		cout << "Enter Account Name : ";
//		getline(cin, name);
//		AccountName = name;
//	}
//
//	string getAccountNo() {
//		string no{};
//		cout << "Enter Account Number : ";
//		cin >> no;
//		AccountNo = no;
//		return AccountNo;
//	}
//
//	int getBalance() {
//		int amount{};
//		cout << "Enter Amount To Add To Balance : ";
//		cin >> amount;
//		Balance += amount;
//		return Balance;
//	}
//
//	string getAccountType() {
//		string type{};
//		cout << "Enter Account Type : ";
//		cin >> type;
//		AccountType = type + " Account";
//		return AccountType;
//	}
//
//	//Methods
//	int Deposit(int amount) {
//		cout << "\nDepositing..." << endl;
//		cout << "Deposited " << amount << " BDT to " << AccountNo << " successfully." << endl;
//		Balance += amount;
//		cout << "Current balance is BDT " << Balance << "\n" << endl;
//		return Balance;
//	}
//
//	int Withdraw(int amount) {
//		if (amount <= Balance)
//		{
//			cout << "\nWithdrawing BDT " << amount << " from " << AccountNo << "...\nWithdraw successful.\nYour previous balance was BDT " << Balance << endl;
//			Balance -= amount;
//			cout << "Current balance is BDT " << Balance << "\n" << endl;
//			return Balance;
//		}
//		else
//		{
//			cout << "\nWithdrawing from " << AccountNo << "...\nCan't withdraw balance too low." << endl;
//			return 0;
//		}
//	}
//
//	int Transfer(int amount, Account receiver) {
//		if (Balance >= amount)
//		{
//			cout << "\nTransfering...\n";
//			receiver.Balance += amount;
//			Balance -= amount;
//			cout << "Transferd BDT " << amount << " from " << AccountNo << " to " << receiver.AccountNo << " successfully." << endl;
//			cout << "Sender " << AccountName << "'s balance is BDT " << Balance << endl;
//			cout << "Receiver " << receiver.AccountName << "'s balance is BDT " << receiver.Balance << endl;
//			return Balance;
//		}
//		else
//		{
//			cout << "\nInsufficient balance. Can't transfer." << endl;
//			return 0;
//		}
//	}
//
//	void ShowAccountDetails() {
//		cout << "\nShowing " << AccountName << "'s Account Details..." << endl;
//		cout << "Account Name : " << AccountName << endl;
//		cout << "Account No   : " << AccountNo << endl;
//		cout << "Balance      : " << Balance << endl;
//		cout << "Account Type : " << AccountType << endl << endl;
//	}
//
//	//Constructor ~ Destructor
//	Account() {
//		cout << "Empty Constructor Called. Default Values Set." << endl;
//	}
//
//	Account(string o, string n, int b, string a) {
//		AccountName = o;
//		AccountNo = n;
//		Balance = b;
//		AccountType = a;
//		cout << "Parameterized Constructor Called." << endl;
//	}
//
//	~Account() {
//		cout << "\nDestructor called for " << AccountName << endl;
//	}
//};
//
//int main()
//{
//	Account b1;
//	b1.ShowAccountDetails();
//	b1.setAccountName("Albar Hossain");
//	b1.setAccountNo("B1");
//	b1.setBalance(15000);
//	b1.setAccountType("Student Account");
//	b1.ShowAccountDetails();
//
//	b1.Withdraw(500);
//	b1.Deposit(1000);
//
//	Account b2("Rabla Hossain", "B2", 10000, "Savings Account");
//	b2.ShowAccountDetails();
//	b2.Transfer(5000, b1);
//	b2.ShowAccountDetails();
//
//	//User input
//	Account b3;
//	b3.getAccountName();
//	b3.getAccountNo();
//	b3.getBalance();
//	b3.getAccountType();
//
//	b3.Transfer(100, b2);
//	b3.ShowAccountDetails();
//
//	return 0;
//}