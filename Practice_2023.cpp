#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void foo(const int x) {
     const int* p = &x;
     cout << *p;
}
int main(){
    int y = 42;
    foo(y);
    cout << y << endl;
}