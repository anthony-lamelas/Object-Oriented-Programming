/*
  rec03_start.cpp
  2024 Fall
 */

// Provided
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// Task 1
// Define an Account struct
struct Account {
     string name;
     int number;
};


// Task 2
// Define an Account class (use a different name than in Task 1)
class AccountV2 {
     friend ostream& operator << (ostream& os, const AccountV2& acc);

     public:
          AccountV2(const string& n, const int& num): name(n), number(num){}

     const string& getName() const {return name;}
     int getNumber() const {return number;}

     private:
          string name;
          int number;
};

// Task 3
// Define another Account class (use a different name than in Task
// 1&2) and a Transaction class. The Transaction class is to be
// defined outside of the Account class, i.e. it is not "nested".

class Transaction {
     friend ostream& operator << (ostream& os, const Transaction& tran);
     public:
          Transaction(const string& type, const int& a) : type(type), amount(a){} 

          string getType() const {return type;}
          int getAmount() const {return amount;} 
             
     private:
          string type;   
          int amount;
};

class AccountV3 {
     friend ostream& operator << (ostream& os, const AccountV3& acc);
     public:
          AccountV3(const string& name, const int& number, const vector<Transaction>& h = {}, const int& b = 0) 
               : name(name), number(number), history(h), balance(b){}

     void deposit(const int amount){
          balance += amount;
          history.push_back(Transaction("Deposit", amount));    
     }

     void withdrawal(int amount){
          if (amount > balance){
               cerr << "Insufficient funds." << endl; 
          } else {
               balance -= amount;
               history.push_back(Transaction("Withdrawal", amount)); 
          }
     }

     int getNumber() const { return number; }

     private:
          string name;
          int number;
          vector<Transaction> history;
          int balance;
};


// Task 4
// Define yet another Account class, this time with a nested public
// Transaction class. Again use a different name for the Account class
// than in the previous Tasks. Note that it is NOT necessary to rename
// the Transaction class, since it is nested.

class AccountV4 {
    friend ostream& operator << (ostream& os, const AccountV4& acc);

    public:
        class Transaction {
            friend ostream& operator << (ostream& os, const Transaction& tran);
            
            public:
                Transaction(const string& type, const int& a) : type(type), amount(a) {}
                
                string getType() const { return type; }
                int getAmount() const { return amount; }

            private:
                string type;
                int amount;
        };
        AccountV4(const string& name, const int& number, const int& b = 0) 
            : name(name), number(number), balance(b) {}

        void deposit(const int amount) {
            balance += amount;
            history.push_back(Transaction("Deposit", amount));
        }
        void withdrawal(const int amount) {
            if (amount > balance) {
                cerr << "Insufficient funds." << endl;
            } else {
                balance -= amount;
                history.push_back(Transaction("Withdrawal", amount));
            }
        }

        int getNumber() const { return number; }
    private:
        string name;
        int number;
        vector<Transaction> history;
        int balance;
};



// Task 5
// Same as Task 4, but make the Transaction nested class private.
// Yes, the Account class needs a new name but, again, the Transaction
// class does not.

//Prototypes
void open_file(fstream& file, const string& filename);
ostream& operator << (ostream& os, const AccountV2& acc);
ostream& operator << (ostream& os, const Transaction& tran);
ostream& operator << (ostream& os, const AccountV3& acc);
ostream& operator << (ostream& os, const AccountV4& acc);


