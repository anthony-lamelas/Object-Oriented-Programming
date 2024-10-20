#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


struct Account{
    int acc_id;
    int balance;
};

void fill(Account* data[10], ifstream& ifs, const string& filename){
    ifstream file(filename);

    if(!file){
        cerr << "error opening file" << endl;
        return;
    }

    string skip1;
    int id;
    string skip2;
    int bal;

    int index = 0;
    while(
    file >> skip1 >> id >> skip2 >> bal){
        Account* acc = new Account;
        acc->acc_id = id;
        acc->balance = bal;
        data[index] = acc;
        index +=1;
    }

    file.close();
}

void free_memory(Account* data[10]){
    for(int i = 0; i < 10; ++i){
        delete data[i];
        data[i] = nullptr;
    }
}