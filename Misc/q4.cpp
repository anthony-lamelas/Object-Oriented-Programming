#include<iostream>

using namespace std;
/*
class Thing{
public:
    Thing(double x = 0): x(x) {} // line 1
    void display() {
        cout << x;
    } // line 2
private:
    double x;
};

int main(){
    Thing th;           // line 3
    th = 2.718;         // line 4
    th.display();       // line 5
}*/

int main() {
    int* numbers = new int[5];
    for (int i = 0; i < 5; i++) {
        numbers[i] = i;
    }

    numbers++;
    for (int i = 0; i < 2; i++) {
        numbers[i]++;
    }

    cout << *(numbers + 1) << " ";
}

