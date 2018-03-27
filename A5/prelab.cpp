#include <iostream>
#include <string.h>
using namespace std;

#define NAME_MAXL 30

class BankAccount {
private:
  char name[NAME_MAXL];
  int account_number;
  double balance;
public:
  /* Constructors */
  BankAccount() {
    memset(name,0,strlen(name));
    account_number = 0;
    balance = 0;
  }
  BankAccount(char *fn) {
    strcpy(name, fn);
    account_number = 0;
    balance = 0;
  }
  BankAccount(char *fn, int act, double bal) {
    strcpy(name, fn);
    account_number = act;
    balance = bal;
  }
  /* Methods */
  void printSummary() {
    cout << "Name: " << name << endl;
    cout << "Account Number: " << account_number << endl;
    cout << "Balance: " << balance << endl;
  }
  void assign_name(char *fn) {strcpy(name, fn);}
  void assign_actno(int act) {account_number = act;}
  void assign_balance(double bal) {balance = bal;}
  double withdraw(double withdraw_amt) {
    if (balance - withdraw_amt >= 0) {
      balance = balance - withdraw_amt;
      return withdraw_amt;
    }
    else {
      printf("Withdraw not possible due to lack of funds");
      return 0;
    }
  }
  void deposit(double dep_amt) {
    balance = balance + dep_amt;
  }
  double getBalance() {
    printf("Your balance: %lf\n", balance);
    return 0;
  }
};

int main(void) {
  char nCindy[] = "Cindy";
	char nBill[] = "Bill";

	BankAccount daveAcc;
	BankAccount cindyAcc(nCindy);
	BankAccount billAcc(nBill, 123456, 2000);

	// daveAcc.printSummary();
	// cindyAcc.printSummary();
	// billAcc.printSummary();
  billAcc.withdraw(500);
  billAcc.withdraw(500);
  billAcc.getBalance();
  billAcc.deposit(1250);
  billAcc.getBalance();

	return 0;
}
