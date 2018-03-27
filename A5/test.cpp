#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;
#define NAME_MAXL 30


class BankAccount
{
protected:
    char name[NAME_MAXL];
    int account_number;
    double balance;
    
    
public:
    void printSummary();
    void setBalance(double);
    void setName(char*);
    void setacc(int);
    void deposit(double);
    double withdraw(double);
    double getBalance(double);
    BankAccount ();
    BankAccount (char *n);
    BankAccount(char *n, int acc, float bal);
    double callInterest(double balance);
    
    
};






class saveBankAccount : public BankAccount
{
private:
    double interestrates;
    int noWithDraws;
    int MAXnoWithDraws;
    
    
public:
    saveBankAccount(): BankAccount()
    {
        interestrates= 0.0;
        noWithDraws= 0;
        MAXnoWithDraws = 0;
        
    }
    saveBankAccount(char x[], int acc, double bal, double interest_rates, int NoWithDraws, int MAXNoWithDraws): BankAccount(x, acc, bal)
    {
        interestrates= interest_rates;
        noWithDraws= NoWithDraws;
        MAXnoWithDraws = MAXNoWithDraws;
    }
    void printSummary() {
        BankAccount::printSummary();
        cout << "Interests_Rates:" << interestrates << endl;
        cout << "NoWithDraws:"<<noWithDraws << endl;
        cout << "MAXnoWithDraws:" << MAXnoWithDraws << endl;
        cout << "---------------------" << endl;
    }
    
    void resetWithdraws(int NoWithDraws);
    
    
    double callInterest(double balance, double interest_rates);
    
    double withdraw(double d)
    {
        if (noWithDraws<MAXnoWithDraws)
        {
            BankAccount::withdraw(d);
        }
        else
        {
            cout << "sorry but you seemed to have reached your limit of withdraws" << endl;
        }
        noWithDraws=noWithDraws+1;
        return (d);
    }
    
    
    
    
};






int main(void)
{
    char name1[]="Tom";
    
    
    saveBankAccount tomAcc(name1, 234567, 3000, 0.05, 0, 1);
    
    
    tomAcc.printSummary();
    // tomAcc.BankAccount::printSummary();
    
    tomAcc.callInterest(0,0);
    tomAcc.withdraw(500);
    cout << "Balance is: " << tomAcc.getBalance(1) << endl;
    cout << "---------------------" << endl;
    tomAcc.callInterest(0,0);
    tomAcc.withdraw(500);
    cout << "Balance is: " << tomAcc.getBalance(1) << endl;
    cout << "---------------------" << endl;
    tomAcc.resetWithdraws(0);
    tomAcc.callInterest(0,0);
    tomAcc.withdraw(500);
    cout << "Balance is: " << tomAcc.getBalance(1) << endl;
    cout << "---------------------" << endl;
    return(0);
    
}










//**********************************************
// class BankAccount: methods
//**********************************************

double BankAccount :: callInterest(double x)
{
    
    x=balance;
    
    return(x);
}

double saveBankAccount:: callInterest(double x,double y)
{
    double interest;
    x= BankAccount::callInterest(x);
    
    y=interestrates;
    
    interest= x*y;
    cout << "interest: " << interest<< endl;
    
    return (interest);
    
}
void saveBankAccount:: resetWithdraws(int x)
{
    x=0;
    noWithDraws=0;
}


BankAccount :: BankAccount () {
    name[0] = 0;
    account_number = 0;
    balance = 0.0;
}

BankAccount :: BankAccount (char *x) {
    strcpy(name, x);
    account_number = 0;
    balance = 0.0;
}

BankAccount :: BankAccount(char  *x, int acc, float bal) {
    strcpy(name, x);
    account_number = acc;
    balance = bal;
}

void BankAccount :: setName(char *x)
{
    strcpy(name, x);
}

void BankAccount :: setBalance(double b)
{
    balance = b;
}
void BankAccount :: setacc(int c)
{
    account_number=c;
}

void BankAccount :: printSummary() {
    cout << "---------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Account Number: " << account_number << endl;
    cout << "Balance: " << balance << endl;
    cout << "---------------------" << endl;
}

double BankAccount:: withdraw(double d)
{
    if (balance>d)
    {
        balance-=d;
    }
    else
        
    {
        printf("Error insuffiecient funds sorry for the inconvenience...\n");
    }
    return (d);
}


double BankAccount :: getBalance(double e)
{
    
    return balance;
}

void BankAccount :: deposit(double toDep)
{
    balance += toDep;
}

//**********************************************
//**********************************************

