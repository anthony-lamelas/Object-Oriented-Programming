#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int SIZE = 12;
    int* arr = new int[SIZE];

    for (int i = 0; i < SIZE; i++){
        arr[i] = 2*i - 1;
    }

    int* ptr1 = arr + SIZE - 2;
    int* ptr2 = ptr1 - 1;

    cout <<"A: " << ptr1[1] << endl;
    cout << "B: " << *ptr2 << endl;
}