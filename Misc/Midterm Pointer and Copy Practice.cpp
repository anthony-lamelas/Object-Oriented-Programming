#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;



class DynamicArray{
    public:

    DynamicArray(int s) : size(s) {

        data = new int[size];
        for (int i = 0; i < size; i++){
            data[i] = 0;
    }
    }

    //Copy constructor and destructor


    ~DynamicArray() {delete[] data;}

    DynamicArray(const DynamicArray& rhs) : size(rhs.size) {
        data = new int [size];
        for (int i =0; i<size; i++){
            data[i] = rhs.data[i];
        }
    }

    //Assignment operator

    DynamicArray& operator=(const DynamicArray& rhs){
        if (this != &rhs){
            delete[] data;
            size = rhs.size;

            data = new int[rhs.size];
            for (int i = 0; i<rhs.size; i++){
                data[i] = rhs.data[i];
            }
        }
         return *this;
    }

    private:

    int* data;
    int size;
};









class Rectangle {
    public:
    Rectangle(int w, int h) : width(w), height(h) {
        data = new int[10];
        for(int i = 0; i<width; i++){
            data[i] = 0;
        }
    }


    int getArea() const {return width*height;}
    void printVals(const int* const ptr) {cout << *ptr << endl;} 

    //Destructor
    ~Rectangle() {delete[] data;}

    //Copy Constructor
    Rectangle(const Rectangle& rhs) : width(rhs.width), height(rhs.height){
        data = new int[width];
        for(int i = 0; i<width; i++){
            data[i] = rhs.data[i];
        }
    }

    //Assignment Operator
    Rectangle& operator=(const Rectangle& rhs){
        if (this != &rhs){
            delete[] data;
            width = rhs.width;
            height = rhs.height;

            data = new int[width];
            for(int i = 0; i<width; i++){
                data[i] = rhs.data[i];
            }
        }
        return *this;
    }


    private:
        int width;
        int height;
        int* data;
};

class Person {
    public:
    Person(const string&n) : name(n){}

    string getName(const Person& person) const {return person.name;}
    private:
        string name;

};


const int& maxValArray(const int arr[], const int size){
    int max = 0;
    for(int i =0; i <size; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

void doubleValue(int* const ptr) {
    // Double the value that ptr points to
    *ptr *= 2;
}

void swapWithPointers(int* a, int* b) {
    // Swap the values of a and b using pointers
    int temp = *a;
    *a = *b;
    *b = temp;
    }

void swapWithReferences(int& a, int& b) {
    // Swap the values of a and b using references
    int temp = a;
    a = b;
    b = temp;
}


int* calculate(int a, int b) {
    // Allocate an array dynamically, store the sum and difference, and return the pointer
    int* arr = new int[2];

    arr[0] = a - b;
    arr[1] = a + b;
    return arr;
}