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
      cout << "Withdrawal Successful" << endl << endl;
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

class saveBankAccount : public BankAccount {
public:
  double interestRate;
  int noWithDraws;
  int MAXnoWithDraws;
  /* Add onto constructor from base class */
  saveBankAccount(char *fn, int act, double bal, double irate, int wdmax)
  : BankAccount(fn, act, bal)
  {
    interestRate = irate;
    MAXnoWithDraws = wdmax;
    noWithDraws = 0;
  }
  /* Add onto method from base class */
  void printSummary() {
    BankAccount::printSummary();
    cout << "Interest Rate: " << interestRate << endl;
    cout << "Number of Withdrawals: " << noWithDraws << endl;
    cout << "Max Number of Withdrawals: " << MAXnoWithDraws << endl;
  }
  double calInterest(int irate, double bal) {
    return irate*bal;
  }
  void resetWithdraws() {
    noWithDraws = 0;
  }
  double withdraw(double withdraw_amt) {
    if (noWithDraws < MAXnoWithDraws) {
      noWithDraws++;
      BankAccount::withdraw(withdraw_amt);

    }
    else {
      cout << "Number of Withdrawals Exceeded" << endl << endl;
      return 0;
    }
  }
};

int main(void) {
  char nTom[] = "Tom";

  saveBankAccount tomAcc(nTom, 234567, 3000, 0.05, 1);

  tomAcc.printSummary();
  tomAcc.withdraw(500);
  tomAcc.withdraw(500);
  tomAcc.printSummary();
  tomAcc.resetWithdraws();
  tomAcc.withdraw(500);
  tomAcc.printSummary();

	return 0;
}
