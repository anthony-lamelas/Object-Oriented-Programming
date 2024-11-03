#include <string>
#include <iostream>
#include <vector>
using namespace std;


class IntArray {
private:
    int* arr;
    int size;

public:
    // Constructor
    IntArray(int s) : size(s) {
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = 0;
        }
    }

    // Destructor
    ~IntArray(){
        delete[] arr;
        arr = nullptr;
        }

    // Copy Constructor
        IntArray(const IntArray& rhs) : size(rhs.size){
            arr = new int[size];
            for (int i =0; i<size; ++i){
                arr[i] = rhs.arr[i];
            }
        }
    

    // Assignment Operator
    IntArray& operator=(const IntArray& rhs){
        if(this != &rhs){
        delete[] arr;
        arr = nullptr;
        size = rhs.size;

        arr = new int[size];
        for (int i =0; i<size; ++i){
                arr[i] = rhs.arr[i];
            }
        }
        return *this;
    }
    
};

class StringArray {
private:
    string* arr;
    int size;

public:
    // Constructor
    StringArray(int s) : size(s) {
        arr = new string[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = "";
        }
    }

    // Destructor
    ~StringArray(){
        delete[] arr;
        arr = nullptr;
    }

    // Copy Constructor
    StringArray(const StringArray& rhs) : size(rhs.size){
        arr = new string[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = rhs.arr[i];
        }
    }
  

    // Assignment Operator
    StringArray& operator=(const StringArray& rhs){
        if(this != &rhs){
            delete[] arr;
            arr = nullptr;

            size = rhs.size;
            arr = new string[size];
            for (int i = 0; i < size; ++i) {
                arr[i] = rhs.arr[i];
            }

        }
        return *this;
    }
 
};




class Matrix {
private:
    int** data;
    int rows;
    int cols;

public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = 0; // Initialize with 0
            }
        }
    }

    // Destructor
    ~Matrix(){
        for (int i = 0; i < rows; ++i){
                delete[] data[i];
        }
        delete[] data;
    };

    // Copy Constructor
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols){
        
        data = new int*[rows];
        for (int i = 0; i < rows; ++i){
            data[i] = new int[cols];
            for (int j = 0; j<cols; ++j){
                data[i][j] = other.data[i][j];
            }
        } 
    };

    // Assignment Operator
    Matrix& operator=(const Matrix& other){
        if (this != &other){
        for (int i = 0; i < rows; ++i){
                delete[] data[i];
        }
        delete[] data;

        cols = other.cols;
        rows = other.rows;

        data = new int*[rows];
        for (int i = 0; i < rows; ++i){
            data[i] = new int[cols];
            for (int j = 0; j<cols; ++j){
                data[i][j] = other.data[i][j];
            }
        } 
        }
        return *this;

    };

    // Other member functions can be added here...
};


#include <cstring>
using namespace std;

class StringArray {
private:
    char** data;
    int size;

public:
    // Constructor
    StringArray(int s) : size(s) {
        data = new char*[size];
        for (int i = 0; i < size; ++i) {
            data[i] = nullptr; // Initialize with null pointers
        }
    }

    // Destructor
    ~StringArray(){
         for (int i = 0; i < size; ++i) {
            delete[] data[i]; 
        }
        delete[] data;
    }

    // Copy Constructor
    StringArray(const StringArray& rhs) : size(rhs.size){
        data = new char*[size];

        for (int i = 0; i < size; ++i){
            data[i] = rhs.data[i];
        }
    }

    // Assignment Operator
    StringArray& operator=(const StringArray& rhs){

        if (&rhs != this){
            for (int i = 0; i < size; ++i) {
            delete[] data[i]; 
        }
            delete[] data;

            size = rhs.size;

            data = new char*[size];
            for (int i = 0; i<size; ++i){
                data[i] = rhs.data[i];
            }

        }
        return *this;
    }

};


int main(){

    int** daip = new int*[100];

    for (int i = 0; i < 100; ++i){
        daip[i] = new int(i + 1);
    }

    for (int i = 0; i < 100; ++i){
        *daip[i] += i;
    }

    for (int i = 0; i < 100; ++i){
        delete daip[i];
        daip[i] = nullptr;
    }

        delete daip;
        daip = nullptr;

    vector<int*>* vect;

//A
    int** intArray = new int*[50];


//B
    int count = 0;
    for (int i = 0; i<50; ++i){
        count+=2;
        intArray[i] = new int(count);
    }

//C
     for (int i = 0; i<50; ++i){
        *intArray[i] += (i*3);
     }

//D
     for (int i = 0; i<50; ++i){{
        delete intArray[i];
        intArray[i] = nullptr;
     }
        delete[] intArray;
        intArray = nullptr;
}


//has Battery* bt and double size
Cellphone& operator=(const Cellphone& rhs){
    if (this != &rhs){
        delete bt;
        size = rhs.size;

        bt = new Battery(*rhs.bt);
    }
    return *this;
    
}