int main() {
     fstream fileStream;
     open_file(fileStream, "accounts.txt");

    // Task 1: account as struct
    //      1a
    cout << "Task1a:\n"
         << "Filling vector of struct objects, define a local struct instance\n"
         << "and set fields explicitly:\n\n";
          string name;
          int number;
          vector<Account> account_structs;

          while (fileStream >> name >> number) {
               Account new_acc;
               new_acc.name = name;
               new_acc.number = number;
               account_structs.push_back(new_acc);
          }
          fileStream.close();

          for (const Account& acc : account_structs){
               cout << acc.name << " " << acc.number <<  endl;
          }
          cout << "\n" << endl;

    //      1b
    cout << "Task1b:\n"
         << "Filling vector of struct objects, using {} initialization:\n\n";
          fileStream.clear();
         account_structs.clear();
         open_file(fileStream, "accounts.txt");

         while (fileStream >> name >> number) {
               Account new_acc{name, number};
               account_structs.push_back(new_acc);
          }
          fileStream.close();

          for (const Account& acc : account_structs){
               cout << acc.name << " " << acc.number <<  endl;
          }
          cout << "\n" << endl;

    //==================================
    // Task 2: account as class

    //      2a
    cout << "==============\n";
    cout << "\nTask2a:"
         << "\nFilling vector of class objects, using local class object:\n\n"; 
          fileStream.clear();
          vector<AccountV2> account_structs2;
         open_file(fileStream, "accounts.txt");

         while (fileStream >> name >> number) {
               AccountV2 new_acc(name, number);
               account_structs2.push_back(new_acc);
          }
          fileStream.close();

          for (const AccountV2& acc : account_structs2){
               cout << acc.getName() << " " << acc.getNumber() <<  endl;
          }
          cout << "\n" << endl;
     account_structs2.clear();

    cout << "\nTask2b:\n";
    cout << "output using output operator with getters\n\n";
    
          fileStream.clear();
          open_file(fileStream, "accounts.txt");

          while (fileStream >> name >> number) {
                    AccountV2 new_acc(name, number);
                    account_structs2.push_back(new_acc);
               }
          fileStream.close();

          for (const AccountV2& acc : account_structs2){
                    cout << acc;
          }
     cout << "\n" << endl;
     account_structs2.clear();


    cout << "\nTask2c:\n"
         << "output using output operator as friend without getters\n\n";

          fileStream.clear();
          open_file(fileStream, "accounts.txt");

          while (fileStream >> name >> number) {
               AccountV2 new_acc(name, number);
               account_structs2.push_back(new_acc);
          }
          fileStream.close();
          for (const AccountV2& acc : account_structs2){
               cout << acc;
          }
          account_structs2.clear();

    cout << "\n" << endl;

    cout << "\nTask2d:\n"
         << "Filling vector of class objects, using temporary class object:\n\n";

    fileStream.clear();
          open_file(fileStream, "accounts.txt");

          while (fileStream >> name >> number) {
               account_structs2.push_back(AccountV2(name, number));
          }
          fileStream.close();
          for (const AccountV2& acc : account_structs2){
               cout << acc;
          }
          account_structs2.clear();

    cout << "\nTask2e:\n"
         << "Filling vector of class objects, using emplace_back:\n\n";

     fileStream.clear();
            open_file(fileStream, "accounts.txt");
     
            while (fileStream >> name >> number) {
                  account_structs2.emplace_back(name, number);
            }
            fileStream.close();
            for (const AccountV2& acc : account_structs2){
                  cout << acc;
            }
            account_structs2.clear();   

            cout << "\n" << endl;
    
    cout << "==============\n"
         << "\nTask 3:\nAccounts and Transaction:\n";

     fstream transaction_stream;
     open_file(transaction_stream, "transactions.txt");
     vector<AccountV3> account_structs3;
     string command;
     int amount;

while (transaction_stream >> command){
     if (command == "Account"){
          transaction_stream >> name >> number;
          account_structs3.push_back(AccountV3(name, number)); 

     } else if (command == "Deposit"){
          transaction_stream >> number >> amount;
          for (AccountV3& acc : account_structs3){
               if (acc.getNumber() == number){
                    acc.deposit(amount);  
                    break;
               }
          }
     } else if (command == "Withdraw"){
          transaction_stream >> number >> amount;
          for (AccountV3& acc : account_structs3){
               if (acc.getNumber() == number){
                    acc.withdrawal(amount);  
                    break;
               }
          } 
     }
}

for (const AccountV3& acc : account_structs3) {
    cout << acc;  
}
transaction_stream.close();


    cout << "==============\n"
         << "\nTask 4:\nTransaction nested in public section of Account:\n";

fstream transaction_stream4;
open_file(transaction_stream4, "transactions.txt");
vector<AccountV4> account_structs4;
string command4;
int amount4;

while (transaction_stream4 >> command4) {
    if (command4 == "Account") {
        transaction_stream4 >> name >> number;
        account_structs4.push_back(AccountV4(name, number));  

    } else if (command4 == "Deposit") {
        transaction_stream4 >> number >> amount4;
        for (AccountV4& acc : account_structs4) {
            if (acc.getNumber() == number) {
                acc.deposit(amount4);  
                break;
            }
        }

    } else if (command4 == "Withdraw") {
        transaction_stream4 >> number >> amount4;
        for (AccountV4& acc : account_structs4) {
            if (acc.getNumber() == number) {
                acc.withdrawal(amount4);  
                break;
            }
        }
    }
}

for (const AccountV4& acc : account_structs4) {
    cout << acc;  
}


    cout << "==============\n"
         << "\nTask 5:\nTransaction nested in private section of Account:\n";

}

void open_file(fstream& file, const string& filename){

     file.clear();
     file.open(filename);

     if (!file) {
          cerr << "Failed to open file." << endl;
          exit(1);
     }
}

//operator overload
ostream& operator << (ostream& os, const AccountV2& acc){
    //os << acc.getName() << acc.getNumber() << endl;
    os << acc.name << " " << acc.number << endl;
    return os;
}

ostream& operator<<(ostream& os, const Transaction& tran){
    os << tran.getType() << " " << tran.getAmount() << endl;
    return os;
}

ostream& operator<<(ostream& os, const AccountV4::Transaction& tran){
    os << tran.getType() << " " << tran.getAmount() << endl;
    return os;
}

ostream& operator << (ostream& os, const AccountV3& acc) {
    os << acc.name << endl;
    for (const Transaction& tran : acc.history) {
        os << tran;  
    }
    return os;  
}

ostream& operator << (ostream& os, const AccountV4& acc) {
    os << acc.name << endl;
    for (const AccountV4::Transaction& tran : acc.history) {
        os << tran;
    }
    return os;
}

