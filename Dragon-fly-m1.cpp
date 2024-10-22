#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Dragon {
public:
    Dragon(string val) : payload(val) {}

    void display() { cout << "Dragon payload: " << payload << endl; }

private:
    string payload;
};

class Falcon {
public:
    void display() {
        cout << "Falcon class ship\n";
        fly.display();
    }
private:
    Dragon fly;
};

int main() {
    Falcon heavy;
    heavy.display();
}
